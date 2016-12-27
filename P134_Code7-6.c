#include<stdio.h>
#include<string.h>

int t,n,m,ans;
char s1[1007];

/***************************************************************/
//代码7-6 解决四叉树翻转问题的分治算法 

int reverse(char *it,char *s){
	int i,j,k,l;
	char head = it[0];
	++it;
	
	if(head=='b'||head=='w'){
		s[0]=head;
		s[1]='\0';
		return 1;
	}
	
	//当head为x时，处理得到其四块的字符串 
	//C++中迭代器在递归的时候会一直累加。
	//但是C指针在递归的时候不会自动累加，需要手动累加定位字符串的首个位置 
	char upperLeft[1007]={0},upperRight[1007]={0},lowerLeft[1007]={0},lowerRight[1007]={0};
	k=reverse(it,upperLeft);
	k=reverse(it+=k,upperRight);
	k=reverse(it+=k,lowerLeft);
	k=reverse(it+=k,lowerRight);
	
	//合并到s[] 
	s[0]='x';k=1;
	strcpy(s+k,lowerLeft);k+=strlen(lowerLeft);
	strcpy(s+k,lowerRight);k+=strlen(lowerRight);
	strcpy(s+k,upperLeft);k+=strlen(upperLeft);
	strcpy(s+k,upperRight);k+=strlen(upperRight);
	s[k]='\0'; 
	//printf("%c: %s %s %s %s :%s\n",head,lowerLeft,lowerRight,upperLeft,upperRight,s);
	return k;
}

/***************************************************************/ 

int main()
{
	int i,j,k,l;
	scanf("%d",&t); 
	while(t--){
		scanf("%s",s1);
		l=strlen(s1);
		char s[1007]={0};
		reverse(s1,s);
		puts(s);
	}
	return 0;
}

/*
4
w
xbwwb
xbwxwbbwb
xxwwwbxwxwbbbwwxxxwwbbbwwwwbb

//Answer //
w
xwbbw
xxbwwbbbw
xxwbxwwxbbwwbwbxwbwwxwwwxbbwb
*/
