#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> matrix(h);    
    rep(i, 0, h){
        cin >> matrix[i];
    }
    
    vector<vector<int>> l_count(h+1, vector<int>(w+1));
    rep(i, 0, h){
        int count = 0;
        rep(j, 0, w){
            if (matrix[i][j] == '.'){
                count += 1;
                l_count[i][j] = count;
            } else {
                count = 0;
                l_count[i][j] = 0;
            }
        }
    }

    vector<vector<int>> r_count(h+1, vector<int>(w+1));
    rep(i, 0, h){
        int count = 0;
        rrep(j, w-1, 0){
            if (matrix[i][j] == '.'){
                count += 1;
                r_count[i][j] = count;
            } else {
                count = 0;
                r_count[i][j] = 0;
            }
        }
    }

    vector<vector<int>> u_count(h+1, vector<int>(w+1));
    rep(i, 0, w){
        int count = 0;
        rep(j, 0, h){
            if (matrix[j][i] == '.'){
                count += 1;
                u_count[j][i] = count;
            } else {
                count = 0;
                u_count[j][i] = 0;
            }
        }
    }

    vector<vector<int>> d_count(h+1, vector<int>(w+1));
    rep(i, 0, w){
        int count = 0;
        rrep(j, h-1, 0){
            if (matrix[j][i] == '.'){
                count += 1;
                d_count[j][i] = count;
            } else {
                count = 0;
                d_count[j][i] = 0;
            }
        }
    }

    // rep(i, 0, h){
    //     rep(j, 0, w){
    //         cout << d_count[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    
    int res = 0;
    rep(i, 0, h){
        rep(j, 0, w){
            res = max(res, l_count[i][j] + r_count[i][j] + u_count[i][j] + d_count[i][j] - 3);
        }
    }
    cout << res << endl;
}