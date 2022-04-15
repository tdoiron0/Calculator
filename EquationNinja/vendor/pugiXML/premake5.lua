project "pugixml" 
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"include/pugiconfig.hpp", 
		"include/pugixml.cpp", 
		"include/pugixml.hpp"
	}

	filter "system:windows"
		staticruntime "On"
		systemversion "10.0.19041.0"

	configuration "Debug"
		defines { "_DEBUG" }

	configuration "Release"
		defines { "NDEBUG" }