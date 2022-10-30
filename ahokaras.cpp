struct ahokaras{
    const int alphabet = 12; /// размер алфавита (обычно 26)

    vvi next;
    vi val;
    vi link;
    int sz;

    ahokaras(){
        sz = 1;
        val.push_back(0);
        next.push_back(vi(12, -1));
        link.push_back(-1);
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

    void add_string(string s, int value){ /// все эти функции должны быть перед функцией bild_link
        int cur = 0;
        for (int i = 0; i < s.size(); ++i){
            if (next[cur][s[i] - 'a'] == -1){
                next.push_back(vi(12, -1));
                next[cur][s[i] - 'a'] = sz;
                val.push_back(0);
                link.push_back(-1);

                sz++;
            }

            cur = next[cur][s[i] - 'a'];
        }

        val[cur] += value;
    }

    void bild_links(int cur = 0){
        //dbg(next[cur]);
        for (int i = 0; i < alphabet; ++i){
            if (next[cur][i] != -1){
                //dbg(link[cur]);
                link[next[cur][i]] = get_link(link[cur], i);
                //dbg(cur, i);
                //dbg(next[cur][i]);
                bild_links(next[cur][i]);
            }
        }
    }

    friend ostream& operator<<(ostream& o, const ahokaras& cur)
    {
        for (long long u = 0; u < cur.sz; ++u){
            o << "u: " << u << " link: " << cur.link[u] << " val: " << cur.val[u] << "  ";
            for (long long j = 0; j < cur.alphabet; ++j){
                o << cur.next[u][j] << " ";
            }
            o << "\n";
        }
        return o;
    }
};
