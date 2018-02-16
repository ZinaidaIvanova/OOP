set PROGRAM="%~1"

%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

%PROGRAM% 

:err
echo program testing failed
exit 1

:success
echo success testing
exit 0