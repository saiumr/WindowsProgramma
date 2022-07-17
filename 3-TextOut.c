#include <wchar.h>
#include <windows.h>

LRESULT CALLBACK WndProcTextOut(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProcDrawText(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    PSTR cmdLine,  
    int cmdShow  
) {
    static TCHAR szClassName[] = TEXT("TextWelcomeWindowsClass");
    HWND hwnd;
    MSG msg;
    WNDCLASS wndclass;

    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    //wndclass.lpfnWndProc = WndProcTextOut;
    wndclass.lpfnWndProc = WndProcDrawText;
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

//���ڹ���
LRESULT CALLBACK WndProcDrawText(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
    HDC         hdc;  //�豸�������
    PAINTSTRUCT ps;
    RECT        rect;
    switch (message){
        //���ڻ�����Ϣ
        case WM_PAINT:
            hdc = BeginPaint (hwnd, &ps) ;
            GetClientRect (hwnd, &rect) ;
            DrawText(
                hdc,
                TEXT("��ã���ӭ����C����������"),
                -1,
                &rect,
                DT_SINGLELINE | DT_CENTER | DT_VCENTER
            );
            EndPaint (hwnd, &ps) ;
            return 0 ;
        //����������Ϣ
        case WM_DESTROY:
            PostQuitMessage(0) ;
            return 0 ;
    }
    return DefWindowProc(hwnd, message, wParam, lParam) ;
}

LRESULT CALLBACK WndProcTextOut(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    HDC hdc;   
    PAINTSTRUCT ps;
    TCHAR szText[] = TEXT("�¸³壡");

    switch (message) {
        case WM_PAINT:
            hdc = BeginPaint(hwnd, &ps);
            TextOut(hdc, 50, 50, szText, lstrlen(szText));
            EndPaint(hwnd, &ps);
            return 0;
        
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc(hwnd, message, wParam, lParam);
}



