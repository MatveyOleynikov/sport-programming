struct ahokaras {
    int alphabet = 26;
    vvi next; vi link; int sz;
    ahokaras() {
        sz = 1;
        next = vvi{ vi(alphabet, -1) };
        link = { -1 };
    }
    void add_string(string s, int value) {
        int cur = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (next[cur][s[i] - 'a'] == -1) {
                next.push_back(vi(alphabet, -1));
                next[cur][s[i] - 'a'] = sz++;
                link.push_back(0);
            }
            cur = next[cur][s[i] - 'a'];
        }
    }
    int get_link(int cur, int sym) {
        if (cur == -1) return 0;
        if (next[cur][sym] != -1) return next[cur][sym];
        return get_link(link[cur], sym);
    }
    void bild_links() {
        queue<int> edges; edges.push(0);
        while (!edges.empty()) {
            int cur = edges.front(); edges.pop();
            for (int i = 0; i < alphabet; ++i) {
                if (next[cur][i] != -1) {
                    link[next[cur][i]] = get_link(link[cur], i);
                    edges.push(next[cur][i]);
                }
            }
        }
    }
};
