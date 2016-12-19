#include<stdio.h>

/***************************************************************/
//代码7-2 模板2 矩阵快速幂取模（求10^18内的Fibonacci） 

//long long 版 
typedef long long LL;

LL MOD=1e9+7;//一般模数是这个数字居多，如果是其他的可以在这里改，全局变量省略传参 

//定义矩阵中的行和列，从1..Row存储行，而1..Column存储列 
const LL Row=3,Column=3;//若C编译失败可以把const删掉 

struct Mat{
	LL r,c;
	LL a[3][3];//若用C++的话这里可以直接用上面的Row和Column，写成LL a[Row][Column]; 
};
typedef struct Mat Matrix;

//对某个矩阵的初始化 
void init(Matrix* a){
	LL i,j,k,l;
	a->r=Row-1;
	a->c=Column-1;
	for(i=0;i<=a->r;i++){
		for(j=0;j<=a->c;j++){
			a->a[i][j]=0;
		}
	}
}
//矩阵X与矩阵Y的乘积 
Matrix MUL(Matrix X,Matrix Y){
	LL i,j,k,l;
	Matrix cnt;
	init(&cnt);
	cnt.r=X.r;cnt.c=Y.c;
	for(i=1;i<=X.r;i++){
		for(j=1;j<=Y.c;j++){
			for(k=1;k<=X.r;k++){
				cnt.a[i][j]+=(X.a[i][k]*Y.a[k][j]%MOD);
			}
			cnt.a[i][j]%=MOD;
		}
	}
	return cnt;
}
//矩阵X的y次幂 
Matrix MQP(Matrix X, LL y){
	LL i,j,k,l;
	Matrix res;
	init(&res);
	for(i=1;i<=res.r;i++)res.a[i][i]=1;//初始化res为单位矩阵 
	while(y){
		if(y&1LL)res=MUL(res,X);
		X=MUL(X,X);
		y>>=1;
	}
	return res;
}

/***************************************************************/ 

LL t,n,m,ans;
Matrix A,B,C;

int main()
{
	LL i,j,k,l;
	//初始化 
	init(&A);init(&B);B.c=1;
	//以矩阵快速幂求Fibonacci sequence为例
	//i    0 1 2 3 4...
	//fib  1 1 2 3 5...
	A.a[1][1]=A.a[1][2]=A.a[2][1]=1;
	B.a[1][1]=2;B.a[2][1]=1;
	//计算第n(n>0)个fibonacci number
	while(scanf("%lld",&n),n){
		if(n<=3){
			printf("%lld\n",n);
			continue;
		}
		C=MQP(A,n-2);//Matrix Quick Power 矩阵A的n-2次幂 
		C=MUL(C,B);//multiply 矩阵C和矩阵B相乘 
		ans=C.a[1][1];
		ans=(ans%MOD+MOD)%MOD;
		printf("%lld\n",ans);
	}
	return 0;
}
