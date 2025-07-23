#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 100

char stack[N];
int top = -1;

void full(char c) {
    if (top < N - 1) {
        stack[++top] = c;
    }
}

char end() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0'; 
}

int znak(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int prioritetznak(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    }
    return 0;
}

void translate(const char *inf, char *post) {
    int j = 0;
    for (int i = 0; inf[i]; i++) {
        if (isdigit(inf[i])) {
            post[j++] = inf[i];
        } else if (inf[i] == '(') {
            full(inf[i]);
        } else if (inf[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                post[j++] = end();
            }
            end();
        } else if (znak(inf[i])) {
            while (top != -1 && prioritetznak(stack[top]) >= prioritetznak(inf[i])) {
                post[j++] = end();
            }
            full(inf[i]);
        }
    }
    while (top != -1) {
        post[j++] = end();
    }
    post[j] = '\0';
}

int main() {
    char inf[N];
    char post[N];

    const char *str[] = {
        "1+2*3",
        "4/2-3+1",
        "5*4+(3-1)/2"
    };

    for (int i = 0; i < 3; i++) {
        strcpy(inf, str[i]);
        translate(inf, post);
        printf("Инфиксная : %s\nПостфиксная: %s\n\n", inf, post);
    }

    return 0;
}
