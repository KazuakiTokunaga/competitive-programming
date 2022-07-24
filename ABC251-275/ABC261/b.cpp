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
        string s;
        cin >> s;
        grid.push_back(s);
    }

    bool check = true;
    rep(i, 0, N-1){
        rep(j, i+1, N){
            if (grid[i][j] == 'W') if (grid[j][i] != 'L') check = false;
            if (grid[i][j] == 'D') if (grid[j][i] != 'D') check = false;
            if (grid[i][j] == 'L') if (grid[j][i] != 'W') check = false;
        }
    }

    if (check) cout << "correct" << endl;
    else cout << "incorrect" << endl;
}