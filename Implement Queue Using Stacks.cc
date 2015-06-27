class Queue {
public:
    Queue(){
        head = new List();
        end = new List();
        head->next = end;
        head->pre = end;
        end->next = head;
        end->pre = head;
    }
    // Push element x to the back of queue.
    void push(int x) {
        List *node = new List(x);
        if (head->next == end){
            head->next = node;
            node->pre = head;
            node->next = end;
            end->pre = node;
        } else {
            node->next = end;
            node->pre = end->pre;
            end->pre->next = node;
            end->pre = node;
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (head->next != end){
            List *node = head->next;
            head->next = node->next;
            node->next->pre = head;
            delete node;
        }
    }

    // Get the front element.
    int peek(void) {
        if (head->next != end){
            return head->next->val;
        }
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return head->next == end;
    }
private:
    typedef struct List{
        List(int i = 0):val(i),pre(NULL), next(NULL){}
        int val;
        struct List *pre;
        struct List *next;
    }List;
    List *head;
    List *end;
};