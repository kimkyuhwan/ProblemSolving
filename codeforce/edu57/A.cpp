#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int T;
int l,r;
int main(){
	freopen("input.txt","r",stdin);
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		scanf("%d %d",&l,&r);
		printf("%d %d\n",l,2*l);
	}
	return 0;
}