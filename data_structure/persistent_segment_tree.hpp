template<class S, S (*op)(S, S), S (*e)(), int NODES = 10'000'000>
struct PersistentSegmentTree {
    struct Node {
        S d;
        Node* l, *r;
    };

    PersistentSegmentTree(const vector<S>& v) : pid(0), n(v.size()) {
        pool = new Node[NODES];
        nil = my_new(e());
        nil->l = nil->r = nil;
        roots.reserve(262144);
        roots.push_back(build(0, v.size(), v));
    }

    PersistentSegmentTree(int n) : pid(0), n(n) {
        pool = new Node[NODES];
        nil = my_new(e());
        nil->l = nil->r = nil;
        roots.reserve(262144);
        roots.push_back(nil);
    }

    ~PersistentSegmentTree() { delete[] pool; }

    Node* set(int p, const S& x) {
        Node* root = set(p, x, roots.back(), 0, n);
        roots.push_back(root);
        return root;
    }
    Node* set(int t, int p, const S& x) {
        Node* root = set(p, x, roots[t], 0, n);
        roots.push_back(root);
        return root;
    }

    Node* add(int p, const S& x) {
        Node* root = add(p, x, roots.back(), 0, n);
        roots.push_back(root);
        return root;
    }
    Node* add(int t, int p, const S& x) {
        Node* root = add(p, x, roots[t], 0, n);
        roots.push_back(root);
        return root;
    }

    S prod(int l, int r) { return prod(l, r, roots.back(), 0, n); }
    S prod(int t, int l, int r) { return prod(l, r, roots[t], 0, n); }

  private:
    Node* pool;
    int pid;
    int n;
    Node* nil;
    vector<Node*> roots;

    Node* my_new(const S& d) {
        pool[pid].d = d;
        pool[pid].l = pool[pid].r = nil;
        return &(pool[pid++]);
    }
    
    Node* merge(Node* l, Node* r) {
        pool[pid].d = op(l->d, r->d);
        pool[pid].l = l;
        pool[pid].r = r;
        return &(pool[pid++]);
    }

    Node* build(int l, int r, const vector<S>& v) {
        if(l + 1 == r) return my_new(v[l]);
        int m = (l + r) >> 1;
        return merge(build(l, m, v), build(m, r, v));
    }

    Node* set(int p, const S& x, Node* n, int l, int r) {
        if(l + 1 == r) return my_new(x);
        int m = (l + r) >> 1;
        if(p < m) return merge(set(p, x, n->l, l, m), n->r);
        return merge(n->l, set(p, x, n->r, m, r));
    }

    Node* add(int p, const S& x, Node* n, int l, int r) {
        if(l + 1 == r) return my_new(op(n->d, x));
        int m = (l + r) >> 1;
        if(p < m) return merge(add(p, x, n->l, l, m), n->r);
        return merge(n->l, add(p, x, n->r, m, r));
    }

    S prod(int a, int b, Node* n, int l, int r) {
        if(n == nil) return e();
        if(r <= a || b <= l) return e();
        if(a <= l && r <= b) return n->d;
        int m = (l + r) >> 1;
        return op(prod(a, b, n->l, l, m), prod(a, b, n->r, m, r));
    }
};
