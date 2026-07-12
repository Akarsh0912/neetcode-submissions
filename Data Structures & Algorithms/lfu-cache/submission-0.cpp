class Node {
public:
    int key;
    int value;
    int freq;

    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        freq = 1;
        prev = nullptr;
        next = nullptr;
    }
};

class List {
public:
    int size;
    Node* head;
    Node* tail;

    List() {
        size = 0;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    // Insert node right after head (Most Recently Used)
    void addFront(Node* node) {

        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;

        size++;
    }

    // Remove any node
    void removeNode(Node* node) {

        Node* previous = node->prev;
        Node* nextNode = node->next;

        previous->next = nextNode;
        nextNode->prev = previous;

        size--;
    }
};

class LFUCache {

private:

    int capacity;
    int currentSize;
    int minFreq;

    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqList;

public:

    LFUCache(int capacity) {

        this->capacity = capacity;
        currentSize = 0;
        minFreq = 0;
    }

    void updateFrequency(Node* node) {

        // Remove node from old frequency list
        int oldFreq = node->freq;

        List* oldList = freqList[oldFreq];
        oldList->removeNode(node);

        // If this was the minimum frequency
        // and now the list becomes empty,
        // increase minFreq
        if (oldFreq == minFreq && oldList->size == 0) {
            minFreq++;
        }

        // Increase frequency
        node->freq++;

        // Create new list if not present
        if (freqList.find(node->freq) == freqList.end()) {
            freqList[node->freq] = new List();
        }

        // Insert node into new frequency list
        freqList[node->freq]->addFront(node);
    }

    int get(int key) {

        if (keyNode.find(key) == keyNode.end()) {
            return -1;
        }

        Node* node = keyNode[key];

        updateFrequency(node);

        return node->value;
    }

    void put(int key, int value) {

        if (capacity == 0)
            return;

        // Key already exists
        if (keyNode.find(key) != keyNode.end()) {

            Node* node = keyNode[key];

            node->value = value;

            updateFrequency(node);

            return;
        }

        // Cache full
        if (currentSize == capacity) {

            List* list = freqList[minFreq];

            // Least Recently Used node
            Node* nodeToDelete = list->tail->prev;

            list->removeNode(nodeToDelete);

            keyNode.erase(nodeToDelete->key);

            delete nodeToDelete;

            currentSize--;
        }

        // Create new node
        Node* newNode = new Node(key, value);

        // New node always has frequency = 1
        minFreq = 1;

        if (freqList.find(1) == freqList.end()) {
            freqList[1] = new List();
        }

        freqList[1]->addFront(newNode);

        keyNode[key] = newNode;

        currentSize++;
    }
};