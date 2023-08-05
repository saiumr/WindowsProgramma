#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <windef.h>
#include <iostream>

HCURSOR cursor_normal;
HCURSOR cursor_click;
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// wWinMain is specified by MSVC
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const wchar_t CLASS_NAME[] = L"Cursor";
    
    cursor_normal = (HCURSOR)LoadImage(NULL, L"./popo1.cur", IMAGE_CURSOR, 104, 104, LR_LOADFROMFILE );
    cursor_click = (HCURSOR)LoadImage(NULL, L"./popo2.cur", IMAGE_CURSOR, 104, 104, LR_LOADFROMFILE );
    SetCursor(cursor_normal);

    WNDCLASSEX wc = {};
    wc.cbSize            = sizeof(WNDCLASSEX);
    wc.lpfnWndProc       = WindowProc;
    wc.hInstance         = hInstance;
    wc.cbClsExtra        = 0;
    wc.cbWndExtra        = 0;
    wc.lpszClassName     = CLASS_NAME;
    
    RegisterClassEx(&wc);

    HWND hwnd =  CreateWindowEx(
            WS_EX_TOOLWINDOW |
            WS_EX_NOACTIVATE |
            WS_EX_TRANSPARENT |
            WS_EX_LAYERED |
            WS_EX_TOPMOST,
            CLASS_NAME,
            L"popoCATcursor",
            WS_POPUP,
            0, 0, 0, 0,
            NULL,
            NULL,
            hInstance,
            nullptr
            );
    if (hwnd == 0) return 0;
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0) ) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CLOSE:
            if (MessageBox(hwnd, L"Really quit?", L"嘎嘎冲！", MB_OKCANCEL) == IDOK ) {
                PostQuitMessage(0);
            }
            return 0;

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW+1));
            EndPaint(hwnd, &ps);
        }
        return 0;

        case WM_LBUTTONUP:
            SetCursor(cursor_normal);
            return 0;

        case WM_LBUTTONDOWN:
            std::cout << "chao" << std::endl;
            SetCursor(cursor_click);
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


