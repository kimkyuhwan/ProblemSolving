#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char S[1010];
char str[1010];
int T, N;
char value[256];


int main(){
    value['a']='2';    value['b']='2';    value['c']='2';
    value['d']='3';    value['e']='3';    value['f']='3';
    value['g']='4';    value['h']='4';    value['i']='4';
    value['j']='5';    value['k']='5';    value['l']='5';
    value['m']='6';    value['n']='6';    value['o']='6';
    value['p']='7';    value['q']='7';    value['r']='7'; value['s']='7';
    value['t']='8';    value['u']='8';    value['v']='8';
    value['w']='9';    value['x']='9';    value['y']='9'; value['z']='9';
    scanf("%d",&T);
    for(int testcase=1;testcase<=T;testcase++){
        int sol=0;
        scanf(" %s %d",S, &N);
        int ssz=strlen(S);
        for(int i=0;i<N;i++){
            scanf(" %s",str);
            int sz=strlen(str);
            if(sz!=ssz) {
                continue;
            }
            for(int j=0;j<=sz;j++){
                if(j==sz) {
                    sol++;
                    break;
                }
                if(value[str[j]]!=S[j]){
                    break;
                }
            }
        }
        printf("#%d %d\n",testcase,sol);
    }
}
