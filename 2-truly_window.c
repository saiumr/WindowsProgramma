#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    PSTR cmdLine,  // 命令行参数  
    int cmdShow  // 窗口的显示方式
) {
    static TCHAR szClassName[] = TEXT("TextWelcomeWindowsClass");
    HWND hwnd;
    MSG msg;
    WNDCLASS wndclass;

    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszClassName = szClassName;
    wndclass.lpszMenuName = NULL;

    RegisterClass(&wndclass);

    hwnd = CreateWindow(
        szClassName,
        TEXT("Welcome"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        500,
        300,
        NULL,
        NULL,
        hInstance,
        NULL
    );
    
    ShowWindow(hwnd, cmdShow);

    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0) ) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    HDC hdc;  // 设备环境句柄，Windows不允许直接操作硬件，必须使用HDC
    PAINTSTRUCT ps;
    RECT rect;

    switch (message) {
        case WM_PAINT:
            hdc = BeginPaint(hwnd, &ps);
            GetClientRect(hwnd, &rect);
            DrawText(
                hdc,
                TEXT("Hello newbie"),
                -1,
                &rect,
                DT_SINGLELINE | DT_CENTER | DT_VCENTER
            );
            EndPaint(hwnd, &ps);
            return 0;
        
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc(hwnd, message, wParam, lParam);
}



