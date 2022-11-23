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
	rep(i, 0, 3){
		int a,b;
		cin >> a >> b;
		dxy.push_back({a,b});
	}
 
	set<pair<int,int>> S;
	rep(i, 0, m){
		int a,b;
		cin >> a >> b;
		S.insert({a,b});
	}
	
	vector<vector<ll>> dp(1,vector<ll>(1));
	dp[0][0]=1;
	for(int i=0;i<n;i++){
		vector<vector<ll>> new_dp(i+2, vector<ll>(i+2));
		for(ll a=0;a<=i;a++)for(ll b=0;b<=i;b++){
			ll x=a*dxy[0].first +b*dxy[1].first +(i-a-b)*dxy[2].first;
			ll y=a*dxy[0].second+b*dxy[1].second+(i-a-b)*dxy[2].second;
			for(int k=0;k<3;k++){
				auto[dx,dy]=dxy[k];
				if(S.find({x+dx,y+dy})==S.end()){
					new_dp[a+(k==0)][b+(k==1)] += dp[a][b];
                    new_dp[a+(k==0)][b+(k==1)] %= MOD;
				}
			}
		}
		swap(dp,new_dp);
	}
	
	ll res=0;
	for(int a=0;a<=n;a++)for(int b=0;b<=n;b++) {res+=dp[a][b]; res %= MOD;}
    
	cout << res << endl;
}