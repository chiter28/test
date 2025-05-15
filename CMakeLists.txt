cmake_minimum_required(VERSION 3.30)

set(PROJECT_NAME FightClubGame)
project(${PROJECT_NAME} VERSION 1.0.0)

#common option
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

#cpp option

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /FA")

#sources
set(MATH_SOURCES Sources/Utils/math.cpp)
set(MATH_INCLUDES Sources/Utils/math.h)

set(DLL_GAME_SOURCES
        Sources/Game/Character.cpp
        Sources/Game/Weapon.cpp)

set(DLL_GAME_INCLUDES 
        Sources/Game/Character.h
        Sources/Game/Weapon.h)

#Game
source_group("Source Files/Game"  FILES "Sources/Game/Character.cpp" "Sources/Game/Weapon.cpp")
source_group("Header Files/Game"  FILES "Sources/Game/Character.h" "Sources/Game/Weapon.h")


#targets
add_executable(${PROJECT_NAME} Sources/main.cpp)
add_library(MathLib STATIC ${MATH_SOURCES} ${MATH_INCLUDES})
add_library(${PROJECT_NAME}Lib SHARED ${DLL_GAME_SOURCES} ${DLL_GAME_INCLUDES})

add_executable(${PROJECT_NAME}TestRunner Sources/Tests/main.cpp)

#defines
target_compile_definitions(${PROJECT_NAME}Lib PRIVATE EXPORT)
target_compile_definitions(${PROJECT_NAME} PRIVATE IMPORT)

#link
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}Lib)
target_link_libraries(${PROJECT_NAME}Lib PRIVATE MathLib)

target_link_libraries(${PROJECT_NAME}TestRunner PRIVATE MathLib)
target_link_libraries(${PROJECT_NAME}TestRunner PRIVATE ${PROJECT_NAME}Lib)


option(SKIP_GAME_OPT "Skip Game" OFF)
if(SKIP_GAME_OPT)
    target_compile_definitions(${PROJECT_NAME} PUBLIC SKIP_GAME)
endif()


#include dirs
set(TARGETS
        ${PROJECT_NAME}
        ${PROJECT_NAME}TestRunner
        ${PROJECT_NAME}Lib)

foreach(target IN LISTS TARGETS)
    target_include_directories(${target} PUBLIC ${CMAKE_SOURCE_DIR}/Sources)
endforeach()

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


message("Hello world ${PROJECT_NAME}")
message("Compiler flags: " ${CMAKE_CXX_FLAGS})
message("Compiler flags for Release: " ${CMAKE_CXX_FLAGS_RELEASE})
message("Compiler flags for Debug: " ${CMAKE_CXX_FLAGS_DEBUG})
message("Configuration type: ${CMAKE_CONFIGURATION_TYPES}")
