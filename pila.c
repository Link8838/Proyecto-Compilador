#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct Stack {
    int top;
    int cantidad;
    void **array;
};

struct Stack* createStack()
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->cantidad = 0;
    stack->top = -1;
    stack->array = malloc(sizeof(*stack->array));
    return stack;
}


int isEmpty(struct Stack* stack)
{
    return stack->cantidad == 0;
}

void push(struct Stack* stack, void *item)
{
    stack->array[++stack->top] = item;
    stack->cantidad = ++(stack->cantidad) ;
    printf("%p pushed to stack\n", item);
}


void* pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    stack->cantidad = --(stack->cantidad) ;
    return stack->array[stack->top--];
}

void* peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top];
}

int tamano(struct Stack* stack){
  return stack->cantidad;
}
