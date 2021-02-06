#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

struct Stack *createStack()
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(Stack*));
    stack->cantidad = 0;
    stack->top = -1;
    stack->array = malloc(sizeof(*stack->array));
    return stack;
}

int isEmpty(Stack *stack)
{
    return stack->cantidad == 0;
}

void push(Stack *stack, void *item)
{
    stack->array[++stack->top] = item;
    stack->cantidad = ++(stack->cantidad) ;
    printf("%p pushed to stack\n", item);
}


void* pop(Stack *stack)
{
    if (isEmpty(stack))
        return NULL;
    stack->cantidad = --(stack->cantidad) ;
    return stack->array[stack->top--];
}

void* peek(Stack *stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top];
}

int tamano(Stack *stack){
  return stack->cantidad;
}
