#include<stdio.h>
#include<string.h> 

int t,n,m,ans; 

/***************************************************************/
//代码8-6 解决通配符问题的穷举搜索法 

//返回通配符范式w与字符串s是否对应 
//多传递两个变量表示字符串长度 
int match(char *w,char *s,int len_w,int len_s){
	//匹配w[pos]和s[pos]
	int pos=0;
	while(pos<len_w && pos<len_s && (w[pos]=='?'||w[pos]==s[pos]) ) 
		++pos;
	//无法再检索对应关系，则确认while循环结束
	//已到达范式的最后一个字符的情况：字符串也到达了最后一个字符，则对应关系成立。
	if(pos==len_w)
		return pos==len_s;
	//遇到"*"而结束的情况：利用递归调用，查看"*"对应几个字符
	int skip;
	if(w[pos]=='*')
		for(skip=0;pos+skip<=len_s;skip++)
			if(match(w+pos+1, s+pos+skip, len_w-pos-1, len_s-pos-skip))
				return 1;
	//除此之外的所有的对应关系都不成立
	return 0; 
}

/***************************************************************/ 

int main()
{
	int i,j,k,l,len_w,len_s;
	char w[111],s[111];
	scanf("%d",&t);
	while(t--){
		scanf("%s%d",w,&n);
		len_w=strlen(w);
		while(n--){
			scanf("%s",s);
			len_s=strlen(s);
			ans=match(w,s,len_w,len_s);
			if(ans)
				puts(s);
		}
	}
	return 0;
}

/*
3
he?p
3
help
heap
helpp
*p*
3
help
papa
hello
*bb*
1
babbbc

//Answer// 
help
heap
help
papa
babbbc
*/
