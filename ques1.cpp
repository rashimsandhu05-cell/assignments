#include <bits/stdc++.h>
using namespace std;

struct Edge{int u,v,w;};

int findp(int p[],int x){
    if(p[x]==x) return x;
    return p[x]=findp(p,p[x]);
}

void bfs(int n, vector<vector<int>>&g, int s){
    vector<int>vis(n,0); queue<int>q;
    vis[s]=1; q.push(s);
    while(!q.empty()){
        int u=q.front(); q.pop();
        cout<<u<<" ";
        for(int v:g[u]) if(!vis[v]) vis[v]=1,q.push(v);
    }
}

void dfsUtil(int u, vector<vector<int>>&g, vector<int>&vis){
    vis[u]=1; cout<<u<<" ";
    for(int v:g[u]) if(!vis[v]) dfsUtil(v,g,vis);
}

void dfs(int n, vector<vector<int>>&g, int s){
    vector<int>vis(n,0);
    dfsUtil(s,g,vis);
}

void prim(int n, vector<vector<pair<int,int>>>&g){
    vector<int>d(n,1e9),vis(n,0); d[0]=0; 
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0});
    int cost=0;
    while(!pq.empty()){
        auto [w,u]=pq.top(); pq.pop();
        if(vis[u]) continue;
        vis[u]=1; cost+=w;
        for(auto [v,w2]:g[u]) if(!vis[v] && w2<d[v]) d[v]=w2, pq.push({w2,v});
    }
    cout<<cost;
}

void kruskal(int n, vector<Edge>&e){
    int p[100]; for(int i=0;i<n;i++) p[i]=i;
    sort(e.begin(),e.end(),[](Edge&a,Edge&b){return a.w<b.w;});
    int cost=0;
    for(auto &x:e){
        int a=findp(p,x.u), b=findp(p,x.v);
        if(a!=b){ p[a]=b; cost+=x.w; }
    }
    cout<<cost;
}

void dijkstra(int n, vector<vector<pair<int,int>>>&g, int s){
    vector<int>d(n,1e9); d[s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,s});
    while(!pq.empty()){
        auto [du,u]=pq.top(); pq.pop();
        if(du!=d[u]) continue;
        for(auto &[v,w]:g[u])
            if(d[v]>du+w){
                d[v]=du+w;
                pq.push({d[v],v});
            }
    }
    for(int i=0;i<n;i++) cout<<d[i]<<" ";
}

int main(){
    int n,m; cin>>n>>m;

    vector<vector<int>> g(n);
    vector<vector<pair<int,int>>> wg(n);
    vector<Edge> edges;

    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back(v);
        g[v].push_back(u);
        wg[u].push_back({v,w});
        wg[v].push_back({u,w});
        edges.push_back({u,v,w});
    }

    int ch; cin>>ch;
    if(ch==1) bfs(n,g,0);
    else if(ch==2) dfs(n,g,0);
    else if(ch==3) prim(n,wg);
    else if(ch==4) kruskal(n,edges);
    else if(ch==5) dijkstra(n,wg,0);
}
