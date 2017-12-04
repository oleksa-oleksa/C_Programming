// Created by Oleksandra Baga on 29.11.17.
/* Task: Implement the functions from Standard C Library:
 sigemptyset() - initializes a signal set to be empty.
 sigfillset() - initializes a signal set to contain all signals.
 sigaddset() - adds the specified signal signo to the signal set.
 sigdelset() - deletes the specified signal signo from the signal set.
 sigismember() - returns whether a specified signal signo is contained in
     the signal set.
 There are 32 signals to handle with

 // Remark for myself: There are two ways to initialize a signal set.
 You can initially specify it to be empty with sigemptyset and then add specified signals individually.
 Or you can specify it to be full with sigfillset and then delete specified signals individually.
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "menu.h"
#include "tools.h"

//  The chosen solution: using the BINARY TREE to implement the set in C
typedef struct sigNode_t {
    int signo;
    struct sigNode_t *left;
    struct sigNode_t *right;
} sigNode;

typedef struct {
    sigNode *root;
} tree;

int readSigno();
int my_sigdelset(int signo, tree *t);
int my_sigdelnode(int signo, sigNode *root);
sigNode *getMinNode(sigNode *leaf);
int my_sigismember(int signo, tree *t);
int my_sigisnode(int signo, sigNode *root);
void my_sigfillset(tree *root);
void my_sigemptyset(tree *t);
void my_sigaddset(int signo, tree *t);
void add_node(sigNode *leaf, sigNode *root);
void print_tree(tree *t);


        void print_node(sigNode *root) {
    if(root == NULL){
        return;
    }
    if(root->left){
        print_node(root->left);
    }
    printf("%d\n", root->signo);
    if(root->right){
        print_node(root->right);
    }
}

void print_tree(tree *t) {
    print_node(t->root);
}


void add_node(sigNode *leaf, sigNode *root) {

    while (root != NULL) {
        if (leaf->signo > root->signo)
            if (root->right) {
                root = root->right;
            } else {
                root->right = leaf;
                return;
            }
        else {
            if (root->left) {
                root = root->left;
            } else {
                root->left = leaf;
                return;
            }
        }
    }
}


/* Creates a new tree if necessary
 */
void my_sigaddset(int signo, tree *t) {
    if(t == NULL) {
        return;
    }
    sigNode *n = malloc(sizeof(sigNode));
    n->left=NULL;
    n->right=NULL;
    n->signo = signo;

    if(t->root == NULL) {
        t->root = n;
        puts("New root\n");
    }
    else add_node(n, t->root);
}

void my_sigemptyset(tree *t)
{
    if(t != NULL )
    {
        for(int i = 31; i <= 0; i--){
            my_sigdelnode(i, t->root);
        }
    }
}

void my_sigfillset(tree *root) {
    for(int i = 1; i <= 31; i++){
        my_sigaddset(i, root);
    }
}

int my_sigisnode(int signo, sigNode *root)
{
    while (root != NULL){
        if (signo < root->signo){
            root = root->left;
        }
        if (signo > root->signo){
            root = root->right;
        }
        if (signo == root->signo){
            return 1;
        }
        else
            return 0;

    }
    return 0;
}

int my_sigismember(int signo, tree *t) {
    if (t != NULL && t->root != NULL)
    {
        return my_sigisnode(signo, t->root);
    }
    return 0;
}

sigNode *getMinNode(sigNode *leaf){
    if (leaf == NULL){
        return NULL;
    }
    // if left tree exists - the smallest node is there
    if (leaf->left != NULL){
        return getMinNode(leaf->left);
    }
    else {
        return leaf;
    }

}

int my_sigdelnode(int signo, sigNode *root) {
    if (root == NULL){
        return 0;
    }
    // signai is not supported
    if (root->signo <= 0 || root->signo > 31) {
        return -1;
    }
    while (root != NULL) {
        if (signo < root->signo) {  // data is in the left sub tree.
            root = root->left;
        }
        if (signo > root->signo) {  // data is in the right sub tree.
            root = root->right;
        }
        if (signo == root->signo) {
            // case 1: no children
            if (root->left == NULL && root->right == NULL) {
                free(root);
            }
                // case 2: one child (right)
            else if (root->left == NULL && root->right != NULL) {
                sigNode *temp = root; // save current node as a backup
                root = root->right;
                free(temp);
            }
                // case 3: one child (left)
            else if (root->right == NULL && root->left != NULL) {
                sigNode *temp = root; // save current node as a backup
                root = root->left;
                free(temp);
            }
                // case 4: two children
            else {
                sigNode *minNode = getMinNode(
                        root->right); // find minimal value of right sub tree - new root for a sub-tree
                sigNode *temp = root; // node-to-be-deleted
                root->signo = minNode->signo; // duplicate the node
                free(minNode);
                free(temp);
                return 0;
            }
        }
    }
    return 0;
}

int my_sigdelset(int signo, tree *t){
    if (t == NULL) {
        return 0;
    }
    else {
        return my_sigdelnode(signo, t->root);
    }
}

int readSigno(){
    printf("\nSignal number (1 - 31): \n ");
    int isValid = 0;
    int choice;
    do {
        isValid = scanf("%i", &choice);
        clearBuffer();
        if (choice > 31 || choice <= 0)
        {
            printf("Error: invalid number input. Signal number (1 - 31):\n");
            isValid = 0;
        }
    } while (!isValid);
    return choice;
}

int main() {
    int signo, isInSet;
    clearScreen();
    tree t;
    t.root = NULL;
    int choice;
    char *Menu[] = {"Add all signals to a set",
                    "Add a signal to a set",
                    "Delete all signals from a set",
                    "Delete a signal from a set",
                    "Check if a signal in a set",
                    "Exit"};

    do {
        clearScreen();
        choice = getMenu("Signal Set Management", Menu, 6);
        switch (choice) {
            case 1:
                my_sigfillset(&t);
                printf("Signals 1 - 31 were added in a set.\n");
                waitForEnter();
                break;
            case 2:
                signo = readSigno();
                my_sigaddset(signo, &t);
                printf("Signal %d was added in a set.\n", signo);
                print_tree(&t);
                waitForEnter();
                break;
            case 3:
                //my_sigemptyset(t->root);
                printf("Signal set is empty.\n");
                waitForEnter();
                break;
            case 4:
                signo = readSigno();
                my_sigdelset(signo, &t);
                printf("Signal %d was deleted from a set.\n", signo);
                waitForEnter();
                break;
            case 5:
                signo = readSigno();
                isInSet = my_sigismember(signo, &t);
                if (isInSet){
                    printf("Signal %d is in a set.\n", signo);
                    waitForEnter();
                } else {
                    printf("Signal %d is not presented in a set.\n", signo);
                    waitForEnter();
                }
                break;
            case 6:
                break;
        }

    } while (choice != 6);

    return EXIT_SUCCESS;
}

