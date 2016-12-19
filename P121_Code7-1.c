#include<stdio.h>
 
/***************************************************************/
//代码7-1 利用分治算法求1-n之和 

//必要条件：n为正整数 
//返回1+2+3+...+n的和 
int fastSum(int n){
	//初始部分 
	if(1==n)return 1;
	if(n%2==1)return fastSum(n-1)+n;
	else return 2*fastSum(n/2)+(n/2)*(n/2);
}

/***************************************************************/ 

int main()
{
	int n,answer;
	while(~scanf("%d",&n)){//输入大于0的正整数 
		answer=fastSum(n);
		printf("%d\n",answer); 
	}
	return 0;
}
