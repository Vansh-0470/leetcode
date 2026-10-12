class Solution {
public:

    int nthUglyNumber(int n) {
        
        set<long long> st;

      st.insert(1);

        

        
        long long smallest;
        while(n>0){
            smallest = *st.begin();
            st.erase(st.begin());
            st.insert(smallest*2);
             st.insert(smallest*3);
              st.insert(smallest*5);
              n--;
        }
        return smallest;
    }
};