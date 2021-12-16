#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int x;
	struct node *next;
};
struct pilha {
	struct node *top;
	int size;
};

struct pilha *create_pilha(void);
int isEmpty(struct pilha * ptr);
void push (struct pilha * ptr, int a);
int pop (struct pilha * ptr);
void math (struct pilha *ptr);

int main()
{
	struct pilha *p = create_pilha();
	char command[50];
	char choice[50];
	int num;

	while(fgets(command, 50, stdin)){
		sscanf(command, "%s", choice);

		if (strcmp(choice, "push") == 0){
			sscanf(command, "%s %d", choice, &num);
			push(p, num);
		}
		else if(strcmp(choice, "pop") == 0){
			printf("%d\n", pop(p));
		}
		else if(strcmp(choice, "abs") == 0){
			math(p);
		}
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

int isEmpty(struct pilha * ptr)
{
	if (ptr->size == 0){
		return 1; 
	} else {
		return 0;
	}
}

void push (struct pilha * ptr, int a)
{
	struct node *new;
	new = malloc(sizeof(struct node));

	if (new != NULL){
		new->next = ptr->top;
		new->x = a;

		ptr->top =  new;
		ptr->size++; 
	}
}

int pop (struct pilha * ptr)
{
	struct node *aux;
	aux = malloc(sizeof(struct node));
	int value;
	if (isEmpty(ptr)){
		return 0;
	} else {
		aux = ptr->top;
		value = aux->x;

		ptr->top = aux->next;
		ptr->size = ptr->size--;

		free(aux);
		return value;
	}
}

void math (struct pilha *ptr)
{
	struct node *pointer;
	pointer = malloc(sizeof(struct node));
	pointer = ptr->top;
	int i, max = 0, min = 100000, dif;

	while(pointer != NULL){
		if (pointer->x < min){
			min = pointer->x;
		}
		if (pointer->x > max){
			max = pointer->x;
		}
		pointer = pointer->next;
	}
	dif = max - min;
	printf("%d\n", dif);
}
