#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* makeNode(char data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preorder(TreeNode* root) {
    if (root) {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TreeNode* root) {
    if (root) {
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
    }
}

void postorder(TreeNode* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    TreeNode* nodes[26];
    for (int i = 0; i < 26; i++) {
        nodes[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        char id, left, right;
        scanf(" %c %c %c", &id, &left, &right);

        if (nodes[id - 'A'] == NULL) {
            nodes[id - 'A'] = makeNode(id);
        }
        if (left != '.') {
            nodes[left - 'A'] = makeNode(left);
            nodes[id - 'A']->left = nodes[left - 'A'];
        }
        if (right != '.') {
            nodes[right - 'A'] = makeNode(right);
            nodes[id - 'A']->right = nodes[right - 'A'];
        }
    }

    preorder(nodes[0]);
    printf("\n");
    inorder(nodes[0]);
    printf("\n");
    postorder(nodes[0]);
    printf("\n");

    for (int i = 0; i < 26; i++) {
        if (nodes[i] != NULL) {
            free(nodes[i]);
        }
    }

    return 0;
}
