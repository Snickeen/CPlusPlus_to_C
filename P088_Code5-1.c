
//代码5-1 二分法检索 

//必要条件：A[]已经排成升序
//结果：返回满足A[i-1]<x<A[i]的i值
//设A[-1]=负无穷，A[n]=正无穷
int binsearch(int A[],int n,int x){//n为A[]长度 
	int lo=-1,hi=n;
	//循环不变式1：lo<hi 
	//循环不变式2：A[lo]<x<A[hi] 
	//(*)不变式在此处必须成立 
	while(lo+1<hi){
		int mid=(lo+hi)/2;
		if(A[mid]<x)
			lo=mid;
		else 
			hi=mid;
		//(**)不变式在此处也必须成立  
	} 
	return hi;
} 
