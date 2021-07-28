cd %CODEBUILD_SRC_DIR%
set "PATH=%PATH%;C:\Program Files\CMake\bin"
call python/get_python.bat
call python/python.cmd -u scripts\build\ci_build.py --platform Windows --type profile_vs2019