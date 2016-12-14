
//代码4-6 最简单形态的素因子分解算法

//原代码：返回保存有自然数n的素因子分解结果的整数数组
//当前代码：将自然数n的素因子分解结果保存在整数数组中,返回总个数tot 

int ret[1111],tot;
int factor(int n){
	int i,j;
	tot=0; 
	if(1 == n){
		ret[tot++]=1;
		return tot;
	}
	for(int div=2;n>1;div++){
		while(n%div==0){
			n/=div;
			ret[tot++]=div;
		}
	}
	return tot;
}
