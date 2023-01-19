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


using namespace std;

// tray icon data
NOTIFYICONDATA m_NID;

BOOL CreateTrayIcon()
{
    memset(&m_NID, 0, sizeof(m_NID));
    m_NID.cbSize = sizeof(m_NID);

    m_NID.uID = IDI_USER_IMAGE;

    // set handle to the window that receives tray icon notifications
    m_NID.hWnd = GetForegroundWindow();

    // fields that are being set when adding tray icon
    m_NID.uFlags = NIF_MESSAGE | NIF_ICON;

    // set image
    m_NID.hIcon = LoadIcon(NULL,MAKEINTRESOURCE(IDI_USER_IMAGE));

    if (!m_NID.hIcon)
        return FALSE;

    m_NID.uVersion = NOTIFYICON_VERSION_4;

    if (!Shell_NotifyIcon(NIM_ADD, &m_NID))
        return FALSE;

    return Shell_NotifyIcon(NIM_SETVERSION, &m_NID);
}

BOOL ShowTrayIconBalloon(LPCTSTR pszTitle, LPCTSTR pszText, UINT unTimeout, DWORD dwInfoFlags)
{
    m_NID.uFlags |= NIF_INFO;
    m_NID.uFlags |= NIF_ICON;
    //m_NID.uFlags |= NIF_ICON | NIF_TIP | NIF_GUID | NIF_MESSAGE;
    m_NID.uTimeout = unTimeout;
    m_NID.dwInfoFlags = dwInfoFlags;

    if (StringCchCopy(m_NID.szInfoTitle, sizeof(m_NID.szInfoTitle), pszTitle) != S_OK)
        return FALSE;

    if (StringCchCopy(m_NID.szInfo, sizeof(m_NID.szInfo), pszText) != S_OK)
        return FALSE;

    return Shell_NotifyIcon(NIM_MODIFY, &m_NID);
}

notif(){
    CreateTrayIcon();
    ShowTrayIconBalloon("Keyce drive", "Nouvelle cle detecte", 10000, NULL);
}
