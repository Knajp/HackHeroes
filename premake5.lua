workspace "HackHeroes"
    configurations {"Debug", "Release"}
    architecture "x64"

project "ScrollKiller"
    kind "ConsoleApp"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"
    files { "src/**.hpp", "src/**.cpp", "src/**.c" }

   includedirs {
        "vendor/include"
   }
   libdirs {
        "vendor/lib"
   }

   links {
       "glfw3.lib",
       "glfw3_mt.lib",
       "glfw3dll.lib",
       "libcurl_imp.lib"
   }

   defines { "GLM_FORCE_PACKED"}
   buildoptions { "/utf-8" }

   postbuildcommands {
      "{COPY} vendor/bin/curl/libcurl.dll %{cfg.targetdir}"
   }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"

    filter "system:macosx"
        defines { "__APPLE__" }
        links { "Cocoa.framework", "OpenGL.framework", "IOKit.framework", "CoreVideo.framework" }
        cppdialect "C++17"