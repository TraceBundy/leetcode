class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        Node *node = new Node(x);
        if (!head->next){
            head->next = node;
        } else {
            Node *tmp = head->next;
            head->next = node;
            node->next = tmp;
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        if (head->next){
            Node *tmp = head->next;
            head->next = tmp->next;
            delete tmp;
        }
    }

    // Get the top element.
    int top() {
        if (head->next){
            return head->next->val;
        }
        return 0;
    }

    // Return whether the stack is empty.
    bool empty() {
        if (head->next) return false;
        else return true;
    }
    
    typedef struct Node{
        int val;
        struct Node *next;
        Node(int x):val(x), next(NULL){}
        Node():next(NULL){}
    }Node;
    
    Node *head;
    
    Stack(){
        head = new Node();
    }
};