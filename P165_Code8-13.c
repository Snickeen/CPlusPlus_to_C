#include<stdio.h> 
#include<string.h> 
#include<malloc.h>
 
int t,ans; 

int max(int a,int b){
	return a>b?a:b;
}

/***************************************************************/
//代码8-13 解决合并LIS问题的动态规划算法

//输入值的取值范围是有符号的32位整数型 
//人为设定的最小值取值范围必须是64位 
long long NEGINF=-1e18; //这里其实还有比此数更小的，当前数只要比有符号32位最小值小即可 
int n,m,A[111],B[111];
int cache[111][111],CACHE;
//以min(A[indexA],B[indexB])、max(A[indexA],B[indexB])起始的合并递增子序列中 
//返回最大长度 
//但要假设indexA==indexB==-1或者A[indexA]!=B[indexB] 
int jlis(int indexA,int indexB){
	//制表 
	int *ret=&cache[indexA+1][indexB+1];
	if(*ret != CACHE) return *ret;
	//A[indexA],B[indexB]已经存在(假设不相等)，故长度至少是2个元素 
	*ret=2;
	long long a = ( indexA==-1 ? NEGINF : A[indexA] ); 
	long long b = ( indexB==-1 ? NEGINF : B[indexB] ); 
	//这里(下面)用三目运算，如果调用上面的max()的话会出错，因为max()用的int定义的变量 
	//将代码中所有的变量全部用long long可以避免类似的状况 
	long long maxElement=a>b?a:b;
	//找出下一个元素 
	int nextA,nextB;
	for(nextA=indexA+1;nextA<n;nextA++){
		if(maxElement<A[nextA]){
			int tmp=jlis(nextA,indexB)+1;
			*ret=max(*ret,tmp);
		}
	}
	for(nextB=indexB+1;nextB<m;nextB++){
		if(maxElement<B[nextB]){
			int tmp=jlis(indexA,nextB)+1;
			*ret=max(*ret,tmp);
		}
	}
	return *ret;
} 

/***************************************************************/ 

void solve(){
	int i,j,k,l;
	
	memset(cache,-1,sizeof(cache));
	CACHE=cache[0][0];
	
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	for(i=0;i<m;i++)
		scanf("%d",&B[i]);
	
	ans=jlis(-1,-1)-2;
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
3 
3 3 
1 2 4 
3 4 7 
3 3 
1 2 3 
4 5 6 
5 3 
10 20 30 1 2 
10 20 30 

//Answer //
5
6
5

*/
