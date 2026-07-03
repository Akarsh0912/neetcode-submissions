class MinStack {
    stack<int> st;
    stack<int> minSt;
    void getMinElement(stack<int>&st,int &ans){
        if(st.empty()){
            return;
        }

        int topElm = st.top();
        st.pop();
        ans = min(ans,topElm);
        getMinElement(st,ans);
        st.push(topElm);
    }
public:
    
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);

        if (minSt.empty())
            minSt.push(val);
        else{
            int minVal = min(val,minSt.top());
            minSt.push(minVal);
            
        }
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        st.pop();
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        return st.top();
    }
    
    int getMin() {
        int ans = INT_MAX;
        stack<int> temp = st;
        getMinElement(st,ans);
        return ans;
        
    }
};
