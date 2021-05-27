class MyLinkedList {
private:
    struct Node{
        int val;
        Node *next;
    };

public:
    Node* head;
    // Linked List basic functions
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = nullptr;
    }
    /** Print the list */
    void printList(Node* n)
    {
        while (n != nullptr) {
            std::cout << n->val << " ";
            n = n->next;
        }
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        Node *indexed_node = new Node();
        indexed_node = head;
        while (index > 0)
        {
           index--;
           indexed_node = indexed_node->next;
           if (indexed_node == nullptr) return -1;
        }

        return indexed_node->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *new_node = new Node();
        new_node->val = val;
        new_node->next = head;
        head = new_node;

    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *new_node = new Node();
        new_node->val = val;
        new_node->next = nullptr;
        if (head == nullptr) head = new_node;
        else
        {
            Node *i = head;
            while (i->next != nullptr)
            {
                i = i->next;
            }
            i->next = new_node;
        }
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        Node *new_node = new Node();
        new_node->val = val;
        if (index == 0)
        {
            return addAtHead(val);
        }

        Node *prev_node = head;
        while (index > 1)
        {
            if (prev_node == nullptr) return;
            index--;
            prev_node = prev_node->next;
        }
        new_node->next = prev_node->next;
        prev_node->next = new_node;

    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        Node *prev_node = head;
        if (index == 0)
        {
            head = head->next;
            return;
        }
        while (index > 1)
        {
            if (prev_node == nullptr) return;
            index--;
            prev_node = prev_node->next;
        }
        if(prev_node->next == nullptr)
        {
            return;
        }
        prev_node->next = prev_node->next->next;


    }

    /** get size of list */
    int getSize() {
        int size =0;
        Node *i = head;
        while (i->next != NULL)
        {
            size++;
        }
        return size;
    }

    /** Append a node of value val to the last element of the linked list with next to a prev. */
    void addCycle(int val,int index) {
        Node *new_node = new Node();
        Node *temp_node = head;
        new_node->val = val;
        if (head == nullptr) head = new_node;
        else
        {
            Node *i = head;
            while (i->next != nullptr)
            {
                i = i->next;
            }
            i->next = new_node;
            while (index > 0)
            {
                index--;
                temp_node = temp_node->next;
            }
            new_node->next = temp_node;
        }


    }

    /** Check for cycle in the linked list */
    bool hasCycle() {
        if (head == nullptr || head->next == nullptr) return false;
        Node *slow = head;
        Node *fast = head->next;
        while(1)
        {
            if( fast == nullptr || fast->next == nullptr) return false;

            if (slow == fast) return true;

            slow = slow->next;
            fast = fast->next->next;
        }

    }

    /** Detect the cycle Node in the linked list */
    int detectCycle()
        {

            if (head == nullptr || head->next == nullptr) return 0;
            Node *slow = head;
            Node *fast = head->next;
            while (1) {
                if (fast == nullptr || fast->next == nullptr) return 0;

                if (slow == fast) {
                    slow = head;
                    fast = fast->next;
                    while (slow != fast) {

                        slow = slow->next;
                        fast = fast->next;
                    }
                    return slow->val;
                };
                slow = slow->next;
                fast = fast->next->next;

            }
        }

    };