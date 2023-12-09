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
    int y = HEIGHT - 4; // ������ �ʱ� Y ��ġ
    int isJumping = 0;
    int jumpHeight = 5;  // ���� ���� �ʱⰪ�� �ٿ��� ������ ������ ��
    int obstacleX = WIDTH - 20;

    while (1) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == ' ' && !isJumping) {
                isJumping = 1;
                jumpHeight = 5;  // �� �������� ���� ���̸� �缳��
            }
        }

        if (isJumping) {
            y -= jumpHeight;
            jumpHeight--;   // �� ������ �����Ͽ� �ϰ� �ӵ��� ����
            if (jumpHeight < -5) {  // jumpHeight�� ������ ����Ͽ� �� ���� �ϰ� ����
                isJumping = 0;
            }
        }
        else {
            if (y < HEIGHT - 4) {
                y++;  // �������� �ʰ� ���� ���� ���� �� �� ���� ������
            }
        }

        clearScreen();
        drawDinosaur(y);
        drawObstacle(obstacleX);

        obstacleX -= 2;
        if (obstacleX < 0) {
            obstacleX = WIDTH - 20;
        }

        GotoXY(WIDTH, HEIGHT); // Ŀ���� ȭ�� ������ �̵�
        Sleep(30); // ��ü ���� �ӵ��� ������ �ϱ� ���� ���� �ð��� 30�и��ʷ� ����
    }

    return 0;
}
*/