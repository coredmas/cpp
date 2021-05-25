#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};

struct queue
{
    struct node* head;
    struct node* tail;
    int size;
};

void create_queue(struct queue** queue_ptr)
{
    if(queue_ptr == NULL)
    {
        return;
    }
    if(*queue_ptr != NULL)
    {
        return;
    }
    *queue_ptr = malloc(sizeof(struct queue));
    if(*queue_ptr == NULL)
    {
        return;
    }
    (*queue_ptr)->head = NULL;
    (*queue_ptr)->tail = NULL;
    (*queue_ptr)->size = 0;
}

void add_node_queue(struct queue** queue_ptr,int val)
{
    if(queue_ptr == NULL)
    {
        return;
    }
    if(*queue_ptr == NULL)
    {
        return;
    }
    struct node* new_node = malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        return;
    }
    memset(new_node,0,sizeof(struct node));
    new_node->data = val;
    if((*queue_ptr)->head == NULL && (*queue_ptr)->tail == NULL)
    {

        (*queue_ptr)->head = new_node;
        (*queue_ptr)->tail = new_node;
        (*queue_ptr)->size++;
    }
    else
    {
        new_node->prev = (*queue_ptr)->tail;
        (*queue_ptr)->tail->next = new_node;
        (*queue_ptr)->tail = new_node;
        (*queue_ptr)->size++;
    }
}

void del_queue(struct queue** queue_ptr)
{
    if(queue_ptr == NULL)
    {
        return;
    }
    if(*queue_ptr == NULL)
    {
        return;
    }
    struct node* current_node = (*queue_ptr)->head;
    while(current_node != NULL){
        struct node* freed_node = current_node;
        current_node = current_node->next;
        free(freed_node);
    }
    free(*queue_ptr);
}

void print_queue(struct queue** queue_ptr)
{
    if(queue_ptr == NULL)
    {
        return;
    }
    if(*queue_ptr == NULL)
    {
        return;
    }
    printf("******************************** print_queue\n");
    struct node* current_node = (*queue_ptr)->head;
    while(current_node != NULL){
        printf("value %d\n",current_node->data);
        current_node = current_node->next;
    }
    printf("********************************\n");
}

void print2_queue(struct queue** queue_ptr)
{
    if(queue_ptr == NULL)
    {
        return;
    }
    if(*queue_ptr == NULL)
    {
        return;
    }
    printf("******************************** print2_queue\n");
    struct node* current_node = (*queue_ptr)->tail;
    while(current_node != NULL){
        printf("value %d\n",current_node->data);
        current_node = current_node->prev;
    }
    printf("********************************\n");
}

int main() {
    struct queue* queue_ptr = NULL;
    create_queue(&queue_ptr);
    add_node_queue(&queue_ptr,10);
    add_node_queue(&queue_ptr,20);
    add_node_queue(&queue_ptr,30);
    add_node_queue(&queue_ptr,40);
    add_node_queue(&queue_ptr,50);
    print2_queue(&queue_ptr);
    del_queue(&queue_ptr);
    return 0;
}
