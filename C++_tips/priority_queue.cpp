#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    // https://qiita.com/e869120/items/518297c6816adb67f9a5#3-14-priority_queue

    // デフォルトは降順
    vector<int> a = {4,3,5,6,8,10,1,23};
    priority_queue<int, vector<int>> q0; // 第一引数は要素の型、第二引数はその要素を持つベクトル
    for (int i: a) q0.push(i);
    
    while (!q0.empty()){
        cout << q0.top() << " ";
        q0.pop();
    }
    cout << endl;

    // 昇順にする場合
    priority_queue<int, vector<int>, greater<int>> q1;
    for (int i: a) q1.push(i);

    while (!q1.empty()){
        cout << q1.top() << " ";
        q1.pop();
    }
    cout << endl;


    // ラムダ式を使って、ベクトルの2番目の値の昇順で管理する
    vector<vector<int>> a1 = {{1,2}, {2,9}, {3,1}, {4,6}, {5,5}, {6,3}};
    auto c = [](vector<int> l, vector<int> r) { return l[1] >= r[1]; };
    priority_queue<vector<int>, vector<vector<int>>, decltype(c)> q2(c);

    for (vector<int> i: a1) q2.push(i);

    while (!q2.empty()){
        cout << q2.top()[0] << "," << q2.top()[1] << " ";
        q2.pop();
    }
    cout << endl;
}