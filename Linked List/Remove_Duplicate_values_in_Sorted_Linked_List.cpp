//83. Remove Duplicates from Sorted List

#include <bits/stdc++.h>
using namespace std;

// ListNode Class
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

//Function For Delete Duplicates
ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *Result = head;

    while (Result != NULL && Result->next != NULL)
    {
        if (Result->val == Result->next->val)
        {   
            ListNode*todelete=Result->next;
            Result->next = Result->next->next;
            delete todelete;
        }

        else
        {
            Result = Result->next;
        }
    }
    return head;
}

//Function For Print a List 
void print(ListNode *&head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL";
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);

    ListNode *temp = deleteDuplicates(head);
    print(temp);

    return 0;
}