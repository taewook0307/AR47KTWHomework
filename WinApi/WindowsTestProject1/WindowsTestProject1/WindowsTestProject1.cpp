// WindowsTestProject1.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "WindowsTestProject1.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,                 // 윈도우가 응용프로그래머에게 주는 우리 프로그램의 등록번호
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,                  // main 인자
                     _In_ int       nCmdShow)
{
    // 참조 안 한 파라미터 경고를 없애기 위한 코드
    UNREFERENCED_PARAMETER(hPrevInstance);                      // (hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);                          // (IpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSTESTPROJECT1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);                                 // 윈도우 창 형식을 등록하는 함수(내 형식을 등록)

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSTESTPROJECT1));

    MSG msg;

    // 기본 메시지 루프입니다:
    // 윈도우가 켜져있는동안 프로그램이 계속 켜져있도록 만들어놓음
    // GetMessage는 윈도우에 무슨일이 생길 때만 리턴되는 함수
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
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

    wcex.style          = CS_HREDRAW | CS_VREDRAW;                                              // 크기를 바꾸면 다시 그려라 => 다른 설정을 사용한 적 없음
    wcex.lpfnWndProc    = WndProc;                                                              // 윈도우에 무슨 일이 생기면 어떻게 해야하는가? => 함수포인터
    
    // 0이면 기본설정
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;

    wcex.hInstance      = hInstance;                                                            // 윈도우 클래스를 등록하려는 프로그램의 등록번호 지정
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSTESTPROJECT1));        // 윈도우 기본 아이콘
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);                                       // 윈도우 기본 커서 => IDC_ARROW : 화살표 변경 가능
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);                                             // 윈도우 색깔
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSTESTPROJECT1);                            // 메뉴
    wcex.lpszClassName  = szWindowClass;                                                        // 이 윈도우 형식의 이름 : 앞으로 윈도우를 만들 때 선택할 수 있는 형식 중 1가지로 등록
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);                                                             // 해당 윈도우 형식을 등록
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

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   HWND hWndTest = CreateWindowW(
       szWindowClass,               // 등록된 윈도우 형식명
       L"hWndTest", //szTitle,       // 윈도우 창 제목
       WS_OVERLAPPEDWINDOW,         // 윈도우 스타일
       CW_USEDEFAULT,               // 창의 시작점 X좌표
       0,                           // 창의 시작점 Y좌표
       CW_USEDEFAULT,               // 창의 끝점 X좌표
       0,                           // 창의 끝점 Y좌표
       nullptr,
       nullptr,
       hInstance,                   // 윈도우 창의 주인
       nullptr
   );

   if (!hWnd)
   {
      return FALSE;
   }

   if (!hWndTest)
   {
       return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   ShowWindow(hWndTest, nCmdShow);
   UpdateWindow(hWnd);                // 윈도우 한 번 갱신
   UpdateWindow(hWndTest);

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
    // HWnd : 어떤 윈도우에 메시지가 왔는지 알려주는 인자
    // message : 윈도우에서 벌어진 일의 종류를 의미 ex) 윈도우 선택, 윈도우 창 크기가 바뀜
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
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

            // HDC hdc : 화면에 그리기 위한 권한
            // 화면에 무언가를 그리기 위해서 hdc를 넘겨주고 권한을 받음

            Rectangle(hdc, 10, 10, 200, 200);   // 사각형을 그리기 위해 hdc를 넘겨줌

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);         // GetMessage 함수에서 0을 리턴하게 함
        break;
    default:
        // 처리할 수 없는 조건은 윈도우가 처리하는 기본적인 방식으로 처리하게끔 해줌. 
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
