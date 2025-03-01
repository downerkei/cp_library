template<typename U = unsigned, int B = 32>
struct BinaryTrie {
    struct Node {
        int cnt;
        Node *ch[2];
        Node() : cnt(0), ch{nullptr, nullptr} {}
    };

    BinaryTrie() {}

    void insert(U val) { root = insert(root, val); }
    void erase(U val) { root = erase(root, val); }
    bool find(U val) { return find(root, val); }
    U xor_max(U val) { return xor_min(root, ~val); }
    U xor_min(U val) { return xor_min(root, val); }

  private: 
    Node* root;

    Node* insert(Node* n, U val, int b = B - 1) {
        if(n == nullptr) n = new Node();
        n->cnt++;
        if(b >= 0) n->ch[(val >> b) & 1] = insert(n->ch[(val >> b) & 1], val, b - 1);
        return n;
    }

    Node* erase(Node* n, U val, int b = B - 1) {
        if(b >= 0) n->ch[(val >> b) & 1] = erase(n->ch[(val >> b) & 1], val, b - 1);
        n->cnt--;
        if(n->cnt == 0) { delete n; return nullptr; }
        return n;
    }

    bool find(Node* n, U val, int b = B - 1) {
        if(b < 0) return true;
        int f = (val >> b) & 1;
        if(n->ch[f] == nullptr) return false;
        return find(n->ch[f], val, b - 1);
    }

    U xor_min(Node* n, U val, int b = B - 1) {
        if(b < 0) return 0;
        bool f = (val >> b) & 1;
        if(n->ch[f] == nullptr) f ^= 1;
        return xor_min(n->ch[f], val, b - 1) | ((U)f << b);
    }
};
