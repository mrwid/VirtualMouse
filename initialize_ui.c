#include "initialize_ui.h"
#include "constant.h"

//////////////////////////////////////////////////////////////////////////

//初始化主界面
void InitWndUI( HWND hwnd, HINSTANCE hInstance, HWND *hwndBtn, HFONT hFont, LOGFONT lf )
{
	//////////////////////////////////////////////////////////////////////////
	//三个按钮
	hwndBtn[0] = CreateWindow(
		TEXT("button"), TEXT("暂停模拟"),
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
		290, 20, 80, 40,
		hwnd, (HMENU)ID_BTN_PAUSE, hInstance, NULL
	);
	SendMessage( hwndBtn[0], WM_SETFONT, (WPARAM)hFont, 0 );

	hwndBtn[1] = CreateWindow(
		TEXT("button"), TEXT("隐藏窗口"),
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
		290, 100, 80, 40,
		hwnd, (HMENU)ID_BTN_HIDE, hInstance, NULL
	);
	SendMessage( hwndBtn[1], WM_SETFONT, (WPARAM)hFont, 0 );

	hwndBtn[2] = CreateWindow(
		TEXT("button"), TEXT("退出模拟"),
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
		290, 180, 80, 40,
		hwnd, (HMENU)ID_BTN_EXIT, hInstance, NULL
	);
	SendMessage( hwndBtn[2], WM_SETFONT, (WPARAM)hFont, 0 );

	//////////////////////////////////////////////////////////////////////////
	//复选框
	hwndBtn[3] = CreateWindow(
		TEXT("button"), TEXT("开机自动运行"),
		WS_CHILD|WS_VISIBLE|BS_CHECKBOX,
		270, 240, 120, 20,
		hwnd, (HMENU)ID_ID_AUTORUN, hInstance, NULL
	);
	lf.lfWidth = 7;		lf.lfHeight = 16;
	SendMessage( hwndBtn[3], WM_SETFONT, (WPARAM)CreateFontIndirect(&lf), 0 );

	//////////////////////////////////////////////////////////////////////////
	//超链接
	lf.lfWidth			= 6;
	lf.lfHeight			= 12;
	lf.lfUnderline		= 1;
	hwndBtn[4] = CreateWindow(
		TEXT("syslink"), TEXT(""),
		WS_CHILD|WS_VISIBLE|SS_NOTIFY,
		10, 246, 180, 20,
		hwnd, (HMENU)ID_ID_HYPERLINK, hInstance, 0
	);
	SetWindowText( hwndBtn[4], TEXT("<a href=\"\">http://www.cnblogs.com/mr-wid</a>") );
	SendMessage( hwndBtn[4], WM_SETFONT, (WPARAM)CreateFontIndirect(&lf), 0 );
}
