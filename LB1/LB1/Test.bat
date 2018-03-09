set PROGRAM="%~1"

echo test 1
%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

echo test 2
%PROGRAM% not-exist-file.txt "search string" > nul
if NOT ERRORLEVEL 1 goto err

echo test 3
%PROGRAM% test-data\example.txt "cat" > nul
if NOT ERRORLEVEL 1 goto err

echo test 4
%PROGRAM% test-data\example.txt "dog" > nul
if ERRORLEVEL 1 goto err

echo test 5
%PROGRAM% test-data\example.txt "dog" > "%TEMP%\result.txt"
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\result.txt" test-data\resultText5.txt > nul
if ERRORLEVEL 1 goto err

echo test 6
%PROGRAM% test-data\example.txt "Dog" > "%TEMP%\result.txt"
if NOT ERRORLEVEL 1 goto err
fc.exe "%TEMP%\result.txt" test-data\resultText6.txt > nul
if ERRORLEVEL 1 goto err

echo success testing
exit 0

:err
echo program testing failed
exit 1