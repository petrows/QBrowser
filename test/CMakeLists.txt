cmake_minimum_required(VERSION 2.8.11)

message(STATUS "Configure tests")
message(STATUS "QBrowser platform: ${BROWSER_PLATFORM}")
message(STATUS "QBrowser libs: ${QBROWSER_LIBS}")

# Scan for projects
file(GLOB TEST_PROJECTS "src/*")

foreach(TEST_PROJECT_DIR ${TEST_PROJECTS})
	get_filename_component(TEST_PROJECT ${TEST_PROJECT_DIR} NAME)
	message(STATUS "Test project: ${TEST_PROJECT}")

	project(${TEST_PROJECT})

	# Find the QtWidgets library
	find_package(Qt5Core)
	find_package(Qt5Widgets)
	find_package(Qt5Network)
	find_package(Qt5Xml)

	file(GLOB_RECURSE TEST_SRC "src/${TEST_PROJECT}/*.cpp" "src/${TEST_PROJECT}/*.h")

	# Res files
	FILE (GLOB_RECURSE TEST_RES "res/*.qrc")
	qt5_add_resources(TEST_RES_RCC ${RESOURCES})

	# UI files
	file(GLOB_RECURSE TEST_UI "src/*.ui")
	qt5_wrap_ui(TEST_UI_MOC ${TEST_UI})

	include_directories(${QBROWSER_INCLUDES})
	add_executable(${TEST_PROJECT} WIN32 ${TEST_SRC} ${TEST_RES} ${TEST_RES_RCC} ${TEST_UI} ${TEST_UI_MOC})
	target_link_libraries(${TEST_PROJECT} ${QBROWSER_LIBS} Qt5::Core Qt5::Widgets Qt5::Network Qt5::Xml)
endforeach(TEST_PROJECT_DIR)

