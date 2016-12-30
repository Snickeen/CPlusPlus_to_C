#include<stdio.h> 
#include<string.h> 
#include<malloc.h>
 
int t,ans; 

int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
int Abs(int a){return a>0?a:-a;}

/***************************************************************/
//代码8-15 Quantizaion问题的实现方法 

int INF=987654321;
//A[]：需要量化的序列，已排好序 
//pSum[]：保存A[]的部分和。pSum[i]等于A[0]...A[i]的总和 
//pSqSum[]：保存A[]平方的部分和。pSum[i]等于A[0]^2...A[i]^2的总和 
int n;
int A[111],pSum[111],pSqSum[111];
//排序A[]并求部分和 
void precalc(){
	int i,j,k,l;
	//数据量比较小，随便暴力一个排序 
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(A[j]<A[i]){
				k=A[i];
				A[i]=A[j];
				A[j]=k;
			}
		}
	}
	pSum[0]=A[0];
	pSqSum[0]=A[0]*A[0];
	for(i=1;i<n;i++){
		pSum[i]=pSum[i-1]+A[i];
		pSqSum[i]=pSqSum[i-1]+A[i]*A[i];
	}
}

//把区间A[lo]...A[hi]量化为1个数值时，求出最小误差之和 
int minError(int lo,int hi){
	//利用部分和求出A[lo]...A[hi]的和 
	int sum=pSum[hi]-(lo==0?0:pSum[lo-1]); 
	int sqSum=pSqSum[hi]-(lo==0?0:pSqSum[lo-1]); 
	//用四舍五入过的平均值表示各个数值快 
	int m=(int)(0.5+(double)sum/(hi-lo+1));
	//用部分和的形式表示sum(A[i]-m)^2的展开结果 
	int ret=sqSum-2*m*sum+m*m*(hi-lo+1); 
	return ret;
}

int cache[111][111],CACHE;
int quantize(int from,int parts){
	//初始部分：已经所有数值量化 
	if(from==n)return 0; 
	//初始部分：还有剩余数值但无法再组合时，返回极大值 
	if(0==parts)return INF; 
	int* ret=&cache[from][parts];
	if(*ret != CACHE) return *ret;
	*ret=INF;
	//改变数值块的长度并找出最小值 
	int partSize,tmp;
	for(partSize=1;from+partSize<=n;partSize++){
		tmp=minError(from,from+partSize-1)+quantize(from+partSize,parts-1);
		*ret=min(*ret,tmp);
	}
	return *ret;
}


/***************************************************************/ 

void solve(){
	int i,j,k,l,s;
	
	memset(cache,-1,sizeof(cache));
	CACHE=cache[0][0];
	
	scanf("%d%d",&n,&s);
	for(i=0;i<n;i++)scanf("%d",&A[i]); 
	precalc();
	ans=quantize(0,s);
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
2
10 3
3 3 3 1 2 3 2 2 2 1 
9 3
1 744 755 4 897 902 890 6 777

//Answer //
0
651

*/
