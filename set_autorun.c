#include "set_autorun.h"

//////////////////////////////////////////////////////////////////////////

//响应开机自启动设置
int VirtualMouseAutorun( HWND hwndChk )
{
	int iChk = (int)SendMessage( hwndChk, BM_GETCHECK, 0, 0 );
	if( iChk == 0 )
	{
		setVMAutorun();
		SendMessage( hwndChk, BM_SETCHECK, 1, 0 );
	}
	else
	{
		delVMAutorun();
		SendMessage( hwndChk, BM_SETCHECK, 0, 0 );
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////

//设置开机自启动
int setVMAutorun()
{
	HKEY hKey;     
	long lRet = RegOpenKeyEx( HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_WRITE, &hKey );
	if(lRet == ERROR_SUCCESS) 
	{
		wchar_t pFilePath[MAX_PATH] = {0};
		DWORD dwRet = GetModuleFileName(NULL, (char*)pFilePath, MAX_PATH);
		lRet = RegSetValueEx( hKey, "VirtualMouse", 0, REG_SZ, (BYTE *)pFilePath, dwRet*2 );
		RegCloseKey(hKey);
	}
	if( lRet == ERROR_SUCCESS )
		return 1;
	return 0;
}

//////////////////////////////////////////////////////////////////////////

//取消开机自启动
int delVMAutorun()
{
    HKEY hKey;     
    long lRet = RegOpenKeyEx( HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_WRITE, &hKey );
    if( lRet == ERROR_SUCCESS )
    {
        lRet = RegDeleteValue( hKey, "VirtualMouse" );
        RegCloseKey(hKey);
    }
	if( lRet == ERROR_SUCCESS )
		return 1;
	return 0;
}

//////////////////////////////////////////////////////////////////////////

//检查是否已经开机自动运行
int checkAutorun()
{
    HKEY hKey;
    DWORD dwtype, sizeBuff;
    long lRet;
    char reBuff[MAX_PATH]	 = {0};
	char pFilePath[MAX_PATH] = {0};
	
    lRet= RegOpenKeyEx( HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_READ, &hKey );
    if( lRet == ERROR_SUCCESS ) 
    {
        sizeBuff = sizeof(reBuff);

        //读取键值
        if( RegQueryValueEx( hKey, "VirtualMouse", 0, &dwtype, (BYTE*)reBuff, &sizeBuff ) == ERROR_SUCCESS )
		{
			GetModuleFileName( NULL, (char*)pFilePath, MAX_PATH );
			if( strcmp( pFilePath, reBuff ) == 0 )
			{
				RegCloseKey(hKey);
				return 1;
			}
		}
        RegCloseKey(hKey);
    }
	return 0;
}
