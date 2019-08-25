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
#include <cstring>
#include <cstdio>

using namespace std;
const int maxn =  11000000+5;

char a[maxn];
char str[2*maxn];
int rad[2*maxn];  //rad[i]为以i为中心的最长回文串的半径比如 #a#a# 的半径为3 
int ans=1;
 
int main()
{
	scanf("%s",a);
	int len=strlen(a);
	int cur=0;
	for(int i=0;i<len;i++){
		str[cur++]='#';
		str[cur++]=a[i];
	}
	str[cur]='#';
//	cout<<str<<endl;
	rad[0]=1;
	int cen = 0;
	for(int i=1;i<2*len+1;i++){
		if(i<cen+rad[cen]){
			rad[i]=min(rad[2*cen-i],cen+rad[cen]-i);
		}
		while((i+rad[i]<2*len+1) && (i-rad[i]>=0) && str[i+rad[i]]==str[i-rad[i]] )
			rad[i]++;
		ans=max(ans,rad[i]-1);
		if(i+rad[i]>cen+rad[cen])
		{
			cen=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}
