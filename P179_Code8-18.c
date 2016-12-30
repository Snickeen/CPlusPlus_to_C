#include<stdio.h>
#include<string.h> 
#include<math.h>

int t,ans; 

/***************************************************************/
//代码8-18 解决爬出水井的蜗牛问题的动态规划算法 

int n,m; 
int cache[111][222],CACHE;
//假设蜗牛在days天时间内爬行了climbed米
//第m日之前能够爬行n米的所有组合个数 
int climb(int days,int climbed){
	//初始部分：已过了m天 
	if(days==m) return climbed>=n?1:0;
	//制表
	int *ret=&cache[days][climbed];
	if(*ret != CACHE) return *ret;
	return *ret=climb(days+1,climbed+1)+climb(days+1,climbed+2);
} 

/***************************************************************/ 


void solve(){
	int i,j,k,l;
	memset(cache,-1,sizeof(cache));
	CACHE=cache[0][0];
	
	scanf("%d%d",&n,&m);
	ans=climb(0,0);
	printf("%d %lf\n",ans,1.0*ans/pow(2.0,m));
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
