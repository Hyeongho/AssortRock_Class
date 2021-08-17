// 210817.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "210817.h"

/*
    윈도우는 메세지 기반의 운영체제이다.
    특정이벤트(마우스 클릭이나 키보드 누름, 마우스 이동 등) 가 발생하면 운영체제는 이를 메세지로 만들어준다.
    윈도우즈 프로그램은 메세지 큐를 가지고 있다.
    무한 루프로 메세지 루프가 돌아가며 운영체제가 메세지큐에 메세지를 넣어주면 해당 메세지를 받아와서
    메세지에 맞는 작업을 처리해주게 된다.
    윈도우 종료 메세지가 들어오면 무한루프도 종료가 되며 프로그램이 종료가 되는 방식이다.
*/

#define MAX_LOADSTRING 100

// 전역 변수:
// HINSTANCE는 실행되는 프로그램을 구분하기 위해 운영체제가 부여하는 고유한 ID값이다.
HINSTANCE hInst;                                // 현재 인스턴스입니다.

// WinAPI를 할때는 Unicode 문자집합을 이용하여 문자열을 사용한다.
// multbite 문자집합을 사용하던 기존 방식은 char배열을 이용하여 문자열을 표현하였다.
// 이는 알파벳같은 1바이트 문자를 저장할때 유용한 방법이지만 한국어, 일어, 중국어 등은 2개의 배열을 이용하여 표현해야 했다.
// wchar_t 라는 타입이 있다. 이 타입은 2바이트 변수이다. 2바이트 문자들도 변수 1개에 저장이 가능한 타입이다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

// WinMain이 WinAPI의 진입점 함수이다.
// 이 함수는 운영체제가 동작시켜주며 운영체제가 이 프로그램이 동작될때 고유한 ID를 만들어서 인자로 전달해주고 있다.
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY210817, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY210817));

    MSG msg;

    // 기본 메시지 루프입니다:

    /*
        윈도우의 메세지 루프입니다. GetMessage 함수를 이용해서 메세지 큐에 있는 메세지를 얻어올 수 있다.
        만약 메세지큐에 아직 메세지가 없다면 메세지가 들어올때까지 이 함수에서 안빠져나오고 대기상태로 들어가있게 된다.
        즉, 메세지가 생길때까지 다른작업을 할 수 없다는 의미이다.
        GetMessage 함수는 만약 윈도우 종료메세지가 들어올 경우 while문을 빠져나갈 수 있게 FALSE가 나오게 된다.
    */
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            // WM_KEYDOWN 이라는 메세지가 있다. 이는 키보드 키를 눌렀을때 발생되는 메세지이다.
            // TranslateMessage 함수에서는 메세지를 전달해주면 WM_KEYDOWN 인지를 판단해주고
            // 눌려진 키가 문자 키인지를 판단해거 인반 문자 키라면 WM_CHAR라는 메시지를 만들어서 메세지 큐에 추가해주게 된다.
            TranslateMessage(&msg);

            // DIspatchMessage 함수는 메세지를 윈도우 프록시저로 보내준다.
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    // 작업영역이 바뀔때 다시 크리게끔 해준다. 가로와 세로 모두 다시 그린다.
    wcex.style          = CS_HREDRAW | CS_VREDRAW;

    // 메세지가 큐에 들어왔을때 해당 메세지를 꺼내오고 꺼내온 메세지를 인자로 전달해서 호출해줄 함수를 지정한다.
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;

    // window Instance를 지정한다.
    wcex.hInstance      = hInstance;

    // 실행파일이 만들어질때 사용할 아이콘 이미지를 지정한다.
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY210817));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY210817);
    // 유니코드 문자열을 사용할때 L"" 을 붙여서 사용을 한다.
    // TEXT 매크로는 "" 앞에 L 을 붙여서 L"" 만들어준다.
    // 유니코드일때는 이렇게 해주고 multibyte 일때는 그냥 "" 로 만들어준다.
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.
    
   /*
       CreateWindow 함수를 이용해서 윈도우 창을 만들면 WindowHandle를 반환해준다.
       WindowHandle은 각 윈도우마다의 고유한 번호이다.
   */
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   // SW_SHOW: 윈도우창을 화면에 보여준다.
   // SW_HIDE: 창을 만들긴 하지만 화면에 보여주는건 아니다.
   ShowWindow(hWnd, nCmdShow);

   // UpdateWindow 함수는 갱신할 부분이 있다면 갱신하라는 명령을 내려주는 함수다.
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;

            // HDC: 화면에 출력하기 위한 그리기 도구이다.
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

            Rectangle(hdc, 100, 100, 200, 200);
            Ellipse(hdc, 200, 100, 300, 200);

            // MoveToEx: 선의 시작점을 지정한다.
            MoveToEx(hdc, 400, 100, nullptr);

            // LineTo: 선의 끝점을 지정한다.
            LineTo(hdc, 500, 200);

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
