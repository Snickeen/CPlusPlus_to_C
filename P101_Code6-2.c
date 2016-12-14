#include<stdio.h>

int picked[111];
void printPicked(int p[]){
	int i; 
	for(i=1;i<=p[0];i++){
		if(i>1)printf(" "); 
		printf("%d",p[i]);
	}
	printf("\n");
}

/*********************************************************/
//代码6-2 求在n个元素中选择m个元素的所有可能的组合 

//n：元素总数量
//picked：已选元素的序号,picked[0]存储选了几个，序号存储从1开始 
//为0时，输出toPick个元素的所有组合方式
void pick(int n,int picked[],int toPick){
	//初始部分：无可选元素时，输出已选元素
	if(0==toPick) {
		printPicked(picked);//输出调用的函数需要自己写 
		return ;
	}
	//计算可选的最小序号
	int smallest,nextOne;
	smallest = picked[0]==0 ? 0 : picked[picked[0]]+1;
	//在此阶段选择一个元素
	for(nextOne=smallest;nextOne<n;nextOne++){
		picked[++picked[0]]=nextOne;
		pick(n,picked,toPick-1);
		picked[0]--;
	}
}
/***********************************************************/

int main()
{
	int i,j,k,l,n,m;
	while(~scanf("%d%d",&n,&m))
		pick(n,picked,m);
	return 0;
}
