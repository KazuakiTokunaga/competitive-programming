// 最大流最小カット（フォード・ファルカーソン法）

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Graph {
    struct Edge {
        int rev, from, to, cap;
        Edge(int r, int f, int t , int c): rev(r), from(f), to(t), cap(c){}
    };

    vector<vector<Edge>> list;

    Graph(int n=0): list(n){}

    size_t size() {
        return list.size();
    }

    vector<Edge> &operator[] (int i){
        return list[i];
    }

    Edge& redge(const Edge &e){
        return list[e.to][e.rev];
    }

    void run_flow(Edge &e, int f){
        e.cap -= f;
        redge(e).cap += f;
    }

    void addedge(int from, int to, int cap){
        int fromrev = (int)list[from].size();
        int torev = (int)list[to].size();
        list[from].push_back(Edge(torev, from, to, cap));
        list[to].push_back(Edge(fromrev, to, from, 0));
    }
};

struct FordFulkerson {
    static const int INF = 1 << 30;
    vector<int> seen;

    FordFulkerson() {}

    int fodfs(Graph &G, int v, int t, int f){
        if (v==t) return f;

        seen[v] = true;
        for (auto &e: G[v]) {
            if (seen[e.to]) continue;
            if (e.cap == 0) continue;

            int flow = fodfs(G, e.to, t, min(f, e.cap));

            if (flow == 0) continue;

            G.run_flow(e, flow);

            return flow;
        }
        return 0;
    }

    int solve(Graph &G, int s, int t){
        int res = 0;

        while (true){
            seen.assign((int)G.size(), 0);
            int flow = fodfs(G, s, t, INF);

            if (flow == 0) return res;

            res += flow;
        }

        return 0;
    }
};

int main (){
    int n, m;
    cin >> n >> m;
    Graph G(n);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;

        G.addedge(u, v, c);
    }

    FordFulkerson ff;
    int s = 0, t = n - 1;
    cout << ff.solve(G, s, t) << endl;
}

/*
入力例（図16.12）
6 9
0 1 5
1 3 37
0 3 5
1 2 4
3 2 3
2 4 56
3 4 9
4 5 2
2 5 9
*/