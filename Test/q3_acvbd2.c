// SPDX-License-Identifier: GPL-2.0
#include <stdio.h>

int recursao(int c, int p);

int main(void)
{
	int c, m, p, valor_total;

	while (!feof(stdin)) {
		c = 0;
		m = 0;
		p = 0;
		valor_total = 0;
		scanf("%d %d %d", &c, &m, &p);
		if (c == 0 && p >= 0)
			printf("Sim\n");
		else {
			valor_total = recursao(c, p);

			if (valor_total <= m)
				printf("Sim\n");
			else
				printf("Nao\n");
		}

	}
}

int recursao(int c, int p)
{
	int x;

	if (c > 0) {
		c--;
		x = p;
	}
	if (c == 0)
		return x;
	else
		return x + recursao(c, p);
}
