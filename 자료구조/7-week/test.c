#include <stdio.h>
#include <stdlib.h>


// https://srdeveloper.tistory.com/26

// 구조체 Node 정의
typedef struct Node
{
    int data;
    struct Node* Left, * Right;
}Node;

// 노드 Insert
Node* Insert(Node* node, int data)
{
    if(node == NULL)
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->Left = NULL;
        newNode->Right = NULL;

        return newNode;
    }
    else
    {
        if(node->data > data)
        {
            node->Left = Insert(node->Left, data);
        }
        else if(node->data < data)
        {
            node->Right = Insert(node->Right, data);
        }
        else
        {
        	//중복 된 데이터이므로 추가하지 않는다.
        }

        return node;
    }
}

// 노드 값 변경 / 바꾸고자 하는 값 & 바꾸는 값
void Modify(Node* node, int data, int newData)
{
    if(node == NULL) return;

    if(node->data == data)
    {
        node->data = newData;
    }
    else
    {
        if(node->data > data)
        {
            Modify(node->Left, data, newData);
        }
        else
        {
            Modify(node->Right, data, newData);
        }
    }
}

// 노드 검색
Node* Search(Node* node, int data)
{
    if(node == NULL) return NULL;

    if(node->data == data)
    {
        return node;
    }
    else
    {
        if(node->data > data)
        {
            return Search(node->Left, data);
        }
        else
        {
            return Search(node->Right, data);
        }
    }
}

// 중위 순회 함수 탐색 +
Node* FindMinNode(Node* node, Node** minNode)
{
    if(node->Left == NULL)
    {
        *minNode = node;
        node = node->Right;
        return node;
    }
    else
    {
        node->Left = FindMinNode(node->Left, minNode);
        return node;
    }
}

// 노드 삭제 (복잡함 주의)
// 삭제할 키 값 -> 가지고 있는 노드 (재귀함수 탐색)
// 찾은 노드에서 양쪽의 자식이 없는 경우 -> 찾은 노드 삭제
// 왼쪽 자식 노드 존재시 -> 찾은 노드 삭제 후 왼쪽 노드 반환
// 오른쪽 자식 노드 -> 찾은 노드 삭제 후 오른쪽 노드 반환

// 양쪽 자식 노드 / 모두 존재시 (...)
// 왼쪽 자식 노드 중 가장 큰 키 값을 가진 노드를 찾거나

// 오른쪽 자식 노드 중 가장 작은 키 값을 가진 노드를 찾아서 키 값이 일치한 노드의 자리에 넣어주고
// 기존 노드 삭제

// 아래 코드 기준
// 오른쪽 자식 노드에서 가장 작은 키 값을 가진 노드 탐색
// 왼쪽 자식이 없는 노드 -> 가장 작은 키 값을 가진 노드 / 왼쪽 자식이 없는 노드를 찾을 때까지 진행


Node* Delete(Node* node, int data)
{
    if(node == NULL) return NULL;

    if(node->data == data)
    {
        Node* deleteNode = node;
        if(node->Left == NULL && node->Right == NULL)
        {
            node = NULL;
        }
        else if(node->Left != NULL && node->Right == NULL)
        {
            node = node->Left;
        }
        else if(node->Left == NULL && node->Right != NULL)
        {
            node = node->Right;
        }
        else
        {
            Node* minNode = NULL;
            node->Right = FindMinNode(node->Right, &minNode);
            minNode->Left = deleteNode->Left;
            minNode->Right = deleteNode->Right;
            node = minNode;
        }

        free(deleteNode);
        return node;
    }
    else
    {
        if(node->data > data)
        {
            node->Left = Delete(node->Left, data);
        }
        else
        {
            node->Right = Delete(node->Right, data);
        }

        return node;
    }
}

void ShowInOrder(Node* node)
{
    if (node == NULL) return;

    ShowInOrder(node->Left);
    printf("%d ", node->data);
    ShowInOrder(node->Right);
}

void main()
{
	Node* root = NULL;

    //INSERT
    root = Insert(root, 20);
    root = Insert(root, 10);
    root = Insert(root, 32);
    root = Insert(root, 4);
    root = Insert(root, 13);
    root = Insert(root, 25);
    root = Insert(root, 55);

    //               내부 구조
    //                  20
    //          10              32
    //      4       13      25      55

    ShowInOrder(root);
    //결과 : 4 10 13 20 25 32 55
    printf("\n");

    //MODIFY
    Modify(root, 10, 12);
    ShowInOrder(root);
    //결과 : 4 12 13 20 25 32 55
    printf("\n");

    //SEARCH
    printf("%d", Search(root, 12)->data);
    //결과 : 12
    printf("\n");

    //DELETE
    root = Delete(root, 32);
    //               내부 구조
    //                  20
    //          10              55
    //      4       13      25

    ShowInOrder(root);
    //결과 : 4 12 13 20 25 55
    printf("\n");

}