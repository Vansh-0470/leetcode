class MedianFinder {
public:
   priority_queue<int>pq;
   priority_queue<int,vector<int>,greater<int>>minheap;
   vector<int>total;
    MedianFinder() {
        
    }  
    void addNum(int num) {
        total.push_back(num);
        int n =total.size();
        int k;
            if(!minheap.empty()){
           if(num>minheap.top()){
            pq.push(minheap.top());
            minheap.pop();
            minheap.push(num);
           }
           else {
            pq.push(num);
           }
            }
            else {
            pq.push(num);
           }
             
           if(n%2==0){
            k=n/2+1;
           }
           else {
            k=(n+1)/2;
           }
            if(pq.size()>k){
                minheap.push(pq.top());
               pq.pop();
            }
    }
    
    double findMedian() {
        int n =total.size();
        double ans ;
        if(n%2!=0){
            return pq.top();
        }
        else {
        int a =pq.top();
        pq.pop();
        int b =pq.top();
        pq.pop();
        ans=(double)(a+b)/2;
        pq.push(a);
        pq.push(b);
        }
        return ans ;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */