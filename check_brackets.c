#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

typedef struct Bracket
{
    char type;
    int position;
    
} Bracket;


typedef struct Stack
{
    Bracket brackets[MAX];
    int top;
} Stack;

int isEmpty(Stack* s);
int isFull(Stack* s);
int push(Stack* s, Bracket bracket);
Bracket pop(Stack* s);
int Match(char type, char c);

void main() {
    char* txt = malloc(MAX * sizeof(char));
    Stack s;
    s.top = -1;
    fgets(txt, MAX, stdin);


    for (int i = 0; txt[i] != '\0'; i++) {
        if (txt[i] == '(' || txt[i] == '[' || txt[i] == '{') {
            Bracket b;
            b.position = i;
            b.type = txt[i];
            push(&s, b);
        } 
        if (txt[i] == ')' || txt[i] == ']' || txt[i] == '}') {
            if (isEmpty(&s)) {
                printf("%d\n", i + 1);
                return;
            }
            Bracket b = pop(&s);
            if (Match(b.type, txt[i]) == 0) {
                printf("%d\n", i + 1);
                return;
            }
        }
    }

    if (isEmpty(&s)) {
        printf("Success\n");
    } else {
        printf("%d\n", s.brackets[0].position + 1);
    }

}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int isFull(Stack* s) {
    return s->top >= MAX - 1;
}

int push(Stack* s, Bracket bracket) {
    if (isFull(s)) {
        return 0;
    }
    s->brackets[++s->top] = bracket;
    return 1;
}

Bracket pop(Stack* s) {
    return s->brackets[s->top--];
}

int Match(char type, char c) {
    return ((type == '(' && c == ')') || (type == '[' && c == ']') || (type == '{' && c == '}'));
}