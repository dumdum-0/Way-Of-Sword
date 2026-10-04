#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>
#include <raymath.h>

class Player{
    public:
        Vector2 position;
        float speed;
        float size;

        Player(float startx , float starty){
            position.x = startx;
            position.y = starty;
            speed = 4.0f;
            size = 40.0f;
        }

        void Update(){

            if (IsKeyDown(KEY_W))
            {
                position.y -= speed;
            }
            if (IsKeyDown(KEY_S))
            {
                position.y += speed;
            }
            if (IsKeyDown(KEY_A))
            {
                position.x -= speed;
            }
            if (IsKeyDown(KEY_D))
            {
                position.x += speed;
            }
            
        }

        void Draw(){
            DrawRectangle( position.x , position.y , size , size , RED);
        }
};

class Mob{
    public:
        Vector2 position;
        float speed;
        float size;

        Mob( float startx, float starty){
            position.x = startx ;
            position.y = starty ;
            speed = 2.0f ;
            size = 30.0f ;
        }

        void Update(Vector2 playerposition){

            Vector2 direction ;

            direction.x = playerposition.x - position.x ;
            direction.y = playerposition.y - position.y ;

            direction = Vector2Normalize(direction);

            position.x += direction.x * speed;
            position.y += direction.y * speed;
            
        }

        void Draw(){
            DrawRectangle( position.x , position.y , size ,size , GREEN);
        }
};



int main(){
    int screenWidth = 800;
    int screenHeight = 600;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth , screenHeight , "Way Of Sword");
    SetTargetFPS(60);
    MaximizeWindow();
    Player Samurai (GetScreenWidth()/2-20, GetScreenHeight()/2-20);
    Mob Goblin(100,100);
    while (!WindowShouldClose())
    {
        Samurai.Update();
        Goblin.Update(Samurai.position);
        BeginDrawing();
        ClearBackground(BLACK);
        Samurai.Draw();
        Goblin.Draw();

        EndDrawing();
    }
    CloseWindow();
    return 0;
}