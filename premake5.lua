workspace "Freezer"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}




outputdir = "%{cfg.buildcfg}_%{cfg.system}_%{cfg.architecture}"

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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines {
			"FREEZER_PLATFORM_WINDOWS",
			"FREEZER_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Testing")
		}

	filter "configurations:Debug"
		defines "FREEZER_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FREEZER_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FREEZER_DIST"
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

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines {
			"FREEZER_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "FREEZER_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FREEZER_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FREEZER_DIST"
		optimize "On"
