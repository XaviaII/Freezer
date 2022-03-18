workspace "Freezer"
	architecture "x64"
	startproject "Testing"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}_%{cfg.system}_%{cfg.architecture}"

-- Include GLFW and GLAD
IncludeDir = {}
IncludeDir["GLFW"] = "Freezer/vendor/GLFW/include"
IncludeDir["GLAD"] = "Freezer/vendor/GLAD/include"

include "Freezer/vendor/GLFW"
include "Freezer/vendor/GLAD"

project "Freezer"
	location "Freezer"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin_int/" .. outputdir .. "/%{prj.name}")

	pchheader "Freezerpch.h"
	pchsource "Freezer/src/Freezerpch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}"
	}

	links {
		"GLFW",
		"GLAD",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines {
			"FREEZER_PLATFORM_WINDOWS",
			"FREEZER_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines {
			"FREEZER_DEBUG",
			"FREEZER_ENABLE_ASSERTS"
		}
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "FREEZER_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "FREEZER_DIST"
		buildoptions "/MD"
		optimize "On"





project "Testing"
	location "Testing"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin_int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Freezer/vendor/spdlog/include",
		"Freezer/src"
	}

	links {
		"Freezer"
	}
	
	postbuildcommands {
		("{COPY} ../bin/%{outputdir}/Freezer/* ../bin/%{outputdir}/%{prj.name}/")
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines {
			"FREEZER_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "FREEZER_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "FREEZER_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "FREEZER_DIST"
		buildoptions "/MD"
		optimize "On"
