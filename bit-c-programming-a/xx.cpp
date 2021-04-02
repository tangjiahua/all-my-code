#include <stdio.h>
#include <string.h>
int result;
int num[100];
char op[100];
void cal(int n) {
	if (n == 1) {
		result = num[0];
		return;
	}
	int i;
	for (i = 0;i < n - 1;i++) {
		if (op[i] == '*' || op[i] == '/') {
			break;
		}
	}
	if (i == n - 1) {
		i = 0;
	}
	switch (op[i]) {
	case '+':num[i] = num[i] + num[i + 1];break;
	case '-':num[i] = num[i] - num[i + 1];break;
	case '*':num[i] = num[i] * num[i + 1];break;
	case '/':num[i] = num[i] / num[i + 1];break;
	}
	int k;
	for (k = i;k < n - 2;k++) {
		num[k + 1] = num[k + 2];
		op[k] = op[k + 1];
	}
	cal(n - 1);
}

int main()
{
	char in[100];
	fgets(in, 100, stdin);
	int i = 0, cur = 0, j;
	int l = strlen(in) - 1;
	while (i < l) {
		if (in[i] >= '0'&&in[i] <= '9') {
			for (j = i;in[j] >= '0'&&in[j] <= '9';j++) {
				num[cur] = 10 * num[cur] + in[j] - 48;
			}
			i = j;
		}
		else {
			op[cur++] = in[i];
			i++;
		}
	}
	cal(cur+1);
	printf("%d\n", result);
    return 0;
}
