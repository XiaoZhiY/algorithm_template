#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <map>
#include <sstream>
#include <iterator>
#include <deque>
#include <list>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

using namespace std;



const int maxn = 100000 + 10;
const int logn = log(maxn) / log(2) + 10;
int dp[maxn][26];

void RMQ_init(const vector<int>& a)
{
	int n = a.size();
	for (int i = 0; i < n; i++)
		dp[i][0] = a[i];
	for (int j = 1; (1 << j) <= n; j++)
	{
		for (int i = 0; i + (1 << j) - 1 < n; i++)
		{
			dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int RMQ(int l, int r)
{
	int k = 0;
	while ((1 << (k + 1)) < (r - l + 1)) k++;
	return min(dp[l][k], dp[r - (1 << k) + 1][k]);
}

int main() 
{
	vector<int> a = { 9,4,5,6,1,7,2,8,3 };
	RMQ_init(a);
	return 0;
}