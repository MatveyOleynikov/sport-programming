struct weighed_graph{
    int n, m;
    vector<vector<pair<int, int>>> g;

    weighed_graph(){
        n = 0;
        m = 0;
    }

    weighed_graph(int col){
        n = col;
        g.resize(n);
        m = 0;
    }

    friend ostream& operator<<(ostream& o, const weighed_graph& cur)
    {
        o << "Vertexes: " << cur.n << "\n";
        o << "Edges: " << cur.m << "\n";

        for (int u = 0; u < cur.n; ++u){
            o << u << ":";
            o << '(';
            for (auto [v, w]: cur.g[u]){
                o << '(';
                o << v;
                o << ',';
                o << w;
                o << ')';
                o << ',';
            }
            o << ')';
            o << '\n';
        }
        return o;
    }

    friend istream& operator>>(istream& o, weighed_graph& cur)
    {
        o >> cur.n;
        cur.g.resize(cur.n);

        o >> cur.m;
        for (int i = 0; i < cur.m; ++i){
            int u, v, w;
            o >> u; u--;
            o >> v; v--;
            o >> w;
            cur.g[u].push_back({v, w});
            cur.g[v].push_back({u, w});
        }
        return o;
    }

    void add_edge(int u, int v, int w){
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        m++;
    }

    vector<int> djkstra(int start){
        vector<int> ans(n);
        vector<int> pr(n);
        for (int i = 0; i < n; i++) {
            ans[i] = inf64;
            pr[i] = -1;   //Значение, обозначающее что из этой вершины возвращаться некуда
        }

        ans[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        q.push({0, start});

        while (!q.empty()) {
            pair<int, int> c = q.top();
            q.pop();

            int dst = c.first, v = c.second;

            if (ans[v] < dst) {
                continue;
            }

            for (pair<int, int> e: g[v]) {
                int u = e.first, len_vu = e.second;

                int n_dst = dst + len_vu;
                if (n_dst < ans[u]) {
                    ans[u] = n_dst;
                    pr[u] = v;
                    q.push({n_dst, u});
                }
            }
        }

        return ans;
        /*vector<int> path;
        int cur = end;
        path.push_back(cur);
        while (pr[cur] != -1) {
            cur = pr[cur];
            path.push_back(cur);
        }
        reverse(path.begin(), path.end());
        cout << "Shortest path between vertices " << start + 1 << " and " << end + 1 << " is: " << endl;
        for (int v: path) {
            cout << v + 1 << ", ";
        }*/ /// если нужен сам путь
    }

    weighed_graph kraskal(){
        struct snm{
            int n;
            vector<int> clr;
            vector<vector<int>> obr_clr;

            void join(int color1, int color2){
                if (obr_clr[color1].size() < obr_clr[color2].size()){
                    swap(color1, color2);
                }

                for (auto elem: obr_clr[color2]){
                    obr_clr[color1].push_back(elem);
                    clr[elem] = color1;
                }
            }

            bool equal_snm(int u, int v){
                return clr[u] == clr[v];
            }

            void join_elems(int u, int v){
                join(clr[u], clr[v]);
            }

            snm(int n){
                this->n = n;

                clr.resize(n);
                obr_clr.resize(n);

                for (int i = 0; i < n; ++i){
                    clr[i] = i;
                    obr_clr[i].push_back(i);
                }
            }
        };

        weighed_graph res(n);

        snm my_snm(this->n);

        vector<pair<int, pii>> edges;

        dbg(edges);

        for (int i = 0; i < this->n; ++i){
            for (auto elem: this->g[i]){
                edges.push_back({elem.second, {i, elem.first}});
            }
        }

        sort(all(edges));

        for (auto elem: edges){
            if (!my_snm.equal_snm(elem.second.first, elem.second.second)){
                my_snm.join_elems(elem.second.first, elem.second.second);
                res.add_edge(elem.second.first, elem.second.second, elem.first);
            }
        }

        return res;
    }
};
