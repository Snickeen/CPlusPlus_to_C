#include<stdio.h>
#include<string.h>

int t,n,m,ans;
char s1[10007],s2[10007];
int a[10007],b[10007];

int abs(int x){
	return x<0?-x:x;
}

/***************************************************************/
//代码7-3 两个大(正)数值相乘的O(n*n)时间复杂度算法 

//处理num[]的进位
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

//原代码返回两个长自然数的乘积，这里把结果记录在c[]中并返回其长度 
//每个数组保存着各操作数从个位起始的数值 
//如：multiply({3,2,1},{6,5,4})=123*456=56088={8,8,0,6,5} 
//多传递了la,lb表示数组a,b的长度 
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
		lc=multiply(a,b,la,lb,c);
		for(i=lc-1;i>=0;i--)
			printf("%d",c[i]);
		printf("\n"); 
	} 
	return 0;
}
