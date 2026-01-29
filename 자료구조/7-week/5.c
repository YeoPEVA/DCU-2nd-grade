#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct QueueNode {
    TreeNode *data;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;

Queue* createQueue() {
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(Queue *queue, TreeNode *data) {
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

TreeNode* dequeue(Queue *queue) {
    if (queue->front == NULL) return NULL;
    QueueNode *temp = queue->front;
    TreeNode *data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL)
        queue->rear = NULL;
    free(temp);
    return data;
}

int isEmpty(Queue *queue) {
    return queue->front == NULL;
}

TreeNode* createNode(int data) {
    TreeNode *newNode = (TreeNode*) malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void levelOrder(TreeNode *root) {
    if (root == NULL) return;
    Queue *queue = createQueue();
    enqueue(queue, root);

    while (!isEmpty(queue)) {
        TreeNode *current = dequeue(queue);
        printf("%d ", current->data);
        if (current->left != NULL) {
            enqueue(queue, current->left);
        }
        if (current->right != NULL) {
            enqueue(queue, current->right);
        }
    }
}

int main() {
    TreeNode *root = createNode(15);
    root->left = createNode(4);
    root->right = createNode(20);
    root->left->left = createNode(1);
    root->right->left = createNode(16);
    root->right->right = createNode(25);

    levelOrder(root);
    printf("\n");

    free(root->left->left);
    free(root->right->left);
    free(root->right->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
