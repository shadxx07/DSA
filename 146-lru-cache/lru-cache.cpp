class LRUCache {
public:

    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };

    int capacity;
    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    // Remove a node
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Insert at front
    void insert(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {

        if(mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        // Make it most recently used
        remove(node);
        insert(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if(mp.find(key) != mp.end()) {

            Node* node = mp[key];

            remove(node);

            node->value = value;

            insert(node);
        }

        // New key
        else {

            Node* node = new Node(key, value);

            mp[key] = node;
            insert(node);

            // Capacity exceeded
            if(mp.size() > capacity) {

                Node* lru = tail->prev;

                mp.erase(lru->key);
                remove(lru);

                delete lru;
            }
        }
    }
};