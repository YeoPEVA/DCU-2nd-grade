#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node {
    element data;
    struct Node *link;
} Node;

Node* insert_first(Node* head, element data)
{
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;

    if(head == NULL){
        head = node;
        node->link = head;
    }else{
        node->link = head->link;
        head->link = node;
    }
    return head;
}

Node* insert_last(Node* head, element data)
{
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;

    if(head == NULL){
        head = node;
        node->link = head;
    }else{
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}

void print_node(Node* head)
{
    Node* p;

    if(head == NULL){
        return;
    }
    p = head->link;

    do{
        printf("%d->", p->data);
        p = p->link;
    }while(p != head->link);
}

int main() {
    Node *head = NULL;

    head = insert_last(head, 20);
    head = insert_last(head,30);
    head = insert_last(head,40);
    head = insert_first(head,10);

    print_node(head);
    return 0;
}