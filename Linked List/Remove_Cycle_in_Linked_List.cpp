#include<iostream>
using namespace std;

class ListNode{
    public:
       int data;
       ListNode*next;

       ListNode(int d){
        this->data=d;
        this->next=NULL;
       }
};

ListNode* detectCycle(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;

            if (slow == fast) {
                slow = head;

                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }

        return NULL;
    }

 void remove_cycle(ListNode* &head){
    if(head == NULL){
        return;
    }

    ListNode *startofloop=detectCycle(head);

    if(startofloop == NULL){
        return;
    }

    ListNode *temp=startofloop;

    while(temp->next != startofloop){
        temp=temp->next;
    }

    temp->next=NULL;

 }
 
void print(ListNode* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    ListNode *head = new ListNode(3);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(0);
    ListNode *fourth = new ListNode(-4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second;

    remove_cycle(head);

    print(head);

    return 0;
}