#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>

#define HEIGHT 24
#define WIDTH 80
#define spd 50
#define MAX_X 80
#define MAX_Y 24

void GotoXY(int x, int y) {
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int dinosaur(int y,int under) {
    static bool leg = true;
    if (under) {
        GotoXY(1, y + 2);
        printf("        ****** ");
        GotoXY(1, y + 3);
        printf("       *****♥**");
        GotoXY(1, y + 4);
        printf("       ******9 ");
        GotoXY(1, y + 5);
        printf("  *   ******");
        GotoXY(1, y + 6);
        printf("  **  *******");
        GotoXY(1, y + 7);
        printf("   ***********");
        GotoXY(1, y + 8);
        printf("     ********");
        if (leg) {
            GotoXY(1, y + 9);

            printf("     *  ***   ");
            GotoXY(1, y + 10);
            printf("     ** ");
            leg = false;
        }
        else {
            GotoXY(1, y + 9);
            printf("     ***  *     ");
            GotoXY(1, y + 10);
            printf("          **    ");
            leg = true;
        }

    }
    else {

        GotoXY(1, y);
        printf("        ****** ");
        GotoXY(1, y + 1);
        printf("       *****♥**");
        GotoXY(1, y + 2);
        printf("       ********");
        GotoXY(1, y + 3);
        printf("       ****    ");
        GotoXY(1, y + 4);
        printf("       ******9 ");
        GotoXY(1, y + 5);
        printf("  *   ******");
        GotoXY(1, y + 6);
        printf("  **  *******");
        GotoXY(1, y + 7);
        printf("   ***********");
        GotoXY(1, y + 8);
        printf("     ********");
        if (leg) {
            GotoXY(1, y + 9);

            printf("     *  ***   ");
            GotoXY(1, y + 10);
            printf("     ** ");
            leg = false;
        }
        else {
            GotoXY(1, y + 9);
            printf("     ***  *     ");
            GotoXY(1, y + 10);
            printf("          **    ");
            leg = true;
        }
    }
}
void Gameover(int y, int map[HEIGHT][WIDTH], bool* over) {
    for (int i = 0;i < 11;i++) {
        if (map[y + i][2] == 2 || map[y + i][2] == 3) {
            *over = 1;
            return 0;
        }
    }
}







    int speed =50;
    int main(void) {
        time_t Time = time(NULL);
        int ob = 4;
        int Height = 4;
        int Jumping = 0;
        int y = HEIGHT - 13;
        int under = 0;
        int undertime = 0;

        int map[24][80] = {
         1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1,
         1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1,
         1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1,
         1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1,
         1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1,
         1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1,
         1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1,
         1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1,
         1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1,
         1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1,
         1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1,
         1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1,
         1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1,
         1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1,
         1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1,
         1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1,
         1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1,
         1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1,
         1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1,
         1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1,
         1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1,
         1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1,
         1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1,
        };
        char keyin = 0;
        int score = 0;
        time_t start, curr;
        curr = time(NULL);
        start = curr;
        bool over = false;

        while (!over) {
            system("cls");
            GotoXY(0, 0);
            if (difftime(time(NULL), Time) >= 0) {
                curr = time(NULL);
                score++;
            }


            if (_kbhit()) {
                char ch = _getch();
                if (ch == ' ' && !Jumping) {
                    Jumping = 1;
                    Height = 4;
                }
                else if (ch == 72) {
                    if (!Jumping) {
                        Jumping = 1;
                        Height = 3;
                    }


                }
                else if (ch == 80) {
                    //under = 1;
                    undertime = 5;
                }
                else under=0;
            }

            if (Jumping) {
                if (Height > 0) {
                    y -= Height; // 상승
                }
                else {
                    if (y < HEIGHT - 13) {
                        y++; // 하강
                    }
                }


                Height--; // 상승 중에는 감소

                if (y >= HEIGHT - 13) { // 공룡이 지면에 도달하면
                    y = HEIGHT - 13;    // 지면 아래로 내려가지 않도록 설정
                    Jumping = 0;      // 점프 상태 해제
                    Height = 4;     // 점프 높이 초기화
                }
            }
            if (undertime > 0) {
                under = 1;
                undertime--;
            }
            else {
                under = 0;
            }
            //system("cls");




            for (int i = 0; i < HEIGHT; i++) {
                for (int j = 0; j < WIDTH - 1; j++) {
                    if (map[i][j] == 2 || map[i][j] == 3) {
                        if (map[i][j - 2] != 4 && map[i][j - 2] != 1) {
                            map[i][j - 2] = map[i][j];
                            map[i][j] = 0;
                        }
                        else {
                            map[i][j] = 0;
                        }
                        //map[i][j] = 0;
                    }
                }
                //map[i][WIDTH - 2] = 0;
            }




            if (difftime(time(NULL), Time) >= ob) {
                void obstacle(); {
                    int rad;

                    if (score > 200) {
                        rad = rand() % 5;
                    }
                    else {
                        rad = rand() % 3;
                    }
                    if (rad == 0) {// 4칸 선인장
                        map[21][78] = 2;
                        map[20][77] = 2;
                        map[20][78] = 2;
                        map[19][78] = 2;
                        map[20][76] = 2;
                        map[19][76] = 2;
                        map[18][76] = 2;
                    }
                    else if (rad == 1) {//4칸
                        map[21][77] = 2;
                        map[20][77] = 2;
                        map[19][77] = 2;
                        map[19][78] = 2;
                        map[18][78] = 2;
                    }
                    else if (rad == 2) {//3칸
                        map[21][77] = 2;
                        map[20][77] = 2;
                        map[20][76] = 2;
                        map[19][76] = 2;
                        map[19][78] = 2;
                        map[20][78] = 2;
                    }
                    else if (rad == 3) {     //높은새
                        map[8][78] = 3;
                        map[7][78] = 3;
                        map[6][78] = 3;
                        map[7][77] = 3;
                        map[7][76] = 3;
                    }
                    else if (rad == 4) {     //높은새
                        map[12][78] = 3;
                        map[11][78] = 3;
                        map[10][78] = 3;
                        map[11][77] = 3;
                        map[11][76] = 3;
                    }
                }
                Time = time(NULL);
            }

            for (int i = 0; i < HEIGHT; i++) {
                for (int j = 0; j < WIDTH; j++) {
                    switch (map[i][j]) {
                    case 0: printf(" "); break;
                    case 1: printf("#"); break;
                    case 2: printf("^"); break;
                    case 3: printf("<"); break;
                    case 4: printf("*"); break;
                    }
                }
                printf("\n");
            }

        


            // GotoXY(0, 0);  
            if (score  >= 0 && score != 0) {
                ob = max(1, 4 - (score / 1000)); 
            }


            GotoXY(65, 1);
            printf("Score: %d", score);
            dinosaur(y,under);
            if (score % 900 == 0 && score != 0) {
                speed = max(10, speed - 10);
            }
            Sleep(speed);

        }
        if (Gameover) {
            GotoXY(WIDTH / 2 - 8, HEIGHT / 2);
            printf("GAMEOVER\n\t\t\t\tSCORE:%d", score);

        }
    
    }
