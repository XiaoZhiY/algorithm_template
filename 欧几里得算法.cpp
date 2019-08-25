/*
*/
#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <vector> 
#include <set>
#include <algorithm>
#include <math.h>
#include <string> 
#include <string.h>
using namespace std;

int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}

int exgcd(int a,int b,int& x,int& y){//a*x+b*y=gcd(a,b)的一组解 
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	int g=exgcd(b,a%b,y,x);
	y=y-(a/b)*x;	//新增的 
	return g;
} 

/*
通过exgcd可以求出ax+by=gcd(a,b)的一组解(x0,y0)
通解为(x0+kb',y0-ka') b'=b/gcd  a'=a/gcd 
那么对于ax+by=c来说如果c是gcd(a,b)的整数倍,假设为 n 倍
那么ax+by=c的一组解为(nx0,ny0),如果不是整数倍则无解
通解为(nx0+kb',ny0-ka') 
最小的正数解 X=(nx0%b'+b')%b' 
*/
int main()
{
	int x,y;
	cout<<exgcd(6,15,x,y)<<endl;
	cout<<x<<" "<<y<<endl;
	return 0;
}
