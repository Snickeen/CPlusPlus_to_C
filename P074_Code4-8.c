
//代码4-8 选择排序和插入排序

void swap(int A[],int i,int j){
	int t=A[i];
	A[i]=A[j];
	A[j]=t;
} 
//选择排序
void selectionSort(int A[],int len){
	int i,j,k;
	for(i=0;i<len;i++){
		int minIndex=i;
		for(j=i+1;j<len;j++){
			if(A[minIndex]>A[j])
				minIndex=j;
		}
		int tmp=A[i];A[i]=A[minIndex];A[minIndex]=tmp;
	}
} 
//插入排序
void insertionSort(int A[],int len){
	int i,j;
	for(i=0;i<len;i++){
		//向A[0...i-1]中加入A[i]
		j=i;
		while(j>0&&A[j-1]>A[j]){
			int tmp=A[j-1];
			A[j-1]=A[j];
			A[j]=tmp; 
			j--;
		} 
	}
}

