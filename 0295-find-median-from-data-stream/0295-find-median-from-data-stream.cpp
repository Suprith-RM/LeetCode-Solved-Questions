class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    int size_min, size_max;
    MedianFinder() {
        size_min = 0;
        size_max = 0;
    }

    void addNum(int num) {
        if (maxHeap.empty() || num < maxHeap.top()) {
            maxHeap.push(num);
            size_max++;
        } else {
            minHeap.push(num);
            size_min++;
        }
        if (size_max - size_min > 1) {
            size_max--;
            size_min++;
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (size_min - size_max > 1) {
            size_max++;
            size_min--;
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (size_max == size_min) {
            return (minHeap.top() + maxHeap.top()) / 2.0;
        } else if (size_max > size_min) {
            return maxHeap.top() * 1.0;
        } else {
            return minHeap.top() * 1.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */