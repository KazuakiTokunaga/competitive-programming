#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

// https://qiita.com/e869120/items/518297c6816adb67f9a5#3-19-tuple
int main() {
    typedef tuple<string, int, int> Restaurant;

    vector<Restaurant> l;
    l.push_back(Restaurant("hoge", 1, 10));
    l.push_back(Restaurant("fuga", 100, 20));
    l.push_back(Restaurant("fuga", 100, 5));

    auto order = [](auto a, auto b){
        if (get<0>(a) != get<0>(b)){
            return get<0>(a) < get<0>(b);
        } else {
            return get<1>(a) > get<1>(b);
        }
    };

    sort(l.begin(), l.end(), order);
    rep(i, 0, l.size()){
        cout << get<2>(l[i]) << " ";
    }
    cout << endl;

    string s; int a, b;
    tie(s,a,b) = l.back();
    cout << s<< " " << a << " " << b << endl;
}