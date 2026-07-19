class FreqStack {
public:
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> group;
    int maxFreq;
    FreqStack() {
        maxFreq=0;
    }
    
    void push(int val) {
        int f = freq[val]++;
        maxFreq = max(f,maxFreq);
        group[f].push(val);

    }
    
    int pop() {
        int popped = group[maxFreq].top();
        group[maxFreq].pop();
        freq[popped]--;

        if(group[maxFreq].empty()){
            maxFreq--;
        }
        return popped;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */