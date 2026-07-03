class MinStack {
    stack<int> st;
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
        if(!st.empty()){

        
        }
        st.push(val);
        
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
       
        st.pop();
        if(!st.empty()){

      
        }
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
