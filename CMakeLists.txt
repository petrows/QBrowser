cmake_minimum_required(VERSION 2.8.11)
set(PROJECT qbrowser)

# Project
project(${PROJECT})

# Detect the OS and set proper var
set(OS_MAC 0)
set(OS_WIN 0)
set(OS_LINUX 0)
set(OS_NAME 0)
set(LIBS "")
set(PLATFORM_ID "")

message(STATUS "System name: ${CMAKE_SYSTEM_NAME}")

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	set(OS_MAC 1)
	set(OS_NAME "macos")
	set(LIBS ${LIBS} z)
	set(PLATFORM_ID webview)
endif()

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	set(OS_LINUX 1)
	set(OS_NAME "linux")
	set(LIBS ${LIBS} z)
	set(PLATFORM_ID webkit)
endif()

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	set(OS_WIN 1)
	set(OS_NAME "windows")
	set(PLATFORM_ID webview)
endif()

if(NOT OS_NAME)
	message(FATAL_ERROR "Unknown build target platform!")
endif()

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC OFF)

if ("" STREQUAL "${BROWSER_PLATFORM}")
	set(BROWSER_PLATFORM "${PLATFORM_ID}")
endif()
message(STATUS "Using browser platform: ${BROWSER_PLATFORM}")

option(ENABLE_STATIC "Make static version of library"  ON)
if(ENABLE_STATIC)
  add_definitions(-DLIB_STATIC)
  set(BUILD_SHARED_LIBS OFF)
else()
  set(BUILD_SHARED_LIBS ON)
endif()
OPTION(ENABLE_STATIC_RUNTIME "Visual Studio, link with runtime statically"  ON)

option(VISIBILITY_HIDDEN "Build with -fvisibility=hidden"  OFF)
if(VISIBILITY_HIDDEN)
  add_definitions (-fvisibility=hidden)
endif()

option(BUILD_TESTS "Build the test suite"  OFF)
option(BUILD_EXAMPLES "Build the examples"  OFF)

# Find the QtWidgets library
find_package(Qt5Core)
find_package(Qt5Widgets)
find_package(Qt5Network)
find_package(Qt5Xml)

if ("webkit" STREQUAL ${BROWSER_PLATFORM})
	find_package(Qt5WebKit REQUIRED)
	find_package(Qt5WebKitWidgets REQUIRED)
	set(LIBS ${LIBS} Qt5::WebKit Qt5::WebKitWidgets)
endif()

# Export libs list
set(QBROWSER_LIBS qbrowser ${LIBS})
set(QBROWSER_LIBS ${QBROWSER_LIBS} PARENT_SCOPE)

set(QBROWSER_INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/src/qbrowser")
set(QBROWSER_INCLUDES ${QBROWSER_INCLUDES} PARENT_SCOPE)

set(QBROWSER_PLATFORM ${BROWSER_PLATFORM})
set(QBROWSER_PLATFORM ${QBROWSER_PLATFORM} PARENT_SCOPE)

# Source files
file(GLOB_RECURSE SRC_LIB "src/qbrowser/*")
include_directories("src/qbrowser")
# Platform files
file(GLOB_RECURSE SRC_PLATFORM "src/platform/${BROWSER_PLATFORM}/*")
include_directories("src/platform/${BROWSER_PLATFORM}")
# Test files
file(GLOB_RECURSE SRC_TEST "src/${BROWSER_PLATFORM}/*")

# Res files
FILE (GLOB_RECURSE RESOURCES "res/*.qrc")
qt5_add_resources(RESOURCES_RCC ${RESOURCES})

# UI files
file(GLOB_RECURSE SRCS_UI "src/*.ui")
qt5_wrap_ui(SRCS_UI_MOC ${SRCS_UI})

# Tell CMake to create the helloworld executable
add_library(${PROJECT} ${SRC_LIB} ${SRC_PLATFORM} ${SRCS_UI_MOC} ${SE_SRC} ${ZIP_SRCS} ${RESOURCES_RCC})

# Use the Widgets module from Qt 5.
target_link_libraries(${PROJECT} ${LIBS} Qt5::Core Qt5::Widgets Qt5::Network Qt5::Xml)

#if (${BUILD_TESTS})
	add_subdirectory(test)
#endif()
