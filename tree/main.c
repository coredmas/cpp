#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//srand(time(NULL));
//int r = rand();

struct tree_node {
    int value;
    struct tree_node *left_child;
    struct tree_node *right_child;
};

int create_node_tree(struct tree_node **node_prt, int value) {

    if (node_prt == NULL) {
        return 1;
    }
    if (*node_prt != NULL) {
        return 1;
    }
    *node_prt = malloc(sizeof(struct tree_node));
    if (*node_prt == NULL) {
        return 1;
    }
    (*node_prt)->left_child = NULL;
    (*node_prt)->right_child = NULL;
    (*node_prt)->value = value;
    return 0;
}

void add_node_tree(struct tree_node **node_prt, int value)
{
    if (*node_prt == NULL)
    {
        create_node_tree(node_prt,value);
        return;
    }

    if ((*node_prt)->value < value) {
        add_node_tree(&(*node_prt)->left_child, value);
    }
    if ((*node_prt)->value >= value) {
        add_node_tree(&(*node_prt)->right_child, value);
    }
}

void delete_node_tree(struct tree_node **node_prt)
{
    if (*node_prt != NULL)
    {
        delete_node_tree(&(*node_prt)->left_child);
        delete_node_tree(&(*node_prt)->right_child);
        free(*node_prt);
    }
}


int main() {

    struct tree_node *root = NULL;
    create_node_tree(&root,50);
    add_node_tree(&root,30);
    add_node_tree(&root,20);
    add_node_tree(&root,40);
    add_node_tree(&root,70);
    add_node_tree(&root,60);
    add_node_tree(&root,80);
    delete_node_tree(&root);
    return 0;
}