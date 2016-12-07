
//代码4-7 线性检索

//返回满足array[i]==element的第一个i，如果没有返回-1
int firstIndex(int array[],int len,int element){
	for(int i=0;i<len;i++){
		if(array[i]==element)
			return i;
	}
	return -1;
} 
