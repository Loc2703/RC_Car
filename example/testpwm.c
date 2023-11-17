#include <stdio.h>

unsigned char PIN_12, PIN_13, PIN_14, PIN_15, Value, V1, V2;

unsigned char decode(unsigned char Vin, _Bool Mode);

// return percent of value
unsigned char map_(unsigned char value);

void Stop(void);

void Forward(void);
void Back(void);
void L_Spin(void);
void R_Spin(void);

void pwm(unsigned char pwmA, unsigned char pwmB);

// void pwm_(unsigned char V2, unsigned char V1);

void controll(unsigned char value);

unsigned char decode(unsigned char Vin, _Bool Mode)
{
    return (Mode == 1) ? (Vin >> 4) : (Vin & 15);
}

unsigned char map_(unsigned char value)
{
    unsigned char mp[] = {100, 85, 71, 56, 42, 28, 14, 0, 14, 28, 42, 56, 71, 85, 100};
    return mp[value];
}

// void pwm_(unsigned char V2, unsigned char V1)
//{
//
//   if (V1 == 7)
//   {
//		pwmA = pwmB = map_(V2);
//
//
//     __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, pwmA);
//		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, pwmA);
//
//		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, pwmB);
//		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, pwmB);
//   }
//	else
//	{
//		if (V2 > 7)
//		{
//			pwmA = map_(V1);
//			pwmB = pwmA * map_(V2) / 100;
//		}
//		if (V2 < 7)
//		{
//			pwmB = map_(V1);
//			pwmA = pwmB * map_(V2) / 100;
//		}
//		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, pwmA);
//		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, pwmA);
//
//		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, pwmB);
//		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, pwmB);
//	}
////  HAL_Delay(50);
//}

void Stop()
{
    // HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_PIN_RESET);
    //   __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
    //   __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0);
    //   __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 0);
    //   __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 0);
    PIN_12 = PIN_13 = PIN_14 = PIN_15 = 0;
}

void Forward()
{
    // Motor L up
    // HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12 | GPIO_PIN_14, GPIO_PIN_SET);
    // Motor R up
    // HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13 | GPIO_PIN_15, GPIO_PIN_RESET);
    PIN_12 = PIN_14 = 1;
    PIN_13 = PIN_15 = 0;
}
void Back()
{
    // // Motor L down
    // HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12 | GPIO_PIN_14, GPIO_PIN_RESET);

    // // Motor R down
    // HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13 | GPIO_PIN_15, GPIO_PIN_SET);

    PIN_12 = PIN_14 = 0;
    PIN_13 = PIN_15 = 1;
}

void L_Spin()
{
    // // Motor L down
    // HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12 | GPIO_PIN_15, GPIO_PIN_RESET);
    // // Motor R up
    // HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13 | GPIO_PIN_14, GPIO_PIN_SET);
    PIN_12 = PIN_15 = 0;
    PIN_13 = PIN_14 = 1;
}
void R_Spin()
{
    // // Motor L up
    // HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12 | GPIO_PIN_15, GPIO_PIN_SET);
    // // Motor R down
    // HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13 | GPIO_PIN_14, GPIO_PIN_RESET);
    PIN_12 = PIN_15 = 1;
    PIN_13 = PIN_14 = 0;
}

void pwm(unsigned char pwmA, unsigned char pwmB)
{
    // __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, pwmA);
    // __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, pwmA);
    // __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, pwmB);
    // __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, pwmB);
    printf("pwmA = %u \t pwmB = %u\n", pwmA, pwmB);
}

void controll(unsigned char value)
{
    //  unsigned char V1, V2;

    V1 = decode(value, 0);
    V2 = decode(value, 1);

    if (V2 == 7)
    {
        if (V1 == 7)
            Stop();
        else
        {
            pwmA = pwmB = map_(V1);
            pwm(pwmA, pwmB);
            //    pwm(map_(V1),map_(V1));
            if (V1 < 7)
                Back();
            else
                Forward();
        }
    }
    if (V2 < 7)
    {
        if (V1 == 7)
        {
            pwmA = pwmB = map_(V2);
            L_Spin();
            pwm(pwmA, pwmB);
            //      pwm(map_(V2),map_(V2));
        }
        else
        {
            pwmA = map_(V1) - ((~(V2 - 7) + 1) << 1);
            pwmB = map_(V1);
            pwm(pwmA, pwmB);
            //      pwm(map_(V1)-((~(V2-7)+1)<<1), map_(V1));
            if (V1 > 7)
                Forward();
            else
                Back();
        }
    }
    if (V2 > 7)
    {
        if (V1 == 7)
        {
            pwmA = pwmB = map_(V2);
            R_Spin();
            pwm(pwmA, pwmB);
            //      pwm(map_(V2),map_(V2));
        }
        else
        {
            pwmA = map_(V1);
            pwmB = map_(V1) - ((V2 - 7) << 1);
            pwm(pwmA, pwmB);
            //      pwm(map_(V1), map_(V1) - ((V2-7)<<1));
            if (V1 > 7)
                Forward();
            else
                Back();
        }
    }
}

int main()
{
    unsigned char func = 1;
    while (func == 1)
    {
        printf("Get V value = ");
        scanf("%u", &Value);
        controll(Value);
    }
    return 0;
}