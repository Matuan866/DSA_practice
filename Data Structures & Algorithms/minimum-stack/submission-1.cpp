class MinStack {
private:
    stack<int> st;
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        int minVal=st.top();
        stack<int> tmp;
        while(!st.empty()){
            int mini=st.top();
            minVal=std::min(minVal, mini);
            st.pop();
            tmp.push(mini);
        }

        while(!tmp.empty()){
            int temp=tmp.top();
            tmp.pop();
            st.push(temp);
        }
        return minVal;
    }
};
