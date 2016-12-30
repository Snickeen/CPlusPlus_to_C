#include<stdio.h>
#include<string.h> 

int t,n,m,ans; 

/***************************************************************/
//代码8-2 利用制表计算二项式系数

//初始化-1
int cache[30][30],CACHE; 
int bino2(int n,int r){
	//初始部分：n==r(选择完所有元素的情况) 或 r=0(没有可选元素的情况)
	if(r==0 || n==r) return 1;
	//如果不是-1，则说明这个值是之前已计算过的结果值，直接返回
	//这里用CACHE代替-1 
	if(cache[n][r]!=CACHE)
		return cache[n][r];
	//直接计算并保存到数组 
	return cache[n][r]=bino2(n-1,r-1)+bino2(n-1,r); 
}
/***************************************************************/ 

int main()
{
	int n,r;
	//初始化为-1 
	memset(cache,-1,sizeof(cache));
	CACHE=cache[0][0];//这里用一个变量CACHE来代替-1，可以减少一些麻烦 
	
	while(~scanf("%d%d",&n,&r)){
		printf("%d\n",bino2(n,r));
	}
	return 0;
}
