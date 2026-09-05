class TimeMap {
public:
  unordered_map<string,map<int, string>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
     m[key][timestamp]=value ;
    }
    
    string get(string key, int timestamp) {
       // as timestamp in increasing order than apply binary search to find the value 
       // stucked at how to find the last timestamp for that key 
       // ok so need to find the range just use ordered inner map  then use upper bound function which will give the first times greater than timestamp and move one step back and return the ans 
       auto &mp = m[key];

    auto it = mp.upper_bound(timestamp);

    if(it == mp.begin())
        return "";

    --it;

    return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */