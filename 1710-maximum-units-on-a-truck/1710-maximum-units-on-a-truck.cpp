class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int TruckSize) {
     sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b) {
    return a[1] > b[1];
});
int ans=0;
      for(int i =0;i<boxTypes.size();i++){
       if(TruckSize<=0)break;
     if(boxTypes[i][0]<=TruckSize){
       TruckSize-=boxTypes[i][0];
       ans+=boxTypes[i][1]*boxTypes[i][0];
      }
     else {
      
       ans+=boxTypes[i][1]*TruckSize;
        TruckSize=0;
     }
      }
      return ans;
    }
};