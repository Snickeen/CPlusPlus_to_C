#include<stdio.h>
#include<string.h>

int t,n,m,ans;
int a[20007];

/***************************************************************/
//代码7-7 解决切割篱笆问题的O(n*n)算法 

//给定保存木板高度的数组h[]时，返回长方形的最大面积 
int bruteForce(int *h,int len){
	int left,right,k;
	int ret=0;
	//检索所有可能的left和right的组合
	for(left=0;left<len;left++){
		int minHeight = h[left];
		for(right=left;right<len;right++){
			if(h[right]<minHeight)minHeight=h[right];
			k=(right-left+1)*minHeight;
			if(k>ret)ret=k;
		}
	}
	return ret;
}

/***************************************************************/ 

int main()
{
	int i,j,k,l;
	scanf("%d",&t); 
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		ans=bruteForce(a,n);
		printf("%d\n",ans);
	}
	return 0;
}

/*
3
7
7 1 5 9 6 7 3
7
1 4 4 4 4 1 1 
4
1 8 2 2 

//Answer //
20
16
8

*/
