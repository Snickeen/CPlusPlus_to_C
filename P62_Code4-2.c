
//代码4-2 在给定数组中找出出现次数最多的数值 2

//A[]中的各元素是从0到100的数值，返回出现次数最多的数值 
int majority2(int A[],int N){
	int i,j,k,l;
	int count[111]={0};
	for(i=0;i<N;i++){
		count[A[i]]++;
	}
	//在目前的检索中，吧出现次数最多的数值保存到majority 
	int majority=0;
	for(i=0;i<=100;i++){
		if(count[i]>count[majority])
			majority=i;
	} 
	return majority;
}
