
//代码4-3 求移动平均

//给出实数数组A，在个数据点计算M-移动平均值
int tot; 
double ret[1007];
void mavingAverage1(double A[],int N,int M){
	int i,j;
	tot=0;//初始化tot=0用来计数，表示ret的大小 
	for(i=M-1;i<N;i++){
		//求A[i]为止的移动平均；
		double partialSum=0;
		for(j=0;j<M;j++){
			partialSum += A[i-j];
		}
		ret[tot++]=(partialSum/M);
	}
	//ret[0,tot-1]即为答案，由于tot和ret[]定义为全局变量，不用返回
}
