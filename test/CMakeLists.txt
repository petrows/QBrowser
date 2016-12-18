cmake_minimum_required(VERSION 2.8.11)

message(STATUS "Configure tests")

# Scan for projects
file(GLOB TEST_PROJECTS "src/*")

foreach(TEST_PROJECT_DIR ${TEST_PROJECTS})
	get_filename_component(TEST_PROJECT ${TEST_PROJECT_DIR} NAME)
	message(STATUS "Test project: ${TEST_PROJECT}")

	project(${TEST_PROJECT})
	file(GLOB_RECURSE TEST_SRC "src/${TEST_PROJECT}/*.cpp" "src/${TEST_PROJECT}/*.h")
	add_executable(${TEST_PROJECT} WIN32 ${TEST_SRC})
	target_link_libraries(${TEST_PROJECT} qbrowser Qt5::Core Qt5::Widgets Qt5::Network Qt5::Xml)
endforeach(TEST_PROJECT_DIR)

