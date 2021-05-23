#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void create_list(struct node** head_ptr, int sz){
    int pos = 0;
    if(head_ptr == NULL)
    {
        return;
    }
    if(*head_ptr != NULL)
    {
        return;
    }

    struct node *current_node = NULL;
    while(pos < sz)
    {
        if(pos == 0){
            *head_ptr = malloc(sizeof(struct node));
            if (*head_ptr == NULL)
            {
                return;
            }
            (*head_ptr)->next = NULL;
            (*head_ptr)->data = 0;
            pos++;
            current_node = *head_ptr;
            continue;
        }
        current_node->next = malloc(sizeof(struct node));
        if(current_node->next == NULL)
        {
            return;
        }
        current_node = current_node->next;
        current_node->next = NULL;
        current_node->data = pos;
        pos++;
    }
}

void delete_list(struct node** head_ptr){
    struct node *current_node = *head_ptr;
    struct node *node_to_free = NULL;
    while (current_node != NULL)
    {
        node_to_free = current_node;
        current_node = current_node->next;
        free(node_to_free);
        node_to_free = NULL;
    }
}

void print_list(struct node* head){
    struct node *current_node = head;
    while (current_node != NULL)
    {
        printf("data %d\n",  current_node->data);
        current_node = current_node->next;
    }
}

void delete_node_by_value_list(struct node** head_ptr,int del_value){

    struct node *current_node = *head_ptr;
    struct node *prev_node = NULL;
    while (current_node != NULL)
    {
        if(current_node->data == del_value){
            struct node *tmp_node = current_node->next;
            if(prev_node != NULL){
                prev_node->next = tmp_node;
            }
            if(*head_ptr == current_node){
                *head_ptr = tmp_node;
            }
            free(current_node);
            current_node = tmp_node;
            continue;
        }
        prev_node = current_node;
        current_node = current_node->next;
    }
}

void add_node_by_value_list(struct node** head_ptr,int add_value){

    struct node *current_node = *head_ptr;
    struct node *prev_node = NULL;
    while (current_node != NULL)
    {
        if(current_node->data >= add_value){
            struct node *add_node = malloc(sizeof( struct node));
            add_node->next = current_node;
            add_node->data = add_value;
            if(prev_node != NULL){
                prev_node->next = add_node;
            }
            if(*head_ptr == current_node){
                *head_ptr = add_node;
            }
            return;
        }
        prev_node = current_node;
        current_node = current_node->next;
    }

    struct node *add_node = malloc(sizeof( struct node));
    add_node->next = NULL;
    add_node->data = add_value;
    prev_node->next = add_node;
    return;
}

int main() {
    struct node* head = NULL;
    create_list (&head,10);
    printf("*********************************create_list size 10\n");
    print_list(head);

    delete_node_by_value_list(&head,7);
    printf("*********************************delete_node_by_value_list 7\n");
    print_list(head);

    delete_node_by_value_list(&head,0);
    printf("*********************************delete_node_by_value_list 0\n");
    print_list(head);

    delete_node_by_value_list(&head,9);
    printf("*********************************delete_node_by_value_list 9\n");
    print_list(head);

    add_node_by_value_list(&head,10);
    printf("*********************************add_node_by_value_list 10\n");
    print_list(head);

    add_node_by_value_list(&head,-1);
    printf("*********************************add_node_by_value_list -1\n");
    print_list(head);

    add_node_by_value_list(&head,4);
    printf("*********************************add_node_by_value_list 4\n");
    print_list(head);

    delete_list(&head);
    printf("*********************************delete_list\n");
}