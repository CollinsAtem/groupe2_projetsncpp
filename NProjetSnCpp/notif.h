


using namespace std;

#ifndef NOTIF_H_INCLUDED
#define NOTIF_H_INCLUDED

#include <iostream>
#include <filesystem>
#include <string>


#include <tchar.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <strsafe.h>
#include "resource.h"
#define UNICODE
#include <windows.h>

void notif();
BOOL ShowTrayIconBalloon(LPCTSTR pszTitle, LPCTSTR pszText, UINT unTimeout, DWORD dwInfoFlags);
BOOL CreateTrayIcon();

#endif // NOTIF_H_INCLUDED
