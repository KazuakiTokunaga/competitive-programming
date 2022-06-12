#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> jobs(n);
    rep(i, 0, n){
        int a, b;
        cin >> a >> b;
        jobs[i].first = a;
        jobs[i].second = b;
    }

    auto larger = [](auto a, auto b){return a.second > b.second;};
    sort(jobs.begin(), jobs.end(), larger);

    int time = 0;
    while (!jobs.empty()){
        int a,b;
        pair<int, int> p = jobs.back();
        a = p.first;
        b = p.second;
        time += a;
        if (time > b){
            cout << "No" << endl;
            return 0;
        }
        jobs.pop_back();
    }
    cout << "Yes" << endl;
    return 0;
}