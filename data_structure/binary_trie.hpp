template<typename U = unsigned, int B = 32>
struct BinaryTrie {
    struct Node {
        int cnt;
        Node *ch[2];
        Node() : cnt(0), ch{nullptr, nullptr} {}
    };

    BinaryTrie() : root(nullptr) {}

    void insert(U x) { insert(root, x); }
    void erase(U x) { erase(root, x); }
    bool find(U x) { return find(root, x); }
    U xor_max(U x) { return xor_min(root, ~x); }
    U xor_min(U x) { return xor_min(root, x); }

  private: 
    Node* root;

    void insert(Node*& n, U x, int b = B - 1) {
        if(n == nullptr) n = new Node();
        n->cnt++;
        if(b >= 0) insert(n->ch[(x >> b) & 1], x, b - 1);
    }    

    void erase(Node*& n, U x, int b = B - 1) {
        if(b >= 0) erase(n->ch[(x >> b) & 1], x, b - 1);
        if(n && --n->cnt == 0) { delete n; n = nullptr; }
    }

    bool find(Node* n, U x, int b = B - 1) {
        if(n == nullptr) return false;
        if(b < 0) return true;
        if(n->ch[(x >> b) & 1] == nullptr) return false;
        return find(n->ch[(x >> b) & 1], x, b - 1);
    }

    U xor_min(Node* n, U x, int b = B - 1) {
        if(b < 0) return 0;
        bool f = (x >> b) & 1;
        if(n->ch[f] == nullptr) f ^= 1;
        return xor_min(n->ch[f], x, b - 1) | ((U)f << b);
    }
};
