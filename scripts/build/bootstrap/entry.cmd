cd %CODEBUILD_SRC_DIR%

powershell.exe scripts/build/build_node/Platform/Windows/install_vsbuildtools.ps1
choco install cmake -y --installargs 'ADD_CMAKE_TO_PATH=System'

set "PATH=%PATH%;C:\Program Files\CMake\bin;C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\MSBuild\Current\Bin"
call python/get_python.bat
call python/python.cmd -u scripts\build\ci_build.py --platform Windows --type profile_vs2019