#include<stdio.h>
#include<string.h>

int t,n,m,ans;

int max(int a,int b){
	return a>b?a:b;
}
int min(int a,int b){
	return a<b?a:b;
}

/***************************************************************/
//代码7-8 解决切割篱笆问题的分治算法 

//保存各木板高度的数组 
int h[20007];
//返回h[left...right]区间中可截取的面积最大长方形的面积 
int solve(int left,int right){
	//初始部分：只有1个木板的情况
	if(left==right) return h[left];
	//分割为[left,mid]和[mid+1,right]两个区间的子问题 
	int mid=(left+right)/2;
	//分别计算分割的子问题
	int retLeft,retRight,ret;
	retLeft=solve(left,mid);
	retRight=solve(mid+1,right);
	ret=max(retLeft,retRight);
	//子问题3：找出横跨两个子问题的面积最大的长方形
	int lo=mid,hi=mid+1;
	int height=min(h[lo],h[hi]);
	//只考虑包含[mid,mid+1]的宽度为2的长方形 
	ret=max(ret,height*2);
	//扩展长方形，直至覆盖所有输入值。
	while(left<lo||hi<right){
		//总是向高度更高的方向扩展
		if(hi<right&&(lo==left||h[lo-1]<h[hi+1])){
			++hi;
			height=min(height,h[hi]);
		}
		else {
			--lo;
			height=min(height,h[lo]);
		}
		//扩展后的长方形的面积 
		ret=max(ret,height*(hi-lo+1));
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
			scanf("%d",&h[i]);
		ans=solve(0,n-1);
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
