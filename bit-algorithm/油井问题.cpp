#include <stdio.h>
#include <iostream>
using namespace std;
int z, y[2000005], n;

void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
//冒泡排序 
void BubbleSort(int a[], int p, int r)
{

	bool change;
	for (int i = p; i <= r - 1; i++)
	{
		change = false;
		for (int j = i + 1; j <= r; j++)
		{
			if (a[j] < a[j - 1])
			{
				Swap(a[j], a[j - 1]);
				change = true;
			}
		}

		if (false == change)
		{
			break;
		}
	}
}


int Partition(int a[], int p, int r, int x)
{
	int i = p - 1, j = r + 1;

	while (true)
	{
		while (a[++i] < x && i < r);
		while (a[--j] > x);
		if (i >= j)
		{
			break;
		}
		Swap(a[i], a[j]);
	} 
	return j;
}


int Select(int a[], int p, int r, int k)
{
	if (r - p < 75)
	{
		BubbleSort(a, p, r);
		return a[p + k - 1];
	}

	for (int i = 0; i <= (r - p - 4) / 5; i++)
	{
		BubbleSort(a, p + 5 * i, p + 5 * i + 4);
		Swap(a[p + 5 * i + 2], a[p + i]);
        int x = Select(a, p, p + (r - p - 4) / 5, (r - p - 4) / 10);
        int ii = Partition(a, p, r, x);
        int j = ii - p + 1;
        if(k <= j) return Select(a,p,ii,k);
        else return Select(a,ii+1,r,k-j);
	}

	
	// if (k <= j)
	// {
	// 	return Select(a, p, i, k);
	// }
	// else
	// {
	// 	return Select(a, i + 1, r, k - j);
	// }
}

int main()
{
	int ppp, ans;
	while (scanf("%d,%d\n", &z, &y[n]) != EOF) {
		n++;
	}
	if (n % 2 == 1) {
		ppp = (n+1)/2;
		ans = Select(y, 0, n - 1, ppp);
	}
	else {
		ppp = n / 2;
		ans = Select(y, 0, n - 1, ppp);
	}
	printf("%d\n", ans);
	return 0;
}
