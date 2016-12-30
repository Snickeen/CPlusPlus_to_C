#include<stdio.h> 
#include<string.h> 
#include<malloc.h>
 
int t,n,m,ans; 

int max(int a,int b){
	return a>b?a:b;
}

/***************************************************************/
//代码8-11 解决最长递增子序列问题的动态规划算法(1) O(n^2) 

int n;
int cache[111],CACHE,S[111];
//返回S[start]起始的递增子序列的最大长度 
int lis2(int start){
	int *ret=&cache[start];
	if(*ret != CACHE) return *ret;
	//总是存在S[start]，故长度至少是1
	*ret=1;
	int next;
	for(next=start+1;next<n;next++){
		if(S[start]<S[next]){
			int tmp=lis2(next)+1;
			*ret=max(*ret,tmp);
		}
	}
	return *ret;
} 

/***************************************************************/ 

void solve(){
	int i,j,k,l;
	
	memset(cache,-1,sizeof(cache));
	CACHE=cache[0];
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&S[i]);
	
	int begin,maxLen=0;
	for(begin=0;begin<n;begin++){
		ans=lis2(begin);
		maxLen=max(maxLen,ans);
	}
	
	printf("%d\n",maxLen);
}

int main()
{
	scanf("%d",&t);
	while(t--) 
		solve();
	return 0;
}

/*
1
8
3 2 1 7 5 4 2 6
//Answer //
3
*/
