cmake_minimum_required(VERSION 4.0)

set(PROJECT_NAME FightClubGame)
project(${PROJECT_NAME} VERSION 1.0.0)

#common option
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
message("Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

#cpp option

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /FA")

#app options
set(SOURCES
        Sources/main.cpp
        Sources/Game/Character.cpp
        Sources/Game/Weapon.cpp
        Sources/Utils/math.cpp
    )

set(INCLUDES
        Sources/Game/Character.h
        Sources/Game/Weapon.h
        Sources/Utils/math.h
    )

#Utils
source_group("Source Files/Utils" FILES "Sources/Utils/math.cpp")
source_group("Header Files/Utils" FILES "Sources/Utils/math.h")
#Game
source_group("Source Files/Game"  FILES "Sources/Game/Character.cpp" "Sources/Game/Weapon.cpp")
source_group("Header Files/Game"  FILES "Sources/Game/Character.h" "Sources/Game/Weapon.h")

add_executable(${PROJECT_NAME} ${SOURCES} ${INCLUDES})


message("Using ${CMAKE_CXX_COMPILER_ID} compiler")
message("System ${CMAKE_HOST_SYSTEM_NAME}")

if(WIN32)
    message("Running on Windows")
elseif(LINUX)
    message("Running on Linux")
endif()

if(MSVC)
    message("MSVC version: ${MSVC_VERSION}")
    message("MSVC toolset: ${MSVC_TOOLSET_VERSION}")
    target_compile_options(${PROJECT_NAME} PUBLIC $<$<CONFIG:MinSizeRel>: /FA>)
endif()

#includes
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/Sources)

message("Hello world ${PROJECT_NAME}")
message("Compiler flags: " ${CMAKE_CXX_FLAGS})
message("Compiler flags for Release: " ${CMAKE_CXX_FLAGS_RELEASE})
message("Compiler flags for Debug: " ${CMAKE_CXX_FLAGS_DEBUG})
message("Configuration type: ${CMAKE_CONFIGURATION_TYPES}")

