// https://takeuforward.org/data-structure/find-middle-element-in-a-linked-list/

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

Node *findMiddle(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node *temp = head;
    int count = 0;

    while(temp!=NULL){
        count++;
        temp = temp->next;
    }

    int mid = count / 2 + 1;
    temp = head;

    while(temp!=NULL){
        mid = mid - 1;

        if(mid==0){
            break;
        }

        temp = temp->next;
    }

    return temp;

    // Time Complexity: O(N+N/2) ~ O(N)
    // Space Complexity : O(1)
}

Node *findMiddle_Optimal(Node* head){
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;

    // Time Complexity: O(N/2) ~ O(N)
    // Space Complexity : O(1)
}

int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Find the middle node
    Node *middleNode = findMiddle(head);

    // Display the value of the middle node
    cout << "The middle node value is: " << middleNode->data << endl;

    return 0;
}
