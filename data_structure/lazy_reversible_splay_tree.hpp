template<class S,
         S (*op)(S, S),
         S (*e)(), 
         void (*reverse_prod)(S&), 
         class F, 
         S (*mapping)(F, S), 
         F (*composition)(F, F), 
         F (*id)()>
struct LazyReversibleSplayTree{
    struct Node{
        Node* l = nullptr;
        Node* r = nullptr;
        Node* p = nullptr;
        S val = e();
        S prod = e();
        F f = id();
        int i = -1;
        int sz = 1;
        int rev = 0;
        Node(S x) : val(x), prod(x) {}
    };

    Node* root = nullptr;
    vector<Node*> A;

    void right_rotate(Node* v) {
        Node* u = v->l;
        v->l = u->r;
        if (u->r) u->r->p = v;
        u->p = v->p;
        if (!v->p) root = u;
        else if (v == v->p->l) v->p->l = u;
        else v->p->r = u;
        u->r = v;
        v->p = u;
    }

    void left_rotate(Node* v) {
        Node* u = v->r;
        v->r = u->l;
        if (u->l) u->l->p = v;
        u->p = v->p;
        if (!v->p) root = u;
        else if (v == v->p->l) v->p->l = u;
        else v->p->r = u;
        u->l = v;
        v->p = u;
    }

    void splay(Node* v) {
        if(!v) return;
        propagate(v);
        while (v->p) {
            Node* p = v->p;
            Node* g = p->p;
            if(g) propagate(g);
            propagate(p);
            propagate(v);
            if (!g) { // zig
                if (p->l == v) right_rotate(p);
                else left_rotate(p);
            } else if (p->l == v && g->l == p) { // zigzig
                right_rotate(g);
                right_rotate(p);
            } else if (p->r == v && g->r == p) { // zigzig
                left_rotate(g);
                left_rotate(p);
            } else if (p->l == v && g->r == p) { // zigzag
                right_rotate(p);
                left_rotate(g);
            } else { // zigzag
                left_rotate(p);
                right_rotate(g);
            }
            if(g) all_apply(g);
            all_apply(p);
            all_apply(v);
        }
        all_apply(v);
    }

    void propagate(Node* v) {
        if(!v) return;
        if(v->l) {
            v->l->val = mapping(v->f, v->l->val);
            v->l->prod = mapping(v->f, v->l->prod);
            v->l->f = composition(v->f, v->l->f);
        }
        if(v->r) {
            v->r->val = mapping(v->f, v->r->val);
            v->r->prod = mapping(v->f, v->r->prod);
            v->r->f = composition(v->f, v->r->f);
        }
        if(v->rev) {
            swap(v->l, v->r);
            if(v->l) {
                v->l->rev ^= 1;
                reverse_prod(v->l->prod);
            }
            if(v->r) {
                v->r->rev ^= 1;
                reverse_prod(v->r->prod);
            }
            v->rev = 0;
        }
        v->f = id();
    }

    void all_apply(Node* v) {
        v->sz = 1;
        if(v->l) v->sz += v->l->sz;
        if(v->r) v->sz += v->r->sz;
        v->prod = e();
        if(v->l) v->prod = op(v->prod, v->l->prod);
        v->prod = op(v->prod, v->val);
        if(v->r) v->prod = op(v->prod, v->r->prod);
    }

    Node* kth_element(int k) {
        Node* cur = root;
        while(cur) {
            propagate(cur);
            if(!cur->l && k == 0) break;
            if(cur->l && cur->l->sz == k) break;
            else if(cur->l && cur->l->sz > k) cur = cur->l;
            else {
                k -= 1;
                if(cur->l) k -= cur->l->sz;
                cur = cur->r;
            }
        }
        propagate(cur);
        splay(cur);
        return cur;
    }

    void insert_at(int k, S x) {
        Node* nv = new Node(x);
        nv->i = A.size();
        A.push_back(nv);
        if(k == 0) {
            nv->r = root;
            if(root) root->p = nv;
            root = nv;
            all_apply(nv);
            return;
        }
        if(root && k == root->sz) {
            nv->l = root;
            if(root) root->p = nv;
            root = nv;
            all_apply(nv);
            return;
        }
        Node* p = kth_element(k);
        nv->l = p->l;
        nv->r = p;
        root = nv;
        if(nv->l) nv->l->p = nv;
        p->p = nv;
        p->l = nullptr;
        all_apply(p);
        all_apply(nv);
    }

    void erase_at(int k) {
        Node* p = kth_element(k);
        if(k == 0) {
            root = p->r;
            if(root) root->p = nullptr;
        }
        else if(root && k == root->sz - 1) {
            root = p->l;
            if(root) root->p = nullptr;
        }
        else {
            Node* l = p->l;
            Node* r = p->r;
            r->p = nullptr;
            root = r;
            kth_element(0);
            r = root;
            r->l = l;
            l->p = r;
            all_apply(r);
        }
        swap(p->i, A.back()->i);
        swap(A[p->i], A[A.back()->i]);
        A.pop_back();
        delete p;
    }

    Node* between(int l, int r) {
        if(l == 0 && r == root->sz) return root;
        if(l == 0) return kth_element(r)->l;
        if(r == root->sz) return kth_element(l - 1)->r;
        Node* rp = kth_element(r);
        Node* lp = rp->l;
        root = lp;
        lp->p = nullptr;
        lp = kth_element(l - 1);
        root = rp;
        rp->l = lp;
        lp->p = rp;
        all_apply(rp);
        return lp->r;
    }

    void reverse(int l, int r) {
        Node* v = between(l, r);
        v->rev ^= 1;
        reverse_prod(v->prod);
        splay(v);
    }

    void apply(int l, int r, F f) {
        Node* v = between(l, r);
        v->val = mapping(f, v->val);
        v->prod = mapping(f, v->prod);
        v->f = composition(f, v->f);
        splay(v);
    }

    S prod(int l, int r) {
        return between(l, r)->prod;
    }

    int size() {
        if(!root) return 0;
        return root->sz;
    }

    S get(int k) {
        return prod(k, k + 1);
    }
};
