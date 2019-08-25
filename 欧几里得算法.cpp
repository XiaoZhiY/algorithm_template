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

int exgcd(int a,int b,int& x,int& y){//a*x+b*y=gcd(a,b)��һ��� 
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	int g=exgcd(b,a%b,y,x);
	y=y-(a/b)*x;	//������ 
	return g;
} 

/*
ͨ��exgcd�������ax+by=gcd(a,b)��һ���(x0,y0)
ͨ��Ϊ(x0+kb',y0-ka') b'=b/gcd  a'=a/gcd 
��ô����ax+by=c��˵���c��gcd(a,b)��������,����Ϊ n ��
��ôax+by=c��һ���Ϊ(nx0,ny0),����������������޽�
ͨ��Ϊ(nx0+kb',ny0-ka') 
��С�������� X=(nx0%b'+b')%b' 
*/
int main()
{
	int x,y;
	cout<<exgcd(6,15,x,y)<<endl;
	cout<<x<<" "<<y<<endl;
	return 0;
}
