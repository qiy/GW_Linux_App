#include <assert.h> //assert where .h
#include <stddef.h> //NULL where .h
#include <stdio.h> //printf where .h
char *strcpy(char* Strest,const char* Strbuf)
{
    assert( (Strest != NULL) && (Strbuf != NULL) );  //it is possible to put the first sentence of the function;
    char* address = Strest;
    while(*Strest++ = *Strbuf++);
    return address;
}

int main(void)
{
    char str_one[50];
    char* buf_two = " will be OK";
//    char str_three[10];
//    scanf("%s",str_three);
      char* address =  strcpy(str_one,buf_two);
//    char* address = strcpy(str_one,str_three);
    printf("This is lynn test for strcpy the out is : %s\r\n",address); 
    return 0;
}
