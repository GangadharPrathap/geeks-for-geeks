#include <bits/stdc++.h>  
using namespace std;  

struct Node {  
    int data;  
    Node* next;  
};  

void push(Node** head_ref, int new_data) {  
    Node* new_node = new Node{new_data, *head_ref};  
    *head_ref = new_node;  
}  

Node* reverseList(Node* head) {  
    stack<Node*> stk;  
    for (Node* ptr = head; ptr; ptr = ptr->next)  
        stk.push(ptr);  

    head = stk.top();  
    stk.pop();  
    Node* ptr = head;  

    while (!stk.empty()) {  
        ptr->next = stk.top();  
        stk.pop();  
        ptr = ptr->next;  
    }  
    ptr->next = nullptr;  
    return head;  
}  

void printList(Node* head) {  
    while (head) {  
        cout << head->data << " ";  
        head = head->next;  
    }  
}  

int main() {  
    Node* head = nullptr;  
    for (int i = 5; i >= 1; --i)  
        push(&head, i);  

    head = reverseList(head);  
    printList(head);  
    return 0;  
}  
