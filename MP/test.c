#include <stdio.h>
#include <string.h>
int main(void)
{
    char str[1505];
    int s;
    int ans = 0;
    while ((scanf("%s", str)) != EOF)
    {
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] == ' ')
            {
                str[i] = '+';
            }
            else if (str[i] == 'a')
            {
                str[i] = '+';
            }
            else if (str[i] == 'b')
            {
                str[i] = '+';
            }
            else if (str[i] == 'c')
            {
                str[i] = '+';
            }
            else if (str[i] == 'd')
            {
                str[i] = '+';
            }
            else if (str[i] == 'e')
            {
                str[i] = '+';
            }
            else if (str[i] == 'f')
            {
                str[i] = '+';
            }
            else if (str[i] == 'g')
            {
                str[i] = '+';
            }
            else if (str[i] == 'h')
            {
                str[i] = '+';
            }
            else if (str[i] == 'i')
            {
                str[i] = '+';
            }
            else if (str[i] == 'j')
            {
                str[i] = '+';
            }
            else if (str[i] == 'k')
            {
                str[i] = '+';
            }
            else if (str[i] == 'l')
            {
                str[i] = '+';
            }
            else if (str[i] == 'm')
            {
                str[i] = '+';
            }
            else if (str[i] == 'n')
            {
                str[i] = '+';
            }
            else if (str[i] == 'o')
            {
                str[i] = '+';
            }
            else if (str[i] == 'p')
            {
                str[i] = '+';
            }
            else if (str[i] == 'q')
            {
                str[i] = '+';
            }
            else if (str[i] == 'r')
            {
                str[i] = '+';
            }
            else if (str[i] == 's')
            {
                str[i] = '+';
            }
            else if (str[i] == 't')
            {
                str[i] = '+';
            }
            else if (str[i] == 'u')
            {
                str[i] = '+';
            }
            else if (str[i] == 'v')
            {
                str[i] = '+';
            }
            else if (str[i] == 'w')
            {
                str[i] = '+';
            }
            else if (str[i] == 'x')
            {
                str[i] = '+';
            }
            else if (str[i] == 'y')
            {
                str[i] = '+';
            }
            else if (str[i] == 'z')
            {
                str[i] = '+';
            }
        }
        int x = 1;
        int tmp = 0;
        for (int i = strlen(str) - 1; i >= 0; i--)
        {
            if (str[i] != '+')
            {
                tmp = tmp + (str[i] - '0') * x;
                x = x * 10;
            }
            else
            {
                tmp = tmp + 0;
                x = 1;
            }
            if (i == 0)
                ans += tmp;
        }
        printf("%d\n", ans);
    }

    scanf("%d", &s);
    getchar();
    return 0;
}