@ECHO OFF

:: From http://stackoverflow.com/questions/1291941/batch-files-number-of-command-line-arguments#1292094
:: Get number of arguments
set argC=0
for %%x in (%*) do Set /A argC+=1

::echo %argC%
::echo %1

:: Check if appropriate number of arguments
if not %argC%==1 (
    echo usage: trace.bat target.exe
    goto:eof
)

start "" "C:\Program Files\Windows Kits\8.1\Debuggers\x86\windbg.exe" -y "SRV*downstream_store*http://msdl.microsoft.com/download/symbols" -c "$$><script.txt;g;q" %1
