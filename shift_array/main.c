#include <stdio.h>

void shift_array_right_on_one(int *arr,int length){

    int last_elem = arr[length-1];
    for(int i = 1;i < length;i++){
        int tmp =  arr[i];
        arr[i] = arr[0] ;
        arr[0] = tmp;
    }
    arr[0] = last_elem;
}
void print_array(int *arr,int length){
    for(int i = 0;i<length;i++){
        printf("elem %d \n",arr[i]);
    }
}
int main() {

    int array[] = {1,2,3,4,5,6,7,8,9,10};
    printf("******************case0 before \n");
    print_array(array,10);
    printf("******************  \n");
    printf("******************case0 after\n");
    shift_array_right_on_one(array,10);
    print_array(array,10);
    printf("******************  \n");

    printf("******************case1 before \n");
    print_array(array,10);
    printf("******************  \n");
    printf("******************case1 after\n");
    for(int i = 0 ;i < 110; i++){
        shift_array_right_on_one(array,10);
    }

    print_array(array,10);
    printf("******************  \n");

    return 0;
}
