#include <windows.h>
#include <tchar.h>
#include <stdio.h>

int main(void)
{
    CreateFile(_T("C:\\File.txt"), FILE_READ_DATA, FILE_SHARE_READ, NULL, OPEN_ALWAYS, 0, NULL);

    return 0;
}
