#include <stdio.h>
#include <string.h>
#define MAX_SIZE 30

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

void push(Stack *s, char data) {
    s->arr[++(s->top)] = data;
}

char pop(Stack *s) {
    if(isEmpty(s)){
        return 1;
    }else{
        return s->arr[(s->top)--];
    }
}

int main() {
    char input[MAX_SIZE], reversed[MAX_SIZE];

    Stack s;
    initialize(&s);

    int loop = 0;

    scanf("%s", input);

    for(int i=0; i<MAX_SIZE; i++){
        if(input[i] == '\0'){
            // push(&s, '\0');
            break;
        }
        push(&s, input[i]);
        // printf("push : %c\n", input[i]);
    }

    for(int i=0; i<MAX_SIZE; i++){
        loop += 1;
        reversed[i] = pop(&s);

        if(reversed[i] == input[0]){
            break;
        }else if(reversed[i] == "\0"){
            continue;
        }

        // printf("pop : %c \n", reversed[i]);
    }

    reversed[loop] = '\0';
    printf("%s", reversed);

    return 0;
}
