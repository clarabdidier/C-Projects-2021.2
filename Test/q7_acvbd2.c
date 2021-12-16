// SPDX-License-Identifier: GPL-2.0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char entrada;
	struct node *next;
};

struct pilha {
	struct node *top;
	int size;
};

struct pilha *create_pilha(void);
int isempty(struct pilha *ptr);
void push(struct pilha *ptr, char a);
char pop(struct pilha *ptr);

int main(void)
{
	int num = 0, y, i;

	scanf("%d", &num);

	for (y = 0; y < num; y++) {
		struct pilha *p = create_pilha();
		char t[100001];

		scanf("%s", t);

		for (i = 0; t[i] != '\0'; i++) {
			if (t[i] == '(' || t[i] == '[' || t[i] == '{')
				push(p, t[i]);
			else if (!isempty(p)) {
				switch (t[i]) {
					case ')':
					if (p->top->entrada == '(')
						pop(p);
					else if (p->top->entrada != '(')
						push(p, t[i]);
						
					break;
					case ']':
					if (p->top->entrada == '[')
						pop(p);
					else if (p->top->entrada != '[')
						push(p, t[i]);
						
					break;
					case '}':
					if (p->top->entrada == '{')
						pop(p);
					else if (p->top->entrada != '{')
						push(p, t[i]);
						
					break;
					default:
					push(p, t[i]);
					break;
				}
			} else {
				if (t[i] == ')' || t[i] == ']' || t[i] == '}')
					push(p, t[i]);
			}
		}
		if (p->size != 0)
			printf("N\n");
		else
			printf("S\n");
	}
	return 0;
}

struct pilha *create_pilha(void)
{
	struct pilha *ptr;

	ptr = malloc(sizeof(struct pilha));
	ptr->top = NULL;
	ptr->size = 0;

	return ptr;
}
int isempty(struct pilha *ptr)
{
	if (ptr->size == 0)
		return 1; 
	else
		return 0;
}

void push(struct pilha *ptr, char a)
{
	struct node *new;
	new = malloc(sizeof(struct node));

	if (new != NULL) {
		new->next = ptr->top;
		new->entrada = a;

		ptr->top = new;
		ptr->size++; 
	}
}

char pop(struct pilha *ptr)
{
	struct node *aux;
	aux = malloc(sizeof(struct node));
	char b;

	if (isempty(ptr)) {
		return 0;
	} else {
		aux = ptr->top;
		b = aux->entrada;

		ptr->top = aux->next;
		ptr->size--;

		free(aux);
		return b;
	}
}
