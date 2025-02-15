template <int ALPHA_SIZE=26>
struct Trie {
    struct Node {
        vector<Node*> children;
        bool is_end;
        Node() : is_end(false), children(ALPHA_SIZE, nullptr) {}
    };

    Node* root;

    Trie() : root(new Node()) {}

    void insert(const string& word) {
        Node* cur_node = root;
        for(char c : word) {
            int idx = c - 'a';
            if(cur_node->children[idx] == nullptr) cur_node->children[idx] = new Node();
            cur_node = cur_node->children[idx];
        }

        cur_node->is_end = true;
    }

    bool search(const string& word) {
        Node* cur_node = root;
        for(char c : word) {
            int idx = c - 'a';
            if(cur_node->children[idx] == nullptr) return false;
            cur_node = cur_node->children[idx];
        }
        return cur_node->is_end;
    }
};
