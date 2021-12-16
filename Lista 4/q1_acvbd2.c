#include<stdio.h>

int peao(int i, int j, char matriz[8][8]);
int cavalo(int i, int j, char matriz[8][8]);
int torre(int i, int j, char matriz[8][8]);
int bispo (int i, int j, char matriz[8][8]);
int rainha (int i, int j, char matriz[8][8]);

int main()
{
    char matriz[8][8];
    int i, j, xeque = 0;
    
    for(i=0; i<8; i++) //LINHAS
    {
        for(j=0; j<8; j++){ //COLUNAS
            scanf("%c\n", &matriz[i][j]);
        }
    }
    for(i=0; i<8; i++){ //LINHAS
        for(j=0; j<8; j++){ //COLUNAS
            if(matriz[i][j] == 'p'){
                xeque += peao(i, j, matriz);
            }
            if(matriz[i][j] == 'c'){
                xeque += cavalo(i, j, matriz);
            }
            if(matriz[i][j] == 't'){
                xeque += torre(i, j, matriz);
            }
            if(matriz[i][j] == 'b'){
                xeque += bispo(i, j, matriz);
            }
            if(matriz[i][j] == 'q'){
                xeque += rainha(i, j, matriz);
            }
        }
    }
    if(xeque != 0){
        printf("XEQUE");
    }else{
        printf("NAO XEQUE");
    }

    return 0;
}

int peao(int i, int j, char matriz[8][8])
{
    if (matriz[i+1][j-1] == 'K' || matriz[i+1][j+1] == 'K'){
        return 1;
    }
    return 0;      
}
int cavalo(int i, int j, char matriz[8][8])
{
    if (matriz[i+2][j-1] == 'K' || matriz[i+2][j+1] == 'K' || matriz[i-1][j+2] == 'K' || 
    matriz[i+1][j+2] =='K' || matriz[i-2][j-1] == 'K' || matriz[i-2][j+1] == 'K' || 
    matriz[i+1][j-2] == 'K' || matriz[i-1][j-2] == 'K'){
        return 1;
    }
    return 0;
}

int torre(int i, int j, char matriz[8][8]){

    for(int a = i + 1; a < 8; a++){
        if(matriz[a][j] != 'K' && matriz[a][j] != '-'){
            break;
        }
        else if (matriz[a][j] == 'K'){
            return 1;
        }
    }
    for(int b = i - 1; b >= 0; b--){
        if(matriz[b][j] != 'K' && matriz[b][j] != '-'){
            break;
        }
        else if (matriz[b][j] == 'K'){
            return 1;
        }
    }
    for(int c = j + 1; c < 8; c++){
        if(matriz[i][c] != 'K' && matriz[i][c] != '-'){
            break;
        }
        else if (matriz[i][c] == 'K'){
            return 1;
        }
    }
    for(int d = j - 1; d >= 0; d--){
        if(matriz[i][d] != 'K' && matriz[i][d] != '-'){
            break;
        }
        else if (matriz[i][d] == 'K'){
            return 1;
        }
    }
    return 0;
}
int bispo (int i, int j, char matriz[8][8]){
    for(int e = i + 1; e < 8; e++){
        if(matriz[e][e] != 'K' && matriz[e][e] != '-'){
            break;
        }
        if (matriz[e][e] == 'K'){
            return 1;
        }
    }

    for(int f = i - 1; f >= 0; f--){
        if(matriz[f][f] != 'K' && matriz[f][f] != '-'){
            break;
        }
        if (matriz[f][f] == 'K'){
            return 1;
        }
    }

    for(int g = j + 1; g < 8; g++){
        i--;
        if(matriz[i][g] != 'K' && matriz[i][g] != '-'){
            break;
        }
        if (matriz[i][g] == 'K'){
            return 1;
        }
    }
    for(int h = j - 1; h >= 0; h--){
        i++;
        if(matriz[i][h] != 'K' && matriz[i][h] != '-'){
            break;
        }
        if (matriz[i][h] == 'K'){
            return 1;
        }
    }
    return 0;
}
int rainha (int i, int j, char matriz[8][8]){
    //laterais
        for(int a = i + 1; a < 8; a++){
        if(matriz[a][j] != 'K' && matriz[a][j] != '-'){
            break;
        }
        else if (matriz[a][j] == 'K'){
            return 1;
        }
    }
    for(int b = i - 1; b >= 0; b--){
        if(matriz[b][j] != 'K' && matriz[b][j] != '-'){
            break;
        }
        else if (matriz[b][j] == 'K'){
            return 1;
        }
    }
    for(int c = j + 1; c < 8; c++){
        if(matriz[i][c] != 'K' && matriz[i][c] != '-'){
            break;
        }
        else if (matriz[i][c] == 'K'){
            return 1;
        }
    }
    for(int d = j - 1; d >= 0; d--){
        if(matriz[i][d] != 'K' && matriz[i][d] != '-'){
            break;
        }
        else if (matriz[i][d] == 'K'){
            return 1;
        }
    }

    // diagonais
    for(int e = i + 1; e < 8; e++){
        if(matriz[e][e] != 'K' && matriz[e][e] != '-'){
            break;
        }
        if (matriz[e][e] == 'K'){
            return 1;
        }
    }

    for(int f = i - 1; f >= 0; f--){
        if(matriz[f][f] != 'K' && matriz[f][f] != '-'){
            break;
        }
        if (matriz[f][f] == 'K'){
            return 1;
        }
    }

    for(int g = j + 1; g < 8; g++){
        i--;
        if(matriz[i][g] != 'K' && matriz[i][g] != '-'){
            break;
        }
        if (matriz[i][g] == 'K'){
            return 1;
        }
    }
    for(int h = j - 1; h >= 0; h--){
        i++;
        if(matriz[i][h] != 'K' && matriz[i][h] != '-'){
            break;
        }
        if (matriz[i][h] == 'K'){
            return 1;
        }
    }

    return 0;
}
