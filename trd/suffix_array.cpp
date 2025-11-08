struct suf_mas {
    static vector<int> get_mas(string s) {
        s.push_back(0);  // добавляем нулевой символ в конец строки
        int n = (int)s.size(),
            cnt = 0,  // вспомогательная переменная: счётчик для сортировки
            cls = 0;  // количество классов эквивалентности
        vector<int> c(n), p(n);
        map<int, vector<int>> t;
        for (int i = 0; i < n; i++)
            t[s[i]].push_back(i);
        // «нулевой» этап
        for (auto& x : t) {
            for (int u : x.second)
                c[u] = cls, p[cnt++] = u;
            cls++;}
        // пока все суффиксы не стали уникальными
        for (int l = 1; cls < n; l++) {
            vector<vector<int>> a(cls);  // массив для сортировки подсчётом
            vector<int> _c(n);  // новые классы эквивалентности
            int d = (1 << l) / 2;
            int _cls = cnt = 0;  // новое количество классов
            for (int i = 0; i < n; i++) {
                int k = (p[i] - d + n) % n;
                a[c[k]].push_back(k);}
            for (int i = 0; i < cls; i++) {
                for (size_t j = 0; j < a[i].size(); j++) {
                    // если суффикс начинает новый класс эквивалентности
                    if (j == 0 || c[(a[i][j] + d) % n] != c[(a[i][j - 1] + d) % n])
                        _cls++;
                    _c[a[i][j]] = _cls - 1;
                    p[cnt++] = a[i][j];}}
            c = _c; cls = _cls;}
        return p;}
    static vector<int> kosai(string str, vector<int>& suf) {
        str.push_back(0);  // добавляем нулевой символ в конец строки
        int n = str.size();
        vector<int> lcp(n);
        vector<int> pos(n);   // pos[] — массив, обратный массиву suf
        for (int i = 0; i < n; ++i) pos[suf[i]] = i;
        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (k > 0) k--;
            if (pos[i] == n - 1) {
                lcp[n - 1] = -1;
                k = 0;
                continue;}
            else {
                int j = suf[pos[i] + 1];
                while (max(i + k, j + k) < n && str[i + k] == str[j + k]) k++;
                lcp[pos[i]] = k;}}
        return lcp;}};
