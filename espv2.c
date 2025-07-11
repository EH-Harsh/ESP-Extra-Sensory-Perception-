#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

#define WIDTH 20
#define HEIGHT 10
#define ENEMY_COUNT 3

int playerX = WIDTH / 2;
int playerY = HEIGHT / 2;

// Enemies ka position
int enemyX[ENEMY_COUNT] = {5, 12, 17};
int enemyY[ENEMY_COUNT] = {2, 7, 4};

void draw() {
    system("cls"); // clear screen

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == playerX && y == playerY) {
                printf("P"); // Player
            } else {
                int found = 0;
                for (int i = 0; i < ENEMY_COUNT; i++) {
                    if (x == enemyX[i] && y == enemyY[i]) {
                        printf("E"); // Enemy
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf(".");
                }
            }
        }
        printf("\n");
    }

    // ESP info
    printf("\n[ESP] Player at (%d, %d)\n", playerX, playerY);
    for (int i = 0; i < ENEMY_COUNT; i++) {
        int dx = playerX - enemyX[i];
        int dy = playerY - enemyY[i];
        float distance = sqrt(dx * dx + dy * dy);
        printf("[ESP] Enemy %d at (%d, %d) | Distance: %.2f units\n", i + 1, enemyX[i], enemyY[i], distance);
    }
}

void input() {
    if (_kbhit()) {
        char key = _getch();
        switch (key) {
            case 'w': playerY--; break;
            case 's': playerY++; break;
            case 'a': playerX--; break;
            case 'd': playerX++; break;
        }
    }
}

void clamp() {
    if (playerX < 0) playerX = 0;
    if (playerX >= WIDTH) playerX = WIDTH - 1;
    if (playerY < 0) playerY = 0;
    if (playerY >= HEIGHT) playerY = HEIGHT - 1;
}

int main() {
    while (1) {
        draw();
        input();
        clamp();
        Sleep(100); // delay
    }
    return 0;
}
