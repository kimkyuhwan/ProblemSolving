#include <cstdio>
#include <algorithm>
using namespace std;
char mmap[52][52];
int T,N,M;

int checkMap(int white,int blue,int red){
    int ret=0;
    for(int i=0;i<white;i++){
        for(int j=0;j<M;j++){
            ret+=(mmap[i][j]!='W');
        }
    }
    for(int i=0;i<blue;i++){
        for(int j=0;j<M;j++){
            ret+=(mmap[i+white][j]!='B');
        }
    }
    for(int i=0;i<red;i++){
        for(int j=0;j<M;j++){
            ret+=(mmap[i+white+blue][j]!='R');
        }
    }

    return ret;
}


int main(){
    scanf("%d",&T);
    for(int testcase=1;testcase<=T;testcase++){
        int sol=100000;
        scanf("%d %d",&N,&M);
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                scanf(" %c",&mmap[i][j]);
            }
        }
        for(int w=1;w<=N-2;w++){
            for(int b=1;b+w<=N-1;b++){
                int sum=checkMap(w,b,N-w-b);
                sol=min(sol,sum);
            }
        }
        printf("#%d %d\n",testcase,sol);


    }
}
