class Solution {
public:
// zero can only be made by 2 and 5 multiplication 
// this is legender's formual 
//Legendre's Formula is used to find the highest power of a prime number \(p\) that divides \(n!\).

    int trailingZeroes(int n) {
       
       int ans =0;
       while(n>=5){
         n/=5;
         ans+=n;
       } 
       return ans ; 
    } 
};