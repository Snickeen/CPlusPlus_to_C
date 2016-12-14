
//代码4-4 线性时间的求移动平均

//给出元素个数是N的数组A，求各个元素位置的M-移动平均

int tot; 
double ret[1007];
void mavingAverage1(double A[],int N,int M){
	int i,j;
	tot=0;//初始化tot=0用来计数，表示ret的大小 
	double partialSum=0;
	for(i=0;i<M-1;i++)
		partialSum += A[i];
	for(i=M-1;i<N;i++){
		partialSum += A[i];
		ret[tot++]=(partialSum/M);
		partialSum -= A[i-M+1];
	}
	//ret[0,tot-1]即为答案，由于tot和ret[]定义为全局变量，不用返回
}
