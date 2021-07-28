cd %CODEBUILD_SRC_DIR%
set LY_CMAKE_PATH="C:\Program Files\CMake\bin"
python/get_python.bat
set PATH="%PATH%;C:\Program Files\CMake\bin"
python/python.cmd -u scripts\build\ci_build.py --platform Windows --type profile_vs2019