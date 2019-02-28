#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long ll;
int N,M,val,Q;
vector<vector<int> > stone;
vector<pair<pair<int,int>,ll> > qry;
ll need[300010];
ll tree[300010];
int lo[300010];
int hi[300010];

vector<vector<int> > vt;
void init(){
	memset(tree,0,sizeof(tree));
}

void update(ll pos, ll val) {
    while (pos <= M) {
        tree[pos] += val;
        pos += (pos&-pos);
    }
}
ll query(int pos) {
    ll ret = 0;
    while (pos > 0) {
        ret += tree[pos];
        pos -= (pos&-pos);
    }
    return ret;
}

void rainStone(int a,int b,int stone){
	if(a<=b) update(a,stone), update(b+1,-stone);
	else update(1,stone), update(b+1,-stone), update(a,stone);
}

int main(){
	scanf("%d %d",&N,&M);
	stone.resize(N+1);
	for(int i=1;i<=M;i++) {
		scanf("%d",&val);
		stone[val].push_back(i);
	}
	for(int i=1;i<=N;i++) scanf("%lld",&need[i]);
	scanf("%d",&Q);
	qry.resize(Q+1);
	vt.resize(Q+2);
	for(int i=1;i<=Q;i++){
		scanf("%d %d %lld",&qry[i].first.first,&qry[i].first.second,&qry[i].second);
	}
	for(int i=1;i<=N;i++){
		lo[i]=1;
		hi[i]=Q+1;
	}
	bool isDone=false;
	while(!isDone){
		isDone=true;
		init();
		for(int i=1;i<=N;i++){
			if(lo[i]!=hi[i]){
				int mid=(lo[i]+hi[i])>>1;
				vt[mid].push_back(i);
				isDone=false;
			}
		}
		for(int i=1;i<=Q;i++){
			rainStone(qry[i].first.first,qry[i].first.second,qry[i].second);
			while(vt[i].size()){
				int idx = vt[i].back();
				vt[i].pop_back();
				ll sum=0;
				for(int j=0;j<stone[idx].size();j++){
					int here=stone[idx][j];
					sum+=query(here);
					if(sum>=need[idx]) break;
				}
				if(sum>=need[idx]) hi[idx]=i;
				else lo[idx]=i+1;
			}
		}
	}
	for(int i=1;i<=N;i++){
		if(lo[i]==Q+1) puts("NIE");
		else printf("%d\n",lo[i]);
	}


}