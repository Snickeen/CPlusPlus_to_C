#include<stdio.h>
#include<string.h>

/***************************************************************/
//代码8-3 使用制表示例 

//把所有元素初始化为-1
int cache[2500][2500],CACHE; 
//a和b是[0,2500)区间内的整数
//返回值总是int类型的非负整数 
int someObscureFunction(int a,int b){
	//先处理初始部分
	if( ... ) return ...;
	//已经求解过(a,b)，则直接返回解过的值 
	int& ret=cache[a][b]; 
	if(ret != CACHE) return ret;
	//在此求解
	... 
	return ret; 
}
/***************************************************************/ 

int main()
{
	//利用memset()从初始化cache数组
	memset(cache,-1,sizeof(cache));
	CACHE=cache[0][0];
	
	//...your own code...
	 
}
