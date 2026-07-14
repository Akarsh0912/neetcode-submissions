class Solution {
public:
    bool isValid(string str) {
        stack<char> st;
        for(auto s : str){
            if(s == '(' || s == '{' || s == '['){
                st.push(s);
            }
            else if(s == ')'){
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(s == '}'){
                if(!st.empty() && st.top() == '{'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(s == ']'){
                if(!st.empty() && st.top() == '['){
                    st.pop();
                }
                else{
                    return false;
                }

            }
        }
       if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
