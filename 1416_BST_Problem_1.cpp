#include <cstdio>

class BST {
public:
    BST();
    void Insert(int);
    void Size(int);
private:
    class Node{
        Node(int);
        int Value;
        int Size;
        Node *LC, *RC;
    };
    Node *root;
};

BST::BST() {
    root = NULL;
}

void BST::Insert(int X) {
    if (!root) {
        root = new BST::Node(X);
    }
    else {
        
    }
}

BST::Node::Node(int X) {
    Value = X;
    Size = 1;
    LC = RC = NULL;
}
