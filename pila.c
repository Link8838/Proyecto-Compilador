// C program for array implementation of stack
#include <stdio.h>
#include <stdlib.h>


// A structure to represent a stack
struct Stack {
    int top;
    int cantidad;
    void **array;
};

// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack* createStack()
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->cantidad = 0;
    stack->top = -1;
    stack->array = malloc(sizeof(*stack->array));
    return stack;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
    return stack->cantidad == 0;
}

// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack, const void *item)
{
    stack->array[++stack->top] = item;
    stack->cantidad = ++(stack->cantidad) ;
    printf("%p pushed to stack\n", item);
}

// Function to remove an item from stack.  It decreases top by 1
void* pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    stack->cantidad = --(stack->cantidad) ;
    return stack->array[stack->top--];
}

// Function to return the top from stack without removing it
void* peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top];
}

int tamano(struct Stack* stack){
  return stack->cantidad;
}

int main()
{
    struct Stack* stack = createStack();
   

    push(stack,symb);

    printf("%p peek \n", peek(stack));
    printf("%d tamano \n", tamano(stack));
    printf("%d vacio?\n", isEmpty(stack) );
    pop(stack);
    printf("%p peek \n", peek(stack));
    printf("%d tamano \n", tamano(stack) );
    printf("%d vacio?\n", isEmpty(stack) );

    return 0;
}
