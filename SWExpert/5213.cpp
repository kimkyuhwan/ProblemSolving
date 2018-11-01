#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
int N, cnt;
int L,R;
ll dp[1000001];
ll psum[1000001];
bool isPrime[1000001];
vector<int> prime;
void getPrime(){
    isPrime[2]=true;
    dp[1]=1;
    dp[2]=1;
    for(int i=3;i<1000000;i+=2){
        isPrime[i]=true;
    }
    for(int i=3;i<1000000;i+=2){
        if(!isPrime[i]) continue;
        if(i<=1000)
            prime.push_back(i);
        dp[i]=i+1;
        for(int j=i*3;j<1000000;j+=i){
            isPrime[j]=false;
        }
    }
}

ll getfunc(int pos){
    int r=pos;
    ll ret=1;
    while(r%2==0) r/=2;
    if(dp[r]!=-1) return dp[r];
    for(int i=0;i<prime.size() && sqrt(r)>=prime[i];i++){
        int cnt=0;
        int gop=1;
        int sum=1;
        while(r%prime[i]==0){
            cnt++;
            gop*=prime[i];
            sum+=gop;
            r/=prime[i];
        }
        ret*=sum;
    }
    return dp[pos]=ret*getfunc(r);
}

void getPsum(){
    for(int i=1;i<=1000000;i++){
        psum[i]=psum[i-1]+getfunc(i);
    }
}
int main(){
    memset(dp,-1,sizeof(dp));
    getPrime();
    getPsum();
    scanf("%d",&N);
    for(int testcase=1;testcase<=N;testcase++){
        scanf("%d %d",&L,&R);
        printf("#%d %lld\n",testcase,psum[R]-psum[L-1]);
    }
}
