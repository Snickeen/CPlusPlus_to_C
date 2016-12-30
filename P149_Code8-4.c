#include<stdio.h>
#include<string.h> 

int t,ans; 

/***************************************************************/
//代码8-4 跳跃游戏的递归调用算法 

int n,board[105][105]; 
int jump(int y,int x){
	//初始部分：超出棋盘边界的情况
	if(y>=n||x>=n) return 0;
	//初始部分：到达终点的情况
	if(y==n-1&&x==n-1) return 1;
	int jumpSize=board[y][x];
	return jump(y+jumpSize,x)||jump(y,x+jumpSize); 
}

/***************************************************************/ 

int main()
{
	int i,j,k,l;
	while(~scanf("%d",&n)){
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&board[i][j]);
		ans=jump(0,0);
		puts(ans?"YES":"NO");
	}
	return 0;
}
