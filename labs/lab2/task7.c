#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define n 128

typedef struct {
    int data[n];
    int top;
} Stack;

void full(Stack *stack, int value) {
    if (stack->top == n - 1) {
        printf("Ошибка: стек переполнен\n");
        exit(1);
    }
    stack->data[++stack->top] = value;
}

int pust(Stack *stack) {
    if (stack->top == -1) {
        printf("Ошибка: стек пуст\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

int perevod(const char *str) {
    Stack stack;
    stack.top = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch == ' ') {
            continue;
        }

        if (isdigit(ch)) {
            int sch = 0;
            while (isdigit(str[i])) {
                sch = sch * 10 + (str[i] - '0');
                i++;
            }
            i--;
            full(&stack, sch);
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int z2 = pust(&stack);
            int z1 = pust(&stack);
            int result;

            switch (ch) {
                case '+': 
                result = z1 + z2; 
                break;
                case '-': 
                result = z1 - z2; 
                break;
                case '*': 
                result = z1 * z2; 
                break;
                case '/': 
                    if (z2 == 0) {
                        printf("Ошибка: деление на ноль\n");
                        exit(1);
                    }
                    result = z1 / z2; 
                    break;
                default:
                    printf("Ошибка: неизвестный оператор '%c'\n", ch);
                    exit(1);
            }
            full(&stack, result);
        } else {
            printf("Ошибка: недопустимый символ '%c'\n", ch);
            exit(1);
        }
    }
    return pust(&stack);
}

int main() {
    FILE *file = fopen("input.txt", "r");

    char str[128];
    while (fgets(str, sizeof(str), file)) {
        int result = perevod(str);
        printf("Результат: %d\n", result);
    }
    fclose(file);
    return 0;
}
