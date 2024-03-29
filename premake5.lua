workspace "Paradigm"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release", 
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Paradigm"
	location "Paradigm"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
		"PD_PLATFORM_WINDOWS",
		"PD_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
	
	filter "configurations:Debug"
		defines "PD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PD_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PD_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Paradigm/vendor/spdlog/include",
		"Paradigm/src"
	}

	links
	{
		"Paradigm"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
		"PD_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "PD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PD_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PD_DIST"
		optimize "On"