#include "GameManager.h"
#include "Timer.h"

CGameManager* CGameManager::m_Inst = nullptr;
bool CGameManager::m_Loop = true;

CGameManager::CGameManager() : m_Timer(nullptr)
{
}

CGameManager::~CGameManager()
{
    ReleaseDC(m_hWnd, m_hDC);

    SAFE_DELETE(m_Timer);
}

bool CGameManager::Init(HINSTANCE hInst)
{
	m_hInst = hInst;

    m_RS.Width = 1280;
    m_RS.Height = 720;

	Register();
	Create();

    // DC�� �����Ѵ�.
    m_hDC = GetDC(m_hWnd);

    m_RenderRC.Left = 100;
    m_RenderRC.Top = 100;
    m_RenderRC.Right = 200;
    m_RenderRC.Bottom = 200;

    m_Timer = new CTimer;

	return true;
}

int CGameManager::run()
{
    MSG msg;

    // �⺻ �޽��� �����Դϴ�:

    /*
        �������� �޼��� �����Դϴ�. GetMessage �Լ��� �̿��ؼ� �޼��� ť�� �ִ� �޼����� ���� �� �ִ�.
        ���� �޼���ť�� ���� �޼����� ���ٸ� �޼����� ���ö����� �� �Լ����� �Ⱥ��������� �����·� ���ְ� �ȴ�.
        ��, �޼����� ���涧���� �ٸ��۾��� �� �� ���ٴ� �ǹ��̴�.
        GetMessage �Լ��� ���� ������ ����޼����� ���� ��� while���� �������� �� �ְ� FALSE�� ������ �ȴ�.
    */
    while (m_Loop)
    {
        // GetMessage�� �޼����� ���� ��� �ٸ����� �� �� ����.
        // �޼����� �ö����� ����ϰ� �ִ� �ð��� �������� ����Ÿ���̶�� �Ѵ�.
        // ������ �޼����� �ִ� �ð����� ���� �ð��� �ξ� ���.
        // �׷��� ������ �������� ����Ÿ�ӵ��� ������ ���۵� �� �ְ� �����Ѵ�.
        // PeekMessage�� �޼���ť���� �޼����� ���´�.
        // �׷��� ���� �޼����� ���ٸ� false�� �����ϸ鼭 �ٷ� ����������
        // �޼����� �ִٸ� true�� �����ϸ鼭 �ش� �޼����� �����´�
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            // WM_KEYDOWN �̶�� �޼����� �ִ�. �̴� Ű���� Ű�� �������� �߻��Ǵ� �޼����̴�.
            // TranslateMessage �Լ������� �޼����� �������ָ� WM_KEYDOWN ������ �Ǵ����ְ�
            // ������ Ű�� ���� Ű������ �Ǵ��ذ� �ι� ���� Ű��� WM_CHAR��� �޽����� ���� �޼��� ť�� �߰����ְ� �ȴ�.
            TranslateMessage(&msg);

            // DIspatchMessage �Լ��� �޼����� ������ ���Ͻ����� �����ش�.
            DispatchMessage(&msg);
        }

        // �����찡 ����Ÿ���� ��� ����� ������ �ȴ�.
        else
        {
            Logic();
        }
    }

    return (int)msg.wParam;
}

void CGameManager::Logic()
{
    float DeltaTime = m_Timer->Update();

    Update(DeltaTime);
    PostUpdate(DeltaTime);
    Collision(DeltaTime);
    Render(DeltaTime);
}

bool CGameManager::Update(float DeltaTime)
{
    return false;
}

bool CGameManager::PostUpdate(float DeltaTime)
{
    return false;
}

bool CGameManager::Collision(float DeltaTime)
{
    return false;
}

