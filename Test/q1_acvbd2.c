// SPDX-License-Identifier: GPL-2.0
#include <stdio.h>

int main(void)
{
	int matrix[3][3], i, j, sup = 0, inf = 0;

	while (!feof(stdin)) {
		sup = 0;
		inf = 0;
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				scanf("%d", &matrix[i][j]);
				if (i < j) {
					if (matrix[i][j] == 0)
						inf++;
				}
				if (i > j) {
					if (matrix[i][j] == 0)
						sup++;
				}
			}
		}
		if (sup == 3)
			printf("Por baixo\n");
		else if (inf == 3)
			printf("Por cima\n");
		else
			printf("Nao pode atravessar\n");
	}
}
