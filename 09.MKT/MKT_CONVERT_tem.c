#include<stdio.h>  
//#include<algorithm.h>  
#include<math.h> 
#include <assert.h> //assert where .h
#include <stddef.h> //NULL where .h
#include <stdio.h> //printf where .h
#include <malloc.h>
//using namespace std;  

#define N 180
double tem_mark[N]={
20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,
30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,
30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,
40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,
40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,
40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40
};

//#define E_double 2.718281
#define Rm 8.314472   //kj/kmol.k
#define H_t 60
#if 0
double MTK_CONVERT(double *item,int EACH_TIME,int ALL_TIME)
{
    assert(item != NULL);
    double MTK_NUM;
    double *tem_buf = (double *)malloc(sizeof(item));
    double *tem_add = tem_buf; 
    assert(tem_buf != NULL);
    while(*tem_buf++ = *item++);

//    printf("this is tem_add:%f\n",*tem_add);
    const double DEN_NUM = -H_t/Rm;
    printf("%f\n",DEN_NUM); 
    printf("%ld\n",sizeof(item)); 

//    const double 
//    double DAT_SUM = 
    return MTK_NUM;
}
#endif

double MTK_CONVERT(double item[],int EACH_TIME,int ALL_TIME)
{
    assert(item != NULL);
    double MTK_NUM;
    const double DEN_NUM = -H_t/Rm;
    double TEM_SUM;
    for(int i = 0; i < ALL_TIME/EACH_TIME; i ++)
    {
        TEM_SUM += EACH_TIME*exp(DEN_NUM/item[i]); 
    }
    MTK_NUM = DEN_NUM/log(TEM_SUM/ALL_TIME);

    return MTK_NUM;
}

int main()  
{ 

//    double result;
//    double x = 800.6872;   
//    result = log10(x);
//    result = log10(10);
//    printf("The common log of %lf is %lf\n", x, result); 

    double  test_num = exp(1);
//    double test_buf = log10(test_num); 
//    printf("%f\n",log(10));  
//    printf("%f\n",log(E_double));  
//    printf("%f\n",log10(10));  
    printf("%f\n",test_num);  
    printf("%f\n",log(test_num));  
//    printf("%f\n",log10(0.1)); 
    exp(1);

    double  test_num1 = MTK_CONVERT(tem_mark ,1,180);
    printf("%f\n",test_num1); 
    return 0;  
}  
