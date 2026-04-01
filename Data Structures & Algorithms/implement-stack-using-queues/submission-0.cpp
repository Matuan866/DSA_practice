class MyStack {
private:
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int n=q.size();
        q.push(x);

        for(int i=0;i<n;++i){
            int fr=q.front();
            q.pop();
            q.push(fr);
        }
    }
    
    int pop() {
        int topEle=q.front();
        q.pop();
        return topEle;
    }
    
    int top() {
        int topEle=q.front();
        return topEle;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */