cmake_minimum_required(VERSION 2.6)

project(${MY_PROJECT_NAME} CXX)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
find_package(SFML 2 COMPONENTS system window graphics audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

# Include specific tags on OSX
IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	set(EXTERNAL_LIBS ${SFML_LIBRARIES})
	set(CMAKE_CXX_LINK_FLAGS "-framework OpenGL")
ELSE(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	set(EXTERNAL_LIBS ${SFML_LIBRARIES} "GL")
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

set(MY_PROJECT_NAME "UniversalSupremacy")

# DO NOT TOUCH 
set(CMAKE_CXX_FLAGS_RELEASE "-Wall -Wextra -std=c++11 -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -std=c++11 -pedantic -g")
set(LINK_FLAGS_RELEASE "-Wall -Wextra -Werror -std=c++11 -pedantic")
set(LINK_FLAGS_DEBUG "-Wall -Wextra -Werror -std=c++11 -pedantic -g")

file(GLOB_RECURSE FILES src/*)

add_executable(../${MY_PROJECT_NAME} ${FILES})
target_link_libraries(../${MY_PROJECT_NAME} ${EXTERNAL_LIBS})
