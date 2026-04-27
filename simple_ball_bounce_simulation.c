#include <stdio.h>
#include "raylib.h"
int cx=150,cy=100,r=10;
int h=600,w=600;
int dx=2,dy=2;
int main()
{   InitWindow(w,h,"ball");

    SetTargetFPS(60);
    while(!WindowShouldClose())
    { cx+=dx;
      cy+=dy;
      if(cx<=r || cx>= w-r ) dx = -dx;
      if(cy<=r || cy>= h-r ) dy = -dy;
    BeginDrawing();
    ClearBackground(BLACK);
    DrawCircle(cx,cy,r,RED);
    EndDrawing();
    }
    CloseWindow();
    
    return 0;
}
