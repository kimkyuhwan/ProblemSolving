#include <cstdio>
#include <cstring>
char a[20], b[20];
int sol;
int main()
{
	scanf("%s %s", a,b);
	int sz = strlen(b) - strlen(a);
	for (int i = 0; i < strlen(b) - sz; i++)
	{
		if (a[i] == b[sz + i])
			sol++;
	}
	printf("%d", sol);
}