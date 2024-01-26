#include <blend2d.h>
#include "raylib.h"

int main(int argc, char* argv[]) {
  // Use constructor or `create()` function to
  // allocate a new image data of the required
  // format.
  BLImage img(480, 480, BL_FORMAT_PRGB32);

  // Attach a rendering context into `img`.
  BLContext ctx(img);

  // Clearing the image would make it transparent.
  ctx.clearAll();

  // Create a path having cubic curves.
  BLPath path;
  path.moveTo(26, 31);
  path.cubicTo(642, 132, 587, -136, 25, 464);
  path.cubicTo(882, 404, 144, 267, 27, 31);

  // Fill a path with opaque white - 0xAARRGGBB.
  ctx.fillPath(path, BLRgba32(0xFFFFFFFF));

  // Detach the rendering context from `img`.
  ctx.end();

  const int screenWidth = 800;
  const int screenHeight = 800;

  InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
  SetTargetFPS(60); 
     
  while (!WindowShouldClose()) 
  {
      BeginDrawing();
      ClearBackground(RAYWHITE);

      Image rimg = GenImageColor(480, 480, RAYWHITE);
      Texture2D texture = LoadTextureFromImage(rimg);

      BLImageData data;
      img.getData(&data);

      UpdateTexture(texture, data.pixelData);
      DrawTexture(texture, 0, 0, RAYWHITE);

      EndDrawing();
  }
  CloseWindow();

  // Let's use some built-in codecs provided by Blend2D.
  img.writeToFile("bl_sample_1.png");

  return 0;
}

