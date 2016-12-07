
//代码4-10 求连续区间最大值的分治方法

//求A[lo...hi]的连续区间的最大值。时间复杂度：O(nlogn)
int fastMaxSum(int A[],int lo,int hi){
	//基本示例：区间长度为1
	if(lo==hi)return A[lo];
	//平分为两个数组A[lo...mid]和A[mid...hi] 
	int mid=(lo+hi)/2;
	//求出横跨两个数组的区间最大值。这个区间最大值是
	//具有 A[i...mid]和A[mid..+1,j]结构的区间最大值之和。 
	//找出具有A[i...mid]结构的区间最大值。 
	int left=MIN,right=MIN,sum=0;
	for(i=midl=;i<lo;i--){
		sum += A[i];
		if(sum>left)left=sum;
	} 
	//找出具有A[mid..=1,j]结构的区间最大值。
	sum=0;
	for(mid+1;j<=hi;j++){
		sum+=A[j];
		if(sum>right)right=sum;
	} 
	//区间最大值在两个数组中的一个时，利用递归调用求出答案。
	int tmp1=fastMaxSum(A,lo,mid),
		tmp2=fastMaxSum(A,mid+1,hi);
	int single;
	if(tmp1>tmp2)single=tmp1;
	else single=tmp2;
	//返回两种结果的最大值
	if(left+right>single)return left+right;
	else return single; 
}
