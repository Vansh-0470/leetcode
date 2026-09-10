// think of lower bound function which uses binary search 
class MyCalendar {
public:
 vector<vector<int>>event;
    MyCalendar() {
       
    }
    
    bool book(int startTime, int endTime) {
        vector<int>help;
        help.push_back(startTime);
        help.push_back(endTime);
        if(event.size()==0){
       event.push_back(help);
       return true ;
        }
        for(int i =0;i<event.size();i++){
            if((startTime>=event[i][0]&&startTime<event[i][1])||(event[i][0]>startTime&&event[i][0]<endTime)){
                return false ;
            }
           else  if((endTime>event[i][0]&&endTime<event[i][1])||event[i][1]>startTime&&event[i][1]<endTime){
                return false ;
            }
        }
        event.push_back(help);
        return true ;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */