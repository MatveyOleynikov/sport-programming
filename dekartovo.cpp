template<typename T>
struct dekartovo{
    vector<T> key;
    vi prior;
    vi l, r;
    vi deti;
    int root = -1;
    int sz = 0;

    int get_deti(int cur){
        return ((cur == -1) ? 0 : deti[cur]);
    }

    void update(int cur) {
        if (cur == -1) {
          return;
        }
        deti[cur] = 1 + get_deti(l[cur]) + get_deti(r[cur]);
    }

    void split (int cur, T split_key, int& split_l, int& split_r) {
        if (cur == -1){
            split_l = split_r = -1; return;
        }

        if (split_key < key[cur])
            split (l[cur], split_key, split_l, l[cur]),  split_r = cur;
        else
            split (r[cur], split_key, r[cur], split_r),  split_l = cur;

        update(split_l);
        update(split_r);
    }

    void insert (int& cur, T val) {
        if (cur == -1)
            cur = sz - 1;
        else if (prior.back() > prior[cur])
            split (cur, key.back(), l.back(), r.back()),  cur = sz - 1;
        else
            insert (key.back() < key[cur] ? l[cur] : r[cur], val);

        update(cur);
    }

    void insert (T val){ /// добавление элемента
        prior.push_back(INT(rand() << 16) + INT(rand()));
        key.push_back(val);
        l.push_back(-1);
        r.push_back(-1);
        deti.push_back(1);
        sz++;

        insert(root, val);
    }

    bool find(int cur, T found_key){
        if (cur == -1){
            return 0;
        }
        if (key[cur] == found_key){
            return 1;
        }
        if (key[cur] > found_key){
            return find(l[cur], found_key);
        }
        if (key[cur] < found_key){
            return find(r[cur], found_key);
        }
    }

    bool find(T found_key){ /// поиск элемента
        return find(root, found_key);
    }

    void merge (int &cur, int merge_l, int merge_r) {
        if (merge_l == -1){
            cur = merge_r;
            return;
        }
        if (merge_r == -1){
            cur = merge_l;
            return;
        }

        if (prior[merge_l] > prior[merge_r])
            merge (r[merge_l], r[merge_l], merge_r),  cur = merge_l;
        else
            merge (l[merge_r], merge_l, l[merge_r]),  cur = merge_r;

        update(merge_l);
        update(merge_r);
    }

    void erase (int &cur, T erase_key) {
        if (key[cur] == erase_key)
            merge (cur, l[cur], r[cur]);
        else
            erase (erase_key < key[cur] ? l[cur] : r[cur], erase_key);

        update(cur);
    }

    void erase(T erase_key){ /// удаление элемента
        if (this->find(erase_key)){
            erase(root, erase_key);
        }
    }

    T kol(int cur, int k){
        if (k > get_deti(cur)){
            exit(1);
        }

        if (k == get_deti(l[cur]) + 1){
            return key[cur];
        }

        if (k < get_deti(l[cur]) + 1){
            return kol(l[cur], k);
        }

        if (k > get_deti(l[cur]) + 1){
            return kol(r[cur], k - (get_deti(l[cur]) + 1));
        }
    }

    T operator[](int k){ /// вывод k-го элемента в 0-индексации
        return kol(root, k + 1);
    }

    friend ostream& operator<<(ostream& o, const dekartovo& cur){ /// вывод дерева для дебага
        o << "root: " << cur.root << "\n";
        o << "size: " << cur.deti[cur.root] << "\n";
        return o;
    }

    int smaller_or_equal(T k, int cur){  /// количество элементов меньших или равных k (далее аналогично)
        if (cur == -1){
            return 0;
        }

        if (key[cur] <= k){
            return get_deti(l[cur]) + 1 + smaller_or_equal(k, r[cur]);
        }

        if (key[cur] > k){
            return smaller_or_equal(k, l[cur]);
        }
    }

    int bigger_or_equal(T k, int cur){
        if (cur == -1){
            return 0;
        }

        if (key[cur] >= k){
            return get_deti(r[cur]) + 1 + bigger_or_equal(k, l[cur]);
        }

        if (key[cur] < k){
            return bigger_or_equal(k, r[cur]);
        }
    }

    int smaller_or_equal(T k){
        return smaller_or_equal(k, root);
    }

    int bigger_or_equal(T k){
        return bigger_or_equal(k, root);
    }

    int equal(T k){
        return smaller_or_equal(k) + bigger_or_equal(k) - deti[root];
    }

    int bigger(T k){
        return deti[root] - smaller_or_equal(k);
    }

    int smaller(T k){
        return deti[root] - bigger_or_equal(k);
    }
};

void solve(){
    dekartovo<string> drv;

    drv.insert("a");
    drv.insert("a");
    drv.insert("b");
    drv.insert("c");

    cout << drv;

    drv.erase("b");

    cout << drv;

    cout << drv.equal("a") << " " << drv.smaller("a") << " " << drv.smaller_or_equal("a") << "\n";
    cout << drv.bigger("a") << " " << drv.bigger_or_equal("a") << "\n";
    return;
}
