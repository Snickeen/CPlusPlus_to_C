#include<stdio.h>
 
/***************************************************************/
//代码7-2 模板1快速幂、快速幂取模 

//求a的b次幂 
int fastPower(int a,int b){
	int res=1;
	while(b){
		if(b&1)res*=a;
		b>>=1;
		a*=a;
	}
	return res;
}

//求a的b次幂并取模 
int fastPowerMod(int a,int b,int mod){
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}

/***************************************************************/
//通常用到快速幂的地方，int常常会溢出。
 
typedef long long LL;
//求a的b次幂 
LL FastPower(LL a,LL b){
	LL res=1LL;
	while(b){
		if(b&1LL)res*=a;
		b>>=1LL;
		a*=a;
	}
	return res;
}

//求a的b次幂并取模 
LL FastPowerMod(LL a,LL b,LL mod){
	LL res=1LL;
	while(b){
		if(b&1LL)res=res*a%mod;
		b>>=1LL;
		a=a*a%mod;
	}
	return res;
}
/***************************************************************/ 

int main()
{
	int n,m,answer;
	while(~scanf("%d%d",&n,&m)){//这里的读入为第一个模板的读入例子 
		answer=fastPower(n,m);
		printf("%d\n",answer); 
	}
	return 0;
}
