/*
本代码有些地方还可以优化，例如代码7-4部分的数组定义可以优化为动态数组申请 等等 
*/
#include<stdio.h>
#include<string.h>

int t,n,m,ans;
char s1[10007],s2[10007];
int a[10007],b[10007];

/***************************************************************/
int abs(int x){
	return x<0?-x:x;
}
int normalize(int *num,int len){//多传递了len表示数组num的长度 
	int i,j,k,l;
	num[len++]=0;
	//处理进位
	for(i=0;i<len;i++){
		if(num[i]<0){
			int borrow=(abs(num[i])+9)/10;
			num[i+1]-=borrow;
			num[i]+=borrow*10; 
		}
		else {
			num[i+1]+=num[i]/10;
			num[i]%=10;
		}
	}
	while(len>1&&num[len-1]==0)len--;
	return len;
}

//当a,b两个数组的长度较小时，调用O(n*n)时间复杂度算法来暴力解决 
int multiply(int *a,int *b,int an,int bn,int *c){
	int i,j,k,l;
	memset(c,0,sizeof(c));
	for(i=0;i<an;i++)
		for(j=0;j<bn;j++)
			c[i+j]+=a[i]*b[j];
	l=normalize(c,an+bn);
	return l;
}
/***************************************************************/


/***************************************************************/
//代码7-4 Karatsuba快速整数乘积算法 

//计算a+=b*(10^k)。
int addTo(int *a,int *b,int k,int an,int bn){//多传递了an,bn表示数组a[],b[]的长度 
	int i,l;
	for(i=0;i<bn;i++)
		a[i+k]+=b[i];
	if(bn+k>an)an=bn+k;
	l=normalize(a,an);
	return l;
} 
//计算a-=b,假设a>=b 
int subFrom(int *a,int *b,int an,int bn){//多传递了an,bn表示数组a[],b[]的长度 
	int i,l;
	for(i=0;i<bn;i++)
		a[i]-=b[i];
	l=normalize(a,an);
	return l;
} 
//由于这里可以保证an>=bn一定成立，所以addTo和subFrom可以简化写成一个，请先自己思考 


//代码返回两个长自然数的乘积，这里把结果记录在ret[]中并返回其长度 
//多传递了数组a[],b[]的长度，以及保存答案的数组 
int karatsuba(int *a,int *b,int la,int lb,int *ret){
	int i,j,k,l;
	int an=la,bn=lb;
	//a的位数小于b时，两数交换
	//这里保证了前面的数组长度不小于后面的数组的长度，为后面addTo和subFrom提供了方便 
	if(an<bn) return karatsuba(b,a,bn,an,ret); 
	//初始部分：数组a或b为空时
	if(an==0||bn==0) return 0;
	//初始部分：数组a的位数比较短时，变更为O(n*n)的乘积
	if(an<=50) return multiply(a,b,an,bn,ret);
	
	int half=an/2;
	//从a和b的低位起始，分割成half位和剩余位
	//预先定义将要用到的数组以及长度变量 
	int a0[10007],a1[10007],b0[10007],b1[10007],len_a0,len_a1,len_b0,len_b1;
	int z0[10007*2]={0},z1[10007*2]={0},z2[10007*2]={0},len_z0,len_z1,len_z2;
	//a0 
	for(i=0;i<half;i++)a0[i]=a[i];
	len_a0=half;
	//a1 
	for(i=half;i<an;i++)a1[i-half]=a[i];
	len_a1=an-half;
	//b0 
	l=bn<half?bn:half;
	for(i=0;i<l;i++)b0[i]=b[i];
	len_b0=l;
	//b1 
	for(i=half;i<bn;i++)b1[i-half]=b[i];
	len_b1=(l>=bn?0:bn-l);
	
	//z2=a1*b1
	len_z2=karatsuba(a1,b1,len_a1,len_b1,z2);
	//z0=a0*b0
	len_z0=karatsuba(a0,b0,len_a0,len_b0,z0);
	//a0=a0+a1,b0=b0+b1
	len_a0=addTo(a0,a1,0,len_a0,len_a1);
	len_b0=addTo(b0,b1,0,len_b0,len_b1);
	//z1=(a0*b0)-z0-z2
	len_z1=karatsuba(a0,b0,len_a0,len_b0,z1);
	len_z1=subFrom(z1,z0,len_z1,len_z0);
	len_z1=subFrom(z1,z2,len_z1,len_z2);
	//ret=z0+z1*10^half+z2*10^(half*2)
	//memset(ret,0,sizeof(ret));
	l=0;
	l=addTo(ret,z0,0,l,len_z0);
	l=addTo(ret,z1,half,l,len_z1);
	l=addTo(ret,z2,half*2,l,len_z2);
	return l;
}

/***************************************************************/ 

int main()
{
	int i,j,k,l;
	while(~scanf("%s%s",s1,s2)){
		int la,lb,lc;
		la=strlen(s1);
		for(i=0;i<la;i++)
			a[la-i-1]=s1[i]-'0';
		lb=strlen(s2);
		for(i=0;i<lb;i++)
			b[lb-i-1]=s2[i]-'0';
		int c[10007*2]={0}; 
		lc=karatsuba(a,b,la,lb,c);//注意这里多传递的变量
		for(i=lc-1;i>=0;i--)
			printf("%d",c[i]);
		printf("\n"); 
	} 
	return 0;
}

