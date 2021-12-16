#include<stdio.h>
int main()
{
    int p, e, i, j, soma_coluna = 0, cont = 0;
    scanf("%d", &p);
    scanf("%d", &e);
    int matriz[e][p];

    for(i=0; i<e; i++)
    {
        for(j=0; j<p; j++){
            scanf("%d", &matriz[i][j]);

        }
    }

    for(j=0; j<p; j++)
    {   
        for(i=0; i<e; i++){
            soma_coluna += matriz[i][j];
        }
        cont++;
        printf("Princesa %d: %d voto(s)\n", cont, soma_coluna);
        soma_coluna = 0;
    
    }       
    return 0;
}