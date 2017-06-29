#include"List.h"  
#include<stdlib.h> 
#include<stdio.h>


int main()  
{  
    List list=NULL;  
    Position p;   
    int i;  
    list = MakeEmpty(list);  
    printf("已生成空链表list\n");  
    if(IsEmpty(list))  
    printf("经检验list是个空链表\n");  
//    int **point;
    p = list;  
    for(i=10;i>0;i--)  
    {  
           Insert(i,list,p);       
           p = Advance(p);  
           printf("已插入的值为%d新节点,addr:%p\n",Retrieve(p),p);  
        } 


//    p = FindNow(9,list);  
//    printf("数据项为9的节点数据项值为%d\n",Retrieve(p));  
//      
//    p = FindPrevious(9,list);  
//    printf("数据项为9的节点前驱的数据项值为%d\n",Retrieve(p));  
//  
//    Delete(9,list);  
      
//    p = list;  
//    for(i=0;i<4;i++)  
//    {     
//           p = Advance(p);  
//           printf("删除数据项为9的节点剩下的节点值为%d\n",Retrieve(p));  
//        } 
    printf("test start\n");
    List_Reverse(list);
    p = list; 
   printf("----------------p:%p\n",p);
//       printf("-------反转后的节点值为%d,addr:%p\n",Retrieve(p),p);  
    for(i=0;i<12;i++)  
    {     
          
         printf("反转后的节点值为%d,addr:%p\n",Retrieve(p),p); 
         p = Advance(p);  
        }    
    DeleteList(list);  
    printf("已删除链表list的所以数据节点\n");  
    if(IsEmpty(list))  
    printf("经检验list是个空链表\n");  
  
}
