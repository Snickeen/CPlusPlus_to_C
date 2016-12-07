
//输出a/b的小数形式
//假设a>=0,b>0;
void printDecimal(int a,int b){
	int iter=0;
	while(a>0){
		//在第一个与第二个数值之间画上小数点
		if(iter++ = 1)printf(".");
		printf("%d",a/b);
		a=(a%b)*10; 
	}
} 
