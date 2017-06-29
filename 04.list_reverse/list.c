
#include <stdio.h> //printf where .h
#include <stddef.h>

//typedef struct
//{
//    char x;
//    struct List_ptr * next;
//}List_ptr;
//
typedef int element_type;  
typedef struct node *node_ptr;  
  
struct node {  
element_type element;  
node_ptr next;  
};

void list_reverse(node_ptr L)  
{  
    if (L->next == NULL) return;  
    node_ptr p = L->next, first = L->next;  
    while (p != NULL && p->next != NULL) {  
           node_ptr next_node = p->next;  
           p->next = next_node->next;  
           next_node->next = first;  
           first = next_node;  
        }  
    L->next = first;  
}
#if 1
/* straight select sort */
int main(void)
{

//    int i = 0, n = 7;
//    int str_one[5]={116,103,105,120,120};
//    int str_two[7]={4,5,1,2,3,5,2};
//    SelectSort(str_two,7); 
//    for(i = 0;i < n; i++)
//    {
//        printf("this is test for buble sort the out is: %d\r\n",str_two[i]);
//    }
//    printf("This is lynn test for strcpy the out is : %s\r\n",str_one); 
    return 0;
}
#endif


