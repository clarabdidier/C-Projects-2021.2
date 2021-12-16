#include <stdio.h>

    int main()
    {
        float value;
        int i, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12;

        scanf("%f", &value);
        i = value * 100;
        r1 = i % 10000;
        i = i / 10000;
        if (i != 0)
        {
            printf("%d nota(s) de R$100.00\n", i);
        }
        r2 = r1 % 5000;
        i = r1 / 5000;
        if( i != 0)
        {
            printf("%d nota(s) de R$50.00\n", i);
        }
        r3 = r2 % 2000;
        i = r2 / 2000;
        if( i != 0)
        {
            printf("%d nota(s) de R$20.00\n", i);
        }
        r4 = r3 % 1000;
        i = r3 / 1000;
        if( i != 0)
        {
            printf("%d nota(s) de R$10.00\n", i);
        }
        r5 = r4 % 500;
        i = r4 / 500;
        if( i != 0)
        {
            printf("%d nota(s) de R$5.00\n", i);
        }
        r6 = r5 % 200;
        i = r5 / 200;
        if( i != 0)
        {
            printf("%d nota(s) de R$2.00\n", i);
        }
        r7 = r6 % 100;
        i = r6 / 100;
        if( i != 0)
        {
            printf("%d moeda(s) de R$1.00\n", i);
        }
        r8 = r7 % 50;
        i = r7 / 50;
        if( i != 0)
        {
            printf("%d moeda(s) de R$0.50\n", i);
        }
        r9 = r8 % 25;
        i = r8 / 25;
        if( i != 0)
        {
            printf("%d moeda(s) de R$0.25\n", i);
        }
        r10 = r9 % 10;
        i = r9 / 10;
        if( i != 0)
        {
            printf("%d moeda(s) de R$0.10\n", i);
        }
        r11 = r10 % 5;
        i = r10 / 5;
        if( i != 0)
        {
            printf("%d moeda(s) de R$0.05\n", i);
        }
        r12 = r11 % 1;
        i = r11 / 1;
        if( i != 0)
        {
            printf("%d moeda(s) de R$0.01\n", i);
        }

    return 0;
    }
