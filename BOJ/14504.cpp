#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX_SIZE 200010
int N, M, Q, sq;
int arr[MAX_SIZE];
int sorted[MAX_SIZE];
int a,b,k;

int getLargeInGroup(int groupIdx,int K){
    int ret=sq;
    int begin=groupIdx*sq;
    int end=begin+sq;
    ret-=upper_bound(sorted+begin,sorted+end,k)-(sorted+begin);
    return ret;
}

int solution(int a,int b,int k){
    int ret=0;
    int a_group=a/sq;
    int b_group=b/sq;
    if(a_group==b_group){
        for(int i=a;i<=b;i++){
            if(arr[i]>k) ret++;
        }
        return ret;
    }

    for(int i=a_group+1;i<b_group;i++) {
        ret+=getLargeInGroup(i,k);
    }
    for(int i=a;i<(a_group+1)*sq;i++){
        if(arr[i]>k) ret++;
    }
    for(int i=b_group*sq;i<=b;i++){
        if(arr[i]>k) ret++;
    }
    return ret;
}


void SortingGroup(int groupIdx){
    int begin=groupIdx*sq;
    int end=begin+sq;
    for(int i=begin;i<end;i++)
        sorted[i]=arr[i];
    puts("BEFORE");
    for(int i=begin;i<end;i++)
            printf("%d ",sorted[i]);
    sort(sorted+begin,sorted+end);
    puts("");
    puts("AFTER");
    for(int i=begin;i<end;i++)
        printf("%d ",sorted[i]);
    puts("");
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    sq=sqrt(N);

    for(int i=0;i<N/sq;i++){
        SortingGroup(i);
    }
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        scanf("%d",&Q);
        if(Q==1){
            scanf("%d %d %d",&a,&b,&k);
            a--,b--;
            printf("%d\n",solution(a,b,k));
        }
        else if(Q==2){
            scanf("%d %d",&a,&k);
            a--;
            arr[a]=k;
            SortingGroup(a/sq);
        }
    }
    return 0;
}
