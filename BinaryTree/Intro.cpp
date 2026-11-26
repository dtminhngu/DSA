#include <bits/stdc++.h>
using namespace std;

//1. Bieu dien cay
struct Node {
    int data;
    Node *left;
    Node *right;
};
Node *root = NULL;

//2. Thao tac/cay
Node *makeNode (int newdata)  {
    Node *n = new Node;
    n -> data = newdata;
    n -> left = NULL;
    n -> right = NULL;
    return n;
}

void NLR (Node *root) { // Duyet cay theo thu tu truoc
    if (root != NULL) {
        cout << root -> data << " ";
        NLR (root -> left);
        NLR (root -> right);
    }
}

void LNR (Node *root) {
    if (root != NULL) {
        LNR (root -> left);
        cout << root -> data << " ";
        LNR (root -> right);
    }
}

void LRN (Node *root) {
    if (root != NULL) {
        LRN (root -> left);
        LRN (root -> right);
        cout << root -> data << " ";
    }
}

int main () {
    // Tao node
    root = makeNode (50);
    Node *node40 = makeNode (40);
    Node *node60 = makeNode (60);
    // ket noi cac node vao cay
    root -> left = node40;
    root -> right = node60;
    NLR (root); // 50 40 60
    cout << "\n";
    LNR (root); // 40 50 60;
    cout << "\n";
    LRN (root); // 40 60 50
    cout << "\n";
    return 0;
}