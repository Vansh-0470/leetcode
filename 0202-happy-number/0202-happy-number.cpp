class Solution {
public:
    bool isHappy(int n) {
        int old = n;
        set<int>s;
        while(true){
            s.insert(n);
           int sum =0;
           while(n!=0){
           sum = sum+((n%10)*(n%10));
           n=n/10;
           }
           if(sum==1){
            return true ;
           }
            if (s.find(sum)!=s.end()){
            return false ;
           }
           else{
            n=sum;
           // sum=0;
           }
        }
        return true ;
    }
};