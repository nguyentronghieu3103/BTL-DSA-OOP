#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
	int n,m,s,t;
	cin>>n>>m>>s>>t;
	int pre[n+1];
	vector <pair<int,int>> p[n+1];
	for(int i=0; i<m; i++){
		int x,y,w;
		cin>>x>>y>>w;
		p[x].push_back({y,w});
	}
	vector <long long> d(n+1,1e9);
	d[s] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
	Q.push({0,s});
	while(!Q.empty()){
		pair<int,int> top = Q.top(); Q.pop();
		int u = top.second;
		int kc = top.first;
		if( kc > d[u]) continue;
		for(auto it : p[u]){
			int v = it.first;
			int w = it.second;
			if( d[v] > d[u]+ w){
				d[v] = d[u] +w;
				Q.push({d[v], v});
				pre[v] =u;
			}
		}
	}
//	for(int i=1; i<=n; i++){
//		cout<<d[i]<<" ";
//	}
	cout<<d[t];
	return 0;	
}
