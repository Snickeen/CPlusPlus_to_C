#include<stdio.h>

int n,m;
char gameboard[22][22];
int board[22][22]; 
//二维数组的传参，将board设置为全局变量，就不需要传参了 

/***************************************************************/
//代码6-6 解决盖游戏板问题的递归调用算法 

//对当前格子的4中覆盖方法 
//构成版块的3个格子的相对位置(dy,dx)(参考图6-3) 
int coverType[4][3][2]={
	{{0,0},{1,0},{0,1}},//(b)
	{{0,0},{0,1},{1,1}},//(c)
	{{0,0},{1,0},{1,1}},//(d)
	{{0,0},{1,0},{1,-1}}//(e)
};

//把board的格子(y,x)用第type种方法进行覆盖或删除已覆盖的版块 
//delta=1表示用版块覆盖，delta=-1则删除已覆盖的版块 
//如果不能正常覆盖(超出游戏版的边界、重叠、覆盖黑色格子)时，返回0 
int Set(/*char board[][22],*/int y,int x,int type,int delta){
	int i,j,k,l;
	int ok=1;
	for(i=0;i<3;i++){
		int ny=y+coverType[type][i][0];
		int nx=x+coverType[type][i][1];
		if(ny<0||ny>=n||nx<0||nx>=m) 
			ok=0;
		else if( (board[ny][nx]+=delta) > 1)
			ok=0;
	}
	return ok;
}

//返回覆盖board中保存着的所有空格的方法总数 
//board[i][j]=1表示已被覆盖的格子或黑色的格子 
//board[i][j]=0表示未被覆盖的白色格子 
int Cover(/*char board[][22]*/){
	//在剩余未被覆盖的白色格子中，寻找摆放在最左上角的格子 
	int i,j,k,l;
	int y=-1,x=-1;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(0 == board[i][j]){
				y=i;
				x=j;
				break;
			}
		}
		if(y!=-1)break;
	}
	//初始部分：已覆盖所有的白色格子，则返回1
	if(y==-1)return 1;
	int ret=0;
	int type;
	for(type=0;type<4;type++){
		//如果能以type的形式覆盖board[y][x]，就进行递归调用 
		if(Set(/*board,*/y,x,type,1))
			ret+=Cover(/*board*/);
		//删除已覆盖的版块 
		Set(/*board,*/y,x,type,-1);
	} 
	//printf("(%d)\n",ret);
	return ret;
}

/***************************************************************/ 

int main()
{
	int i,j,C;
	scanf("%d",&C);
	while(C--){
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++){
			scanf("%s",gameboard[i]);
			for(j=0;j<m;j++)
				board[i][j]=gameboard[i][j]=='#'?1:0;
		}
		int answer = Cover(/*board*/);
		printf("%d\n",answer); 
	}
	return 0;
}



/*
3
3 7
#.....#
#.....#
##...##
3 7
#.....#
#.....#
##..###
8 10
##########
#........#
#........#
#........#
#........#
#........#
#........#
##########
 
*/
