class LRUCache {
public:
    struct node {
    int data;
    node* pre;
    node* next;

    node(int val) {
        data = val;
        pre = nullptr;
        next = nullptr;
    }
};
unordered_map<int,pair<node*,int>>m;
int cap;
node * head;
node * tail;
    LRUCache(int capacity) {
        cap=capacity;
       head=NULL;
       tail=NULL;
    } 
    int get(int key) {
        // if found in map then return the value and shift it at last 
     if(m.find(key)!=m.end()){
              node * find=m[key].first;
              if(find->pre!=NULL&&find->next!=NULL){
                find->pre->next=find->next;
                find->next->pre=find->pre;
                tail->next=find;
                find->pre=tail;
                find->next=NULL;

                tail=find;
              }
              else if (find->next!=NULL){
                   head=head->next;
                   head->pre=NULL;
                tail->next=find;
             find->pre=tail;
             find->next = NULL;
             tail=find;
              }
                //m[key]={tail,value};
        return m[key].second;
     }  
     else return -1; 
    }
    
    void put(int key, int value) {
       
        
            // if first then inilize the head
        if(head==NULL){
            head= new node(key);
            tail=head;
            cap--;
             m[key]={tail,value};
        }
        else{
            // if unique key then add that at last and add value in map
            if(m.find(key)==m.end()){
                 if(cap==0){
            // delete head node and add the new node at last
            m.erase(head->data);
           node * temp=new node(key);
           if(head->next!=NULL){
             head=head->next;
           head->pre=NULL;
            tail->next=temp;
             temp->pre=tail;
             tail=temp;
           }
           else {
           head=temp;
           tail=temp;

           } 
         
           m[key]={tail,value};
        }
        else{
                node * temp=new node(key);
                tail->next=temp;
                temp->pre=tail;
                tail=temp;
                m[key]={tail,value};
                cap--;}
            }
            // if already in map then shift that node to end and change it value to the new one
            else{
                node * find=m[key].first;
                if(find->pre!=NULL&&find->next!=NULL){
                find->pre->next=find->next;
                find->next->pre=find->pre;
                tail->next=find;
                find->pre=tail;
                    find->next=NULL;

                tail=find;
              }
              else if (find->next!=NULL){
                   head=head->next;
                   head->pre=NULL;
                tail->next=find;
             find->pre=tail;
             find->next = NULL;
             tail=find;
              }
                m[key]={tail,value};
            }
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */