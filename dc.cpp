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
    return 0;  // Dado não encontrado
}
int isOrdered(Node* head) {
    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->data > current->next->data) {
            return 0;  // Não está em ordem crescente
        }
        current = current->next;
    }
    return 1;  // Está em ordem crescente
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
    // Testando a função pesquisa()
    Node* head = NULL;
    // Adicionar nós à lista encadeada
    // Chamar a função pesquisa(head, valor)

    // Testando a função isOrdered()
    if (isOrdered(head)) {
        printf("A lista está em ordem crescente.\n");
    } else {
        printf("A lista não está em ordem crescente.\n");
    }

    // Testando a função removeEven()
    removeEven(&head);

    // Testando a função somaRecursiva()
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int soma = somaRecursiva(arr, n);
    printf("A soma dos elementos do vetor é: %d\n", soma);

    // Testando a função decimalParaBinario()
    int decimal = 10;
    printf("O valor decimal %d em binário é: ", decimal);
    decimalParaBinario(decimal);
    printf("\n");

    return 0;
}

