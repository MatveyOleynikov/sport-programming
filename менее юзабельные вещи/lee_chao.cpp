struct lee_chao {
    struct line {
        int k, b;
        line() {
            this->k = 1;
            this->b = 2e16;
        }
        line(int k, int b) {
            this->k = k;
            this->b = b;
        }

        int get(int x) {
            return k * x + b;
        }
    };

    struct Node {
        Node* left;
        Node* right;
        line val;
        Node() {
            left = nullptr;
            right = nullptr;
            val = line();
        }
    };

    int n = 1e9 + 1;
    Node* t;
    lee_chao() {
        t = new Node();
    }

    //comp => поменять с min на max и c '<' на '>' и c 2e16 на -2e16
    void upd(Node* t, int tl, int tr, line L) {
        if (tl > tr) return;
        int tm = (tl + tr) / 2;
        bool l = L.get(tl) < t->val.get(tl); //comp
        bool mid = L.get(tm) < t->val.get(tm); //comp
        if (mid) swap(L, t->val);

        if (l != mid) {
            if (t->left == nullptr) t->left = new Node();
            upd(t->left, tl, tm - 1, L);
        }
        else {
            if (t->right == nullptr) t->right = new Node();
            upd(t->right, tm + 1, tr, L);
        }
    }

    //у каждой линии должен быть уникальный коэф -k
    void upd(line L) {
        upd(t, 0, n, L);
    }

    pair<int, int> get(Node* t, int tl, int tr, int x) {
        if (tl > tr || t == nullptr) return { 2e16, 2e16 }; //comp
        int tm = (tl + tr) / 2;
        if (x == tm) return { t->val.get(x), t->val.k };
        if (x < tm) return min(make_pair(t->val.get(x), t->val.k), get(t->left, tl, tm - 1, x)); //comp
        else return min(make_pair(t->val.get(x), t->val.k), get(t->right, tm + 1, tr, x)); //comp
    }

    pair<int, int> get(int x) {
        return get(t, 0, n, x);
    }
};