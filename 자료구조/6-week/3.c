#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node{
    element data;
    struct Node *link;
}Node;

typedef struct{
    Node *top;
}NodeType;

void init(NodeType *s ){
    s->top = NULL;
}

int is_empty(NodeType *s){
    return (s->top == NULL);
}

int is_full(NodeType *s){
    return 0;
}

void push(NodeType *s, element item){
    Node *temp = (Node *) malloc(sizeof(Node));
    temp->data = item;
    temp->link = s->top;
    s->top = temp;
}

element pop(NodeType *s){
    if(is_empty(s)){
        printf("스택이 비어있음.\n");
        return 0;
    }else{
        Node *temp = s->top;

        int data = temp->data;

        s->top = s->top->link;

        free(temp);

        return data;

    }
}

void print_stack(NodeType *s){
    for(Node *p = s->top; p != NULL; p = p->link){
        printf("%d->", p->data);
    }
    printf("NULL\n");

}

void print_Min_stack(NodeType *s){
    int min;
    int tmp;
    int count = 0;

    for(Node *p = s->top; p != NULL; p = p->link){
        if(count == 0){
            min = p->data;
        }
        tmp = p->data;

        if(min > tmp){
            min = tmp;
        }
        count += 1;
    }
    printf("Min: %d\n", min);

}




int main(void)
{
    NodeType s;
    init(&s);

    printf("Pushing elements onto the stack...\n");

    push(&s, 3);
    print_stack(&s);
    print_Min_stack(&s);

    push(&s, 5);
    print_stack(&s);
    print_Min_stack(&s);

    push(&s, 2);
    print_stack(&s);
    print_Min_stack(&s);

    push(&s, 1);
    print_stack(&s);
    print_Min_stack(&s);

    printf("Popping elements from the stack...\n");

    pop(&s);
    print_stack(&s);
    print_Min_stack(&s);

    pop(&s);
    print_stack(&s);
    print_Min_stack(&s);

    pop(&s);
    print_stack(&s);
    print_Min_stack(&s);
    printf("\n");

    return 0;
}