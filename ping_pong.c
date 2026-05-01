#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "raylib.h"
int w=1000,h=900;
int bh=50,bw=20,bx=200,by=100,bax=800,bay=400;
int x=600,y=400,r=10,dx=5,dy=5;
int sp=0,sa=0;
int run=0,state=0;

int main()
{
 srand(time(0));
 InitWindow(w,h,"Ping Pong");
 SetTargetFPS(60);
 
 while(!WindowShouldClose()) 
 {   if(state==0 && IsKeyPressed(KEY_ENTER)) {state=1; run=1;}
     if(state==1 && IsKeyPressed(KEY_P)) {if(IsKeyPressed(KEY_P)) DrawText("P PRESSED", 400, 200, 30, GREEN);}
     if (IsKeyPressed(KEY_P)) 
      {
         if (state == 1)
         {
           state = 2; // Pause
           run = 0;
          } 
         else if (state == 2) 
         {
            state = 1; // Resume
            run = 1;
         }
       }
     if(run==1 && state==1)
           { 
              x+=dx;
              y+=dy;
              if(x<=r || x>=w-r) dx= -dx;
              if(y<=r || y>=h-r) dy= -dy;
              move(); 
              com();    
              col();
              score();
              if(sp==5 || sa==5) state=3; 
            }
     if(state==3 && IsKeyPressed(KEY_R)){ sp=0; sa=0; x=600; y=400; dx=5; dy=5; state=0; run=0; }
         
BeginDrawing();
         ClearBackground(BLACK);
         DrawText(TextFormat("STATE: %d", state), 400, 50, 30, GREEN);
         if(state==3)
         {    
              if(sp==5 || sa==5)
            {   
             if(sa==5) DrawText("U LOSE",400,400,100,RED);
             if(sp==5) DrawText("U WIN",400,400,100,RED);
             DrawText("Press R to Restart",400,500,100,RED);     
            }
         }
         if(state==0)
         {
             DrawText("PONG", 420, 250, 80, WHITE);
             DrawText("press ENTER to play",380,380,30,WHITE);
         }
      if(state==2) DrawText("press P to play",380,380,30,WHITE);
      if(state==1 || state==2 )
      {   
         DrawRectangle(bx,by,bw,bh,WHITE);
         DrawRectangle(bax,bay,bw,bh,WHITE);
         DrawRectangle(500,0,10,h,WHITE);
         DrawCircle(x,y,r,WHITE);
       }
         DrawText(TextFormat("Player: %d",sp),100,50,30,WHITE);
         DrawText(TextFormat("Player: %d",sa),800,50,30,WHITE);
     
 EndDrawing();     
 }
 CloseWindow();
 return 0;
}
void move()
{
  if(IsKeyDown(KEY_W)) by-=10;
  if(IsKeyDown(KEY_S)) by+=10;
  if(by<=0) by=0;
  if(by>=h-bh) by=h-bh;  
 if(bay<=0) bay=0;
  if(bay>=h-bh) bay=h-bh;      
}


void com()
{
    if(bay>= y) bay-=4;
    if (bay<=y-bh) bay+=6;
}

void score()
{
    if((x-r)<=0) {sa+=1; x=600;y=rand()%h; dy= (rand()%2==0)? 5:-5;}
    if((x+r)>=w) {sp+=1; x=600;y=rand()%h;dy= (rand()%2==0)? 5:-5;}
    if(sp==5 || sa==5) run=0;            
}

void menu()
{
    if(state==0)
    {
        if(IsKeyPressed(KEY_ENTER)){  state=1;run=1;}       
    }
}

void col()
{      
  if(y>=by && y<=by+bh && (x-r)<=(bx+bw) && (x+r)>=bx )  dx= -dx;  
  if(y>=bay && y<=bay+bh && x+r>=bax && (x-r)<=(bax+bw)) dx= -dx;
   
}