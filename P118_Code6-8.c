#include<stdio.h>

/***************************************************************/
//代码6-8 解决时钟同步问题的穷举搜索算法 

int INF=9999,SWITCHES=10,CLOCKS=16;
//linked[i][j]='x' : 第i个开关和第j个时钟连接
//linked[i][j]='.' : 第i个开关和第j个时钟未连接 
char linked[10][16+1]={//直接用变量的话有问题，这里替换为数字 
   //0123456789012345
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x..",
};

//判断是否所有时钟都指向12点 
int areAligned(int clocks[]){
	int i,j=0;
	for(i=0;i<CLOCKS;i++){
		j+=clocks[i]==12;
	}
	return j==CLOCKS;
}

//按下第swtch个开关 
void push(int clocks[],int swtch){
	int clock;
	for(clock=0;clock<CLOCKS;clock++){
		if(linked[swtch][clock]=='x'){
			clocks[clock]+=3;
			if(clocks[clock]==15)clocks[clock]=3;
		}
	}
}

//clocks：当前所有时钟的状态 
//swtch：当前要按下的开关序号 
//此时返回“按下剩余开关使clocks调整为12点的最少次数” 
//若不可能调节为12点，则返回大于INF的数值 
int solve(int clocks[],int swtch){
	if(swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;
	//对当前开关尝试按0到3次 
	int ret = INF, cnt, tmp;
	for(cnt=0;cnt<4;cnt++){
		tmp=cnt+solve(clocks,swtch+1);
		if(tmp<ret) ret=tmp;
		push(clocks,swtch);
	}
	//被调用了4次，所以clocks与原状态相同 
	return ret;
}

/***************************************************************/ 

int main()
{
	int i,j,C;
	int clocks[22];
	scanf("%d",&C);
	while(C--){
		for(i=0;i<16;i++)
			scanf("%d",&clocks[i]);
		int answer = solve(clocks,0);
		if(answer==INF)answer=-1;
		printf("%d\n",answer); 
	}
	return 0;
}


/*
2
12 6 6 6 6 6 12 12 12 12 12 12 12 12 12 12
12 9 3 12 6 6 9 3 12 9 12 9 12 12 6 6

*/
