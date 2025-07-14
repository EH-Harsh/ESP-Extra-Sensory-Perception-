#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10
#define ENEMY_COUNT 3

int playerX = WIDTH / 2;
int playerY = HEIGHT / 2;

int enemyX[ENEMY_COUNT] = {5, 12, 17};
int enemyY[ENEMY_COUNT] = {2, 7, 4};
int enemyHP[ENEMY_COUNT] = {100, 80, 60};  // 👈 New: health of each enemy

void draw() {
    system("cls");

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == playerX && y == playerY) {
                printf("P");
            } else {
                int found = 0;
                for (int i = 0; i < ENEMY_COUNT; i++) {
                    if (x == enemyX[i] && y == enemyY[i]) {
                        printf("E");
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

    // ESP Information
    printf("\n[ESP] Player at (%d, %d)\n", playerX, playerY);
    for (int i = 0; i < ENEMY_COUNT; i++) {
        int dx = playerX - enemyX[i];
        int dy = playerY - enemyY[i];
        float distance = sqrt(dx * dx + dy * dy);
        printf("[ESP] Enemy %d at (%d, %d) | Distance: %.2f | Health: %d HP\n",
            i + 1, enemyX[i], enemyY[i], distance, enemyHP[i]);
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

void moveEnemies() {
    for (int i = 0; i < ENEMY_COUNT; i++) {
        int direction = rand() % 4;
        switch (direction) {
            case 0: enemyY[i]--; break;
            case 1: enemyY[i]++; break;
            case 2: enemyX[i]--; break;
            case 3: enemyX[i]++; break;
        }

        if (enemyX[i] < 0) enemyX[i] = 0;
        if (enemyX[i] >= WIDTH) enemyX[i] = WIDTH - 1;
        if (enemyY[i] < 0) enemyY[i] = 0;
        if (enemyY[i] >= HEIGHT) enemyY[i] = HEIGHT - 1;
    }
}

int main() {
    srand(time(0)); // seed for random

    while (1) {
        draw();
        input();
        clamp();
        moveEnemies();
        Sleep(200);
    }

    return 0;
}
