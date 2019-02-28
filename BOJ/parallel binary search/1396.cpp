#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
int a,b,c;
int q,x,y;
vector<pair<int,pair<int,int> > > edge;

// union find
vector< vector<int> > des;
int w[400010];
int sz[400010];
int parent[400010];
int dp[400010];
int par[400000 + 11][21];
int find(int p){
	if(parent[p]==p) return p;
	return parent[p]=find(parent[p]);
}

void merge(int a,int b){
	int pa=find(a);
	int pb=find(b);
	if(pa==pb) return;
	parent[pa]=pb;
}

void dfs(int here,int prev){
	for(int i=0;i<des[here].size();i++){
		int there =des[here][i];
		if(there==prev) continue;
		par[there][0]=here;
		dp[there]=dp[here]+1;
		dfs(there,here);
	}
}

void f() {
    for (int j = 1; j < 21; j++) {
        for (int i = 1; i <= n+m; i++) {
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
}


int getLCA(int x,int y){
	if (dp[x] > dp[y])
        swap(x, y);
    for (int i = 20; i >= 0; i--) {
        if (dp[y] - dp[x] >= (1 << i)) 
            y = par[y][i];
    }
    if (x == y) return x;
    for (int i = 20; i >= 0; i--) {
        if (par[x][i] != par[y][i]) {
            x = par[x][i];
            y = par[y][i];
        }
    }
    return par[x][0];
}

int main(){
	scanf("%d %d",&n,&m);
	edge.resize(n+m+1);
	des.resize(n+m+1);
	for(int i=1;i<=n+m;i++) {
		parent[i]=i;
		sz[i]=1;
	}
	for(int i=n+1;i<=n+m;i++){
		scanf("%d %d %d",&a,&b,&c);
		edge[i].first=c;
		edge[i].second.first=a;
		edge[i].second.second=b;
	}
	sort(edge.begin(),edge.end());
	for(int i=n+1;i<=n+m;i++){
		a = edge[i].second.first;
		b = edge[i].second.second;
		c = edge[i].first;
		int pa = find(a);
		int pb = find(b);

		if(pa == pb) continue;
		sz[i]=sz[pa]+sz[pb];
		w[i]=c;
		des[i].push_back(pa);
		des[i].push_back(pb);
		merge(a,i);
		merge(b,i);
	}
	for(int i=n+m;i>0;i--){
		if(dp[i]==0){
			dfs(i,0);
		}
	}
	
	f();
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d %d",&x,&y);
		if(find(x)==find(y)){
			int lca= getLCA(x,y);
			printf("%d %d\n",w[lca],sz[lca]);
		}
		else{
			puts("-1");
		}
	}
}