#include <stdio.h>
#include <stdlib.h>

struct _node {
    int value;
    struct _node *prev;
    struct _node *next;
} ;
typedef struct _node Node;

Node * nmalloc(void);

int main(int argc, char *argv[])
{
    char op_in[10];
    int input;
    Node *head=NULL, *tail=NULL, *middle=NULL, *tmp;
    tmp = nmalloc();
    tmp->next = tmp->prev = NULL;
    
    while (~scanf("%s", op_in)) {

        if (strcmp(op_in, "IT")==0) {
            scanf("%d", &input);
            /* emu_it(input); */
            
        }
        else if (strcmp(op_in, "IH")==0) {
            scanf("%d", &input);
            emu_ih(input);
        }
        else if (strcmp(op_in, "RH")==0) {
            emu_rh();
        }
        else if (strcmp(op_in, "RT")==0) {
            emu_rt();
        }
        else {
            emu_swap();
        }
    }
    return 0;
}

Node * nmalloc(void) {
    return (Node*)malloc(sizeof(Node));
}
