class MyQueue {
public:
//The main idea behind this approach is to optimize the push operation which was taking O(2n) Time so top and pop operation are modified 
stack<int>s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int temp1 = 0;
        int temp2 = 0;
        if(s2.size() != 0)
        {
            temp1 = s2.top();
            s2.pop();
            return temp1;
        }
        while(s1.size() != 0)
        {
            s2.push(s1.top());
            s1.pop();
        }
        temp2 = s2.top();
        s2.pop();
        return temp2;
    }
    
    int peek() {
        int temp3 = 0;
        int temp4 = 0;
        if(s2.size() != 0)
        {
            temp3 = s2.top();
            return temp3;
        }
          while(s1.size() != 0)
        {
            s2.push(s1.top());
            s1.pop();
        }
        temp4 = s2.top();
        return temp4;
    }
    
    bool empty() {
        if(s1.size() == 0 && s2.size() == 0)
        {
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */