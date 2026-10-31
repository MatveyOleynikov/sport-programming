struct weighed_graph{
    using pii = pair<int, int>;
    int n, m;
    vector<vector<pii> g;

    weighed_graph(){
        n = 0;
        m = 0;
    }

    weighed_graph(int col){
        n = col;
        g.resize(n);
        m = 0;
    }

    void add_edge(int u, int v, int w){
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        m++;
    }

    pair<int, vector<int>> djkstra(int start){
        vector<int> ans(n);
        vector<int> pr(n);
        for (int i = 0; i < n; i++) {
            ans[i] = inf64;
            pr[i] = -1;   //Значение, обозначающее что из этой вершины возвращаться некуда
        }

        ans[start] = 0;

        priority_queue<pii, vector<pii>, greater<pii>> q;

        q.push({0, start});

        while (!q.empty()) {
            pii c = q.top();
            q.pop();

            int dst = c.first, v = c.second;

            if (ans[v] < dst) {
                continue;
            }

            for (pii e: g[v]) {
                int u = e.first, len_vu = e.second;

                int n_dst = dst + len_vu;
                if (n_dst < ans[u]) {
                    ans[u] = n_dst;
                    pr[u] = v;
                    q.push({n_dst, u});
                }
            }
        }

        vector<int> path;
        int cur = end;
        path.push_back(cur);
        while (pr[cur] != -1) {
            cur = pr[cur];
            path.push_back(cur);
        }
        reverse(path.begin(), path.end());

        return {ans, path};
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

        for (int i = 0; i < this->n; ++i){
            for (auto elem: this->g[i]){
                edges.push_back({elem.second, {i, elem.first}});
            }
        }

        sort(edges.begin(), edges.end());

        for (auto elem: edges){
            if (!my_snm.equal_snm(elem.second.first, elem.second.second)){
                my_snm.join_elems(elem.second.first, elem.second.second);
                res.add_edge(elem.second.first, elem.second.second, elem.first);
            }
        }

        return res;
    }
};
