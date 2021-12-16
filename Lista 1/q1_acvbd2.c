#include <stdio.h>

    int main()
    {
        int i, num_box, num_caps, sum, div;
        char size;
        num_caps = 0;

        for(i = 0; i < 7; i++){
            scanf("%d\n", &num_box);
            scanf("%c", &size);

            size = tolower(size);

            if (size == 'p'){
                num_caps = num_box * 10;
            } 
            if (size == 'g'){
                num_caps = num_box * 16;
            }
            sum += num_caps; 

        }
        printf("\n%d\n", sum);
        div = (sum * 2) / 7;
        printf("%d", div);

    return 0;
    }