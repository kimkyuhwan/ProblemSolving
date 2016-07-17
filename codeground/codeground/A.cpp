#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct rectangle
{
	int Ax, Ay, Bx, By;
	bool operator<(const rectangle &b) const
	{
		return Ax <= b.Ax && Ay <= b.Ay && Bx >= b.Bx && By >= b.By;
	}
	bool isInclude(const rectangle &b)
	{
		if (Bx >= b.Bx)
			return  Ay <= b.Ay && By >= b.By;
		else
			return false;
	}
};

int N, M, K;
vector<rectangle> R;


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
		R=vector<rectangle>(K);
		for (int i = 0; i < K; i++)
			scanf("%d %d %d %d", &R[i].Ax, &R[i].Ay, &R[i].Bx, &R[i].By);
		sort(R.begin(), R.end());
		vector<rectangle> LIS;
		LIS.push_back(R[0]);
		for (int i = 1; i < K; i++)
		{
			if (LIS.back() < R[i])
				LIS.push_back(R[i]);
			else
			{
				vector<in>::iterator it = lower_bound(LIS.begin(), LIS.end(), R[i]);
				*it = i;
			}
		}
		/*
		for (int i = 1; i < K; i++)
		{
			bool isMade = true;
			for (int j = 0; j < A.size(); j++)
			{
				int here = A[j].first;
				if (R[here].isInclude(R[i]))
				{
					A[j].second++;
					isMade = false;
				}
			}
			if (isMade)
				A.push_back(make_pair(i, 1));
		}
		for (int i = 0; i < A.size(); i++)
			sol = max(sol, A[i].second);*/
		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n%d\n", test_case,LIS.size());

	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}