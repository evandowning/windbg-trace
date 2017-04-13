# WinDBG-Trace
These scripts enable a user to trace the Windows API calls of any Portable
Executable file.

## Dependencies
Install Windows 7 (in particular I installed Windows 7 Enterprise Service Pack 1)

Install WinDBG (included with Windows Driver Kit 8.1): https://developer.microsoft.com/en-us/windows/hardware/windows-driver-kit

Install VisualStudio 2013 (to compile tests)

## Citations and Credit
https://www.codeproject.com/articles/6084/windows-debuggers-part-1-a-windbg-tutorial#\_Toc64133680
https://blogs.msdn.microsoft.com/debuggingtoolbox/2007/04/13/windbg-script-tracing-api-calls/

The script.txt file is taken directly from Roberto Alexis Farah's blog http://blogs.msdn.com/debuggingtoolbox/
I simply modified one line. All credit should be given to him.


## Running
Open a Command Prompt and run:
```
PROMPT> trace.bat path\to\test.exe
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

## Running Tests
Open VisualStudio Developer Console and run:
```
PROMPT> cd tests
PROMPT> cl simple.cpp
PROMPT> cl multithread.cpp
PROMPT> cl multiprocess.cpp
PROMPT> cd ..

PROMPT> trace.bat tests\simple.exe
PROMPT> trace.bat tests\multithread.exe
PROMPT> trace.bat "tests\multiprocess.exe C:\Windows\notepad.exe"
```

## Benefits
What's nice about this is that the batch file (trace.bat) will automatically
download the most up-to-date symbols from Microsoft so you don't have to.
It does all the work so you can do all the playing :)

## Limitations
It cannot automatically log child processes activities.
