del *.zip
call dich_sinh.bat
call input.bat 
call dich_solution.bat 
call output.bat
7z a tests.zip test*.???
7z a inputonly.zip test*.inp
@REM call xoa.bat