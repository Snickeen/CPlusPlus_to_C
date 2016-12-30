#include<stdio.h> 
#include<string.h> 
#include<malloc.h>
 
int t,n,m,ans; 

int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
int Abs(int a){return a>0?a:-a;}

/***************************************************************/
//代码8-14 解决背诵圆周率问题的动态规划算法

int INF=987654321;
char N[10007];
//返回区间N[a...b]的难度
int classify(int a,int b){
	int i,j,k,l; 
	//输入数字分割块 
	char *M=(char *)malloc(sizeof(char)*(b-a+2));
	for(i=0,j=a;j<=b;i++,j++)M[i]=N[j];
	m=b-a+1;
	//若与只有第一个字符组成的序列相同则难度为1
	for(k=i=1;i<m;i++){
		if(M[i]!=M[0]){
			k=0;
			break;
		}
	}
	if(k)return 1;
	//检查是否为等差数列
	int progressive=1;
	for(i=0;i<m-1;i++){
		if(M[i+1]-M[i] != M[1]-M[0])
			progressive=0;
	}
	//若为公差为1或者-1的等差数列，则难度为2
	if(progressive && Abs(M[1]-M[0])==1) return 2; 
	//检查两个数字是否交替出现
	int alternating=1;
	for(i=0;i<m;i++){
		if(M[i]!=M[i%2])
			alternating=0;
	}
	//若交替出现，则难度为4  
	if(alternating)return 4;
	//公差不是1的公差序列难度为5 
	if(progressive)return 5;
	//其他难度均为10 
	return 10;
} 

int cache[10007],CACHE;
//输出背诵序列N[begin...]的方法中难度之和的最小值 
int memorize(int begin){
	//初始部分：已到达序列末端的情况 
	if(begin==n)return 0; 
	//制表 
	int* ret = &cache[begin];
	if(*ret != CACHE)return *ret;
	*ret=INF;
	int L;
	for(L=3;L<=5;L++){
		if(begin+L<=n){
			int tmp=memorize(begin+L)+classify(begin,begin+L-1);
			*ret=min(*ret,tmp);
		}
	}
	return *ret;
}

/***************************************************************/ 

void solve(){
	int i,j,k,l;
	
	memset(cache,-1,sizeof(cache));
	CACHE=cache[0];
	
	scanf("%s",N);
	n=strlen(N);
	ans=memorize(0);
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
5
12341234
11111222
12122222
22222222
12673939

//Answer //
4
2
5
2
14

*/
