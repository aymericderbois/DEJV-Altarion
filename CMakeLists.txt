cmake_minimum_required(VERSION 2.6)

set(MY_PROJECT_NAME "UniversalSupremacy")
project(${MY_PROJECT_NAME} CXX)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
find_package(SFML 2 COMPONENTS system window graphics audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

# Include specific tags on OSX
IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	set(EXTERNAL_LIBS ${SFML_LIBRARIES})
	set(CMAKE_CXX_LINK_FLAGS "-framework OpenGL")
	message("Setting up Xcode for C++11 with libc++.")
 	set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++11")
 	set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
ELSE(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	set(EXTERNAL_LIBS ${SFML_LIBRARIES} "GL")
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")


# DO NOT TOUCH # touched it anyway
IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	set(CMAKE_CXX_FLAGS_RELEASE "-Wall -Wextra -std=c++11 -stdlib=libc++ -pedantic")
	set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -std=c++11 -stdlib=libc++ -pedantic -g")
	set(LINK_FLAGS_RELEASE "-Wall -Wextra -Werror -std=c++11 -stdlib=libc++ -pedantic")
	set(LINK_FLAGS_DEBUG "-Wall -Wextra -Werror -std=c++11 -stdlib=libc++ -pedantic -g")
ELSE(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	set(CMAKE_CXX_FLAGS_RELEASE "-Wall -Wextra -std=c++11 -pedantic")
	set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -std=c++11 -pedantic -g")
	set(LINK_FLAGS_RELEASE "-Wall -Wextra -Werror -std=c++11 -pedantic")
	set(LINK_FLAGS_DEBUG "-Wall -Wextra -Werror -std=c++11 -pedantic -g")
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

# file(GLOB_RECURSE FILES src/*)

file(GLOB_RECURSE ActionEngineFiles
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ActionEngine/*.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ActionEngine/*.hh
)

file(GLOB_RECURSE GameEngineFiles
    ${CMAKE_CURRENT_SOURCE_DIR}/src/GameEngine/*.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/GameEngine/*.hh
)

file(GLOB_RECURSE GraphicEngineFiles
    ${CMAKE_CURRENT_SOURCE_DIR}/src/GraphicEngine/*.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/GraphicEngine/*.hh
)

file(GLOB_RECURSE IHMFiles
    ${CMAKE_CURRENT_SOURCE_DIR}/src/IHM/*.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/IHM/*.hh
)

file(GLOB_RECURSE libsFiles
    ${CMAKE_CURRENT_SOURCE_DIR}/src/libs/*.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/libs/*.hh
)

file(GLOB_RECURSE ToolsFiles
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Tools/*.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Tools/*.hh
)

file(GLOB_RECURSE WorldEngineFiles
    ${CMAKE_CURRENT_SOURCE_DIR}/src/WorldEngine/*.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/WorldEngine/*.hh
)

source_group(ActionEngine FILES ${ActionEngineFiles})
source_group(GraphicEngine FILES ${GraphicEngineFiles})
source_group(GameEngine FILES ${GameEngineFiles})
source_group(IHM FILES ${IHMFiles})
source_group(libs FILES ${libsFiles})
source_group(Tools FILES ${ToolsFiles})
source_group(WorldEngine FILES ${WorldEngineFiles})

add_executable(../${MY_PROJECT_NAME} src/main.cc ${ActionEngineFiles} ${GraphicEngineFiles} ${GameEngineFiles} ${IHMFiles} ${libsFiles} ${ToolsFiles} ${WorldEngineFiles})
target_link_libraries(../${MY_PROJECT_NAME} ${EXTERNAL_LIBS})

