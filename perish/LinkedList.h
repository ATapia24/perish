#ifndef NODE_H
#define NODE_H

#include<cstddef>
#include<iostream>

template<class T>
class LinkList {
public:
    
    LinkList() {
        head = NULL;
        tail = NULL;
    }
    
    ~LinkList() {
        
        Node *_current = head;
        
        
        while(_current != NULL)
        {
            Node* next = _current->next;
            delete _current;
            _current = next;
        }
    }
    
    void add(T object) {
        
    }
    
    T getCurrent() {
        T tmp = current->object;
        current = current->next;
        return tmp;
    }
    
    bool atEnd() { 
        if(current->next == NULL)
            return true;
        
        return false;
    }

    
private:

    int size = 0;
    
    struct Node {
    
        T object;
        Node *next;
    
    };
   
    /* pointer of head node */
    Node *head;
    /* pointer of tail node */
    Node *tail;
    
    Node *current;
   
    
};

#endif /* NODE_H */