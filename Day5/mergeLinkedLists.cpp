// https://takeuforward.org/data-structure/merge-two-sorted-linked-lists/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node (int data1, Node* next1){
            data = data1;
            next = next1;
        }

        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

Node* mergeLinkedList(Node* head1, Node* head2){
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;
    
    while(head1!=NULL && head2!=NULL){
        if(head1->data<=head2->data){
            temp->next = head1;
            head1 = head1->next;
        }
        else{
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }

    if (head1 != nullptr){
        temp->next = head1;
    }
    else{
        temp->next = head2;
    }

    return dummyNode->next;
}

void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        // Print the data of the current node
        cout << temp->data << " ";
        // Move to the next node
        temp = temp->next;
    }
    cout << endl;
}


int main(){

    Node *list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    Node *list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

    cout << "First sorted linked list: ";
    printLinkedList(list1);

    cout << "Second sorted linked list: ";
    printLinkedList(list2);

    Node *mergedList =mergeLinkedList(list1, list2);

    cout << "Merged sorted linked list: ";
    printLinkedList(mergedList);

    return 0;
}
