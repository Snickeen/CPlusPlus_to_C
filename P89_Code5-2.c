
//代码5-2 (添加了不变式的)插入排序算法 

void insertionSort(int A[],int len){
	int i,j;
	for(i=0;i<len;i++){
		//不变式a:A[0...i-1]已经排好序 
		//向A[0...i-1]中加入A[i]
		j=i;
		while(j>0&&A[j-1]>A[j]){
			//不变式b: A[j+1...i]的所有元素大于A[j]的元素 
			//不变式c: 在区间A[0...i],除了A[j]以外，已经全部排序完毕 
			int tmp=A[j-1];A[j-1]=A[j];A[j]=tmp; 
			j--;
		} 
	}
}

