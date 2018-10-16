/* win32utils.cxx */
/* Windows utilities Tux Paint Config */
/* John Popplewell <john@johnnypops.demon.co.uk> */
/* Adapted for the Cygwin environment, Make K. Kim <mkkim214@gmail.com> */

#include <windows.h>
#include "win32utils.h"
#include <stdio.h>


#ifdef __CYGWIN__
  #include <sys/stat.h>

  void _mkdir(const char* dir)
  {
    mkdir(dir, 0777);
  }
#else
  #include <direct.h>
  #define snprintf      _snprintf
#endif

extern HINSTANCE fl_display;        // hInstance on win32 platform

/*
  Read access to Windows Registry
*/
static HRESULT ReadRegistry(const char *key, const char *option, char *value, int size)
{
  LONG	res;
  HKEY	hKey = NULL;

  res = RegOpenKeyEx(HKEY_CURRENT_USER, key, 0, KEY_READ, &hKey);
  if (res != ERROR_SUCCESS)
    goto err_exit;
  res = RegQueryValueEx(hKey, option, NULL, NULL, (LPBYTE)value, (LPDWORD)&size);
  if (res != ERROR_SUCCESS)
    goto err_exit;
  res = ERROR_SUCCESS;

err_exit:
  if (hKey) RegCloseKey(hKey);
  return HRESULT_FROM_WIN32(res);
}

/*
  Removes a single '\' or '/' from end of path 
*/
static char *remove_slash(char *path)
{
  int len = strlen(path);

  if (!len)
    return path;

  if (path[len-1] == '/' || path[len-1] == '\\')
    path[len-1] = 0;

  return path;
}

/*
  Returns heap string containing default application data path.
  Creates suffix subdirectory (only one level).
  E.g. C:\Documents and Settings\jfp\Application Data\suffix
*/
char *GetDefaultSaveDir(const char *suffix)
{
  char          prefix[MAX_PATH];
  char          path[2*MAX_PATH];
  const char   *key    = "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders";
  const char   *option = "AppData";
  HRESULT hr = S_OK;

  if (SUCCEEDED(hr = ReadRegistry(key, option, prefix, sizeof(prefix))))
  {
    remove_slash(prefix);
    snprintf(path, sizeof(path), "%s/%s", prefix, suffix);
    _mkdir(path);
    return strdup(path);
  }
  return strdup("userdata");
}

/*
  Returns heap string containing the application executable directory path.
*/
char *GetApplicationDir(void)
{
  char  path[2*MAX_PATH];
  char  *p;

  if (GetModuleFileName(fl_display, path, sizeof(path)))
  {
    if ((p = strrchr(path, '\\')) != NULL)
    {
        *p = 0;
        return strdup(path);
    }
  }
  return strdup("");
}

