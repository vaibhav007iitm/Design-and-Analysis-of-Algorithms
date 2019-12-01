#include<bits/stdc++.h>
#define INF 8000000000
class edge_weight{
public:
  int b,w;
};
class vertex_characteristics{
public:
  int a,v=0;
  float d=INF;
};
using namespace std;
int main(){
  vector<edge_weight> adjlist[2001];
  int i,j,m,A,B,a,w,b;
  edge_weight e1,e2;
  set<int> s;
  set<int>::iterator iters;
  cin>>m>>A>>B;
  for(i=0;i<m;i++){
    cin>>a>>w>>b;
    e1.b=b;
    e1.w=w;
    e2.w=w;
    e2.b=a;
    adjlist[a].push_back(e1);
    adjlist[b].push_back(e2);
    s.insert(a);
    s.insert(b);
  }
  map<int,vertex_characteristics> V;
  map<int,vertex_characteristics>::iterator iterv;
  vertex_characteristics v;
  for(iters=s.begin();iters!=s.end();iters++){
    v.a=*iters;
    V[v.a]=v;
  }
  V[A].d=0;
  vertex_characteristics u;
  for(i=0;i<V.size();i++){
    u.d=INF;
    for(iterv=V.begin();iterv!=V.end();iterv++){
      if(V[iterv->first].v==0 && V[iterv->first].d<u.d)
        u=V[iterv->first];
    }
    V[u.a].v=1;
    for(j=0;j<adjlist[u.a].size();j++){
      if(V[adjlist[u.a][j].b].v==0 && V[adjlist[u.a][j].b].d>u.d+adjlist[u.a][j].w)
        V[adjlist[u.a][j].b].d=u.d+adjlist[u.a][j].w;
    }
  }
  if(V.find(B)==V.end())
    cout<<"NO\n";
  else if(V[B].d==INF)
    cout<<"NO\n";
  else
    cout<<"YES\n"<<V[B].d<<endl;
}
