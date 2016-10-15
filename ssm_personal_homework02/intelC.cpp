#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
int N, M, K;
int x, y,mmm;
ll visited[100010];
vector < vector<pair<int, int> > > dotA,dotB;
ll T;
int dir = 0; //  기울기 1 상향 , 기울기 1 하향 
int curx = 0;
int cury = 0;
int distX, distY;

int getPlusOne(int X, int Y)
{
	return Y - X;
}
int getMinusOne(int X, int Y)
{
	return Y + X;
}
bool isCorner(int X, int Y)
{
	return ((X == 0) && (Y == 0)) || ((X == 0) && (Y == M-1)) || ((X == N-1) && (Y == 0)) || ((X == N-1) && (Y == M-1));

}
int getFirstDot(int a, int b)
{
	if (a == 1)
		return max(0, -b);
	else
		return max(0, b - M);
}
int getLastDot(int a, int b)
{
	if (a == 1)
		return min(M - b, N);
	else
		return min(N, b);
}
int main()
{
	freopen("input.txt", "r", stdin);
	memset(visited, -1, sizeof(visited));
	scanf("%d %d %d", &N, &M, &K);
	dotA.resize(N + M + 1);
	dotB.resize(N + M + 1);
	mmm = N-1;
	for (int i = 0; i < K; i++)
	{
		scanf("%d %d", &x, &y);
		int aa = getPlusOne(x, y) + mmm;
		int bb = getMinusOne(x, y);
		dotA[aa].push_back(make_pair(i, x));
		dotB[bb].push_back(make_pair(i, x));
	}
	int nextTime = 0;
	do
	{
		if (dir == 0) {
			distX = N - curx;
			distY = M - cury;
			int aa = getPlusOne(curx, cury)+mmm;
			nextTime = min(distX, distY);
			curx += nextTime;
			cury += nextTime;
			int xx = getFirstDot(1, aa-mmm);
			for (int i = 0; i < dotA[aa].size(); i++)
			{
				int here = dotA[aa][i].first;
				int nx = dotA[aa][i].second;
				if (visited[here]!=-1) continue;
				visited[here] = T + (nx - xx);
			}
			if (distX > distY)
			{
				dir = 1;
			}
			else if (distY > distX)
			{
				dir = 3;
			}
		}
		else if (dir == 1)
		{
			distX = N - curx;
			distY = cury;
			nextTime = min(distX, distY);
			curx += nextTime;
			cury -= nextTime;
			int bb = getMinusOne(curx, cury);
			int xx = getFirstDot(-1, bb);
			for (int i = 0; i < dotB[bb].size(); i++)
			{
				int here = dotB[bb][i].first;
				int nx = dotB[bb][i].second;
				if (visited[here] != -1) continue;
				visited[here] = T + (nx - xx);
			}
			if (distX > distY)
			{
				dir = 0;
			}
			else if (distY > distX)
			{
				dir = 2;
			}

		}
		else if (dir == 2)
		{
			distX = curx;
			distY = cury;
			int aa = getPlusOne(curx, cury) + mmm;
			nextTime = min(distX, distY);
			curx -= nextTime;
			cury -= nextTime;

			int xx = getLastDot(1, aa-mmm);
			for (int i = 0; i < dotA[aa].size(); i++)
			{
				int here = dotA[aa][i].first;
				int nx = dotA[aa][i].second;
				if (visited[here] != -1) continue;
				visited[here] = T + (xx - nx);
			}
			if (distX > distY)
			{
				dir = 3;
			}
			else if (distY > distX)
			{
				dir = 1;
			}

		}
		else
		{
			distX = curx;
			distY = M - cury;
			nextTime = min(distX, distY);
			curx -= nextTime;
			cury += nextTime;

			int bb = getMinusOne(curx, cury);
			int xx = getLastDot(-1, bb);
			for (int i = 0; i < dotB[bb].size(); i++)
			{
				int here = dotB[bb][i].first;
				int nx = dotB[bb][i].second;
				if (visited[here] != -1) continue;
				visited[here] = T + (xx - nx);
			}
			if (distX > distY)
			{
				dir = 2;
			}
			else if (distY > distX)
			{
				dir = 0;
			}

		}
		T += nextTime;
	} while (distX!=distY);
	for (int i = 0; i < K; i++)
		printf("%lld\n", visited[i]);
}