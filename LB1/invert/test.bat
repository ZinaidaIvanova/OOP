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

echo success testing
exit 0

:err
echo program testing failed
exit 1