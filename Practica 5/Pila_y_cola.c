#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int datos[MAX];
    int tope;
} Pila;

void inicializarPila(Pila *p) {
    p->tope = -1;
    printf("Pila inicializada vacía.\n");
}

int pilaVacia(Pila *p) {
    return p->tope == -1;
}

int pilaLlena(Pila *p) {
    return p->tope == MAX - 1;
}

void push(Pila *p, int valor) {
    if (pilaLlena(p)) {
        printf("Error: la pila está llena %d.\n", valor);
        return;
    }
    p->datos[++p->tope] = valor;
    printf("Elemento %d insertado en la pila.\n", valor);
}

int pop(Pila *p) {
    if (pilaVacia(p)) {
        printf("Error: la pila está vacía, no se puede extraer.\n");
        return -1;
    }
    int valor = p->datos[p->tope--];
    printf("Elemento %d extraído de la pila.\n", valor);
    return valor;
}

void mostrarPila(Pila *p) {
    if (pilaVacia(p)) {
        printf("La pila está vacía.\n");
        return;
    }
    printf("Estado actual de la pila: ");
    for (int i = 0; i <= p->tope; i++) {
        printf("%d ", p->datos[i]);
    }
    printf("\n");
}


typedef struct {
    int datos[MAX];
    int frente;
    int final;
} Cola;

void inicializarCola(Cola *c) {
    c->frente = 0;
    c->final = -1;
    printf("Cola inicializada vacía.\n");
}

int colaVacia(Cola *c) {
    return c->frente > c->final;
}

int colaLlena(Cola *c) {
    return c->final == MAX - 1;
}

void enqueue(Cola *c, int valor) {
    if (colaLlena(c)) {
        printf("Error: la cola está llena %d.\n", valor);
        return;
    }
    c->datos[++c->final] = valor;
    printf("Elemento %d insertado en la cola.\n", valor);
}

int dequeue(Cola *c) {
    if (colaVacia(c)) {
        printf("Error: la cola está vacía, no se puede extraer.\n");
        return -1;
    }
    int valor = c->datos[c->frente++];
    printf("Elemento %d extraído de la cola.\n", valor);
    return valor;
}

void mostrarCola(Cola *c) {
    if (colaVacia(c)) {
        printf("La cola está vacía.\n");
        return;
    }
    printf("Estado actual de la cola: ");
    for (int i = c->frente; i <= c->final; i++) {
        printf("%d ", c->datos[i]);
    }
    printf("\n");
}


int main() {
    Pila pila;
    Cola cola;
    int n, valor, i;

    //Creamos la pila 
    inicializarPila(&pila);

    //Insertamos los elementos (PUSH) 
    printf("¿Cuántos elementos deseas apilar (máximo 10)? ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Elemento [%d]: ", i + 1);
        scanf("%d", &valor);
        push(&pila, valor);
        mostrarPila(&pila);
    }

    //Extraemos los elementos (POP) 
    printf("¿Cuántos elementos deseas desapilar? ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        pop(&pila);
        mostrarPila(&pila);
    }

   //Creamos una col
    inicializarCola(&cola);

    //Insertamos los elementos en la cola (ENQUEUE)
    printf("¿Cuántos elementos deseas encolar (máximo 10)? ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Elemento [%d]: ", i + 1);
        scanf("%d", &valor);
        enqueue(&cola, valor);
        mostrarCola(&cola);
    }

    // Extraemos los elementos de la cola  (DEQUEUE)
    printf("¿Cuántos elementos deseas desencolar? ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        dequeue(&cola);
        mostrarCola(&cola);
    }


    return 0;
}

