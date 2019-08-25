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
#include <set>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

using namespace std;

const int maxn = 10000 + 10;

void getFail(char *p, int *f)
{
	int m = strlen(p);
	f[0] = 0; f[1] = 0;
	for (int i = 1; i < m; i++)
	{
		int j = f[i];
		while (j && p[i] != p[j]) j = f[j];
		f[i + 1] = p[i] == p[j] ? j + 1 : 0;
	}
}

void find(char *s, char *p, int *f)
{
	int n = strlen(s), m = strlen(p);
	getFail(p, f);
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		while (j && p[j] != s[i]) j = f[j];
		if (p[j] == s[i]) j++;
		if (j == m) printf("%d\n", i - m + 1);
	}
}

int main()
{
	char s[maxn], p[maxn];
	int f[maxn];

	scanf("%s", s);
	scanf("%s", p);
	find(s, p, f);
	return 0;
}

