#include<bits/stdc++.h>
#include<limits>
using namespace std;
int main(){
  long long H,N,C,i,count,minimum;
  cin>>H>>N>>C;
  vector<long long> h_new(N),p(N);
  //long long h_new[N],p[N];
  for(i=0;i<N;i++){
    cin>>h_new[i]>>p[i];
  }
  vector<long long> h(N+1);
  //long long h[N+1];
  h[0]=0;
  for(i=1;i<N;i++)
    h[i]=h_new[i]-h_new[i-1];
  h[N]=H-h_new[N-1];
  vector<long long> M[N];
  for(i=0;i<N;i++)
    M[i].resize(C+1);
  //long long M[C+1][N];
  for(i=h[1];i<=C;i++){
    M[0][i]=p[0]*i;
  }
  for(i=1;i<N-1;i++){
    minimum=numeric_limits<long long>::max();
    count=0;
    while(h[i]+count<=C && count<=h[i+1]){
      if(M[i-1][h[i]+count]+(p[i]*(h[i+1]-count))<minimum)
        minimum=M[i-1][h[i]+count]+(p[i]*(h[i+1]-count));
        count++;
      }
    M[i][h[i+1]]=minimum;
    count=1;
    while(h[i+1]+count<=C){
      if(h[i]+h[i+1]+count<=C)
        M[i][h[i+1]+count]=min(M[i][h[i+1]+count-1]+p[i],M[i-1][h[i]+h[i+1]+count]);
      else
        M[i][h[i+1]+count]=M[i][h[i+1]+count-1]+p[i];
      count++;
    }
  }
  //cout<<i<<endl;
  minimum=numeric_limits<long long>::max();
  //cout<<minimum<<endl;
  count=0;
  while(h[i]+count<=C && count<=h[i+1]){
    if(M[i-1][h[i]+count]+(p[i]*(h[i+1]-count))<minimum)
      minimum=M[i-1][h[i]+count]+(p[i]*(h[i+1]-count));
    count++;
  }
  //M[h[i+1]][i]=minimum;
  cout<<minimum<<endl;;
}
