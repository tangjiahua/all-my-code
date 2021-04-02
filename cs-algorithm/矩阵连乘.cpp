#include<stdio.h>
#include<iostream>
using namespace std;
 
int m[106][106];
int s[106][106];
int p[106];

int n;
 

 
void TrackPrint(int i,int j)
{
	if (i == j)
	{
		cout << 'A' << i;
		return;
	}
	
    cout << '(';
    TrackPrint(i, s[i][j]);
    TrackPrint(s[i][j] + 1, j);
    cout << ')';
}

int dp(int i, int j)
{
	for (int i = 1; i <= n; i++)
        m[i][i] = 0;
    for (int r = 1; r <= n - 1;r++)
        for (int i = 1; i <= n - r; i++)
        {
            int j = i + r;
            m[i][j] = m[i][i] + m[i + 1][j] + p[i - 1] * p[i] * p[j];
            s[i][j] = i;
            for (int k = i+1; k < j; k++)
            {
                int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (m[i][j]>t)
                {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    return m[1][n];
}
int main()
{
	cin >> n;
	if (n == 1)
	{
		cout<<"0"<<endl;
		cout<<"(A1)"<<endl;
		return 2;
	}

	for (int i = 0; i <=n; i++)
		cin >> p[i];
	cout << dp(1,n) << endl;
	TrackPrint(1, n);
	cout << endl;
	return 0;
}