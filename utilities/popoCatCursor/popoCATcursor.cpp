#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <windef.h>
#include <synchapi.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

int main(int argc, char** argv) {
    // I
    HCURSOR cursor_general1 = (HCURSOR)LoadImage(NULL, L"./popo2.cur", IMAGE_CURSOR, 36, 47, LR_LOADFROMFILE);
    SetSystemCursor(cursor_general1, 32513);
    
    // wait circle
    HCURSOR cursor_general2 = (HCURSOR)LoadImage(NULL, L"./popo2.cur", IMAGE_CURSOR, 36, 47, LR_LOADFROMFILE);
    SetSystemCursor(cursor_general2, 32514);
    
    // hand
    HCURSOR cursor_general3 = (HCURSOR)LoadImage(NULL, L"./popo2.cur", IMAGE_CURSOR, 36, 47, LR_LOADFROMFILE);
    SetSystemCursor(cursor_general3, 32649);
    
    // arrow with wait circle
    HCURSOR cursor_general4 = (HCURSOR)LoadImage(NULL, L"./popo2.cur", IMAGE_CURSOR, 36, 47, LR_LOADFROMFILE);
    SetSystemCursor(cursor_general4, 32650);

    while (1) {
        if (!KEY_DOWN(VK_LBUTTON)) {
            HCURSOR cursor_normal = (HCURSOR)LoadImage(NULL, L"./popo1.cur", IMAGE_CURSOR, 36, 47, LR_LOADFROMFILE);
            SetSystemCursor(cursor_normal, 32512);
        }
        else {
            HCURSOR cursor_click = (HCURSOR)LoadImage(NULL, L"./popo2.cur", IMAGE_CURSOR, 36, 47, LR_LOADFROMFILE);
            SetSystemCursor(cursor_click, 32512);
        }
        Sleep(100);
    }
    return 0;
}
