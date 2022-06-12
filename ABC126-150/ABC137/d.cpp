#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> inputs;
    inputs.assign(n, {});
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        inputs[i] = {a,b};
    }
    sort(inputs.begin(), inputs.end());
    reverse(inputs.begin(), inputs.end());

    priority_queue<int, vector<int>, less<int>> jobs;
    ll res = 0;
    for (int i = 1; i < m+1; i++) {
        while (inputs.size()){
            vector<int> job = inputs.back();
            int a = job[0], b = job[1];
            if (a <= i) {
                jobs.push(b);
                inputs.pop_back();
            } else {
                break;
            }
        }
        if (!jobs.empty()){
            int b = jobs.top();
            res += b;
            jobs.pop();
        }
    }

    cout << res << endl;     
}