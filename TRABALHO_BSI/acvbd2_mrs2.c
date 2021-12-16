#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void invert(int *position_x, int *position_y)
{
	int temp = *position_x;
	*position_x = *position_y;
	*position_y = temp;
}

void bubble_sort(int size, int number_list[size])
{
	for (int i = 0; i < size-1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (number_list[j] > number_list[j + 1])
				invert(&number_list[j], &number_list[j + 1]);
		}
	}
}

void selection_sort(int size, int number_list[size])
{
	int smallest;

	for (int i = 0; i < size - 1; i++) {
		smallest = i;
		for (int j = i + 1; j < size; j++) {
			if (number_list[j] < number_list[smallest])
				smallest = j;
		}

		invert(&number_list[smallest], &number_list[i]);
	}
}

void insertion_sort(int size, int number_list[size])
{
	int current_num, counter;
	for (int i = 1; i < size; i++) {
		current_num = number_list[i];
		counter = i - 1;

		while (counter >= 0 && number_list[counter] > current_num) {
		number_list[counter + 1] = number_list[counter];
		counter--;
		}
		number_list[counter + 1] = current_num;
	}
}

void heap_aux(int number_list[], int size, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < size && number_list[left] > number_list[largest])
		largest = left;
	if (right < size && number_list[right] > number_list[largest])
		largest = right;
	if (largest != i) {
		invert(&number_list[i], &number_list[largest]);

		heap_aux(number_list, size, largest);
	}
}

void heap_sort(int size, int number_list[size])
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heap_aux(number_list, size, i);

    for (int i = size - 1; i > 0; i--) {
        invert(&number_list[0], &number_list[i]);

        heap_aux(number_list, i, 0);
    }
}

void merge(int number_list[], int left, int med, int right)
{
	int n1 = med - left + 1;
	int n2 = right - med;
	int L[n1], R[n2];
	
	for (int i = 0; i < n1; i++)
		L[i] = number_list[left + i];
	for (int i = 0; i < n2; i++)
		R[i] = number_list[med + 1 + i];

	int i = 0, j = 0, k = left;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			number_list[k] = L[i];
			i++;
		}
		else {
			number_list[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		number_list[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		number_list[k] = R[j];
		j++;
		k++;
	}
}

void merge_sort(int left, int right, int number_list[right + 1])
{
	if (left < right) {
		int med = left + (right - left) / 2;

		merge_sort(left, med, number_list);
		merge_sort(med + 1, right, number_list);
		merge(number_list, left, med, right);
	}
}

int apart(int number_list[], int low, int high) 
{ 
	int center = number_list[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++) { 
		if (number_list[j] < center) { 
		i++;
		invert(&number_list[i], &number_list[j]); 
		} 
	} 
	invert(&number_list[i + 1], &number_list[high]); 
	return i + 1; 
} 

void quick_sort(int number_list[], int low, int high) 
{ 
    if (low < high) {
        int pi = apart(number_list, low, high); 

        quick_sort(number_list, low, pi - 1); 
        quick_sort(number_list, pi + 1, high); 
    } 
} 

int main(void)
{
	clock_t start = clock();

	char *file_name;
	int command, array_size;

	printf("1 - 1000\n2 - 5000\n3 - 10000\n4 - 20000\n5 - 50000\n6 - 75000\n7 - 100000\n");
	printf("Escolha o documento desejado: ");
	scanf("%d", &command);
	switch (command) {
		case 1:
			file_name = "1000.txt";
			array_size = 1000;
			break;
		case 2:
			file_name = "5000.txt";
			array_size = 5000;
			break;
		case 3:
			file_name = "10000.txt";
			array_size = 10000;
			break;
		case 4:
			file_name = "20000.txt";
			array_size = 20000;
			break;
		case 5:
			file_name = "50000.txt";
			array_size = 50000;
			break;
		case 6:
			file_name = "75000.txt";
			array_size = 75000;
			break;
		case 7:
			file_name = "100000.txt";
			array_size = 100000;
			break;
		default:
			printf("\nComando não encontrado, tente novamente!\n");
			break;
	}
	int number_list[array_size];

	FILE *file;
	file = fopen(file_name, "r");
	for (int i = 0; i < array_size; i++)
		fscanf(file, "%d", &number_list[i]);
	fclose(file);

	printf("1 - BubbleSort\n2 - SelectionSort\n3 - InsertionSort\n4 - HeapSort\n5 - MergeSort\n6 - QuickSort\n");
	printf("Agora, escolha o algoritmos de ordenacao: ");
	scanf("%d", &command);

	switch (command) {
		case 1:
			bubble_sort(array_size, number_list);
			break;
		case 2:
			selection_sort(array_size, number_list);
			break;
		case 3:
			insertion_sort(array_size, number_list);
			break;
		case 4:
			heap_sort(array_size, number_list);
			break;
		case 5:
			merge_sort(0, array_size - 1, number_list);
			break;
		case 6:
			quick_sort(number_list, 0, array_size - 1);
			break;
		default:
			printf("\nComando não encontrado, tente novamente!\n");
			break;
	}

	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Runtime: %f\n", time_spent);
	return 0;
}
