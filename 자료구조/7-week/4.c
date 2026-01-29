#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* createNode(int data) {
    TreeNode *newNode = (TreeNode*) malloc(sizeof(TreeNode));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 중위 순회
void inorder(TreeNode *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// 전위 순회
void preorder(TreeNode *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// 후위 순회
void postorder(TreeNode *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    TreeNode *root = createNode(15);
    root->left = createNode(4);
    root->right = createNode(20);
    root->left->left = createNode(1);
    root->right->left = createNode(16);
    root->right->right = createNode(25);

    // 중위 순회 출력
    inorder(root);
    printf("\n");

    // 전위 순회 출력
    preorder(root);
    printf("\n");

    // 후위 순회 출력
    postorder(root);
    printf("\n");

    // 메모리 해제
    free(root->left->left);
    free(root->right->left);
    free(root->right->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
