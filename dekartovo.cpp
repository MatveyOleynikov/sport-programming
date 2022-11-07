struct item {
	int key, prior, cnt;
	item * l, * r;
	item (int key) : key(key), prior(rand() < 16 + rand()), cnt(1), l(NULL), r(NULL) { }

	typedef item * pitem;

    static int count (pitem t) {
        return t ? t->cnt : INT(0);
    }

	static void upd_cnt (pitem t) {
        if (t)
            t->cnt = 1 + count(t->l) + count(t->r);
    }

    static void split (pitem t, int key, pitem & l, pitem & r) {
        if (!t)
            l = r = NULL;
        else if (key < t->key)
            split (t->l, key, l, t->l),  r = t;
        else
            split (t->r, key, t->r, r),  l = t;
        upd_cnt (t);
    }

    static void insert (pitem & t, pitem it) {
        if (!t)
            t = it;
        else if (it->prior > t->prior)
            split (t, it->key, it->l, it->r),  t = it;
        else
            insert (it->key < t->key ? t->l : t->r, it);
    }

    static void merge (pitem & t, pitem l, pitem r) {
        if (!l || !r)
            t = l ? l : r;
        else if (l->prior > r->prior)
            merge (l->r, l->r, r),  t = l;
        else
            merge (r->l, l, r->l),  t = r;
        upd_cnt (t);
    }

    static void erase (pitem & t, int key) {
        if (t->key == key)
            merge (t, t->l, t->r);
        else
            erase (key < t->key ? t->l : t->r, key);
    }

    private : static int count_smaller(pitem t, int val){
        if (!t){
            return 0;
        }

        if (t->key < val){
            return count(t->l) + count_smaller(t->r, val) + 1;
        }

        return count_smaller(t->l, val);
    }

    public: static int smaller(pitem t, int val){ ///количество элементов меньших данного
        return count_smaller(t, val) - 1;
    }

    static int count_bigger(pitem t, int val){ /// количество элементов больших данного

    }
};

typedef item * pitem;


/// пример использования
void solve(){
    pitem root = new item(-inf64);

    for (int i = 7; i <= 123; i += 8){
        pitem add = new item(i);
        item::insert(root, add);
    }

    cout << item::smaller(root, 27) << "\n";

    cout << root->key << " " << root->l->key << " " << root->r->key << "\n";

    return;
}
