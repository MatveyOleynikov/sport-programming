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
 
    int transition(int cur, int sym) {
        if (cur == -1) return 0;
        if (next[cur][sym] != -1) return next[cur][sym];
        return transition(link[cur], sym);
    }
 
    void bild_links() {
        queue<int> states; states.push(0);
        while (!states.empty()) {
            int cur = states.front(); states.pop();
            for (int i = 0; i < alphabet; ++i) {
                if (next[cur][i] != -1) {
                    link[next[cur][i]] = transition(link[cur], i);
                    states.push(next[cur][i]);
                }
            }
        }
    }
};
