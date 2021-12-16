#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operaArray.h"

int main(void)
{
	int size, *arr, i = 0;
	char choice;
	FILE *arquivo = fopen("resultados.txt", "w+");
	/*if (arquivo == NULL) {
		printf("Falha ao abrir o arquivo.\n");
	}*/

	printf("Informe o tamanho do array: \n");
	scanf("%d", &size);
	arr = malloc(size*sizeof(int));
	

	printf("Informe os elementos do array:\n");
	for(i = 0; i<size; i++)
		scanf("%d",&arr[i]);
	
	printf("\nO que voce deseja fazer com o seu array?\n");
	printf("R - inverter a lista\nE - contar o numero de vezes que um elemento aparece no array\n");
	printf("U - informar os numeros que se repetem\nD - deletar o enesimo elemento\n");

	while (scanf("%c", &choice) != EOF){

		if (choice == 'R')
			newReverse(size, arr, arquivo);
		if (choice == 'E')
			elemNum(size, arr, arquivo);
		if (choice == 'U')
			unique(size, arr, arquivo);
		if (choice == 'D')
			size = deleteN(size, arr, arquivo);
	}
	fclose(arquivo);
	free(arr);

	return 0;
}

void newReverse(int size, int *arr, FILE *arquivo){
	int i, j, aux;
	char salvar;

	printf("O array inverso eh: ");
	for (i = 0; i < size/2; i++){
		aux = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = aux;
	}
	for (i=0; i<size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	printf("Deseja salvar o resultado?\nS - sim ou N - nao\n");
	scanf(" %c", &salvar);

	if(salvar == 'S'){
		fprintf(arquivo, "array inverso: ");
		for (j = 0; j < size; j++)
			fprintf(arquivo, "%d ", arr[j]);
		fprintf(arquivo, "\n");
		printf("Resultado salvo\n");

	printf("\nSelecione outra opcao:\n");
	}

}

void elemNum (int size, int *arr, FILE *arquivo){
	int cont = 0, a, i, j;
	char salvar;

	printf("Informe o elemento x a ser pesquisado:\n");
	scanf("%d", &a);
	for(i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if (a == arr[j] && i != j){
				cont++;
				arr[j] = 0; 
			}
		}
	}
	printf("O elemento %d aparece %d vez(es) no array.", a, cont);
	printf("\n");

	printf("Deseja salvar o resultado?\nS - sim ou N - nao\n");
	scanf(" %c", &salvar);

	if(salvar == 'S'){
		fprintf(arquivo, "O elemento %d aparece %d vez(es) no array.", a, cont);
		fprintf(arquivo, "\n");
		printf("Resultado salvo\n");

	printf("\nSelecione outra opcao:\n");
	}
}

void unique (int size, int *arr, FILE *arquivo){
	int i, j, k;
	char salvar;

	for (i = 0; i < size; i++){
		for (j = i+1; j < size;){
			if (arr[j] == arr[i]){
				for (k = j; k < size; k++)
					arr[k] = arr[k + 1];
				size--;
			} else
				j++;
		}
	}
	printf("Depois de remover os valores que se repetem: \n");
	for(i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");

	printf("Deseja salvar o resultado?\nS - sim ou N - nao\n");
	scanf(" %c", &salvar);

	if(salvar == 'S'){
		fprintf(arquivo, "Depois de remover os valores que se repetem: \n");
		for (j = 0; j < size; j++)
			fprintf(arquivo, "%d ", arr[j]);

		fprintf(arquivo, "\n");
		printf("Resultado salvo\n");

	printf("\nSelecione outra opcao:\n");
	}
} 

int deleteN (int size, int *arr, FILE *arquivo){
	int i, a, j;
	char salvar;
 
	printf("Informe o enesimo numero a ser removido:\n");
	scanf("%d", &a);
	for (i = a-1; i < size-1; i++){
		arr[i] = arr[i+1];
		a--;
	}
	size--;
	for (i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	printf("Deseja salvar o resultado?\nS - sim ou N - nao\n");
	scanf(" %c", &salvar);

	if(salvar == 'S'){
		fprintf(arquivo, "Depois de remover o enesimo numero: \n");
		for (j = 0; j < size; j++)
			fprintf(arquivo, "%d ", arr[j]);

		fprintf(arquivo, "\n");
		printf("Resultado salvo\n");
	} else {
		printf("\n");
	}

	printf("\nSelecione outra opcao:\n");

	return size;
}

