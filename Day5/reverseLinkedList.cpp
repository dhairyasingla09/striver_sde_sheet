// https://takeuforward.org/data-structure/reverse-a-linked-list/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        
        Node(int data1, Node* next1){
            data = data1;
            next = next1;
        }

        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

Node* reverseLinkedList(Node *head){
    Node *temp = head;
    stack<int> st;
    while(temp!=nullptr){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp!=nullptr){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
    // Time Complexity: O(2N)
    // Space Complexity: O(N)
}

Node *reverseLinkedList_Optimal(Node *head){
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL){
        Node *front = temp->next;

        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;

    // Time Complexity: O(N)    
    // Space Complexity : O(1) 
}

void printLinkedList(Node *head){
    Node *temp = head;
    while (temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Create a linked list with
    // values 1, 3, 2, and 4
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);

    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}
