#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 원형 큐 체킹 (요구사항에 적합했는지)

typedef char element[30];
typedef struct Node {
    element data;
    struct Node *head;
    struct Node *link;
} Node;

Node* insert_first(Node* head, element data)
{
    Node *node = (Node *) malloc(sizeof(Node));
    strcpy(node->data, data);

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
    strcpy(node->data, data);

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
        printf("Current turn=%s\n", p->data);
        p = p->link;
    }while(p != head->link);
}

int main() {
    Node *head = NULL;

    head = insert_last(head,"KIM");
    head = insert_last(head,"JUNG");
    head = insert_last(head,"LEE");
    head = insert_last(head,"CHOI");
    head = insert_last(head,"PARK");

    print_node(head);
    print_node(head);

    return 0;
}