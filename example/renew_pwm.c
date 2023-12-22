#include <stdio.h>
#include <conio.h>
#include <math.h>

// PROTOTYPE

unsigned char decode(unsigned char Vin, _Bool Mode);
unsigned char map_pwm(unsigned char V1, unsigned char V2);
unsigned char map_pwm_bitwise(unsigned char V1, unsigned char V2);

void control(unsigned char Value);

// DEFINITION

unsigned char decode(unsigned char Vin, _Bool Mode)
{
    return (Mode == 1) ? (Vin >> 4) : (Vin & 15);
}

unsigned char map_pwm(unsigned char V1, unsigned char V2)
{
    unsigned char map[8][8] = {
        {0, 10, 25, 40, 55, 70, 85, 100}, // 0
        {15, 13, 11, 8, 6, 4, 2, 0},      // 1
        {30, 26, 21, 17, 12, 8, 3, 0},    // 2
        {45, 38, 32, 25, 18, 11, 5, 0},   // 3
        {60, 51, 42, 33, 24, 15, 6, 0},   // 4
        {75, 64, 53, 41, 30, 19, 8, 0},   // 5
        {90, 77, 63, 50, 36, 23, 9, 0},   // 6
        {100, 85, 70, 55, 40, 25, 10, 0}  // 7
    };
    return map[abs(V1 - 7)][abs(V2 - 7)];
}

unsigned char map_pwm_bitwise(unsigned char V1, unsigned char V2)
{
    unsigned char map[8][8] = {
        {0, 10, 25, 40, 55, 70, 85, 100}, // 0
        {15, 13, 11, 8, 6, 4, 2, 0},      // 1
        {30, 26, 21, 17, 12, 8, 3, 0},    // 2
        {45, 38, 32, 25, 18, 11, 5, 0},   // 3
        {60, 51, 42, 33, 24, 15, 6, 0},   // 4
        {75, 64, 53, 41, 30, 19, 8, 0},   // 5
        {90, 77, 63, 50, 36, 23, 9, 0},   // 6
        {100, 85, 70, 55, 40, 25, 10, 0}  // 7
    };
    V1 = (V1 < 7) ? (7 - V1) : (V1 - 7);
    V2 = (V2 < 7) ? (7 - V2) : (V2 - 7);
    return map[V1][V2];
}

void control(unsigned char Value)
{
    unsigned char V1 = decode(Value, 0);
    unsigned char V2 = decode(Value, 1);
    printf("Value = %hu\n", Value);
    printf("V1 = %hu\n", V1);
    printf("V2 = %hu\n", V2);
    printf("pwm lech = %hu\n", map_pwm(V1, V2));
    printf("pwm lech bitwise = %hu\n", map_pwm_bitwise(V1, V2));
}

int main()
{
    unsigned char flag = 1;
    unsigned char value;
    do
    {
        printf("Input Value = ");
        scanf("%d", &value);
        control(value);
        printf("Continue?\n\t0: No\n\t1: Yes\nAnswer: ");
        fflush(stdin);
        scanf("%d", &flag);
    } while (flag == 1);
    return 0;
}