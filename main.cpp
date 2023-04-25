//Anthony Lim
//1221618450
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "BST.h"
#include <iostream>
#include <vector>
#include "MM.h"
#include <iomanip>

using namespace std;



void Preorder2(TREE* tree, NODE* key, FILE* fp) {
    NODE* x = key;
    if (x!=NULL) {
        fprintf(fp, "%f\n", x->key);
        Preorder2(tree, x->L, fp);
        Preorder2(tree, x->R, fp);
        }
}

int main(int argc, char **argv){
    // TREE* tree = new TREE();
    // Insert(tree, 10);
    // Insert(tree, 5);
    // Insert(tree, 5);
    // Insert(tree, 12);
    // Insert(tree, 12);
    // Maximum(tree);
    // Minimum(tree, tree->root->key);
    // Search(tree, 15);
    // Search(tree, 5);
    // Delete(tree, 5, 1);
    // Search(tree, 10);
    // Postorder(tree, 10, 0);
    // Print();




    FILE *fp;
    float key;
    int returnV;
    char Word[100];
    char Word2[100];
    string input;
    

    if (argc < 2){
        fprintf(stderr, "Usage: %s <flagmm 0 | 1>\n", argv[0]);
        exit(0);
    }


    TREE* tree = new TREE();
    int flag = atoi(argv[1]);

    if (!tree) {
        fprintf(stderr, "Error: calloc failed\n");
        exit(0);
    }
    


    while (1){

        returnV = nextInstruction(Word, &key, Word2);

        if (returnV == 0){
            fprintf(stderr, "Warning: Invalid instruction\n");
            continue;
        }

        if (strcmp(Word, "Read")==0){
            if (tree->size > 0) {
                fprintf(stderr, "Error: reading into non-empty tree");
            }
            else {
                fp = fopen("ifile", "r");
                if (!fp){
                    fprintf(stderr, "Error: cannot open file %s\n", "ifile");
                    continue;
                }
                int i = 0;
                while ( (returnV = fscanf(fp, "%f", &key)) ==1 ) {
                    if (i==0) {
                        i++;
                        continue;
                    }
                    Insert(tree, key, 1);
                }
                std::cout<<"Reading successful\n";

                continue;

            }
            continue;
        }
    

        if (strcmp(Word, "Stop")==0){
            return 0;
        }


        if (strcmp(Word, "InOrder")==0){
            Inorder(tree, tree->root, key);
            continue;
    
        }
        if (strcmp(Word, "PreOrder")==0){
            Preorder(tree, tree->root, Word2);
            continue;   
    
        }
        if (strcmp(Word, "PostOrder")==0){
            Postorder(tree, tree->root, key);
            continue;
    
        }
        if (strcmp(Word, "Maximum")==0){
            Maximum(tree);
            continue;
        }
        if (strcmp(Word, "Minimum")==0){
            NODE* x = Minimum(tree, tree->root->key);
            cout<< "Minimum = " <<fixed << setprecision(6) << x->key << "\n";

            continue;
        }
        if (strcmp(Word, "Search")==0){
            Search(tree, key);
            continue;
        }

        if (strcmp(Word, "Insert")==0){
            Insert(tree, key);
            continue;
        }

        if (strcmp(Word, "Delete")==0){
            Delete(tree, key, flag);
            continue;
        }

        if (strcmp(Word, "PrintList")==0){
            Print(key);
            continue;
        }

        if (strcmp(Word, "Write")==0){
            if (tree != NULL){
                fp = fopen("ofile", "w");
                if (!fp){
                    fprintf(stderr, "Error: cannot open file");
                    exit(0);
                }

                fprintf(fp, "%d\n", tree->size);
                Preorder2(tree, tree->root, fp);
                cout<<"Writing successful\n";
                fclose(fp);
            }
            continue;
        }
    }
    return 1;
}

    //     if (strcmp(Word, "Insert")==0){
    //         Insert(heap, key);
    //         continue;
    //     }


    //     if (strcmp(Word, "ExtractMin")==0){
    //         ExtractMin(heap);
    //         if (x == 1) {
    //             std::cout<<"Number of Heapify calls: "<< heap->heapify_calls << "\n";
    //         }
            
    //         continue;
    //     }


    //     if (strcmp(Word, "DecreaseKey")==0){
    //         DecreaseKey(heap, key, keyTwo);
    //         continue;
    //     }
    // }
    

