
//代码4-1 在给定数组中找出出现次数最多的数值

//返回给定数组A中相同个数最多的数
//如果多于两个，返回任意一个即可

int majority1(int A[],int N){
	int i,j,k,l;
	int majority = -1, majorityCount = 0;
	for(i=0;i<N;i++){
		//计数A[i]的个数
		int V=A[i],count =0;
		for(j=0;j<N;j++){
			if(A[j]==V)
				count++;
		}
	}
	//假如这个数值的出现频率高于已测试的其他数值，则利用此数值代替原来的数值
	if(count>majorityCount){
		majorityCount=count;
		majority=V;
	} 
	return majority;
}
