#include<stdio.h> 
#include<string.h> 
#include<malloc.h>
 
int t,n,m,ans; 

/***************************************************************/
//代码8-16 计算覆盖方法个数的动态规划算法 

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

/***************************************************************/ 

void solve(){
	int i,j,k,l,s;
	
	memset(cache,-1,sizeof(cache));
	CACHE=cache[0];
	
	scanf("%d",&n);
	ans=tiling(n);
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

//Answer //

*/
