class MedianFinder {
    priority_queue<int> left;  // max heap: smaller half
    priority_queue<int, vector<int>, greater<int>> right; // min heap: larger half

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // Put num into the appropriate heap
        if (left.empty() || num <= left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }

        // Balance the heaps
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }
        else if (right.size() > left.size() + 1) {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if (left.size() > right.size()) {
            return left.top();
        }
        
        if (right.size() > left.size()) {
            return right.top();
        }
        
        return (left.top() + right.top()) / 2.0;
    }
};
