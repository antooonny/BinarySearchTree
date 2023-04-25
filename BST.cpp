//Anthony Lim
//1221618450
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "BST.h"
#include <iomanip>
#include "MM.h"
using namespace std;



void Maximum(TREE* tree) {
    NODE* x = tree->root;
    while (x!=NULL && x->R!=NULL) {
        x = x->R;
    }
    cout<< "Maximum = " << fixed << setprecision(6) << x->key << "\n";
}

NODE* Minimum(TREE* tree, float key) {
    NODE* x = Search(tree, key, 1);
    while (x!=NULL && x->L!=NULL) {
        x = x->L;
    }
    return x;

}

void Insert(TREE* tree, float key) {
    
    NODE* newNode = new NODE();
    newNode->key = key;
    newNode->P = NULL;
    newNode->L = NULL;
    newNode->R = NULL;

    NODE* y = NULL;
    NODE* x = tree->root;

    while (x!=NULL) {
        y=x;
        if (newNode->key < x->key) {
            x = x->L;
        }
        else {
            x = x->R;
        }
    }

    newNode->P = y;
    if (y == NULL) {
        tree->root = newNode;
        cout <<  fixed << setprecision(6) <<key <<" inserted\n";
        tree->size++;
        if (!isEmpty()) {
        EraseFront();
    }
    }

    else if (newNode->key == y->key) {
        cout <<  fixed << setprecision(6) <<key <<" already in tree, no insertion\n";
    }

    else if (newNode->key < y->key) {
        y->L = newNode;
        cout <<  fixed << setprecision(6) <<key <<" inserted\n";
        tree->size++;
        if (!isEmpty()) {
        EraseFront();
    }
    }

    else {
        y->R = newNode;
        cout <<  fixed << setprecision(6) <<key <<" inserted\n";
        tree->size++;
        if (!isEmpty()) {
        EraseFront();
    }
    }
}

void Insert(TREE* tree, float key, int nothing) {
    
    NODE* newNode = new NODE();
    newNode->key = key;
    newNode->P = NULL;
    newNode->L = NULL;
    newNode->R = NULL;

    NODE* y = NULL;
    NODE* x = tree->root;

    while (x!=NULL) {
        y=x;
        if (newNode->key < x->key) {
            x = x->L;
        }
        else {
            x = x->R;
        }
    }

    newNode->P = y;
    if (y == NULL) {
        tree->root = newNode;
        tree->size++;
    }

    else if (newNode->key == y->key) {
    }

    else if (newNode->key < y->key) {
        y->L = newNode;
        tree->size++;
    }

    else {
        y->R = newNode;
        tree->size++;
    }
}

NODE* Search(TREE* tree, float key) {
    NODE* x = tree->root;
    while (x!=NULL) {
        if (key < x->key) {
            x = x->L;
        }
        else if (key > x->key) {
            x = x->R;
        }

        else {
            cout<< key << fixed << setprecision(6) <<" found\n";
            return x;
        }
    }

    cout << key << fixed << setprecision(6) <<" not found\n";
    return NULL;
     
}
NODE* Search(TREE* tree, float key, int test) {
    NODE* x = tree->root;
    while (x!=NULL) {
        if (key < x->key) {
            x = x->L;
        }
        else if (key > x->key) {
            x = x->R;
        }

        else {
            return x;
        }
    }

    return NULL;
     
}

void Transplant(TREE* tree, NODE* x, NODE* y) {
    if (x->P == NULL) {
        tree->root = y;
    }
    else if (x == x->P->L) {
        x->P->L = y;
    }
    else {
        x->P->R = y;
    }
    if (y != NULL) {
        y->P = x->P;
    }
}

void Delete(TREE* tree, float key, int flag) {

    NODE* delNode = Search(tree, key, 1);

    if (delNode == NULL) {

        cout << key <<fixed << setprecision(6) << " not in tree, no deletion\n";
        return;

    }
    else {

        if (delNode->L == NULL) {
            Transplant(tree, delNode, delNode->R);
        } 
        else if (delNode->R == NULL) {
            Transplant(tree, delNode, delNode->L);
        }
        else {
            NODE* y = Minimum(tree, delNode->R->key);
            if (y->P != delNode) {
                Transplant(tree, y, y->R);
                y->R = delNode->R;
                y->R->P = y;

            }
            Transplant(tree, delNode, y);
            y->L = delNode->L;
            y->L->P = y;
        }
        if (flag == 1) {
            Push(delNode);
        }
        cout <<  fixed << setprecision(6) << key <<" deleted\n";
        tree->size--;
    }

    
}


void Inorder(TREE* tree, NODE* node, int flag) {
    NODE* x = node;
    if (x!=NULL) {
        Inorder(tree, x->L, flag);
        cout <<fixed << setprecision(6) << x->key << "\n";
        Inorder(tree, x->R, flag);
    }
    else if (flag==1) {
        cout<<"NULL\n";
        return;
    }

}


void Preorder(TREE* tree, NODE* node, char *flag) {
    NODE* x = node;
    if (x!=NULL) {
        cout << fixed << setprecision(6) << x->key << "\n";
        Preorder(tree, x->L, flag);
        Preorder(tree, x->R, flag);
    }
    else if (strcmp(flag, "1")==0) {
        cout<<"NULL\n";
        return;
    }
}



void Postorder(TREE* tree, NODE* node, int flag) {
    NODE* x = node;
    if (x!=NULL) {
        Postorder(tree, x->L, flag);
        Postorder(tree, x->R, flag);
        cout << fixed << setprecision(6) <<x->key << "\n";
    }
    else if (flag==1) {
        cout<<"NULL\n";
        return;
    }
}


