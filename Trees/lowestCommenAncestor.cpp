#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
//Finding LCA by using binary Lifting

vector<vector<int>> adj;
vector<vector<int>> up;
vector<int> dep;

void dfs(int u=1,int p=-1,int d=0){

	up[0][u] = p;
	for(int i=1;i<20;i++){
		if(up[i-1][u] != -1)
			up[i][u] = up[i-1][up[i-1][u]];
	}
	
	dep[u] = d;
	for(int v : adj[u]){
		if(v != p)
			dfs(v,u,d+1);
	}
}

int LCA(int u,int v){
	if(dep[u] < dep[v])
		swap(u,v);
	
	int diff = dep[u] - dep[v];
	int i = 0;

	while(diff){
		if(diff & 1)
			u = up[i][u];
		i++;
		diff  >>= 1;
	}

	if(u == v)
		return v;

	for(int i = 19;i>=0; i--){
		if(up[i][u] != up[i][v]){
			u = up[i][u];
			v = up[i][v];
		}
	}

	return up[0][v];
}

void solve(){
	int n,q;
	cin >> n >> q;
	adj.resize(n+1);
	dep.resize(n+1);
	up.resize(20,vector<int>(n+1,-1));
	vector<vector<int>> queries(q,vector<int>(2));
	vector<int> res;

	for(int i=2;i<n+1;i++){
		int t;
		cin >> t;
		adj[i].push_back(t);
		adj[t].push_back(i);
	}

	for(int i=0;i<q;i++){
		cin >> queries[i][0] >> queries[i][1];
	}

	dfs();

	for(auto v : queries){
		int lca = LCA(v[0],v[1]);
		res.push_back(lca);
	}

	for(int r : res){
		cout << r << endl;
	}

	return ;
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}