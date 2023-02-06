workspace "Mango"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Distribution"
    }

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Mango"
    location "Mango"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputDir .. "/%{prj.name}")
    objdir ("bin-intermediate/" .. outputDir .. "/%{prj.name}")

    files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Mango/src",
		"Mango/src/Mango",
		"Mango/src/vendor"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		-- add windows specific stuff here

	filter "configurations:Debug"
		defines "MANGO_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MANGO_RELEASE"
		optimize "On"

	filter "configurations:Distribution"
		defines "MANGO_DIST"
		optimize "On"

