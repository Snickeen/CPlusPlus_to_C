#include<stdio.h>
#include<string.h> 

int t,n,m,ans; 

/***************************************************************/
//代码8-7 解决通配符问题的动态规划算法 O(n^3) 

//-1 表示还没进行过计算 
//1 表示两个输入值存在对应关系 
//0 表示两个输入值不存在对应关系
int cache[111][111],CACHE; 
//通配符范式w与字符串s字符串 
char W[111],S[111];
//多定义两个变量表示字符串长度 
int len_w,len_s;

//返回通配符范式w与字符串s是否对应 
int matchMemoized(int w,int s){
	//制表
	int *ret = &cache[w][s];
	if(*ret != CACHE) return *ret;
	//匹配W[w]和S[s]
	while(w<len_w && s<len_s && (W[w]=='?'||W[w]==S[s]) ) 
		++w,++s;
	
	//无法再检索对应关系，则查看while循环结束的原因 
	//已到达范式的最后一个字符的情况：字符串也到达了最后一个字符，则对应关系成立。
	if(w==len_w)
		return *ret=(s==len_s);
	//遇到"*"而结束的情况：利用递归调用，查看"*"对应几个字符
	int skip;
	if(W[w]=='*')
		for(skip=0;s+skip<=len_s;skip++)
			if(matchMemoized(w+1, s+skip))
				return *ret=1;
	//除此之外的所有的对应关系都不成立
	return *ret=0; 
}

/***************************************************************/ 

int main()
{
	int i,j,k,l;
	scanf("%d",&t);
	while(t--){
		scanf("%s%d",W,&n);
		len_w=strlen(W);
		while(n--){
			//初始化 
			memset(cache,-1,sizeof(cache));
			CACHE=cache[0][0];
			
			scanf("%s",S);
			len_s=strlen(S);
			ans=matchMemoized(0,0);
			if(ans)
				puts(S);
		}
	}
	return 0;
}

/*
3
he?p
3
help
heap
helpp
*p*
3
help
papa
hello
*bb*
1
babbbc

//Answer// 
help
heap
help
papa
babbbc

*/
