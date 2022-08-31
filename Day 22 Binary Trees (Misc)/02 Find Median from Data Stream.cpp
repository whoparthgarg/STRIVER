//space: O(n)
class MedianFinder {
public:
    priority_queue<int> maxh; //for small elements
    priority_queue<int,vector<int>,greater<int>> minh; //for big elements
    MedianFinder() {
        
    }
    
    //time: O(logn)
    void addNum(int n) {
        //inserting elements
        if(maxh.empty()==true or maxh.top()>n)
        {
            maxh.push(n);
        }
        else
        {
            minh.push(n);
        }
        
        //rebalancing
        int diff=maxh.size()-minh.size();
        
        if(diff>1)
        {
            minh.push(maxh.top());
            maxh.pop();
        }
        else if(diff<0)
        {
            maxh.push(minh.top());
            minh.pop();
        }
    }
    
    //time: O(1)
    double findMedian() {
        int n1=maxh.size();
        int n2=minh.size();
        
        if(n1==n2)
        {
            return (n1==0)?0:(maxh.top()+minh.top())/2.0;
        }
        else
        {
            return (n1>n2)?maxh.top():minh.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */