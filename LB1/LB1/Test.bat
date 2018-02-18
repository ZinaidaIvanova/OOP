set PROGRAM="%~1"

echo test 1
%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

echo test 2
%PROGRAM% test-data\text.txt "search string"
if ERRORLEVEL 1 goto err 

echo test 3
%PROGRAM% not-exist-file.txt "search string" > nul
if NOT ERRORLEVEL 1 goto err

echo test 4
%PROGRAM% test-data\example.txt "cat" > nul
if NOT ERRORLEVEL 1 goto err

echo success testing
exit 0

:err
echo program testing failed
exit 1