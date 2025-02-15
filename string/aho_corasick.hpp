template <int ALPHA_SIZE=26>
struct AhoCorasick {
    struct Node {
        vector<Node*> children;
        Node* fail;
        vector<int> output;
        Node() : children(ALPHA_SIZE, nullptr), fail(nullptr) {}
    };

    Node* root;
    vector<string> patterns;

    AhoCorasick() : root(new Node()) {}

    void insert(const string& word, int index) {
        Node* cur = root;
        for(char c : word) {
            int idx = c - 'a';
            if(cur->children[idx] == nullptr) cur->children[idx] = new Node();
            cur = cur->children[idx];
        }
        cur->output.push_back(index);
    }

    void build() {
        queue<Node*> q;
        root->fail = root;
        for(int i = 0; i < ALPHA_SIZE; i++) {
            if(root->children[i]) {
                root->children[i]->fail = root;
                q.push(root->children[i]);
            }
            else root->children[i] = root;
        }
        while(q.size()) {
            Node* cur = q.front();
            q.pop();
            for(int i = 0; i < ALPHA_SIZE; i++) {
                Node* child = cur->children[i];
                if(child) {
                    child->fail = cur->fail->children[i];
                    child->output.insert(child->output.end(), child->fail->output.begin(), child->fail->output.end());
                    q.push(child);
                }
                else cur->children[i] = cur->fail->children[i];
            }
        }
    }

    vector<pair<int, int>> search(const string& word) {
        vector<pair<int, int>> matches;
        Node* cur = root;
        for(int i = 0; i < (int)word.size(); i++) {
            int idx = word[i] - 'a';
            cur = cur->children[idx];
            for(int pat_idx : cur->output) matches.emplace_back(i, pat_idx);
        }
        return matches;
    }
};
