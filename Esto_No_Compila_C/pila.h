

typedef struct Stack{
  int top;
  int cantidad;
  void **array;
}Stack;

Stack *createStack();

int isEmpty(Stack *stack);

void push(Stack *stack, void *item);

void* pop(Stack *stack);

void* peek(Stack *stack);

int tamano(Stack *stack);
