#include <stdio.h>

void controll()
{

    // V1
    if (V1 == 7)
    {
        if (V2 == 7) // STOP (0)
        {
            /*
            B12 = B13 = B14 = B15 = pwmA = pwmB = 0
            */
        }
        else
        {
            // pwmA = pwmB = map_(V2)
            if (V2 < 7) // LEFT SPIN (6)
            {
                /*
                B12 = B15 = 0
                B13 = B13 = 1

                */
            }
            if (V2 > 7) // RIGHT SPIN (9)
            {
                /*
                B12 = B15 = 1
                B13 = B13 = 0
                */
            }
        }
        if (V1 > 7)
        {
            if (V2 == 7) // FORWARD
            {
            }
            if (V2 < 7) // LEFT FORWARD
            {
            }
            if (V2 > 7) // RIGHT FORWARD
            {
            }
        }
        if (V1 < 7)
        {
            if (V2 == 7) // BACK
            {
            }
            if (V2 < 7) // LEFT BACK
            {
            }
            if (V2 > 7) // RIGHT BACK
            {
            }
        }

        // V2
        if (V2 == 7)
        {
            // pwm(map_(V1),map_(V1));
        }
        if (V2 < 7)
        {
            if (V1 == 7)
            {
                // L_Spin();
                // pwm(map_(V2),map_(V2));
            }
            else
            {
                // pwm(map_(V1)-((~(V2-7)+1)<<1), map_(V1));
                if (V1 > 7)
                    // Forward();
                else
                    // Back();
            }
        }
        if (V2 > 7)
        {
            if (V1 == 7)
            {
                // R_Spin();
                // pwm(map_(V2),map_(V2));
            }
            else
            {
                // pwm(map_(V1), map_(V1) - ((V2-7)<<1));
                if (V1 > 7)
                    // Forward();
                else
                    // Back();
            }
        }
        
    }

    int main()
    {

        return 0;
    }