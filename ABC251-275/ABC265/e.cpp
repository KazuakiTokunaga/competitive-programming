#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const ll MOD = 998244353;

int main(){
	int n,m;
	cin >> n >> m;
	
	vector<pair<int,int>> dxy;
	for(int i=0;i<3;i++){
		int a,b;
		cin >> a >> b;
		dxy.push_back({a,b});
	}
 
	set<pair<int,int>> S;
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		S.insert({a,b});
	}
	
	map<pair<ll,ll>, ll>dp;
	dp[{0,0}]=1;
	for(int i=0;i<n;i++){
		map<pair<ll,ll>, ll> new_dp;
		for (auto[xy,val]:dp){
			auto[x,y]=xy;
			for(auto[dx,dy]:dxy){
				if(S.find({x+dx,y+dy})==S.end()){
					new_dp[{x+dx, y+dy}] += val;
                    new_dp[{x+dx, y+dy}] %= MOD;
				}
			}
		}
		swap(dp,new_dp);
	}
	
	ll res = 0;
	for(auto[_,val]:dp) {res+=val; res %= MOD;}
	cout << res << endl;
}