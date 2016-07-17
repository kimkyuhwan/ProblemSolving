#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

struct rectangle
{
	int Ax, Ay, Bx, By;
	bool operator<(const rectangle &b) const
	{
		if (Ax == b.Ax) return Bx > b.Bx;
		return Ax < b.Ax;
	}
	bool isInclude(const rectangle &b)
	{
		return Ax <= b.Ax && Ay <= b.Ay && Bx >= b.Bx && By >= b.By;
	}
};


int N, M, K,sol;
int dp[5010];
vector<rectangle> R;
/*
vector < vector<int> > adj;
void findWhere(int &a, int here)
{
	int there = here;
	for (int i = 0; i < adj[here].size(); i++)
	{
		int temp = adj[there][i];
		if (R[temp].isInclude(R[a]))
		{
			there = temp;
			findWhere(a, there);
			return;
		}
	}
	adj[here].push_back(a);
	dist[a] = dist[here] + 1;
	sol = max(sol, dist[a]);
	return;
}*/

int solution(int pos)
{
	int &ret = dp[pos];
	if (ret != -1) return ret;
	ret = 1;
	for (int i = 0; i < K; i++)
	{
		if (i == pos) continue;
		if (R[pos].isInclude(R[i]))
			ret = max(ret, solution(i)+1);
	}
	return ret;
}



int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� sample_input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� sample_input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� sample_input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� sample_input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	freopen("input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	C++���� printf�� ����� ���, printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	���� printf�� ����� ��� setbuf(stdout, NULL) �Լ��� �ݵ�� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		scanf("%d %d %d", &N, &M, &K);
		memset(dp, -1, sizeof(dp));
		R = vector<rectangle>(K);
		for (int i = 0; i < K; i++)
			scanf("%d %d %d %d", &R[i].Ax, &R[i].Ay, &R[i].Bx, &R[i].By);
		sol = 1;
		for (int i = 0; i < K; i++)
			sol = max(sol, solution(i));
		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n%d\n", test_case, sol);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}