# Windows-API-Trace
These scripts enable a user to trace the Windows API calls of any Portable
Executable file.

## Dependencies
Install WinDBG (included with Windows Driver Kit): https://developer.microsoft.com/en-us/windows/hardware/windows-driver-kit

Install VisualStudio (to compile test.cpp)

## Citations and Credit
https://www.codeproject.com/articles/6084/windows-debuggers-part-1-a-windbg-tutorial#\_Toc64133680
https://blogs.msdn.microsoft.com/debuggingtoolbox/2007/04/13/windbg-script-tracing-api-calls/

The script.txt file is taken directly from Roberto Alexis Farah's blog http://blogs.msdn.com/debuggingtoolbox/
I simply modified one line. All credit should be given to him.

## Running
Open VisualStudio Developer Console and run:
```
> cl test.cpp
```

Change trace.bat to match where windbg.exe is stored on your computer.

You'll see an example of where it was stored on mine (C:\Program Files\Windows Kits\8.1\Debuggers\x86).

Open a Command Prompt and run:
```
> trace.bat path\to\test.exe
```

## Output
On your Desktop you'll see a new folder "LogExts".

In this folder you'll see two files ending in *.lgv and *.txt

The LGV file can be opened with the logviewer application (in the same directory
as windbg.exe). This is a detailed view of the program's API sequence.

The TXT file can be opened with notepad or any text editor. This version of
API sequence is not as detailed as the LGV file, but hopefully provides enough
detail so you can parse it with a simple script and extract whatever data you
need.

## Benefits
What's nice about this is that the batch file (trace.bat) will automatically
download the most up-to-date symbols from Microsoft so you don't have to.
It does all the work so you can do all the playing :)
