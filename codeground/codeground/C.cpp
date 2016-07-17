#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int y, x, c;
int arr[210][210];
vector<pair<int, int> > v;
int solution(int y, int x)
{
	int ret = 0;
	for (int i = 0; i < N; i++)
	{
		int Y = v[i].first, X = v[i].second;
		if (arr[Y][X] == 1)
		{
			if ((y<Y && x>X) || (y > Y && x < X))
				ret++;
		}
		else if(arr[Y][X]==0)
		{
			if (((y>Y && x>X) || (y < Y && x < X)))
				ret++;
		}
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
		scanf("%d", &N);
		memset(arr, -1, sizeof(arr));
		v.clear();
		for (int i = 0; i < N; i++)
		{
			scanf("%d %d %d", &x, &y, &c);	
			if (N > 100)
				continue;
			y *= 2;
			x *= 2;
			arr[y][x] = c;
			v.push_back(make_pair(y, x));
		}
		int sol = 0;
		if (N <= 100) {
		for(int i=1;i<=200;i+=2)
			for (int j = 1; j <= 200; j+=2)
			{
				sol = max(sol, solution(i, j));
			}
		}
		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n%d\n", test_case,sol);

	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}