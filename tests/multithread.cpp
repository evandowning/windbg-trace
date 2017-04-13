#include <windows.h>
#include <iostream>
using namespace std;

// From http://www.bogotobogo.com/cplusplus/multithreading_win32A.php

DWORD WINAPI myThread(LPVOID lpParameter)
{
    unsigned int& myCounter = *((unsigned int*)lpParameter);
    while(myCounter < 0xa)
    {
        ++myCounter;
        Sleep(1000*1);
    }
    return 0;
}

int main(int argc, char* argv[])
{
    unsigned int myCounter = 0;
    DWORD myThreadID;
    HANDLE myHandle = CreateThread(0, 0, myThread, &myCounter, 0, &myThreadID);
    for (int i = 0; i < 10; i++)
    {
        cout << "Thread: " << &myThreadID << "    Count: " << myCounter << endl;
        Sleep(1000*1);
    }

    CloseHandle(myHandle);
    return 0;
}
