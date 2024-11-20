#include <imgui.h>
#include <raylib.h>
#include <rlImGui.h>
#include <spdlog/spdlog.h>

#include <cstdlib>
#include <entt/entt.hpp>

#include "raylib_spdlog.h"

int main(int argc, char *argv[]) {
  // Setup logging
  spdlog::set_level(spdlog::level::trace);
  SetTraceLogCallback(raylib_spdlog::SpdLogCallback);

  // Initialization
  //--------------------------------------------------------------------------------------
  entt::registry main_registry = entt::registry{};

  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "Breakout");

  SetTargetFPS(75);

  rlImGuiSetup(true);
  //--------------------------------------------------------------------------------------

  // Main game loop
  while (!WindowShouldClose())  // Detect window close button or ESC key
  {
    // Update
    //----------------------------------------------------------------------------------
    // TODO: Update your variables here
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawText("Congrats! You created your first window!", 190, 200, 20,
             LIGHTGRAY);

    // User interface
    rlImGuiBegin();
    bool open = true;
    ImGui::ShowDemoWindow(&open);
    rlImGuiEnd();

    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow();  // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return EXIT_SUCCESS;
}