#include<stdio.h>

int taken[10];
/***************************************************************/
//代码6-5 解决郊游问题的递归调用代码

int n,m;
int areFriends[10][10];
//若第taken[i]=i个学生找到了伙伴，则返回1，否则返回0 
int CountPairings(int taken[]){
	//在剩余学生中查找序号最靠前的学生
	int i,j,k,l;
	int firstFree=-1;
	for(i=0;i<n;i++){
		if(!taken[i]){
			firstFree=i;
			break;
		}
	}
	//初始部分：所有学生都找到了伙伴，那么已找到1种组合方式，故终止。
	if(-1 == firstFree) return 1;
	int ret=0;
	//选择与此学生组队的伙伴 
	int pairWith;
	for(pairWith=firstFree+1;pairWith<n;pairWith++){
		if(!taken[pairWith] &&areFriends[firstFree][pairWith]){
			taken[firstFree]=taken[pairWith]=1;
			ret+=CountPairings(taken); 
			taken[firstFree]=taken[pairWith]=0;
		}
	} 
	return ret;
}

/***************************************************************/ 

int main()
{
	int i,j,k,l,C;
	scanf("%d",&C);
	while(C--){
		for(i=0;i<10;i++)for(j=0;j<10;j++)areFriends[i][j]=0;//初始化 
		for(i=0;i<10;i++)taken[i]=0;//初始化 
		int u,v;
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++){
			scanf("%d%d",&u,&v);
			areFriends[u][v]=areFriends[v][u]=1; 
		}
		int answer = CountPairings(taken);
		printf("%d\n",answer); 
	}
	return 0;
}
