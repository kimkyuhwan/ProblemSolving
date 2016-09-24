#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int N, W, H, L;
int Sy, Sx;
char mmap[12][12];
int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };
vector<pair<int, int> > robot;
set<vector< pair<int, int> > > s;
queue < vector<pair<int, int>  > > q;

bool isPossible(int y, int x,int rb,vector<pair<int,int> > &v)
{
	if (!(x >= 0 && x < W && y >= 0 && y < H)) return false;
	if (mmap[y][x] == 'W') return false;
	for (int i = 0; i < N; i++)
	{
		if (i == rb) continue;
		if (v[i].first == y && v[i].second == x) return false;
	}
	return true;
}


int main()
{
	scanf("%d %d %d %d", &N, &W, &H, &L);
	robot.resize(N);
	for (int i = 0; i < H; i++)
		scanf("%s", mmap[i]);
	for(int i=0;i<H;i++)
		for (int j = 0; j < W; j++)
		{
			if (mmap[i][j] == 'X')
				Sy = i, Sx = j;
			if (mmap[i][j] >= '1' && mmap[i][j] <= '4')
			{
				robot[mmap[i][j] - '1'].first = i;
				robot[mmap[i][j] - '1'].second = j;
			}
		}
	q.push(robot);
	s.insert(robot);
	int sz = 0;
	int sol = 0;
	while (sz = q.size())
	{
		sol++;
		if (sol > 10) break;
		for (int i = 0; i < sz; i++) {
			vector<pair<int, int> > cur=q.front();
			q.pop();
			for (int rb = 0; rb < N; rb++)
			{
				for (int d = 0; d < 4; d++)
				{
					int nextY=cur[rb].first+dy[d], nextX=cur[rb].second+dx[d];
					for (;; nextY += dy[d], nextX += dx[d])
					{
						if (!isPossible(nextY, nextX, rb, cur)) break;
					}
					vector<pair<int, int> > temp=cur;
					temp[rb].first = nextY-dy[d];
					temp[rb].second = nextX-dx[d];
					sort(++temp.begin(), temp.end());
					if (s.count(temp)) continue;
					if (temp[0].first == Sy && temp[0].second == Sx) {
						printf("%d", sol);
						return 0;
					}
					s.insert(temp);
					q.push(temp);
				}
			}
		}
	}
	puts("NO SOLUTION");
	return 0;
}