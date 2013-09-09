#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int Value;
    Node* left_child, right_child;
} Node;

int main(int argc, char *argv[])
{
    int N, A, B;
    while (scanf("%d", &N) && N) {
        Node *root = NULL;
        while (N--) {
            scanf("%d%d", &A, &B);
            if (!root) {
                /* root is empty*/
                root = New_node(A);
            }
            else {
                Insert_node(A);
            }
            Insert_node(B);
        }
        Trav
    }

    return 0;
}
