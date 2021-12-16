#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push_cliente (struct pilha *ptr, int num_conta, char nome, char sobrenome, float saldo);
void math_transacao (struct pilha *ptr, int num_conta, char transacao, float valor_tran);
void devedores(struct pilha *ptr);

struct dadosClientes {
	int num_conta;
	char nome[20];
	char sobrenome[20];
	float saldo;
	struct dadosClientes *next;
};
struct pilha {
	struct dadosClientes *top;
	int size;
};
int main(){

	FILE *arq_clientes, *arq_transactions;
	int num_conta;
	char nome[20];
	char sobrenome[20];
	char transacao;
	float saldo, valor_tran;
	struct pilha *p = create_pilha;

	arq_clientes = fopen("CLIENTES.txt", "r");
	while (!feof(arq_clientes)){
		fscanf(arq_clientes, "%d %s %s %f", &num_conta, nome, sobrenome, &saldo);
		push_cliente (p, num_conta, nome, sobrenome, saldo);
	}

	arq_transactions = fopen("TRANSACTIONS.txt", "r");
	while (!feof(arq_transactions)){
		fscanf(arq_transactions, "%d %c %f", &num_conta, transacao, &valor_tran);
		math_transacao (p, num_conta, transacao, valor_tran);
	}
	fclose(arq_clientes);
	fclose(arq_transactions);

	//criar devedores
	devedores(p);
}

struct pilha *create_pilha(void)
{
	struct pilha *ptr;

	ptr = malloc(sizeof(struct pilha));
	ptr->top = NULL;
	ptr->size = 0;

	return ptr;
}

void push_cliente (struct pilha *ptr, int num_conta, char nome, char sobrenome, float saldo)
{
	struct dadosClientes *new;
	new = (struct dadosClientes *)malloc(sizeof(struct dadosClientes));

	if (new != NULL) {
		new->next = ptr->top;
		new->num_conta = num_conta;
		strncpy(new->nome, nome, 20);
		strncpy(new->sobrenome, sobrenome, 20);
		new->saldo = saldo;

		ptr->top = new;
		ptr->size++;
	}
}

void math_transacao (struct pilha *ptr, int num_conta, char transacao, float valor_tran){
	struct dadosClientes *aux;
	aux = ptr->top;

	while (aux != NULL){
		if (aux->num_conta == num_conta){
			if (transacao == '+')
				aux->saldo += valor_tran;
			else if (transacao == '-')
				aux->saldo -= valor_tran;
		}
		aux = aux->next;
	}
}

void devedores(struct pilha *ptr)
{
	struct dadosClientes *aux;
	aux = ptr->top;
	FILE *arq_devedores;

	arq_devedores = fopen("DEVEDORES.txt", "w+");
	while (aux != NULL){
		if (aux->saldo < 0)
			fprintf(arq_devedores, "\n%d %s %s %0.2f\n", aux->num_conta, aux->nome, aux->sobrenome, aux->saldo);

		aux = aux->next;
	}
	fclose(arq_devedores);
}
