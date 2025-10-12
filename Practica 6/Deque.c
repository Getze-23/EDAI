#include <stdio.h>
#include <stdlib.h>
#define MAX 5  
typedef struct {
    int datos[MAX];
    int front;
    int size;
} Deque;


void initDeque(Deque *dq) {
    dq->front = 0;
    dq->size = 0;
}


int rear(Deque *dq) {
    return (dq->front + dq->size - 1 + MAX) % MAX;
}


void insert_front(Deque *dq, int valor) {
    if(dq->size == MAX) {
        printf("Deque lleno. No se puede insertar ", valor);
        return;
    }
    dq->front = (dq->front - 1 + MAX) % MAX;
    dq->datos[dq->front] = valor;
    dq->size++;
}

void insert_rear(Deque *dq, int valor) {
    if(dq->size == MAX) {
        printf("Deque lleno. No se puede insertar", valor);
        return;
    }
    int r = (dq->front + dq->size) % MAX;
    dq->datos[r] = valor;
    dq->size++;
}

void delete_front(Deque *dq) {
    if(dq->size == 0) {
        printf("Deque vacío. No se puede eliminar del frente.\n");
        return;
    }
    dq->front = (dq->front + 1) % MAX;
    dq->size--;
}


void delete_rear(Deque *dq) {
    if(dq->size == 0) {
        printf("Deque vacío. No se puede eliminar del final.\n");
        return;
    }
    dq->size--;
}


int peek_front(Deque *dq) {
    if(dq->size == 0) {
        printf("Deque vacío.\n");
        return -1;
    }
    return dq->datos[dq->front];
}


int peek_rear(Deque *dq) {
    if(dq->size == 0) {
        printf("Deque vacío.\n");
        return -1;
    }
    return dq->datos[rear(dq)];
}


void printDeque(Deque *dq) {
    if(dq->size == 0) {
        printf("Deque vacío.\n");
        return;
    }
    printf("Deque: ");
    for(int i=0; i<dq->size; i++) {
        int idx = (dq->front + i) % MAX;
        printf("%d ", dq->datos[idx]);
    }
    printf("\nFront : %d, Rear : %d\n", dq->front, rear(dq));
}

// Pruebas
int main() {
    Deque dq;
    initDeque(&dq);

    insert_front(&dq, 10);          
    insert_rear(&dq, 15);          
    insert_rear(&dq, 20);          
    insert_rear(&dq, 40);           
    printDeque(&dq);

    delete_front(&dq);            
    delete_rear(&dq);               
    printDeque(&dq);

    
    insert_rear(&dq, 60);
    insert_front(&dq, 3);
    printDeque(&dq);

    return 0;
}
