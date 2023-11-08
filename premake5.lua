
newoption
{
    trigger = "graphics",
    value = "OPENGL_VERSION",
    description = "version of OpenGL to build raylib against",
    allowed = {
        { "opengl11", "OpenGL 1.1"},
        { "opengl21", "OpenGL 2.1"},
        { "opengl33", "OpenGL 3.3"},
        { "opengl43", "OpenGL 4.3"}
    },
    default = "opengl33"
}

function string.starts(String,Start)
    return string.sub(String,1,string.len(Start))==Start
end

workspaceName = path.getbasename(os.getcwd())

workspace (workspaceName)
    configurations { "Debug", "Release"}
    platforms { "x64", "x86", "ARM64"}
	
	defaultplatform ("x64")

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

    filter { "platforms:x64" }
        architecture "x86_64"
		
	filter { "platforms:Arm64" }
        architecture "ARM64"

    filter {}

    targetdir "_bin/%{cfg.buildcfg}/"

	startproject(workspaceName)

    cdialect "C99"
    cppdialect "C++17"

include ("raylib_premake5.lua")
include ("src")