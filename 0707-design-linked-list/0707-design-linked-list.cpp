class MyLinkedList {
    struct Node {
        int val;
        Node* next;
        Node(int v) : val(v), next(nullptr) {}
    };
    int size;
    Node* dummy;
public:
    MyLinkedList() {
        size = 0;
        dummy = new Node(0);
    }
    
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* curr = dummy->next;
        while (index--) curr = curr->next;
        return curr->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index < 0) index = 0;
        Node* pred = dummy;
        for (int i = 0; i < index; ++i) pred = pred->next;
        Node* toAdd = new Node(val);
        toAdd->next = pred->next;
        pred->next = toAdd;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        Node* pred = dummy;
        for (int i = 0; i < index; ++i) pred = pred->next;
        Node* toDel = pred->next;
        pred->next = toDel->next;
        delete toDel;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */