struct dinic{ ///если веса равны единице: O(msqrt(n)), иначе: O((n^2)(m)) 
    #ifdef MATVEY
    const int MAXN = 10; // число вершин
    #else
    const int MAXN = 202; // число вершин
    #endif
    int INF = 1e18 + 1; // константа-бесконечность

    int n, s, t; ///in
    vvi c; ///in

    vi d, ptr, q; ///need
    vvi f; ///out

    dinic(){
        n = MAXN, s = MAXN - 2, t = MAXN - 1; ///in
        dbg(n, s, t);
        c.resize(MAXN, vi(MAXN)); ///in

        d.resize(MAXN); ptr.resize(MAXN); q.resize(MAXN); ///need
        f.resize(MAXN, vi(MAXN)); ///out
    }

    void add_edge(int u, int v, int w){
        dbg(u, v, w);
        c[u][v] += w;
    }

    bool bfs() {
        int qh=0, qt=0;
        q[qt++] = s;
        for (int i = 0; i < n; ++i){
            d[i] = -1;
        }
        d[s] = 0;
        while (qh < qt) {
            int v = q[qh++];
            for (int to=0; to<n; ++to)
                if (d[to] == -1 && f[v][to] < c[v][to]) {
                    q[qt++] = to;
                    d[to] = d[v] + 1;
                }
        }
        return d[t] != -1;
    }

    int dfs (int v, int flow) {
        dbg(v, t, flow);
        if (!flow)  return 0;
        if (v == t)  return flow;
        dbg(ptr[v]);
        for (int & to=ptr[v]; to<n; ++to) {
            dbg(to);
            if (d[to] != d[v] + 1)  continue;
            int pushed = dfs (to, min (flow, c[v][to] - f[v][to]));
            if (pushed) {
                f[v][to] += pushed;
                f[to][v] -= pushed;
                return pushed;
            }
        }
        return 0;
    }

    int potok() {
        int flow = 0;
        dbg(flow);
        for (;;) {
            dbg(flow);
            dbg(f);
            if (!bfs())  break;
            for (int el = 0; el < n; ++el){
                ptr[el] = 0;
            }
            while (int pushed = dfs (s, INF)){
                dbg("lol");
                flow += pushed;
            }
        }
        return flow;
    }

};
