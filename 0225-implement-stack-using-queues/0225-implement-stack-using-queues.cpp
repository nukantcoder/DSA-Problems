class MyStack {
public:
queue<int>q1;
    MyStack() {
        
    }
    
    void push(int x) {
        if(q1.size() == 0)
        {
            q1.push(x);
        }
        else
        {
            q1.push(x);
            int count = 0;
            while(count != (q1.size() - 1))
            {
                q1.push(q1.front());
                q1.pop();
                count++;
            }
        }
      
    }
    
    int pop() {
        int temp = q1.front();
        q1.pop();
        return temp;
    }
    
    int top() {
       return q1.front(); 
    }
    
    bool empty() {
        if(q1.size() == 0)
        {
            return true;
        }
        return false;
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