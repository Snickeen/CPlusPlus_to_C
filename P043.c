
//求最大公约数 
int gcd(int a,int b){
	if(b==0) return a;
	else return gcd(b,a%b);
} 

//简化上面的代码 
int GCD(int a,int b){
	return b==0 ? a : GCD(b,a%b);
}


//求最小公倍数
int lcm(int a,int b){
	return a/gcd(a,b)*b;
}

