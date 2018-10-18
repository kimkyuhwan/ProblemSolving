#include <cstdio>
#include <cmath>
double l, w, h,sol;
int main()
{
	scanf("%lf %lf %lf", &l, &h, &w);
	sol = sqrt((w*w + h*h));
	printf("%d %d", (int)((l*h)/sol), (int)((l*w) / sol));
	return 0;
}