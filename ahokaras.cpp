struct ahokaras{
    const int alphabet = 26; /// размер алфавита (обычно 26)

    vvi next;
    vi val;
    vi link;
    int sz;
    vi prop_val;

    ahokaras(){
        sz = 1;
        val.push_back(0);
        next.push_back(vi(alphabet, -1));
        link.push_back(-1);
        prop_val.push_back(0);
    }

    void add_string(string s, int value){ /// все вызовы этой функции должны быть перед вызовами функции bild_link
        int cur = 0;
        for (int i = 0; i < s.size(); ++i){
            if (next[cur][s[i] - 'a'] == -1){
                next.push_back(vi(alphabet, -1));
                next[cur][s[i] - 'a'] = sz;
                val.push_back(0);
                link.push_back(0);
                prop_val.push_back(0);

                sz++;
            }

            cur = next[cur][s[i] - 'a'];
        }

        val[cur] += value;
    }

    int get_link(int cur, int sym){
        if (cur == -1){
            return 0;
        }

        if (next[cur][sym] != -1){
            return next[cur][sym];
        }

        return get_link(link[cur], sym);
    }

    void bild_links(){
        queue<int> edges;
        edges.push(0);

        while (!edges.empty()){
            int cur = edges.front();
            edges.pop();

            for (int i = 0; i < alphabet; ++i){
                if (next[cur][i] != -1){
                    link[next[cur][i]] = get_link(link[cur], i);
                    edges.push(next[cur][i]);
                }
            }
        }
    }

    int get_children(int cur, vi& us, vi& pred){ /// не особо обязательно (доп алгоритм)
        if (cur < 0){
            return 0;
        }

        if (us[cur]){
            return 0;
        }

        us[cur] = 1;
        return val[cur] + get_children(link[cur], us, pred) + get_children(pred[cur], us, pred);
    }

    void propogation(){  /// не особо обязательно (доп алгоритм)
        vi pred(prop_val.size());
        for (int i = 0; i < prop_val.size(); ++i){
            for (int j = 0; j < alphabet; ++j){
                if (next[i][j] != -1)
                    pred[next[i][j]] = i;
            }
        }

        for (int i = 0; i < prop_val.size(); ++i){
            vi us(prop_val.size());
            prop_val[i] += get_children(i, us, pred);
        }
    }

    friend ostream& operator<<(ostream& o, const ahokaras& cur)
    {
        for (long long u = 0; u < cur.sz; ++u){
            o << "u: " << u << " link: " << cur.link[u] << " val: " << cur.val[u] << "  " << " prop_val: " << cur.prop_val[u] << "  ";
            for (long long j = 0; j < cur.alphabet; ++j){
                o << cur.next[u][j] << " ";
            }
            o << "\n";
        }
        return o;
    }
};
