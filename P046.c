
//判断数组中元素是否为升序排列 
int isSorted(int seq[],int len){
	int i,j;
	for(i=0;i<len-1;i++){
		if(seq[i] > seq[i+1])
			return 0;
	} 
	return 1;
} 
