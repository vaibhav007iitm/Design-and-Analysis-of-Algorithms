#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,f,p,cost,i;
  cin>>n>>f>>p;
  int M[n];
  int E[n],T[n];
  for (i=0;i<n;i++)
    cin>>M[i];
  for(i=0;i<n;i++)
    cin>>E[i];
  sort(M,M+n);
  sort(E,E+n);
  for(i=0;i<n;i++)
    T[i]=M[i]+E[n-1-i]-f;
  cost=0;
  for(i=0;i<n;i++)
    if(T[i]>0)
    	cost+=T[i];
  cout<<cost*p<<endl;
  
