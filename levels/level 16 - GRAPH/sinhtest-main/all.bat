@REM Tran Huu Nam - huunam0@gmail.com - 2/2022
del *.zip
call dich_sinh.bat
call input.bat 
@REM call dich_solution.bat 
@REM call output.bat
@REM 7z a tests.zip test*.???
7z a inputonly.zip test*.inp
call xoa.bat