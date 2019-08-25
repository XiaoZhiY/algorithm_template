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

string a="abcbcaabaabcbc",b="aabaab";
int Next[1000];

void getnext(){
	Next[0]=-1;
	int k=-1,j=0;
	while(j<b.length()){
		if(k==-1 || b[j]==b[k]){
			Next[++j]=++k;
		}
		else{
			k=Next[k];
		}
	}
}
 
int main()
{
	getnext();
	int i=0,j=0;
	while(i<(int)a.length() && j<(int)b.length()){
		if( j==-1 ||a[i]==b[j])
		{
			i++;
			j++;
		}
		else{
			j=Next[j];
		}
	}
	if(j<b.length()) cout<<"Not found"<<endl;
	else cout<<a.substr(i-j,j)<<endl;
	return 0;
}
