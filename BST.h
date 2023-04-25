//Anthony Lim
//1221618450
#ifndef _BST_h
#define _BST_h 1
#include "data_structures.h"
#include <vector>

void Maximum(TREE* tree);
void Insert(TREE* tree, float key);
void Insert(TREE* tree, float key, int test);
NODE* Minimum(TREE* tree, float key);
NODE* Search(TREE* tree, float key);
NODE* Search(TREE* tree, float key, int test);
void Transplant(TREE* tree, NODE* x, NODE* y);
void Delete(TREE* tree, float key, int flag);
void Inorder(TREE* tree, NODE* x, int flag);
void Preorder(TREE* tree, NODE* x, char* flag);
void Postorder(TREE* tree, NODE* x, int flag);


#endif
