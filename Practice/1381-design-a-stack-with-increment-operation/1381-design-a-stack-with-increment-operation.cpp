class CustomStack {
public:
    int count;
    int* arr;
    int size;
    CustomStack(int maxSize) {
        size=maxSize;
        count = 0;
        arr = new int[size];
    }
    
    void push(int x) {
        if(count<size){
        arr[count]=x;
        count++;}
    }
    
    int pop() {
        if(count==0) return -1;
        int a=arr[count-1];
        arr[count-1]=0;
        count-=1;
        return a;
    }
    
    void increment(int k, int val) {
        int m=min(k, count);
        for(int i=0;i<m;i++){
            arr[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */