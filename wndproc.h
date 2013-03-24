#pragma once

//////////////////////////////////////////////////////////////////////////

#include <windows.h>
#include <string.h>
#include "constant.h"
	
//////////////////////////////////////////////////////////////////////////

LRESULT CALLBACK WndProc( HWND, UINT, WPARAM, LPARAM );			//主窗口回调事件

void regVirtualMouseHotKey( HWND hwnd );						//注册热键

void dealWithHotKey( HWND, WPARAM );							//处理热键消息

void dealWithBtnMsg( HWND, WPARAM, HWND *hBtn );	//处理按钮消息

void destroyRegedHotKey( HWND );					//撤销注册的热键

void drawTipText( HDC );							//显示提示信息
