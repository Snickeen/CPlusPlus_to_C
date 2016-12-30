#include<stdio.h> 
#include<string.h> 
#include<malloc.h>
 
int t,n,m,ans; 

int max(int a,int b){
	return a>b?a:b;
}

/***************************************************************/
//代码8-10 解决最长递增子序列问题的穷举搜索算法

//多传递一个变量表示数组A[]的大小 
int lis(int *A,int an){
	//初始部分：A[]为空序列
	if(an==0) return 0;
	int ret=0;
	int *B=(int *)malloc(sizeof(int)*1111);
	int i,j,k,l,bn; 
	for(i=0;i<an;i++){
		bn=0;
		for(j=i+1;j<an;j++){
			if(A[i]<A[j]){
				B[bn++]=A[j];
			}
		}
		k=lis(B,bn)+1;
		ret=max(ret,k);
	}
	return ret;
} 

/***************************************************************/ 

void solve(){
	int i,j,k,l;
	int a[1111];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	ans=lis(a,n);
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
1
8
3 2 1 7 5 4 2 6
//Answer //
3
*/
