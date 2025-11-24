struct Euler {
    vector<vector<pair<pii, int>>> g;
    Euler(int n) { g.resize(n); }
    void add_edge(int u, int v) {
        g[u].push_back({ {v, u == v ? g[v].size() + 1 : g[v].size()}, 1});
        g[v].push_back({ {u, g[u].size() - 1}, 1 });}
    void remove_edge(int u, int num) {
        g[u][num].second = 0;
        int v = g[u][num].first.first;
        int obr_num = g[u][num].first.second;
        g[v][obr_num].second = 0;}
    vi calc() { // ломает граф
        int n = g.size(), v1 = -1, v2 = -1; bool bad = false;
        int first = 0; while (g[first].empty())  ++first;

        for (int i = 0; i < n; ++i) {
            if (g[i].size() & 1)
                if (v1 == -1) v1 = i;
                else if (v2 == -1) v2 = i;
                else bad = true;}

        //Добавляет ребро чтобы свести путь к циклу
        if (v1 != -1) {
            if (v2 != -1) add_edge(v1, v2);
            else bad = true;}

        stack<int> st; st.push(first); vi res, skip(n);
        while (!st.empty()){
            int u = st.top();
            while (skip[u] < g[u].size())
                if (g[u][skip[u]].second) break;
                else skip[u]++;
            if (skip[u] == g[u].size()){ res.push_back(u); st.pop();}
            else{ remove_edge(u, skip[u]); st.push(g[u][skip[u]].first.first); } }

        if (v1 != -1)
            for (size_t i = 0; i + 1 < res.size(); ++i)
                if (res[i] == v1 && res[i + 1] == v2 || res[i] == v2 && res[i + 1] == v1){
                    vector<int> res2;
                    for (size_t j = i + 1; j < res.size(); ++j) res2.push_back(res[j]);
                    for (size_t j = 1; j <= i; ++j) res2.push_back(res[j]);
                    res = res2; break;
                }

        for (int u = 0; u < n; ++u) for (auto& el: g[u]) if (el.second) bad = true;
        return bad ? vi{-1} : res;}};
