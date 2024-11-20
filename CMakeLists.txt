# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.24)

project(template_raylib_imgui_entt VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

find_package(raylib CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

add_subdirectory("${CMAKE_SOURCE_DIR}/third_party/imgui" imgui EXCLUDE_FROM_ALL)
add_subdirectory("${CMAKE_SOURCE_DIR}/third_party/rlImGui" rlImGui EXCLUDE_FROM_ALL)

add_executable (${PROJECT_NAME}
	src/main.cpp
	src/raylib_spdlog.h
	src/application.cpp
	src/application.h
)

target_include_directories(${PROJECT_NAME} PRIVATE
	"${CMAKE_SOURCE_DIR}/third_party/include"
)

target_link_libraries(${PROJECT_NAME} PUBLIC  
	raylib
	imgui
	rlImGui
	spdlog::spdlog
)