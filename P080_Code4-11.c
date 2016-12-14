
//代码4-11 求连续区间最大值的动态规划算法

//求A[]的连续区间的最大值。时间复杂度：O(n)

int MIN = (1<<32)-1;
int max(int a,int b){
	return a>b?a:b;
}
int fastestMaxSum(int A[],int len){
	int i,j,ret=MIN,psum=0;
	for(i=0;i<len;i++){
		psum=max(psum,0)+A[i];
		ret=max(psum,ret);
	}
	return ret;
} 
