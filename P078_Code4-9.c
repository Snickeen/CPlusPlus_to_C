
//代码4-9 求连续区间最大值的笨重方法

//第一种方法 
int MIN = (1<<32)-1;
//求A[]连续区间的最大和。 时间复杂度:O(N*N*N)
int inefficientMaxSum(int A[],int len){
	int i,j;
	int ret = MIN;
	for(i=0;i<N;i++){
		for(j=i;j<N;j++){
			//求区间A[i...j]的和
			int sum = 0；
			for(k=i;k<=j;k++)
				sum += A[k];
			if(sum>ret)ret=sum; 
		}
	}
	return ret;
}

//第二种方法 
int MIN = (1<<32)-1;
//求A[]连续区间的最大和。 时间复杂度:O(N*N)
int betterMaxSum(int A[],int len){
	int i,j;
	int ret = MIN;
	for(i=0;i<N;i++){
		int sum=0;
		for(j=i;j<N;j++){
			//求区间A[i...j]的和
			sum += A[j];
			if(sum>ret)ret=sum; 
		}
	}
	return ret;
}

