cd %CODEBUILD_SRC_DIR%

pwsh scripts/build/build_node/Platform/Windows/install_vsbuildtools.ps1
pwsh scripts/build/build_node/Platform/Windows/install_utiltools.ps1
set "PATH=%PATH%;C:\Program Files\CMake\bin;C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\MSBuild\Current\Bin"
call python/get_python.bat
call python/python.cmd -u scripts\build\ci_build.py --platform Windows --type profile_vs2019
type ".\build\windows_vs2019\CMakeFiles\CMakeOutput.log"