// https://takeuforward.org/data-structure/add-two-numbers-represented-as-linked-lists/

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

        Node(int data){
            data = data;
            next = nullptr;
        }
};

Node* addTwoNumbers(Node* head1, Node* head2){
    Node *dummy = new Node();
    Node *temp = dummy;

    int carry = 0;
    while(head1!=NULL || head2!=NULL || carry){
        int sum = 0;
        if(head1!=NULL){
            sum += head1->data;
            head1=head1->next;
        }
        if (head2 != NULL){
            sum += head2->data;
            head2 = head2->next;
        }

        sum += carry;
        carry = sum / 10;// https://takeuforward.org/data-structure/add-two-numbers-represented-as-linked-lists/

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

        Node(int data){
            data = data;
            next = nullptr;
        }
};

Node* addTwoNumbers(Node* head1, Node* head2){
    Node *dummy = new Node();
    Node *temp = dummy;

    int carry = 0;
    while(head1!=NULL || head2!=NULL || carry){
        int sum = 0;
        if(head1!=NULL){
            sum += head1->data;
            head1=head1->next;
        }
        if (head2 != NULL){
            sum += head2->data;
            head2 = head2->next;
        }

        sum += carry;
        carry = sum / 10;

        Node *Node = new Node(sum % 10);
        temp->next = Node;
        temp = temp->next;
    }
    return dummy->next;

    // Time Complexity: O(max(m,n))
    // Space Complexity : O(max(m, n))
}

int main(){

    return 0;
}

        Node *Node = new Node(sum % 10);
        temp->next = Node;
        temp = temp->next;
    }
    return dummy->next;

    // Time Complexity: O(max(m,n))
    // Space Complexity : O(max(m, n))
}

int main(){

    return 0;
}
