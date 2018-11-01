#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define MAX_SIZE 1000010
#define N_SIZE 100000
typedef struct Query{
    int l, r, idx;
}query;
int sq;
int N, M;
int arr[N_SIZE];
int ans[N_SIZE];
query q[N_SIZE];
int cnt[MAX_SIZE];
int sol;

bool cmp(query a,query b){
    int a_grp=a.r/sq;
    int b_grp=b.r/sq;
    return (a_grp == b_grp) ? (a.l < b.l) : (a_grp < b_grp);
}

void add(int num){
    if(++cnt[num]==1){
        sol++;
    }
}

void erase(int num){
    if(--cnt[num]==0){
        sol--;
    }
}
int main(){
    scanf("%d",&N);
    sq=sqrt(N);
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        scanf("%d %d",&q[i].l,&q[i].r);
        q[i].l--,q[i].r--;
        q[i].idx=i;
    }
    sort(q,q+M,cmp);
    int left=0,right=0;
    add(arr[0]);
    for(int i=0;i<M;i++){
        query cur=q[i];
        int nextL=cur.l;
        int nextR=cur.r;

        for(int i=left;i<nextL;i++) erase(arr[i]);
        for(int i=nextL;i<left;i++) add(arr[i]);
        for(int i=right+1;i<=nextR;i++) add(arr[i]);
        for(int i=nextR+1;i<=right;i++) erase(arr[i]);
        ans[cur.idx]=sol;
        left=nextL;
        right=nextR;
    }
    for(int i=0;i<M;i++){
        printf("%d\n",ans[i]);
    }

}
