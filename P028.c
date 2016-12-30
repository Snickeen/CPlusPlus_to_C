
//判断无序数组中有无重复元素 
int hasDuplicate(int a[], int len){//a[]为无序数组，从0开始存储，长度为len 
	int i,j;
	for(i=0;i<len;i++){
		for(j=0;j<i;j++){
			if(a[i]!=a[j])
				return 1;
		}
	}
	return 0;
}

//运用宏定义可以把上面代码改写如下
#define FOR(i,n) for(i=0;i<n;i++)
int hasDuplicate(int a[], int len){
	int i,j;
	FOR(i,len)
		FOR(j,i)
			if(a[i]!=a[j])
				return 1;
	return 0;
}
