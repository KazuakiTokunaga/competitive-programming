#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

struct Restaurant {
    string city;
    int point;
    int index;
    Restaurant(string c, int p, int i): city(c), point(p), index(i) {}
};

int main() {
    int n;
    cin >> n;

    vector<Restaurant> l;

    rep(i, 0, n){
        int p, j = i+1; 
        string c;
        cin >> c >> p;
        l.push_back(Restaurant(c, p, j));
    }

    auto order = [](auto a, auto b){
        if (a.city != b.city) {
            return a.city < b.city;
        } else {
            return a.point > b.point;
        }
    };

    sort(l.begin(), l.end(), order);
    
    rep(i, 0, n){
        cout << l[i].index << endl;
    }
}