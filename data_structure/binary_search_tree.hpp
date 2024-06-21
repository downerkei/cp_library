template<class T=int>
struct BinarySearchTree{
    struct Node{
        T val;
        Node* l = nullptr;
        Node* r = nullptr;
        Node* p = nullptr;
        Node(T x) : val(x) {}
    };

    Node* root = nullptr;

    Node* Find(T x) {
        Node* cur = root;
        while(cur) {
            if(cur->val == x) return cur;
            if(cur->val < x) cur = cur->r;
            else cur = cur->l;
        }
        return cur;
    }

    void Insert(T x) {
        Node* new_node = new Node(x);
        Node* cur = root;
        Node* pre = nullptr;
        while(cur) {
            pre = cur;
            if(cur->val < x) cur = cur->r;
            else cur = cur->l;
        }
        if(!pre) root = new_node;
        else if(pre->val < x) pre->r = new_node;
        else pre->l = new_node;
        new_node->p = pre;
    }

    bool Erase(T x) {
        Node* del = Find(x);
        if(!del) return false;
        if(!del->l) Transplant(del, del->r);
        else if(!del->r) Transplant(del, del->l);
        else {
            Node* nxt = del->r;
            while(nxt->l) nxt = nxt->l;
            if(del->r != nxt) {
                Transplant(nxt, nxt->r);    
                nxt->r = del->r;
                nxt->r->p = nxt;
            }
            Transplant(del, nxt);
            nxt->l = del->l;
            nxt->l->p = nxt;
        }
        delete del;
        return true;
    }

    void Transplant(Node* u, Node* v) {
        if(u == root) root = v;
        else if(u == u->p->l) u->p->l = v;
        else u->p->r = v;
        if(v) v->p = u->p;
    }

    T Minimum() {
        Node* cur = root;
        Node* pre = nullptr;
        while(cur) {
            pre = cur;
            cur = cur->l;
        }
        if(!pre) return -1;
        return pre->val;
    }

    T Maximum() {
        Node* cur = root;
        Node* pre = nullptr;
        while(cur) {
            pre = cur;
            cur = cur->r;
        }
        if(!pre) return -1;
        return pre->val;
    }
};