#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int N, T,len,dot;
char val[200010];
vector<int> v;
int main()
{
	scanf("%d %d", &N,&T);
	scanf("%s", val);
	len = strlen(val);
	for (int i = 0; i < len; i++)
		if (val[i] == '.')
		{
			dot = i;
			break;
		}
	for (int i = dot + 1; i < len; i++)
	{
		if (val[i] >= '5')
		{
			v.push_back(i);
			break;
		}
	}
	int cnt = 0;
	int last =len-1;
	while (!v.empty() && cnt<T)
	{
		cnt++;
		int cur = v.front();
		v.pop_back();
		int there = cur-1;
		last = cur - 1;
		if (there == dot)
		{
			int updat = there - 1;
			if (val[updat] == '9')
			{
				while (updat >= 0 && val[updat] == '9')
				{
					val[updat] = '0';
					updat--;
				}
				if (updat == -1)
					printf("1");
				else
					val[updat]++;
				
			}
			else
			{
				val[updat]++;
			}
			break;
		}
		else
		{
			
			val[last]++;
			if (val[last] >= '5') v.push_back(last);
		}
	}
	for (int i = 0; i <= last; i++)
		printf("%c", val[i]);
}