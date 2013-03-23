#include "initialize_ui.h"
#include "constant.h"

//////////////////////////////////////////////////////////////////////////

void InitWndUI( HWND hwnd, HINSTANCE hInstance, HWND *hwndBtn )
{
	hwndBtn[0] = CreateWindow(
		TEXT("button"), TEXT("ÔÝÍ£Ä£Äâ"),
		WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,
		290, 20, 80, 40, hwnd, (HMENU)ID_BTN_PAUSE, hInstance, NULL
	);

	hwndBtn[1] = CreateWindow(
		TEXT("button"), TEXT("Òþ²Ø´°¿Ú"),
		WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,
		290, 100, 80, 40, hwnd, (HMENU)ID_BTN_HIDE, hInstance, NULL
	);

	hwndBtn[2] = CreateWindow(
		TEXT("button"), TEXT("ÍË³öÄ£Äâ"),
		WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,
		290, 180, 80, 40, hwnd, (HMENU)ID_BTN_EXIT, hInstance, NULL
	);
}
