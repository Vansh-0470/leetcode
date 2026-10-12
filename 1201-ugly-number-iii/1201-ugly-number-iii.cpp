class Solution {
public:
 long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
     }
     
    int nthUglyNumber(int n, int a, int b, int c) {
    //     set<long long> st;
    //   //  int mini=min(a,min(b,c));
    //   st.insert(a);
    //     st.insert(b);
    //       st.insert(c);
    //     long long smallest;
    //     while(n>0){
    //         smallest = *st.begin();
    //         st.erase(st.begin());
    //         st.insert(smallest*a);
    //          st.insert(smallest*b);
    //           st.insert(smallest*c);
    //           n--;
    //     }
    //     return smallest
    long long low =1;
    long long num=pow(10,9);
    long long  high=num*2;
   
long long ab = lcm(a, b);
long long bc = lcm(b, c);
long long ac = lcm(a, c);
long long abc = lcm(ab, c);
    while(low<high){
    int mid =low+(high-low)/2;
    long long  total=((long long)(mid/a)+(long long)(mid/b)+(long long)(mid/c)-(long long)(mid/(ab))-(long long)(mid/(bc))-(long long)(mid/(ac))+(long long)(mid/(abc)));
   if (total >= n) {
    high = mid;
     } else {
     low = mid + 1;
     }
    }
    return low ;
    }
};