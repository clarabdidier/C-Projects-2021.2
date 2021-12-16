#include <stdio.h>
int main()
{
    int a, b, i, j, sum_diag1 = 0, sum_diag2 = 0, maior0 = 0, menor0 = 0;
    scanf("%d %d", &a, &b);
    int matrix[a][b];

    for(i=0; i<a; i++)
	{
        for(j=0; j<b; j++){
            scanf("%d", &matrix[i][j]);
            if(matrix[i][j] > 0){
                maior0++;
            }
            else{
                menor0++;    
            }        
        }
    }
    printf("Matriz formada:\n");
    for(i=0; i<a; i++)
    {
        for(j=0; j<b; j++){
            if(j <b-1){
            printf("%d ", matrix[i][j]);
            }
            else{
                printf("%d", matrix[i][j]);
            }
            }
        printf("\n");
    }
    if( a == b)
    {
        for(i = 0; i < a; i++)
        {
            sum_diag1 += matrix[i][i];
        }

        j=b-1;
        for(i=0; i<a; i++)
        {
            sum_diag2 += matrix[i][j];
            j--;
        }
        printf("A diagonal principal e secundaria tem valor(es) %d e %d respectivamente.\n", sum_diag1, sum_diag2);
    }

    else{
        printf("A diagonal principal e secundaria nao pode ser obtida.\n");
    }
    printf("A matriz possui %d numero(s) menor(es) que zero.\nA matriz possui %d numero(s) maior(es) que zero.", menor0, maior0);

    return 0;
}