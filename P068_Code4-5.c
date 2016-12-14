
//代码4-5 确定菜单 

int INF = 987654321;
//记录menu的元素个数 
int tot;

//返回此菜单是否能满足所有人的用餐需求 
int canEverybodyEat(int menu[]);

//可烹饪的菜肴数
int M;
//判断是否做第food种菜肴
int selectMenu(int menu[],int food){
	//初始部分，到达菜单末尾时是否有解
	if(food==M){
		if(canEverybodyEat(menu)) return tot;
		//加入某个人不能吃任何菜时，返回无穷大的值 
		return INF;
	} 
	//计算不烹饪此菜肴时的答案
	int ret =  selectMenu(menu,food+1);
	//计算烹饪此菜肴时的答案，并选取最小的答案值
	menu[tot++]=food;
	if(selectMenu(menu,food+1)<ret)ret=selectMenu(menu,food+1);//总感觉这里的代码有些问题，稍后细看一下 
	tot--;
	return ret; 
} 
