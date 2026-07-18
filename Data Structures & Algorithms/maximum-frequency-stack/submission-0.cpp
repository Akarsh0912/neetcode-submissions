class FreqStack {
private:
    unordered_map<int, int> freq;          // value -> frequency
    unordered_map<int, stack<int>> group;  // frequency -> stack of values
    int maxFreq;

public:
    FreqStack() {
        maxFreq = 0;
    }

    void push(int val) {
        // Increase frequency
        int f = ++freq[val];

        // Update maximum frequency
        maxFreq = max(maxFreq, f);

        // Push into corresponding frequency stack
        group[f].push(val);
    }

    int pop() {
        // Get most frequent element
        int val = group[maxFreq].top();
        group[maxFreq].pop();

        // Decrease its frequency
        freq[val]--;

        // If no element remains with max frequency
        if (group[maxFreq].empty()) {
            maxFreq--;
        }

        return val;
    }
};