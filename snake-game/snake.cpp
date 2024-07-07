#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

// Constants
const int HEIGHT = 20;
const int WIDTH = 50;
const int MAX_TAIL_LENGTH = 100;
const int INITIAL_SPEED = 100; // Milliseconds
const char SNAKE_HEAD_CHAR = '@';
const char SNAKE_BODY_CHAR = 'o'; // Changed the snake body character
const char FRUIT_CHAR = 'F';


// Structures
struct Point {
    int x, y;
};

// Global variables
bool gameOver;
Point snakeHead;
Point fruit;
Point tail[MAX_TAIL_LENGTH];
int tailLength;
enum Direction { STOP, UP, DOWN, LEFT, RIGHT };
Direction dir;
int score;

// Function prototypes
void Setup();
void Draw();
void Input();
void Logic();

int main() {
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(INITIAL_SPEED);
    }
    cout << "Game over! Your final score is: " << score << endl;
    return 0;
}

void Setup() {
    gameOver = false;
    dir = STOP;
    snakeHead.x = WIDTH / 2;
    snakeHead.y = HEIGHT / 2;
    fruit.x = rand() % WIDTH;
    fruit.y = rand() % HEIGHT;
    score = 0;
    tailLength = 0;
}

void Draw() {
    system("cls");
    for (int i = 0; i < WIDTH + 2; i++)
        cout << "-"; // border
    cout << endl;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0)
                cout << "|"; // border
            if (i == snakeHead.y && j == snakeHead.x)
                cout << "\033[32m" << SNAKE_HEAD_CHAR << "\033[0m"; // Green snake head
            else if (i == fruit.y && j == fruit.x)
                cout << "\033[31m" << FRUIT_CHAR << "\033[0m"; // Red fruit
            else {
                bool print = false;
                for (int k = 0; k < tailLength; k++) {
                    if (tail[k].x == j && tail[k].y == i) {
                        cout << "\033[32m" << SNAKE_BODY_CHAR << "\033[0m"; // Changed snake body character
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }
            if (j == WIDTH - 1)
                cout << "|" ; // border
        }
        cout << endl;
    }

    for (int i = 0; i < WIDTH + 2; i++)
        cout << "-" ; // borderw
    cout << endl;
    cout << "Score: " << score << endl;
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'w':
                if (dir != DOWN)
                    dir = UP;
                break;
            case 's':
                if (dir != UP)
                    dir = DOWN;
                break;
            case 'a':
                if (dir != RIGHT)
                    dir = LEFT;
                break;
            case 'd':
                if (dir != LEFT)
                    dir = RIGHT;
                break;
            case 'x':
                gameOver = true;
                break;
        }
    }
}

void Logic() {
    Point prevTail = { snakeHead.x, snakeHead.y };
    Point prev2Tail;
    tail[0] = prevTail;
    for (int i = 1; i < tailLength; i++) {
        prev2Tail = tail[i];
        tail[i] = prevTail;
        prevTail = prev2Tail;
    }
    switch (dir) {
        case UP:
            snakeHead.y--;
            Sleep(INITIAL_SPEED * 1.2); // Slow down the snake when moving up
            break;
        case DOWN:
            snakeHead.y++;
            Sleep(INITIAL_SPEED * 1.2); // Slow down the snake when moving down
            break;
        case LEFT:
            snakeHead.x--;
            Sleep(INITIAL_SPEED * 0.5); // Normal speed for left movement
            break;
        case RIGHT:
            snakeHead.x++;
            Sleep(INITIAL_SPEED * 0.5); // Normal speed for right movement
            break;
        default:
            break;
    }
    // Collision with borders
    if (snakeHead.x < 0 || snakeHead.x >= WIDTH || snakeHead.y < 0 || snakeHead.y >= HEIGHT)
        gameOver = true;
    // Collision with tail
    for (int i = 0; i < tailLength; i++) {
        if (snakeHead.x == tail[i].x && snakeHead.y == tail[i].y)
            gameOver = true;
    }
    // Collision with fruit
    if (snakeHead.x == fruit.x && snakeHead.y == fruit.y) {
        score += 10;
        fruit.x = rand() % WIDTH;
        fruit.y = rand() % HEIGHT;
        tailLength++;
    }
}
