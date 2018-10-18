#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int maxx,N,M,idx;
char n[4];
int main()
{
	scanf(" %d %d", &N, &M);
	if (N < 10) idx = 1;
	else if (N < 100) idx = 2;
	else if (N < 1000) idx = 3;
	else idx = 4;
	maxx = min(N*idx, M);
	for (int i = 0; i < idx; i++)
	{
		n[i] = (N % 10)+'0';
		N /= 10;
	}
	for (int i = 0, j = idx - 1; i < maxx; i++, j = ((j - 1) + idx) % idx)
		printf("%c", n[j]);
}