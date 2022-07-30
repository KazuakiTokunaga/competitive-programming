#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int N;
    cin >> N;
    
    vector<vector<int>> vec(31);
    rep(i, 0, N){
        if (i == 0){
            cout << 1 << endl;
            vec[0].push_back(1);
            continue;
        }
        rep(j, 0, i+1){
            if (j == 0 or j == i) vec[i].push_back(1);
            else vec[i].push_back(vec[i-1][j-1] + vec[i-1][j]);
        }

        for (auto i: vec[i]) {cout << i << ' ';} cout << endl;
    }
}