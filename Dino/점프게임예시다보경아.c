/*#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 80

void GotoXY(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void drawDinosaur(int y) {
    GotoXY(2, y);
    printf("     ######\n");
    GotoXY(2, y + 1);
    printf("    ##    ##\n");
    GotoXY(2, y + 2);
    printf("    ########\n");
    // Add more lines as needed to draw your dinosaur
}

void drawObstacle(int x) {
    GotoXY(x, HEIGHT - 4);
    printf("####");
    GotoXY(x, HEIGHT - 3);
    printf("####");
}

void clearScreen() {
    system("cls");
}

int main() {
    int y = HEIGHT - 4; // 공룡의 초기 Y 위치
    int isJumping = 0;
    int jumpHeight = 5;  // 점프 높이 초기값을 줄여서 점프를 빠르게 함
    int obstacleX = WIDTH - 20;

    while (1) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == ' ' && !isJumping) {
                isJumping = 1;
                jumpHeight = 5;  // 각 점프마다 점프 높이를 재설정
            }
        }

        if (isJumping) {
            y -= jumpHeight;
            jumpHeight--;   // 더 빠르게 감소하여 하강 속도를 높임
            if (jumpHeight < -5) {  // jumpHeight를 음수로 허용하여 더 빠른 하강 가능
                isJumping = 0;
            }
        }
        else {
            if (y < HEIGHT - 4) {
                y++;  // 점프하지 않고 지면 위에 있을 때 더 빨리 내려옴
            }
        }

        clearScreen();
        drawDinosaur(y);
        drawObstacle(obstacleX);

        obstacleX -= 2;
        if (obstacleX < 0) {
            obstacleX = WIDTH - 20;
        }

        GotoXY(WIDTH, HEIGHT); // 커서를 화면 밖으로 이동
        Sleep(30); // 전체 게임 속도를 빠르게 하기 위해 수면 시간을 30밀리초로 감소
    }

    return 0;
}
*/