#include <minwindef.h>
#include <windows.h>

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdddShow
) {
    int nSecelect = MessageBox(NULL, TEXT("Hello Windows!"), TEXT("Welcome"), MB_OKCANCEL);
    if (nSecelect == IDOK) {
        MessageBox(NULL, TEXT("You clicked OK button"), TEXT("Hint"), MB_OK | MB_ICONINFORMATION);
    }
    else {
        MessageBox(NULL, TEXT("You clicked CANCLE button"), TEXT("Hint"), MB_OK | MB_ICONINFORMATION);
    }

    return 0;
}


