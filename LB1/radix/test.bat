set PROGRAM="%~1"

rem �������� ���������� ���������� ����������
echo test 1
%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err


rem �������� ������������ ���������� ����������
echo success testing
exit 0

:err
echo program testing failed
exit 1