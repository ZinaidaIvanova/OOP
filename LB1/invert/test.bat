set PROGRAM="%~1"

echo test 1
%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

echo test 2
%PROGRAM% not-exist-file.txt > nul
if NOT ERRORLEVEL 1 goto err

echo test 3
%PROGRAM% test-data\empty_file.txt > nul
if NOT ERRORLEVEL 1 goto err

echo test 4
%PROGRAM% test-data\nondegenerate_matrix.txt > "%TEMP%\result.txt"
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\result.txt" test-data\nondegenerate_matrix_result.txt > nul
if ERRORLEVEL 1 goto err

echo test 5
%PROGRAM% test-data\degenerate_matrix.txt > "%TEMP%\result.txt"
if NOT ERRORLEVEL 1 goto err
fc.exe "%TEMP%\result.txt" test-data\degenerate_matrix_result.txt > nul
if ERRORLEVEL 1 goto err

echo success testing
exit 0

:err
echo program testing failed
exit 1