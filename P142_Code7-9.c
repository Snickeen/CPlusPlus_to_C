#include<stdio.h>
#include<string.h>
#include<malloc.h> 
#define MST(a) memset(a,0,sizeof(a));

int t,n,m,ans;
char aa[200007],bb[200007]; 

/****************以下被调用的karatsuba快速乘积算法***************/

int abs(int x){
	return x<0?-x:x;
}
int normalize(int *num,int len){//多传递了len表示数组num的长度 
	int i,j,k,l;
	num[len++]=0;
	//处理进位
	/*//用于本题，这里不处理进位 
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
	*/
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


/////////被调用的////代码7-4 Karatsuba快速整数乘积算法 /////////////////////////

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
	int *a0=(int *)malloc(sizeof(int)*(half+3));
	int *a1=(int *)malloc(sizeof(int)*(half+3));
	int *b0=(int *)malloc(sizeof(int)*(half+3));
	int *b1=(int *)malloc(sizeof(int)*(half+3));
	int *z0=(int *)malloc(sizeof(int)*(an));
	int *z1=(int *)malloc(sizeof(int)*(an));
	int *z2=(int *)malloc(sizeof(int)*(an));
	MST(a0);MST(a1);MST(b0);MST(b1);MST(z0);MST(z1);MST(z2);
	int len_a0,len_a1,len_b0,len_b1 ,len_z0,len_z1,len_z2;
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
	
	free(a0);free(a1);free(b0);free(b1);free(z0);free(z1);free(z2);
	
	return l;
}

/****************以上被调用的karatsuba快速乘积算法***************/



/***************************************************************/
//代码7-9 利用karatsuba快速乘积算法解决粉丝见面会问题的函数 

int hugs(char *members,int N,char *fans,int M){
	int i,j,k,l;
	
	int *A=(int *)malloc(sizeof(int)*(N+2));
	int *B=(int *)malloc(sizeof(int)*(M+2));
	int *C=(int *)malloc(sizeof(int)*(N+M+2));
	memset(A,0,sizeof(A));memset(B,0,sizeof(B));memset(C,0,sizeof(C));
	
	int allHugs=0,len;
	for(i=0;i<N;i++)A[i]=(members[i]=='M');
	for(i=0;i<M;i++)B[M-i-1]=(fans[i]=='M');
	//省略karatsuba算法的进位操作
	len=karatsuba(A,B,N,M,C);
	for(i=N-1;i<M;i++)
		allHugs+=(C[i]==0);
	//for(i=0;i<N+M;i++)printf("%d ",C[i]);puts("");
	free(A);free(B);free(C);
	return allHugs;
}

/***************************************************************/ 

int main()
{
	int i,j,k,l;
//	scanf("%d",&t); 
//	while(t--){
		scanf("%s%s",aa,bb);
		k=strlen(aa);
		l=strlen(bb);
		ans=hugs(aa,k,bb,l);
		printf("%d\n",ans);
//	}
	return 0;
}

/*
4
FFFMMM
MMMFFF

FFFFF
FFFFFFFFFF

FFFFM
FFFFFMMMMF

MFMFMFFFMMMFMF
MMFFFFFMFFFMFFFFFFMFFFMFFFFMFMMFFFFFFF

//Answer //
1
6
2
2

*/
