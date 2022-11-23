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
    
    vector<string> grid;
    rep(i, 0, N){
        string s; cin >> s;
        grid.push_back(s);
    }

    rep(i, 0, N){
        rep(j, 0, N){
            if (i+5 < N){
                int cnt = 0;
                rep(k, 0, 6) if (grid[i+k][j] == '#') cnt++;
                if (cnt >= 4) {cout << "Yes" << endl; return 0;}
            }

            if (j+5 < N){
                int cnt = 0;
                rep(k, 0, 6) if (grid[i][j+k] == '#') cnt++;
                if (cnt >= 4) {cout << "Yes" << endl; return 0;} 
            }

            if (i+5 < N and j+5 < N){
                int cnt = 0;
                rep(k, 0, 6) if (grid[i+k][j+k] == '#') cnt++;
                if (cnt >= 4) {cout << "Yes" << endl; return 0;}                 
            }

            if (i-5 >= 0 and j+5 < N){
                int cnt = 0;
                rep(k, 0, 6) if (grid[i-k][j+k] == '#') cnt++;
                if (cnt >= 4) {cout << "Yes" << endl; return 0;}                 
            }
        }
    }

    cout << "No" << endl;
}