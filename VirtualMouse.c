#include <windows.h>

#include "wndproc.h"
#include "resource.h"

//////////////////////////////////////////////////////////////////////////

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow )
{
	static char szAppName[] = "VirtualMouse";

	HWND		hwnd;
	MSG			msg;
	WNDCLASS	wndclass;

	wndclass.style			= CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc	= WndProc;
	wndclass.hInstance		= hInstance;
	wndclass.hCursor		= LoadCursor( NULL, IDC_ARROW );
	wndclass.hIcon			= LoadIcon( hInstance, MAKEINTRESOURCE(IDI_ICON_LEFT) );
	wndclass.cbClsExtra		= 0;
	wndclass.cbWndExtra		= 0;
	wndclass.hbrBackground	= CreateSolidBrush( RGB(236, 233, 216) );
	wndclass.lpszClassName	= szAppName;
	wndclass.lpszMenuName	= NULL;

	if( !RegisterClass( &wndclass ) )
	{
		MessageBox( NULL, TEXT("¥∞ø⁄¿‡◊¢≤· ß∞‹!"), TEXT("¥ÌŒÛ"), MB_OK | MB_ICONERROR );
		return 0;
	}

	hwnd = CreateWindow(
		szAppName, TEXT("–Èƒ‚ Û±Í"),
		WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX,
		CW_USEDEFAULT, CW_USEDEFAULT,
		400, 300,
		NULL, NULL, hInstance, NULL
	);

	ShowWindow( hwnd, iCmdShow );
	UpdateWindow( hwnd );

	while( GetMessage( &msg, NULL, 0, 0 ) )
	{
		TranslateMessage( &msg );
		DispatchMessage( &msg );
	}

	return msg.wParam;
}
