#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

char str[500010];
int len, N,ans, len1;
vector<int> group;
vector<int> newGroup;
vector<int> suffixArray;
vector<int> lcp;
bool cmp(int i,int j){
  if(group[i]!=group[j]) return group[i] < group[j];
  return group[i+len] < group[j+len];
}
void getSuffixArray(){
  vector<int> cnt;
  vector<int> orderToIdx;
  orderToIdx.resize(N+1);
  suffixArray.resize(N);
  group.resize(N+1);
  newGroup.resize(N+1);
  int lim=max(257,N+1);
  for(int i=0;i<N;i++) {
    suffixArray[i]=i;
    group[i]=str[i];
  }
  for(len=1;len<N;len<<=1){
    // counting sort for stable sorting
    cnt.clear(); cnt.resize(lim);
    for(int i=0;i<N;i++) cnt[group[min(i+len,N)]]++;
    for(int i=1;i<lim;i++) cnt[i]+=cnt[i-1];
    for(int idx=N-1;idx>=0;idx--) orderToIdx[--cnt[group[min(idx+len,N)]]]=idx;

    cnt.clear(); cnt.resize(lim);
    for(int i=0;i<N;i++) cnt[group[i]]++;
    for(int i=1;i<lim;i++) cnt[i]+=cnt[i-1];
    for(int idx=N-1;idx>=0;idx--) suffixArray[--cnt[group[orderToIdx[idx]]]]=orderToIdx[idx];

    newGroup[suffixArray[0]]=1;
    for(int i=1;i<N;i++){
       newGroup[suffixArray[i]]=newGroup[suffixArray[i-1]];

      if(cmp(suffixArray[i-1],suffixArray[i]))
       newGroup[suffixArray[i]]++;

    }
    group=newGroup;
  }
  for(int i=0;i<N;i++){
    group[suffixArray[i]]=i;
  }
}
void getLCP(){
  lcp.resize(N+1);
  for(int i=0,k=0;i<N;i++,k=max(0,k-1)){
    if(group[i]==N-1) continue;
    int j=suffixArray[group[i]+1];
    for(;str[i+k]==str[j+k];k++);
    lcp[group[i]]=k;
    if( (i>len1 && j<len1) || (i < len1 && j > len1)) ans=max(ans,k);
  }
}
int main(){
  scanf("%s",str);
  len1=strlen(str);
  str[len1]='$';
  scanf(" %s",str+len1+1);
  N=strlen(str);
  getSuffixArray();
  for(int i=0;i<N;i++)
  {
    printf("%d\n",suffixArray[i]);
  }
  getLCP();
  printf("%d\n",ans);
  return 0;
}
