/*
  접미사 배열 SuffixArray를 구하는 알고리즘 코드입니다.
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

#define MAX_SIZE 500010

string str;
int len, N;
vector<int> group; // 정렬과정에서 필요한 그룹 번호
vector<int> newGroup; // Group 임시 배열
vector<int> suffixArray; // 접미사 배열을 사전순으로 정렬했을 시 시작 인덱스를 저장
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
    for(int j=suffixArray[group[i]+1];str[i+k]==str[j+k];k++);
    lcp[group[i]]=k;
  }
}
int main(){
  cin>>N>>str;
  getSuffixArray();
  getLCP();
  sort(lcp.rbegin(),lcp.rend());
  printf("%d\n",lcp[0]);
  return 0;
}
