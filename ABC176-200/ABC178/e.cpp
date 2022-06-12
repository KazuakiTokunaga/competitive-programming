#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
const int INF = 2 * pow(10, 9) + 10;

int calc_dist(pii x, pii y){
    return abs(x.first - y.first) + abs(x.second - y.second);
}

int main() {
    int n;
    cin >> n;
    
    vector<pii> a;
    rep(i, 0, n){
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }

    int po_max = -1 * INF, po_min = INF, ne_max = -1 * INF, ne_min = INF;
    pii p_po_max, p_po_min, p_ne_max, p_ne_min;
    rep(i, 0, n){
        pii p = a[i];
        int x = p.first, y = p.second;
        
        if (po_max < x + y){
            po_max = x + y;
            p_po_max = {p.first, p.second};
        }
        if (po_min > x + y){
            po_min = x + y;
            p_po_min = {p.first, p.second};
        }
        if (ne_max < y - x){
            ne_max = y - x;
            p_ne_max = {p.first, p.second};
        }
        if (ne_min > y - x){
            ne_min = y - x;
            p_ne_min = {p.first, p.second};
        }
    }

    cout << max(calc_dist(p_po_max, p_po_min), calc_dist(p_ne_max, p_ne_min)) << endl;


}