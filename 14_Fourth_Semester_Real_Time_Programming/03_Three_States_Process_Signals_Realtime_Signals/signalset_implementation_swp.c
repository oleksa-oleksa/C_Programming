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

typedef struct tree_t {
    sigNode *node;
} tree;

tree *root = NULL;

void print(tree *root) {
  puts("A");
  if(root == NULL) return;
    if(root->left) print(root->left);
    printf("%d\n", root->signo);
    if(root->right) print(root->right);
}


/* Creates a new tree if necessary
 */
void my_sigaddset(int new_signo, tree *root) {
    if(root == NULL)
    {
        root = malloc(sizeof(sigNode));
        root->node->signo = new_signo;
        /* initialize the children to null */
        root->node->left = NULL;
        root->node->right = NULL;
    }
    else if(new_signo < root->node->signo)
    {
        my_sigaddset(new_signo, root->node->left);
    }
    else if(new_signo > root->node->signo)
    {
        my_sigaddset(new_signo, root->node->right);
    }
}

void my_sigemptyset(tree *root)
{
    if(root != NULL )
    {
        my_sigemptyset(root->node->left);
        my_sigemptyset(root->node->right);
        free(root);
    }
}

sigNode *my_sigfillset(tree *root){
    for(int i = 1; i <= 31; i++){
        my_sigaddset(i, root);
    }
    return root;
}

int my_sigismember(int new_signo, tree *root)
{
    if(root != NULL)
    {
        if(new_signo == root->node->signo)
        {
            return 1;
        }
        else if(new_signo < root->node->signo)
        {
            return my_sigismember(new_signo, root->node->left);
        }
        else
        {
            return my_sigismember(new_signo, root->node->right);
        }
    }
    else return 0;
}

sigNode *getMinNode(tree *root){
    if (root == NULL){
        return NULL;
    }
    // if left tree exists - the smallest node is there
    if (root->node->left != NULL){
        return getMinNode(root->node->left);
    }
    else {
        return root;
    }

}

int my_sigdelset(int del_signo, tree *root){
    if (root == NULL) {
        return 0;
    }
    // signai is not supported
    if (root->node->signo <= 0 || root->node->signo > 31) {
        return -1;
    }
    if (leaf != NULL){
        if (del_signo < root->node->signo) {  // data is in the left sub tree.
            my_sigdelset(del_signo, root->node->left);
        } else if (del_signo > root->node->signo) { // data is in the right sub tree.
            my_sigdelset(del_signo, root->node->right );
        } else {
            // case 1: no children
            if (root->node->left == NULL && root->node->right == NULL) {
                free(root); // wipe out the memory, in C, use free function
            }
            // case 2: one child (right)
            else if (root->node->left == NULL && root->node->right != NULL) {
                sigNode *temp = root; // save current node as a backup
                root = root->node->right;
                free(temp);
            }
            // case 3: one child (left)
            else if (root->node->right == NULL && root->node->left != NULL) {
                sigNode *temp = root; // save current node as a backup
                root = root->node->left;
                free(temp);
            }
            // case 4: two children
            else {
                sigNode *minNode = getMinNode(root->node->right); // find minimal value of right sub tree - new root for a sub-tree
                sigNode *temp = root; // node-to-be-deleted
                root->node->signo = minNode->signo; // duplicate the node
                free(minNode);
                free(temp);
                return 0;
            }
        }
    }
    return 0;
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
                root = my_sigfillset(root);
                printf("Signals 1 - 31 were added in a set.\n");
                waitForEnter();
                break;
            case 2:
                signo = readSigno();
                my_sigaddset(signo, root);
                printf("Signal %d was added in a set.\n", signo);
                print(root);
                waitForEnter();
                break;
            case 3:
                my_sigemptyset(root);
                printf("Signal set is empty.\n");
                waitForEnter();
                break;
            case 4:
                signo = readSigno();
                my_sigdelset(signo, root);
                printf("Signal %d was deleted from a set.\n", signo);
                waitForEnter();
                break;
            case 5:
                signo = readSigno();
                isInSet = my_sigismember(signo, root);
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

