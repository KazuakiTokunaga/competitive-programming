#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> city;

    rep(i, 0, n){
        int x, y;
        cin >> x >> y;

        city.push_back(make_pair(x,y));
    }
    sort(city.begin(), city.end());

    long double total_res = 0;
    do {
        long double total_distance = 0;
        rep(i, 0, n-1){
            int x1 = city[i].first, y1 = city[i].second;
            int x2 = city[i+1].first, y2 = city[i+1].second;
            total_distance += pow(pow(x1 - x2, 2) + pow(y1 - y2, 2), 0.5);
        }
        total_res += total_distance;
    } while(next_permutation(city.begin(), city.end()));

    ll factorial = 1;
    rep(i, 1, n+1){
        factorial *= i;
    }

    cout << fixed << setprecision(10);
    cout << total_res / factorial << endl;
}