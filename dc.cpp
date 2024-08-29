#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int pesquisa(Node* head, int value) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return 1;  // Dado encontrado
        }
        current = current->next;
    }
    return 0;  // Dado n�o encontrado
}
int isOrdered(Node* head) {
    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->data > current->next->data) {
            return 0;  // N�o est� em ordem crescente
        }
        current = current->next;
    }
    return 1;  // Est� em ordem crescente
}
void removeEven(Node** head) {
    Node* current = *head;
    Node* prev = NULL;

    while (current != NULL) {
        if (current->data % 2 == 0) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            Node* temp = current;
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
}
int somaRecursiva(int arr[], int n) {
    if (n <= 0) {
        return 0;
    } else {
        return arr[n - 1] + somaRecursiva(arr, n - 1);
    }
}
void decimalParaBinario(int n) {
    if (n > 0) {
        decimalParaBinario(n / 2);
        printf("%d", n % 2);
    }
}
int main() {
    // Testando a fun��o pesquisa()
    Node* head = NULL;
    // Adicionar n�s � lista encadeada
    // Chamar a fun��o pesquisa(head, valor)

    // Testando a fun��o isOrdered()
    if (isOrdered(head)) {
        printf("A lista est� em ordem crescente.\n");
    } else {
        printf("A lista n�o est� em ordem crescente.\n");
    }

    // Testando a fun��o removeEven()
    removeEven(&head);

    // Testando a fun��o somaRecursiva()
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int soma = somaRecursiva(arr, n);
    printf("A soma dos elementos do vetor �: %d\n", soma);

    // Testando a fun��o decimalParaBinario()
    int decimal = 10;
    printf("O valor decimal %d em bin�rio �: ", decimal);
    decimalParaBinario(decimal);
    printf("\n");

    return 0;
}

