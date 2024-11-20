cmake_minimum_required(VERSION 3.8)

project(rlImGui CXX)

set(CMAKE_CXX_STANDARD 17)

set(rlImGui_CPP_SRC_DIR "${CMAKE_CURRENT_LIST_DIR}")
set(rlImGui_BUILD_SOURCES 
	"${rlImGui_CPP_SRC_DIR}/imgui_impl_raylib.h"
	"${rlImGui_CPP_SRC_DIR}/rlImGui.h"
	"${rlImGui_CPP_SRC_DIR}/rlImGui.cpp"
)

add_library(rlImGui STATIC "${rlImGui_BUILD_SOURCES}")
target_compile_definitions(rlImGui PUBLIC NO_FONT_AWESOME IMGUI_DISABLE_OBSOLETE_FUNCTIONS IMGUI_DISABLE_OBSOLETE_KEYIO)
target_include_directories(rlImGui PUBLIC "${rlImGui_CPP_SRC_DIR}")
target_link_libraries(rlImGui PUBLIC imgui raylib)