#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

// 先端でも末尾でも挿入・削除がO(1)で行える
// http://vivi.dyndns.org/tech/cpp/deque.html
// https://kaworu.jpn.org/cpp/std::deque

// queue
// https://kaworu.jpn.org/cpp/std::queue

int main() {
    deque<int> d = {1,2,3,4,5};

    d.push_back(34);
    d.push_front(21);

    cout << "last value:" << " " << d.back() << endl;

    cout << "Print from first: ";
    while (!d.empty()){
        cout << d.front() << " ";
        d.pop_front();
    }
    cout << endl;

    
    queue<int> q;
    rep(i, 1, 6) q.push(i);
    q.pop();
    q.push(12);
    while (!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

// stackはvectorのpop_back(), back()などを使えばOK.
// https://cpprefjp.github.io/reference/vector/vector/pop_back.html