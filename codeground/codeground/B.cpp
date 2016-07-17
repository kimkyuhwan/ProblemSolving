#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[10010][2],N,sol;
int arr[10010][2];

int solution(int pos, int sel)
{
	if (pos >= N) return 0;
	int &ret = dp[pos][sel];
	if (ret != -1) return ret;
	ret = 0;
	if (pos + 1 < N)
		ret += max(solution(pos + 2, 1) + arr[pos + 1][1], solution(pos + 1, 0) + arr[pos][0]);
	else
		ret += solution(pos + 1, 0) + arr[pos][0];
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
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�
		memset(dp, -1, sizeof(dp));
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i][0]);
		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i][1]);
		int A = max(arr[0][0], arr[0][1]);
		int B = arr[1][1];
		int sol = max(solution(1, 0)+A, solution(2, 1)+B);
		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n%d\n", test_case,sol);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}