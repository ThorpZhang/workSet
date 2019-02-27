#include"2048_alg.h"
namespace ManagementSystemV5 {
	int rand0_n_1(int n)        //产生一个小于n的随机数
	{
		return rand() % n;
	}
	int width(int n)        //数字宽度
	{
		int k;
		for (k = 0; n; n /= 10)
			k++;
		return k;
	}
	
}