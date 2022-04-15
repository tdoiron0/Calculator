workspace "v0.4"
	architecture "x86"

	configurations {
		"Debug", 
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "EquationNinja/vendor/pugiXML"

project "EquationNinja"
	location "EquationNinja"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"EquationNinja/src", 
		"EquationNinja/vendor/spdlog/include", 
		"EquationNinja/vendor/pugiXML/include"
	}

	libdirs {
		"lib"
	}

	links {
		"pugixml"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines {
			"EN_PLATFORM_WINDOWS", 
			"EN_BUILD_DLL", 
			"_WINDLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "EN_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "EN_RELEASE"
		symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"EquationNinja/src", 
		"EquationNinja/vendor/spdlog/include", 
		"EquationNinja/vendor/pugiXML/include"
	}

	links {
		"EquationNinja"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines {
			"EN_PLATFORM_WINDOWS", 
			"_WINDLL"
		}

	filter "configurations:Debug"
		defines "EN_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "EN_RELEASE"
		symbols "On"