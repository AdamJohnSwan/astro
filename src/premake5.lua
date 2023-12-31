project (workspaceName)
  	kind "ConsoleApp"
    location "../_build"
    targetdir "../_bin/%{cfg.buildcfg}"
	
    filter "configurations:Release"
		kind "WindowedApp"
		entrypoint "mainCRTStartup"

	filter "action:vs*"
        debugdir "$(SolutionDir)"
		
	filter {"action:vs*", "configurations:Release"}
			kind "WindowedApp"
			entrypoint "mainCRTStartup"
	filter {}
	
	files {"**.c", "**.cpp", "**.h", "**.hpp", "**.ixx"}

    includedirs { "./" }
    includedirs { "src" }
    includedirs { "include" }
	includedirs {"../deps/di" }
	
	link_raylib()
	
	-- To link to a lib use link_to("LIB_FOLDER_NAME")