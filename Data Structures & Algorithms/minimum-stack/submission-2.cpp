class MinStack {
private:
    stack<long long> st;
    long long minEle;

public:
    MinStack() {
    }

    void push(int val) {

        if (st.empty()) {
            st.push(val);
            minEle = val;
        }
        else if (val >= minEle) {
            st.push(val);
        }
        else {
            st.push(2LL * val - minEle);
            minEle = val;
        }
    }

    void pop() {

        if (st.empty()) return;

        if (st.top() >= minEle) {
            st.pop();
        }
        else {
            minEle = 2LL * minEle - st.top();
            st.pop();
        }
    }

    int top() {

        if (st.top() >= minEle)
            return st.top();

        return minEle;
    }

    int getMin() {
        return minEle;
    }
};