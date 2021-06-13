#include "pch.h"
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>


using namespace std;

struct node {
	double x, y;
}a[100005];

double distance(node a, node b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double Min(double x, double y)
{
	if (x > y)
		return y;
	else return x;
}
bool cmp_x(node a, node b)
{
	return a.x < b.x;
}
bool cmp_y(node a, node b)
{
	return a.y < b.y;
}


double find(int l, int r)
{
	double d = 10000;
	if(l == r)
        return d;
    else if(l + 1 == r)
		return distance(a[l], a[r]);
	int mid = (l + r) / 2;
	d = Min(find(l, mid), find(mid + 1, r));
	int i = l, j = r;
	
	while (i < mid && a[mid].x - a[i].x >= d)
		i++;
	while (a[j].x - a[mid].x >= d && j > mid)
		j--;

	sort(a + i + 1, a + j + 1, cmp_y);

	for (int t = i; t <= j; t++)
	{
		for (int m = t + 1; m <= j && a[m].y - a[t].y < d; m++)
		{
			double dd = distance(a[m], a[t]);
			if (d > dd)
				d = dd;
		}
	}
	return d;
}
int main()
{
	int n;
	while ((scanf("%d",&n)!=EOF) && n)
	{
		for (int i = 1; i <= n; i++)
			scanf("%lf %lf", &a[i].x, &a[i].y);
		sort(a + 1, a + n + 1, cmp_x);
		double ans = find(1, n) / 2.0;
		printf("%.2lf\n", ans);
	}

	return 1;
}