#include "GameManager.h"
#include "Timer.h"
#include "Input.h"
#include "Scene/SceneManager.h"
#include "Scene/MainScene.h"

CGameManager* CGameManager::m_Inst = nullptr;
bool CGameManager::m_Loop = true;

CGameManager::CGameManager() : m_Timer(nullptr)
{
}

CGameManager::~CGameManager()
{
    CSceneManager::DestroyInst();

    CInput::DestroyInst();

    SAFE_DELETE(m_Timer);

    ReleaseDC(m_hWnd, m_hDC);
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

    // �Է°����� �ʱ�ȭ
    if (!CInput::GetInst()->Init())
    {
        return false;
    }

    // �������� �ʱ�ȭ
    if (!CSceneManager::GetInst()->Init())
    {
        return false;
    }

    CSceneManager::GetInst()->CreateScene<CMainScene>();

    // Ÿ�̸Ӹ� �����Ѵ�.
    m_Timer = new CTimer;

	return true;
}

int CGameManager::Run()
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

    // �Է� ������Ʈ
    CInput::GetInst()->Update(DeltaTime);

    Update(DeltaTime);
    PostUpdate(DeltaTime);
    Collision(DeltaTime);
    Render(DeltaTime);
}

bool CGameManager::Update(float DeltaTime)
{
    return CSceneManager::GetInst()->Update(DeltaTime);
}

bool CGameManager::PostUpdate(float DeltaTime)
{
    return CSceneManager::GetInst()->Update(DeltaTime);
}

bool CGameManager::Collision(float DeltaTime)
{
    return CSceneManager::GetInst()->Update(DeltaTime);
}

void CGameManager::Render(float DeltaTime)
{
    CSceneManager::GetInst()->Render(m_hDC);
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
