cd %CODEBUILD_SRC_DIR%
set "PATH=%PATH%;C:\Program Files\CMake\bin"
python/get_python.bat
python/python.cmd -u scripts\build\ci_build.py --platform Windows --type profile_vs2019