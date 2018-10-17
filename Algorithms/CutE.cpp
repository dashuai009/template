#include<bits/stdc++.h>
using namespace std;
const int N=100;
struct edge{int to,nxt;}e[N*2];
int head[N],n,ecnt;
int low[N],dfn[N],dfs_clock;
vector<pair<int,int> >bridge;
void addedge(int u,int v){
    e[++ecnt]=(edge){v,head[u]};head[u]=ecnt;
    e[++ecnt]=(edge){u,head[v]};head[v]=ecnt;
}
void dfs(int u,int fa){
	dfn[u]=low[u]=++dfs_clock;
    for(int i=head[u],v;i;i=e[i].nxt)
        if(!dfn[v=e[i].to]){
			dfs(v,u);
			low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]){
                bridge.push_back(make_pair(u,v));
            }
		}else if(dfn[v]<dfn[u]&&v!=fa){
            low[u]=min(low[u],dfn[v]);
        }
}
void tarjan(){
    for(int i=1;i<=n;++i)
        if(!dfn[i])dfs(i,-1);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        int u,v;
        scanf("%d %d",&u,&v);
        addedge(u,v);
    }
}