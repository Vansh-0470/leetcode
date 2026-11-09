class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int>ans;
        int n =arr.size();
        for(int i =0;i<n;i++){
            if(arr[i]==0){
                ans.push_back(arr[i]);
                 if(ans.size()==n){
                break ;
            }
                ans.push_back(0);
            }
            else {
                 ans.push_back(arr[i]);
            }
            if(ans.size()==n){
                break ;
            }
        }
        arr=ans;
        return  ;
    }
};