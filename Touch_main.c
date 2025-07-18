#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

#define WIDTH 20
#define HEIGHT 10

// Simple ESP-like console game
// Player and enemy positions
// Player starts at the center of the grid
// Enemy is at a fixed position
// Player can move with WASD keys
// ESP shows player and enemy positions and distance
// C11 standard
// This code is a simple console game that demonstrates basic ESP functionality


int playerX = WIDTH / 2;
int playerY = HEIGHT / 2;
int enemyX = 5;
int enemyY = 4;

void gotoxy(int x, int y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void draw() {
    system("cls"); // Clear screen

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == playerX && y == playerY) {
                printf("P"); // Player
            } else if (x == enemyX && y == enemyY) {
                printf("E"); // Enemy
            } else {
                printf(".");
            }
        }
        printf("\n");
    }

    // Calculate distance (Euclidean)
    int dx = playerX - enemyX;
    int dy = playerY - enemyY;
    float distance = sqrt(dx * dx + dy * dy);

    // Show ESP info
    printf("\n[ESP] Player at (%d, %d)\n", playerX, playerY);
    printf("[ESP] Enemy at  (%d, %d)\n", enemyX, enemyY);
    printf("[ESP] Distance between player and enemy: %.2f units\n", distance);
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
        Sleep(100); // Slow down loop
    }
    return 0;
}
