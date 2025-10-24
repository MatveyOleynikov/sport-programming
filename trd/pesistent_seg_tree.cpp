struct PersistentSegTree {
    const int good_value = 0;
    int func_idx(int idx1, int idx2) {
        int res = good_value;
        if (idx1 != -1) {res += t[idx1].value;}
        if (idx2 != -1) {res += t[idx2].value;}
        return res;}
    int func_vals(int val1, int val2) {
        return val1 + val2;}
    struct Node {
        signed left; signed right; int value;};
    vector<Node> t;int n;
    PersistentSegTree(int n) {
        t.reserve(n * 4 + 10); this->n = n;
        t.push_back(Node{-1, -1, good_value})};
    int new_rebenok() {
        t.push_back(Node{ -1, -1, good_value });
        return t.size() - 1;}
    int copy(int idx) {
        if (idx == -1) {
            return new_rebenok();}
        t.push_back(t[idx]);
        return t.size() - 1;}
    int get(signed v, signed L, signed R, signed l, signed r) {
        if (v == -1) return good_value;
        if (r < L || R < l) return good_value;
        if (l <= L && R <= r) return t[v].value;
        signed C = (L + R) / 2;
        return func_vals(
            get(t[v].left, L, C, l, r),
            get(t[v].right, C + 1, R, l, r));}
    int get(signed beg, signed l, signed r) {
        return get(beg, 0, n - 1, l, r);}
    void update(int v, int L, int R, int index, int value) {
        if (R < index || index < L) return;
        if (L == R) {
            t[v].value += value; return;}
        int C = (L + R) / 2;
        if (index <= C) {
            t[v].left = copy(t[v].left);
            update(t[v].left, L, C, index, value);}
        if (index > C) {
            t[v].right = copy(t[v].right);
            update(t[v].right, C + 1, R, index, value);}
        t[v].value = func_idx(t[v].left, t[v].right);}
    int update(int pred_root, int index, int value) {
        int cp = copy(pred_root);
        update(cp, 0, n - 1, index, value);
        return cp;}};
