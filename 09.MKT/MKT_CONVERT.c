#include<math.h> 
#include <assert.h> //assert where .h
#include <stddef.h> //NULL where .h
#include <stdio.h> //printf where .h

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
#define Rm 8.314472   //kj/kmol.k 通用气体常数（不变）
#define H_t 60  //活化能量（不同介质有区别）

/**---------------------------------------------------------------------------------
  * @brief       MTK_CONVERT函数.
  * @param    	 item：温度数据缓存，EACH_TIME:采样间隔时间单位s，ALL_TIME:采样总时间.
  *	@arg         NULL
  * @retval      该阶段计算MKT值.
  * @author      lynn
  ---------------------------------------------------------------------------------*/
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
    double  test_num = MTK_CONVERT(tem_mark ,1,180);
    printf("%f\n",test_num); 
    return 0;  
} 
/*********************************************END OF FILE**********************/
