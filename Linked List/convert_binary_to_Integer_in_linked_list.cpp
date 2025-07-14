//1290. Convert Binary Number in a Linked List to Integer

#include <bits/stdc++.h>
using namespace std;

//ListNode Class
class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int d)
    {
        this->val = d;
        this->next = NULL;
    }
};

//Function To Get Decimal From Binary in Linked List
int getDecimalValue(ListNode *head)
{
    ListNode *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    temp = head;
    double sum = 0;
    while (temp != NULL)
    {   
        int value=temp->val;
        sum = sum + (value) * (pow(2, cnt - 1));
        cnt--;
        temp = temp->next;
    }
    return sum;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);

    cout << getDecimalValue(head);  //Output:5

    return 0;
}