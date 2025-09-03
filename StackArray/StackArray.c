#include <stdio.h>
#include <stdlib.h>

#define MAX 100   

struct stack {
    int arr[MAX];
    int top;
};

void initialize(struct stack* stack) {
    stack->top = -1;
}

int isFull(struct stack* stack) {
    return stack->top == MAX - 1;
}

int isEmpty(struct stack* stack) {
    return stack->top == -1;
}

void push(struct stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        stack->arr[++(stack->top)] = value;
        printf("%d pushed to stack\n", value);
    }
}

int pop(struct stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop\n");
        return -1;
    } else {
        return stack->arr[(stack->top)--];
    }
}

int peek(struct stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack->arr[stack->top];
    }
}

void display(struct stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements (top to bottom): ");
        for (int i = stack->top; i >= 0; i--) {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct stack s;
    initialize(&s);

    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1)
                    printf("Popped element: %d\n", value);
                break;
            case 3:
                value = peek(&s);
                if (value != -1)
                    printf("Top element: %d\n", value);
                break;
            case 4:
                display(&s);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
