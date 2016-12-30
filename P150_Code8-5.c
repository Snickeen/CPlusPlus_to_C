#include<stdio.h>
#include<string.h> 

int t,m,ans; 

/***************************************************************/
//代码8-5 解决跳跃游戏的动态规划算法 

int n,board[105][105];
int cache[105][105],CACHE; 
int jump2(int y,int x){
	//处理初始部分
	if(y>=n||x>=n) return 0;
	if(y==n-1&&x==n-1) return 1;
	//制表
	//应用是C++里面的，C中用指针，后面的也都用指针形式 
	int *ret=&cache[y][x];
	if(*ret!=CACHE);
	int jumpSize=board[y][x];
	return *ret=( jump2(y+jumpSize,x)||jump2(y,x+jumpSize) );
	
	/*//或者如下所写 
	if(cache[y][x]!=CACHE);
	int jumpSize=board[y][x];
	return cache[y][x]=( jump2(y+jumpSize,x)||jump2(y,x+jumpSize) );
	*/
}
/***************************************************************/ 

int main()
{
	int i,j,k,l; 
	
	while(~scanf("%d",&n)){
		//初始化为-1 
		memset(cache,-1,sizeof(cache));
		CACHE=cache[0][0];//这里用一个变量CACHE来代替-1，可以减少一些麻烦 
		
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&board[i][j]);
		ans=jump2(0,0);
		puts(ans?"YES":"NO");
	}
	return 0;
}

/*
7
2 5 1 6 1 4 1
6 1 1 2 2 9 3 
7 2 3 2 1 3 1
1 1 3 1 7 1 2
4 1 2 3 4 1 2
3 3 1 2 3 4 1
1 5 2 9 4 7 0
//Answer// 
YES

7
2 5 1 6 1 4 1
6 1 1 2 2 9 3 
7 2 3 2 1 3 1
1 1 3 1 7 1 2
4 1 2 3 4 1 3
3 3 1 2 3 4 1
1 5 2 9 4 7 0
//Answer// 
NO

*/
