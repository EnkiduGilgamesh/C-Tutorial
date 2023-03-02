#ifndef __TREE_H
#define __TREE_H

typedef char elem;
typedef enum {FALSE, TRUE} bool;

typedef struct binaryTreeNode{
    elem data;
    struct binaryTreeNode * lChild, * rChild;
}bTreeNode;

typedef struct{
    bTreeNode * root;
}bTree;

void initBTreeNode(bTreeNode * btree, elem data, bTreeNode * l, bTreeNode * r);
bTreeNode * createBTreeNode(elem data, bTreeNode * l, bTreeNode * r);

bTree * initBTree();
bool isEmptyBTree(bTree * bt);
bTreeNode * makeTree(bTree * bt, elem data, bTreeNode * l, bTreeNode * r);

void preOrderBTree(bTreeNode * n);
void inOrderBTree(bTreeNode * n);
void postOrderBTree(bTreeNode * n);

#endif