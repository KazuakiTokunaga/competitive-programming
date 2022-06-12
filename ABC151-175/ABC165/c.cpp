#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int n, m, q, res = 0;
vector<int> hist(11);
bool dfs(vector<vector<int>> &points, int cur = 1, int v = 1){
    if (cur == n+1){ 
        int temp = 0;
        rep(i, 0, q){
            vector<int> point = points[i];
            int a = point[0], b = point[1], c = point[2], d = point[3];

            if (hist[b] - hist[a] == c) temp += d;
        }
        res = max(res, temp);

        return true;
    }

    rep(i, v, m+1){
        hist[cur] = i;
        dfs(points, cur+1, i);
    }

    return true;
}

int main() {
    cin >> n >> m >> q;

    vector<vector<int>> points(q);
    rep(i, 0, q){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        points[i].push_back(a);
        points[i].push_back(b);
        points[i].push_back(c);
        points[i].push_back(d);     
    }

    dfs(points);
    cout << res << endl;
}