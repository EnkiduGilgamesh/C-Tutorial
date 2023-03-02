#include "tree.h"

void initBTree(bTreeNode * btree, elem data, bTreeNode * l, bTreeNode * r){
    btree->lChild = l;
    btree->rChild = r;
    btree->data = data;
}

bTreeNode * createBTreeNode(elem data, bTreeNode * l, bTreeNode * r){
    bTreeNode * p = (bTreeNode *)malloc(sizeof(bTreeNode));
    if(!p)
        printf("Memory allocation failed!\n");
    else
        initBTree(p, data, l, r);

    return p;
}

bTree * initBTree(){
    bTree * bt = (bTree *)malloc(sizeof(bTree));
    if(!t)
        printf("Memory allocation failed!\n");
    else
        bt->root = NULL;
    return bt;
}

bool isEmptyBTree(bTree * bt){
    return bt->root != NULL;
}

bTreeNode * makeTree(bTree bt, elem data, bTreeNode * l, bTreeNode * r){
    bTreeNode * p = createBTreeNode(elem data, bTreeNode * l, bTreeNode * r);
    bt->root = p;

    return bt->root;
}

void preOrderBTree(bTreeNode * n){
    if(n){
        printf("%c", n->data);
        preOrderBTree(n->lChild);
        preOrderBTree(n->rChild);
    }
}

void inOrderBTree(bTreeNode * n){
    if(n){
        inOrderBTree(n->lChild);
        printf("%c", n->data);
        inOrderBTree(n->rChild);
    }
}

void postOrderBTree(bTreeNode * n){
    if(n){
        postOrderBTree(n->lChild);
        postOrderBTree(n->rChild);
        printf("%c", n->data);      
    }
}
