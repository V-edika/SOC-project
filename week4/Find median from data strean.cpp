class MedianFinder {
    priority_queue<int> low;                                  
    priority_queue<int, vector<int>, greater<int>> high;    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        low.push(num);
        high.push(low.top());
        low.pop();                        
        if (low.size() < high.size()) { 
            low.push(high.top()); high.pop();
         }
    }
    
    double findMedian() {
        return low.size() > high.size() ? low.top() :  (low.top()/2.0) + (high.top()/2.0) ;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
