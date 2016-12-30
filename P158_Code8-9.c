#include<stdio.h>
#include<string.h> 

int t,m,ans; 

/***************************************************************/
//代码8-9 解决三角形的最大路径问题的动态规划算法(2) O(n^2)

int n,triangle[111][111];
int cache2[111][111],CACHE;
//返回从(y,x)起始到最底部路径的最大值
int path2(int y,int x){
	//初始部分
	if(y==n-1) return triangle[y][x];
	//制表
	int *ret=&cache2[y][x];
	if(*ret != CACHE) return *ret;
	//取个最大值 
	int tmp1=path2(y+1,x);
	int tmp2=path2(y+1,x+1);
	tmp1=( tmp1>tmp2 ? tmp1 : tmp2 ); 
	return *ret = tmp1+triangle[y][x];
} 

/***************************************************************/ 

void solve(){
	int i,j,k,l;
	memset(cache2,-1,sizeof(cache2));
	CACHE=cache2[0][0];
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<=i;j++)
			scanf("%d",&triangle[i][j]);
	ans=path2(0,0);
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
2

5
6
1 2
3 7 4
9 4 1 7
2 7 5 9 4

5
1
2 4
8 16 8
32 64 32 64
128 256 128 256 128

//Answer //
28
341
 
*/
