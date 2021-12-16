// SPDX-License-Identifier: GPL-2.0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int x;
	struct node *next;
};

struct line {
	int size_line;
	struct node *head;
	struct node *tail;
	struct line *prox;
};

struct pilha {
	int size_pilha;
	struct line *top;
};

struct pilha *create_pilha(void);
struct line *create_line(void);
int isempty_pilha(struct pilha *ptr_pilha);
int isempty_line(struct line *ptr_line);
void push_pilha(struct pilha *ptr_pilha, struct line *ptr_line);
void push_line(struct line *ptr_line, int a);
void print_line(struct line *ptr_line);
int pop_pilha(struct pilha *ptr_pilha);

int main(void)
{
	struct pilha *p = create_pilha();
	int num = 0;
	char choice[20];

	while (!feof(stdin)) {
		scanf("%s", choice);

		if (strcmp(choice, "PUSH") == 0) {
			struct line *l = create_line();
			while (scanf("%d", &num))
				push_line(l, num);
			push_pilha(p, l);
		}
		if (strcmp(choice, "POP") == 0)
			pop_pilha(p);
	}
	return 0;
}

struct pilha *create_pilha(void)
{
	struct pilha *ptr_pilha;
	ptr_pilha = malloc(sizeof(struct pilha));

	ptr_pilha->top = NULL;
	ptr_pilha->size_pilha = 0;

	return ptr_pilha;
}

struct line *create_line(void)
{
	struct line *ptr_line;
	ptr_line = malloc(sizeof(struct line));

	ptr_line->head = NULL;
	ptr_line->tail = NULL;
	ptr_line->size_line = 0;

	return ptr_line;
}

int isempty_pilha(struct pilha *ptr_pilha)
{
	if (ptr_pilha->size_pilha == 0)
		return 1; 
	 else
		return 0;

}

int isempty_line(struct line *ptr_line)
{
	if (ptr_line->size_line == 0)
		return 1; 
	else
		return 0;
	
}

void push_pilha(struct pilha *ptr_pilha, struct line *ptr_line)
{
	struct line *new;
	new = malloc(sizeof(struct line));

	if (new != NULL) {
		new = ptr_line;
		new->prox = ptr_pilha->top;

		ptr_pilha->top = new;
		ptr_pilha->size_pilha++; 
	}
}

void push_line(struct line *ptr_line, int a)
{
	struct node *new_node;
	new_node = malloc(sizeof(struct node));

	if (new_node != NULL) {
		new_node->x = a;
		if (isempty_line(ptr_line) == 1) {
			ptr_line->head = new_node;
			ptr_line->tail = new_node;
		} else {
			ptr_line->head->next = new_node;
			ptr_line->head =  new_node;
		}
		ptr_line->size_line++;
	}
}

void print_line(struct line *ptr_line)
{
	struct node *aux2;

	aux2 = ptr_line->tail;
	for (int i = 0; i < ptr_line->size_line; i++) {
		if (aux2 != ptr_line->head)
			printf("%d ", aux2->x);
		else
			printf("%d\n", aux2->x);
		aux2 = aux2->next;
	}
}

int pop_pilha(struct pilha *ptr_pilha)
{
	struct line *aux;
	aux = malloc(sizeof(struct line));

	if (isempty_pilha(ptr_pilha)) {
		printf("EMPTY STACK\n");
		return 0;
	} else {
		aux = ptr_pilha->top;

		ptr_pilha->top = aux->prox;
		ptr_pilha->size_pilha--;

		print_line(aux);
		free(aux);
		return 1;
	}
}
