#include<stdio.h> 
#include<string.h> 
#include<malloc.h>
 
int t,n,m,ans; 

/**********下面是被调用的代码8-16 计算覆盖方法个数的动态规划算法 ******************/

int MOD=1e9+7;
int cache[111],CACHE;
//把覆盖2*width大小的长方形的方法数除以MOD后，返回其余数 
int tiling(int width){
	//初始部分：width小于1时 
	if(width<=1)return 1;
	//制表 
	int* ret=&cache[width];
	if(*ret!=CACHE)return *ret;
	return *ret=(tiling(width-2)+tiling(width-1))%MOD;
}
/**********上面是被调用的代码8-16 计算覆盖方法个数的动态规划算法 ******************/



/***************************************************************/ 
//代码8-19 解决非对称铺设问题的动态规划算法

//返回对2*width长方形进行非对称铺设的方法总数 
int asymmetric(int width){
	if(width%2==1)
		return (tiling(width)-tiling(width/2)+MOD)%MOD;
	int ret=tiling(width);
	ret=(ret-tiling(width/2)+MOD)%MOD;
	ret=(ret-tiling(width/2-1)+MOD)%MOD;
	return ret;
} 
/***************************************************************/ 


void solve(){
	int i,j,k,l,s;
	
	memset(cache,-1,sizeof(cache));
	CACHE=cache[0];
	
	scanf("%d",&n);
	ans=asymmetric(n);
	printf("%d\n",ans);
}

int main()
{
	scanf("%d",&t);
	while(t--) 
		solve();
	return 0;
}

/*
8
5
8
17
39
65
2
4
92

//Answer //
6
26
2550
102327390
886316271
0
2
913227494
*/
