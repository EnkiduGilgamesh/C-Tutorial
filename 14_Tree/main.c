#include <stdio.h>
#include "tree.h"

typedef char elem;

int main(){
    bTree * t = initBTree();
    bTreeNode * a, * b, * c, * d, * e, * f;

    d = makeTree(t, 'D', NULL, NULL);
    e = makeTree(t, 'E', NULL, NULL);
    f = makeTree(t, 'F', NULL, NULL);
    b = makeTree(t, 'B', d, NULL);
    c = makeTree(t, 'C', NULL, e);
    b = makeTree(t, 'B', f, NULL);
    a = makeTree(t, 'A', b, c);

    preOrderBTree(a);
    printf("\n");
    
    inOrderBTree(a);
    printf("\n");

    postOrderBTree(a);
    printf("\n");

    return 0;
}