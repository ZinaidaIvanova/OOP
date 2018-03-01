set PROGRAM="%~1"

rem Проверка количества переданных аргументов
echo test 1
%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err


rem Проверка корректности переданных аргументов
echo success testing
exit 0

:err
echo program testing failed
exit 1