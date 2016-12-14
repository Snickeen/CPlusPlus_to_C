#include<stdio.h>

/************************************************************/
//代码6-1 计算1-n之和的循环函数和递归函数

//必要条件：n>=1
//结果：返回1-n的和
int sum(int n){
	int ret=0,i;
	for(i=1;i<=n;i++)
		ret+=i;
	return ret; 
} 

//必要条件：n>=1
//结果：返回1-n的和
int recursiveSum(int n){
	if(n==1) return 1;//不可继续分解时
	return n+recursiveSum(n-1); 
}
/************************************************************/

int main()
{
	int i,j,k,l;
	int n;
	while(~scanf("%d",&n)){
		printf("%d %d\n",sum(n),recursiveSum(n));
	}
	return 0;
}
