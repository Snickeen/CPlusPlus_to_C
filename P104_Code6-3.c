#include<stdio.h>
#include<string.h>

char board[6][6],str[55];

int inRange(int y,int x){
	if(y<0||y>=5||x<0||x>=5) return 0;
	return 1;
}

/***************************************************************/
//代码6-3 串串字连环中找出指定单词的递归调用算法 

int dx[8]={-1,-1,-1,1,1,1,0,0};
int dy[8]={-1,0,1,-1,0,1,-1,1};
//确认给出的单词是否始于5x5串串字连环棋盘的相应位置 
int hasWord(int y,int x,char word[]){
	//初始部分1：其实位置在棋盘以外，则直接返回0，并终止循环 
	if(!inRange(y,x)) return 0;
	//初始部分2：首字母不一致，则直接返回0，并终止循环 
	if(board[y][x]!=word[0]) return 0;
	//初始部分3：单词长度为1，则直接返回1，并终止循环 
	if(strlen(word)==1)return 1;
	//检索相邻的8个格子 
	int direction;
	for(direction=0;direction<8;direction++){
		int nextY=y+dy[direction],nextX=x+dx[direction];
		//没有必要再判断下一个格子是否在允许范围内以及首字母的一致性 
		if(hasWord(nextY,nextX,word+1))
			return 1;
	}
	return 0;
}
/***************************************************************/

int main()
{
	int i,j,k,l;
	scanf("%s",str);
	for(i=0;i<5;i++)
		scanf("%s",board[i]);
	k=0;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(board[i][j]==str[0]){
				k+=hasWord(i,j,str);
				if(k){
					puts("YES");
					return 0;
				}
			}
		}
	}
	puts("NO");
	return 0;
}

/*
PRETTY
URLPM
XPRET
GIAET
XTNZY
XOQRS
*/
