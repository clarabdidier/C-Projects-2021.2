// SPDX-License-Identifier: GPL-2.0
#include <stdio.h>

int min(int a, int b, int c);

int main(void)
{
	int n = 0, i, j, area;

	scanf("%d", &n);
	int matriz[n][n], submatriz[n][n];
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			scanf("%d", &matriz[i][j]);
	}

	for (i = 0; i < n; i++)
		submatriz[i][0] = matriz[i][0];

	for (j = 0; j < n; j++)
		submatriz[0][j] = matriz[0][j];
	
	for (i = 1; i < n; i++) {
		for (j = 1; j < n; j++) {
			if (matriz[i][j] == 1)
				submatriz[i][j] = min(submatriz[i][j-1], submatriz[i-1][j], submatriz[i-1][j-1]) + 1;
			else
				submatriz[i][j] = 0;
		}
	}

	int submax = submatriz[0][0];

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (submax < submatriz[i][j])
				submax = submatriz[i][j];
		}
	}
	area = submax * submax;
	printf("%d", area);

	return 0;
}

int min(int a, int b, int c)
{
	int m = a;
	
	if (m > b)
		m = b;
	if (m > c)
		m = c;
	return m;
}