void CGameManager::Render(float DeltaTime)
{
    // GetAsyncKeyState �Լ��� Ű�� �ԷµǾ������� ������ �� �ִ� �Լ��̴�.
    // 0�� ���ϵǸ� Ű�� ������ �������̴�.
    // 0x8000 �� ������ �Ǹ� Ű�� ���� �������̴�.
    // 0x1�� ������ �Ǹ� Ű�� ������ �ȴ������� ���������ӿ� Ű�� �����ٴ� ���̴�.
    // 0x8001 �� ������ �Ǹ� ���ݵ� ������ ���������ӿ��� ������ ��� ����� �ִٴ� ���̴�
    if (GetAsyncKeyState('W') & 0x8000)
    {
        m_RenderRC.Top -= 200.f * DeltaTime;
        m_RenderRC.Bottom -= 200.f * DeltaTime;
    }

    if (GetAsyncKeyState('S') & 0x8000)
    {
        m_RenderRC.Top += 200.f * DeltaTime;
        m_RenderRC.Bottom += 200.f * DeltaTime;
    }

    if (GetAsyncKeyState('A') & 0x8000)
    {
        m_RenderRC.Left -= 200.f * DeltaTime;
        m_RenderRC.Right -= 200.f * DeltaTime;
    }

    if (GetAsyncKeyState('D') & 0x8000)
    {
        m_RenderRC.Left += 200.f * DeltaTime;
        m_RenderRC.Right += 200.f * DeltaTime;
    }

    if (GetAsyncKeyState(VK_SPACE) & 0x8000)
    {    
        BulletInfo Info;

        Info.rc.Left = m_RenderRC.Right;
        Info.rc.Right = Info.rc.Left + 50.f;
        Info.rc.Top = m_RenderRC.Top + 25.f;
        Info.rc.Bottom = Info.rc.Top + 50.f;
        Info.Distance = 0.f;

        m_BulletList.push_back(Info);
    }

    Rectangle(m_hDC, m_RenderRC.Left, m_RenderRC.Top, m_RenderRC.Right, m_RenderRC.Bottom);

    std::list<BulletInfo>::iterator iter;

    for (iter = m_BulletList.begin(); iter != m_BulletList.end();)
    {
        (*iter).rc.Left += 400.f * DeltaTime;
        (*iter).rc.Right += 400.f * DeltaTime;

        (*iter).Distance += 400.f * DeltaTime;

        if ((*iter).Distance >= 800.f)
        {
            // erase�Լ��� �ش� iterator�� �����ϰ� ������带 ������ �ִ� iterator�� ��ȯ���ش�.
            // �׷��� ������ iter+�� �ϰ� �����Ƿ� �̷��� ó���ϸ� �������� ���� iterator�� ������ �ȵǰ� �ȴ�.
            // �׷��Ƿ� iter++�� ���ش�.
            iter = m_BulletList.erase(iter);
            continue;
        }

        Rectangle(m_hDC, (*iter).rc.Left, (*iter).rc.Top, (*iter).rc.Right, (*iter).rc.Bottom);

        iter++;
    }

    TextOut(m_hDC, 120, 70, TEXT("�׸�"), lstrlen(TEXT("�׸�")));

    char FPSText[32] = {};

    // sprintf_s: ���ڿ��� ������ִ� �Լ��̴�.
    sprintf_s(FPSText, "FPS: %.5f", m_Timer->GetFPS());
    TextOutA(m_hDC, 1000, 50, FPSText, strlen(FPSText));

    // TCHAR: �����ڵ��� ��� wchat_t �� ���������.
    TCHAR BulletCountText[32] = {};
    wsprintf(BulletCountText, TEXT("BulletCount: %d"), m_BulletList.size());

    TextOut(m_hDC, 1000, 100, BulletCountText, lstrlen(BulletCountText));
}

ATOM CGameManager::Register()
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    // �۾������� �ٲ� �ٽ� ũ���Բ� ���ش�. ���ο� ���� ��� �ٽ� �׸���.
    wcex.style = CS_HREDRAW | CS_VREDRAW;

    // �޼����� ť�� �������� �ش� �޼����� �������� ������ �޼����� ���ڷ� �����ؼ� ȣ������ �Լ��� �����Ѵ�.
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;

    // window Instance�� �����Ѵ�.
    wcex.hInstance = m_hInst;

    // ���������� ��������� ����� ������ �̹����� �����Ѵ�.
    wcex.hIcon = LoadIcon(m_hInst, MAKEINTRESOURCE(IDI_ICON1));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = nullptr;
    // �����ڵ� ���ڿ��� ����Ҷ� L"" �� �ٿ��� ����� �Ѵ�.
    // TEXT ��ũ�δ� "" �տ� L �� �ٿ��� L"" ������ش�.
    // �����ڵ��϶��� �̷��� ���ְ� multibyte �϶��� �׳� "" �� ������ش�.
    wcex.lpszClassName = TEXT("GameFramework");
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

    return RegisterClassExW(&wcex);
}

BOOL CGameManager::Create()
{
    m_hWnd = CreateWindowW(TEXT("GameFramework") , TEXT("GameFramework"), WS_OVERLAPPEDWINDOW,
        100, 100, 1280, 720, nullptr, nullptr, m_hInst, nullptr);

    if (!m_hWnd)
    {
        return FALSE;
    }

    // Ŭ���̾�Ʈ ������ 1280, 720���� ������ش�.
    // RECT: �簢���� ǥ���ϴ� ����ü�̴�.
    // left, top, right, bottom 4���� ������ �����Ǿ� �ִ�.
    RECT rc = { 0, 0, m_RS.Width, m_RS.Height };

    // 1������: Ŭ���̾�Ʈ ������ ũ�⸦ �����Ѵ�.
    // �� �Լ��� �Ϸ�Ǹ� rc���� ���� Ŭ���̾�Ʈ ������ ���ϴ� ũ�� �� �� �ִ�
    // ��ü �������� left, top, right, bottom ������ ������ �ȴ�.
    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

    // ������ ���� Rect�� �̿��ؼ� ������ ũ�⸦ �����Ѵ�.
    SetWindowPos(m_hWnd, HWND_TOPMOST, 1920, 100, rc.right - rc.left, rc.bottom - rc.top, SWP_NOMOVE);

    // SW_SHOW: ������â�� ȭ�鿡 �����ش�.
    // SW_HIDE: â�� ����� ������ ȭ�鿡 �����ִ°� �ƴϴ�.
    ShowWindow(m_hWnd, SW_SHOW);

    // UpdateWindow �Լ��� ������ �κ��� �ִٸ� �����϶�� ����� �����ִ� �Լ���.
    UpdateWindow(m_hWnd);

    return TRUE;
}

LRESULT CGameManager::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;

        // HDC: ȭ�鿡 ����ϱ� ���� �׸��� �����̴�.
        HDC hdc = BeginPaint(hWnd, &ps);     

        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        m_Loop = false;
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
