#include "wndproc.h"
#include "initialize_ui.h"
#include "constant.h"

//////////////////////////////////////////////////////////////////////////

//主窗口回调函数
LRESULT CALLBACK WndProc( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	static HWND hBtn[4];

	switch( message )
	{
	case WM_CREATE:
		regVirtualMouseHotKey( hwnd );
		InitWndUI( hwnd, ((LPCREATESTRUCT)lParam)->hInstance, hBtn );
		break;

	case WM_COMMAND:
		dealWithBtnMsg( hwnd, wParam );
		break;

	case WM_HOTKEY:
		dealWithHotKey( hwnd, wParam );
		break;

	case WM_DESTROY:
		PostQuitMessage( 0 );
		return 0;
	}

	return DefWindowProc( hwnd, message, wParam, lParam );
}

//////////////////////////////////////////////////////////////////////////

//注册热键
void regVirtualMouseHotKey( HWND hwnd )
{
	RegisterHotKey( hwnd, ID_HOT_UP,	MOD_CONTROL, VK_NUMPAD8 );			//Ctrl + 8, 上
	RegisterHotKey( hwnd, ID_HOT_DOWN,	MOD_CONTROL, VK_NUMPAD2 );			//Ctrl + 2, 下
	RegisterHotKey( hwnd, ID_HOT_LEFT,	MOD_CONTROL, VK_NUMPAD4 );			//Ctrl + 4, 左
	RegisterHotKey( hwnd, ID_HOT_RIGHT, MOD_CONTROL, VK_NUMPAD6 );			//Ctrl + 6, 右

	RegisterHotKey( hwnd, ID_HOT_SL_UP,		MOD_CONTROL, VK_UP );			//Ctrl + UP,	微调, 上
	RegisterHotKey( hwnd, ID_HOT_SL_DOWN,	MOD_CONTROL, VK_DOWN );			//Ctrl + DOWN,	微调, 下
	RegisterHotKey( hwnd, ID_HOT_SL_LEFT,	MOD_CONTROL, VK_LEFT );			//Ctrl + LEFT,	微调, 左
	RegisterHotKey( hwnd, ID_HOT_SL_RIGHT,	MOD_CONTROL, VK_RIGHT );		//Ctrl + RIGHT,	微调, 右

	RegisterHotKey( hwnd, ID_HOT_TOPLEFT,	MOD_CONTROL, VK_NUMPAD7 );		//注册 Ctrl + 7, 左上
	RegisterHotKey( hwnd, ID_HOT_TOPRIGHT,	MOD_CONTROL, VK_NUMPAD9 );		//注册 Ctrl + 9, 右上
	RegisterHotKey( hwnd, ID_HOT_BOTLEFT,	MOD_CONTROL, VK_NUMPAD1 );		//注册 Ctrl + 1, 左下
	RegisterHotKey( hwnd, ID_HOT_BOTRIGHT,	MOD_CONTROL, VK_NUMPAD3 );		//注册 Ctrl + 3, 右下

	RegisterHotKey( hwnd, ID_HOT_LEFT_CLICK,	MOD_CONTROL, VK_NUMPAD5 );		//注册 Ctrl + 5, 左键击键
	RegisterHotKey( hwnd, ID_HOT_RIGHT_CLICK,	MOD_CONTROL, VK_RETURN );		//注册 Ctrl + Enter, 右键击键

	RegisterHotKey( hwnd, ID_HOT_MIDDLE_UP,		MOD_CONTROL, VK_SUBTRACT );		//注册 Ctrl + UP, 滚轮向上
	RegisterHotKey( hwnd, ID_HOT_MIDDLE_DOWN,	MOD_CONTROL, VK_ADD );			//注册 Ctrl + UP, 滚轮向下
	RegisterHotKey( hwnd, ID_HOT_MIDDLE_PRESS,	MOD_CONTROL, VK_DECIMAL );		//注册 Ctrl + . , 中键按下

	RegisterHotKey( hwnd, ID_HOT_WND_HIDE,		MOD_CONTROL, VK_F12 );			//注册 Ctrl + 12 , 显示窗口
}


//////////////////////////////////////////////////////////////////////////

//处理热键消息
void dealWithHotKey( HWND hwnd, WPARAM wParam )
{
	POINT ptCorPos;
	GetCursorPos( &ptCorPos );

	switch( wParam )
	{
	case ID_HOT_UP:			ptCorPos.y -= 40;	break;			//移动, 上	
	case ID_HOT_DOWN:		ptCorPos.y += 40;	break;			//移动, 下
	case ID_HOT_LEFT:		ptCorPos.x -= 40;	break;			//移动, 左
	case ID_HOT_RIGHT:		ptCorPos.x += 40;	break;			//移动, 右
	case ID_HOT_SL_UP:		ptCorPos.y -= 10;	break;			//微调, 上
	case ID_HOT_SL_DOWN:	ptCorPos.y += 10;	break;			//微调, 下
	case ID_HOT_SL_LEFT:	ptCorPos.x -= 10;	break;			//微调, 左
	case ID_HOT_SL_RIGHT:	ptCorPos.x += 10;	break;			//微调, 右
		
	case ID_HOT_TOPLEFT:		//移动, 左上
		ptCorPos.x -= 40;	ptCorPos.y -= 40;	break;

	case ID_HOT_TOPRIGHT:		//移动, 右上
		ptCorPos.x += 40;	ptCorPos.y -= 40;	break;

	case ID_HOT_BOTLEFT:		//移动, 左下
		ptCorPos.x -= 40;	ptCorPos.y += 40;	break;

	case ID_HOT_BOTRIGHT:		//移动, 右下
		ptCorPos.x += 40;	ptCorPos.y += 40;	break;

	case ID_HOT_LEFT_CLICK:		//左击
		mouse_event( MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0 );
		mouse_event( MOUSEEVENTF_LEFTUP, 0, 0, 0, 0 );
		break;

	case ID_HOT_RIGHT_CLICK:	//右击
		mouse_event( MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0 );
		mouse_event( MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0 );
		break;

	case ID_HOT_MIDDLE_UP:		//滚轮向上
		mouse_event( MOUSEEVENTF_WHEEL, 0, 0, (DWORD)50, 0 );	break;

	case ID_HOT_MIDDLE_DOWN:	//滚轮向下
		mouse_event( MOUSEEVENTF_WHEEL, 0, 0, (DWORD)-50, 0 );	break;

	case ID_HOT_MIDDLE_PRESS:	//中键击键
		mouse_event( MOUSEEVENTF_MIDDLEDOWN, 0, 0, 0, 0 );
		mouse_event( MOUSEEVENTF_MIDDLEUP, 0, 0, 0, 0 );

	case ID_HOT_WND_HIDE:
		ShowWindow( hwnd, SW_SHOWNORMAL );
		SetForegroundWindow(hwnd);	break;
	}
	SetCursorPos( ptCorPos.x, ptCorPos.y );
}

//////////////////////////////////////////////////////////////////////////

//处理按钮消息
void dealWithBtnMsg( HWND hwnd,  WPARAM wParam )
{
	switch( LOWORD(wParam) )
	{
	case ID_BTN_HIDE:
		ShowWindow( hwnd, SW_MINIMIZE );		//先最小化
		ShowWindow( hwnd, SW_HIDE );			//再隐藏
		break;
	}
}