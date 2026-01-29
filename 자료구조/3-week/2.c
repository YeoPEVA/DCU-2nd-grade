#include <stdio.h>
#include <stdbool.h> // bool, true, false가 정의된 헤더 파일
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char arr[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

void push(Stack *s, int data) {
    s->arr[++(s->top)] = data;
}

char pop(Stack *s) {
    if(isEmpty(s)){
        return 1;
    }else{

        return s->arr[(s->top)--];
    }

}

//////////

bool isMatchingPair(char pairA, char pairB) {
    if((pairA == '(' && pairB !=')') || (pairA == '[' && pairB !=']') || (pairA == '{' && pairB != '}')){
        return true;
    }else{
        return false;
    }
}

bool isBalanced(char * expressionCheck) {
    Stack s;
    char ch, open_ch;
    int i, n = strlen(expressionCheck);

    initialize(&s);

    for(i = 0; i < n; i++){
        ch = expressionCheck[i];
        if(ch == '(' || ch == '[' || ch == '{'){
            push(&s, ch);
        }
        if(ch == ')' || ch == ']' || ch == '}'){
            open_ch = pop(&s);
            if(isMatchingPair(open_ch, ch)){
                return false;
            }

            if(!isEmpty(&s)){
                break;
            }
        }
    }
    return true;
}

int main() {
    char expression[MAX_SIZE];
    scanf("%s", expression);

    if (isBalanced(expression))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}
