#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node * next;
};

struct stack
{
    struct node * top;
    int size;
};

int create_stack(struct stack** stack_ptr)
{
    if(stack_ptr == NULL)
    {
        return 1;
    }
    if(*stack_ptr != NULL)
    {
        return 1;
    }
    *stack_ptr = malloc(sizeof(struct stack));
    if(*stack_ptr == NULL)
    {
        return 2;
    }
    (*stack_ptr)->top = NULL;
    (*stack_ptr)->size = 0;
    return 0;
}

int push_stack(struct stack** stack_ptr,int data)
{
    if(stack_ptr == NULL)
    {
        return 1;
    }
    if(*stack_ptr == NULL)
    {
        return 1;
    }
    struct node* new_node = malloc(sizeof(struct node));
    if(new_node == NULL){
        return 2;
    }
    new_node->data = data;
    new_node->next = NULL;

    if((*stack_ptr)->top == NULL){
        (*stack_ptr)->top = new_node;
    }else{
        new_node->next = (*stack_ptr)->top;
        (*stack_ptr)->top = new_node;
    }
    (*stack_ptr)->size++;
    return 0;
}

int pop_stack(struct stack** stack_ptr,int* data){
    if(stack_ptr == NULL){
        return 1;
    }
    if(*stack_ptr == NULL){
        return 1;
    }
    if(data == NULL){
        return 1;
    }
    if((*stack_ptr)->top == NULL){
        return 1;
    }else{
        *data =  (*stack_ptr)->top->data;
        struct node* delete_node = (*stack_ptr)->top;
        (*stack_ptr)->top = (*stack_ptr)->top->next;
        free(delete_node);
    }
    (*stack_ptr)->size++;
    return 0;
}

int main() {
    struct node* stack_ptr = NULL;
    create_stack(&stack_ptr);
    push_stack(&stack_ptr,5);
    push_stack(&stack_ptr,6);
    push_stack(&stack_ptr,7);
    push_stack(&stack_ptr,8);
    int data = 0;
    pop_stack(&stack_ptr,&data);
    printf("current data %d\n",data);
    pop_stack(&stack_ptr,&data);
    printf("current data %d\n",data);
    pop_stack(&stack_ptr,&data);
    printf("current data %d\n",data);
    pop_stack(&stack_ptr,&data);
    printf("current data %d\n",data);
    pop_stack(&stack_ptr,&data);
    printf("current data %d\n",data);
    free(stack_ptr);
    return 0;
}
