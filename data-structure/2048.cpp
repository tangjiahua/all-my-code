#pragma warning(disable : 4996)
#include <stdio.h>
int chess[18];
void move(int a, int b, int c, int d);
void check(char t, int from, int to)
{
    switch (t)
    {
    case 'w':
    {
        move(1, 5, 9, 13);
        move(2, 6, 10, 14);
        move(3, 7, 11, 15);
        move(4, 8, 12, 16);
        break;
    }
    case 'a':
    {
        move(1, 2, 3, 4);
        move(5, 6, 7, 8);
        move(9, 10, 11, 12);
        move(13, 14, 15, 16);
        break;
    }
    case 's':
    {
        move(13, 9, 5, 1);
        move(14, 10, 6, 2);
        move(15, 11, 7, 3);
        move(16, 12, 8, 4);
        break;
    }
    case 'd':
    {
        move(4, 3, 2, 1);
        move(8, 7, 6, 5);
        move(12, 11, 10, 9);
        move(16, 15, 14, 13);
        break;
    }
    }
    int flag = 0;
    while (flag == 0)
    {
        if (chess[from] == 0)
        {
            chess[from] = to;
            flag = 1;
        }
        else
        {
            from = from % 16 + 1;
            continue;
        }
    }
}
void move(int a, int b, int c, int d)
{
    int t[5], k, s[5] = {0, 0, 0, 0};
    t[0] = chess[a];
    t[1] = chess[b];
    t[2] = chess[c];
    t[3] = chess[d];
    k = 0;

    for (int i = 0; i < 4; i++)
    {
        if (t[i] != 0)
        {
            s[k] = t[i];
            k++;
        }
    }

    if (s[0] == s[1])
    {
        s[0] *= 2;
        s[1] = s[2];
        s[2] = s[3];
        s[3] = 0;
    }
    if (s[1] == s[2])
    {
        s[1] *= 2;
        s[2] = s[3];
        s[3] = 0;
    }
    if (s[2] == s[3])
    {
        s[2] *= 2;
        s[3] = 0;
    }
    chess[a] = s[0];
    chess[b] = s[1];
    chess[c] = s[2];
    chess[d] = s[3];
}
int main()
{
    int from, to;
    char t, temp;
    for (int i = 1; i <= 16; i++)
        scanf("%d\n", &chess[i]);

    while ((temp = getchar()) != '\n')
    {
        if (temp == ' ')
            continue;
        t = temp;
        scanf("%d%d", &from, &to);
        check(t, from, to);
    }

    for (int i = 1; i <= 16; i++)
    {
        if (i == 1)
            printf("%d", chess[i]);
        else
            printf(" %d", chess[i]);
    }
    printf("\n");
}