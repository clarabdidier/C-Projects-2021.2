#include<stdio.h>
int main()
{
    int m, n, q, i, j, a, b=0, c=0, valor, vdd = 0;
    scanf("%d %d", &m, &n);
    int matrix[m][n];
    for(i=0; i<m; i++) //LINHAS
    {
        for(j=0; j<n; j++){ //COLUNAS
            scanf("%d\n", &matrix[i][j]);
        }
    }

    scanf("%d\n", &q);

    for(a=0; a<q; a++){
        scanf("%d", &valor);
        for(i=0; i<m; i++) //LINHAS
        {
            if (matrix[i][j-1]>= valor){
                break;
            }
        }
        for(j=0; j<n; j++){ //COLUNAS
            if(valor == matrix[i][j]){
                 vdd++;
                b = i + 1;
                c = j + 1;
            }
                
        }
        
        
        if(vdd != 0){
            printf("YES WITH %d AND %d\n", b, c);
        }else{
            printf("NO\n");
        }
        vdd = 0;
    }

    return 0;
}
