#ifndef __TREE_H
#define __TREE_H

typedef int elem;
enum {FALSE, TRUE} bool;

struct binaryTreeNode{
    elem data;
    struct binaryTreeNode * lChild, * rChild;
}bTreeNode;

struct{
    bTreeNode * root;
}bTree;

void initBTreeNode(bTreeNode * btree, elem data, bTreeNode * l, bTreeNode * r);
bTreeNode * createBTreeNode(elem data, bTreeNode * l, bTreeNode * r);

bTree * initBTree();
bool isEmptyBTree(bTree * bt);
bTree * makeTree(elem data, bTreeNode * l, bTreeNode * r);

void preOrderBTree(bTreeNode * n);
void inOrderBTree(bTreeNode * n);
void postOrderBTree(bTreeNode * n);

#endif