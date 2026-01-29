//
// Created by YeoPEVA on 6/7/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX_WORD_SIZE 100
#define MAX_MEANING_SIZE 100

typedef struct{
    char word[MAX_WORD_SIZE];
    char meaning[MAX_MEANING_SIZE];
} element;

typedef struct TreeNode{
    element key;
    struct TreeNode *left, *right;
} TreeNode;

int compare(element e1, element e2)
{
    return strcmp(e1.word, e2.word);
}

void display(TreeNode *p)
{
    if(p != NULL){
        printf("(");
        display(p->left);
        printf("%s", p->key.word);
        display(p->right);
        printf(")");
    }
}

TreeNode *search(TreeNode *root, element key)
{
    TreeNode *p = root;
    while(p != NULL){
        switch(compare(key, p->key)) {
            case -1:
                p = p->left;
                break;
            case 0:
                return p;
            case 1:
                p = p->right;
                break;
        }
    }
    return p;
}

void insert_node(TreeNode **root, element key)
{
    TreeNode *p, *t;
    TreeNode *n;

    t = *root;
    p = NULL;

    while (t != NULL){
        if(compare(key, t->key) == 0) return;
        p = t;
        if(compare(key, t->key) < 0) t = t->left;
        else t = t->right;
    }

    n = (TreeNode *) malloc(sizeof(TreeNode));
    if(n == NULL) return;

    if(p != NULL)
        if(compare(key, p->key) < 0)
            p->left = n;
        else p->right = n;
    else *root = n;
}

void delete_node(TreeNode **root, element key)
{
    TreeNode *p, *child, *succ, *succ_p, *t;
    p = NULL;
    t = *root;
    while(t != NULL && compare(t->key, key) != 0){
        p = t;
        t = (compare(key, t->key) <0) ?
                t->left : t->right;
    }

    if(t == NULL){
        printf("key is not in the tree");
        return;
    }

    // p 303

}