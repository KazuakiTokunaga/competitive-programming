#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

// 単純なcombinationの計算
#define CMAX 1010
ll memo[CMAX][CMAX];
int noinit = 1;
ll C(ll a, ll b) {
	if (noinit) {
		rep(i, 0, CMAX) rep(j, 0, CMAX) memo[i][j] = -1;
		noinit = 0;
	}
	if (b == 0 || a == b) return 1;
	if (0 <= memo[a][b]) return memo[a][b];
	return memo[a][b] = C(a - 1, b - 1) + C(a - 1, b);
}

// combinationの列挙
vector<vector<ll>> combinations(vector<ll> lis,ll repeat){
    ll cnt=0;
    deque<set<ll>> d;
    set<ll> s,tmp;
    d.push_back(s);
    while (cnt<repeat){
        deque<set<ll>> d2;
        for(auto itr=d.begin(); itr!=d.end(); itr++){
            for(auto it=lis.begin()+cnt; it!=lis.begin()+lis.size()+cnt-repeat+1 ; it++){
                tmp=*itr;
                tmp.insert(*it);
                if (tmp.size()==cnt+1){
                    d2.push_back(tmp);
                }
            }
        }
        d=d2;
        cnt++;
    }
    sort(d.begin(), d.end());
    decltype(d)::iterator result = unique(d.begin(), d.end());
    d.erase(result, d.end());
    vector<vector<ll>> ans;
    for(auto item:d){
        vector<ll> ite(item.begin(),item.end());
        ans.push_back(ite);
    }
    return ans;
}


int main() {

    // パスカルの三角形で求めるcombination
    // https://caprest.hatenablog.com/entry/2016/05/29/181102
    vector<vector<ll>> dp(9, vector<ll>(9));
    rep(i, 0, 9){
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
    rep(j, 1, 9){
        rep(k, 1, j){
            dp[j][k] = dp[j-1][k] + dp[j-1][k-1];
        }
    }

    cout << "パスカルの三角形：" << endl;
    rep(i, 1, 9){
        for (auto j: dp[i]) {cout << j << ' ';} cout << endl;        
    }
    cout << endl;;

    // シンプルなcombinationの計算
    cout << C(20, 8) << endl << endl;;


    // combinationの全組み合わせのベクトルを作る
    // https://qiita.com/KyleKatarn/items/4e64249abfc151d8e82b
    vector<ll> combi = {1,5,7,9,10};
    vector<vector<ll>> out = combinations(combi, 3);
    cout << "組み合わせを列挙：" << endl;
    rep(i, 0, out.size()){
        for (auto j: out[i]) {cout << j << ' ';} cout << endl;   
    }
    cout << endl;
}