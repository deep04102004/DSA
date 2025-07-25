//148. Sort List
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //class ListNode
    class ListNode {
    public:
        int val;
        ListNode *next;
        
        ListNode(int d){
            this->val=d;
            this->next=NULL;
        }
    };

private:
    ListNode* merge(ListNode* left, ListNode* right) {
        if (left == NULL) {
            return right;
        }
        if (right == NULL) {
            return left;
        }

        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;

        while (left != NULL && right != NULL) {
            if (left->val < right->val) {
                temp->next = left;
                temp = left;
                left = left->next;
            } else {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }

        while (left != NULL) {
            temp->next = left;
            temp = left;
            left = left->next;
        }

        while (right != NULL) {
            temp->next = right;
            temp = right;
            right = right->next;
        }

        ans = ans->next;
        return ans;
    }

    ListNode* middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* mid = middle(head);

        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        left = sortList(left);
        right = sortList(right);

        ListNode* result = merge(left, right);

        return result;
    }

    // helper to create list from vector
    ListNode* createList(const vector<int>& arr) {
        if (arr.empty()) return nullptr;
        ListNode* head = new ListNode(arr[0]);
        ListNode* temp = head;
        for (int i = 1; i < (int)arr.size(); i++) {
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }
        return head;
    }

    // helper to print list
    void printList(ListNode* head) {
        while (head != nullptr) {
            cout << head->val;
            if (head->next) cout << " -> ";
            head = head->next;
        }
        cout << endl;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {4, 2, 1, 3};
    Solution::ListNode* head = sol.createList(arr);

    cout << "Original list: ";
    sol.printList(head);

    Solution::ListNode* sorted = sol.sortList(head);

    cout << "Sorted list:   ";
    sol.printList(sorted);

    return 0;
}
