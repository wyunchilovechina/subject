#include <iostream>

using namespace std;

typedef struct ListNode {
        int val;
        ListNode *next;
} ListNode;

ListNode* addTwoNumbers(ListNode *l1, ListNode *l2);
void printList(ListNode *head);

int main(int argc, char **argv)
{
        ListNode *l1;
        ListNode *l2;

        l1 = (ListNode*)malloc(sizeof(ListNode));
        l2 = (ListNode*)malloc(sizeof(ListNode));

        l1->val = 9;
        l2->val = 1;

        l1->next = (ListNode*)malloc(sizeof(ListNode));
        l1->next->next = NULL;
        l1->next->val = 9;

        printList(addTwoNumbers(l1, l2));

        return 0;
}

void printList(ListNode *head)
{
        while (head != NULL) {
                cout << head->val << ' ';
                head = head->next;
        }
        cout << endl;
}

ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
{
        ListNode *head = (ListNode*)malloc(sizeof(ListNode));
        ListNode *ptr = head;
        int carry = 0;

        while (l1 != NULL && l2 != NULL) {
                ListNode *tmp = (ListNode*)malloc(sizeof(ListNode));
                tmp->val = (l1->val + l2->val + carry) % 10;
                carry = (l1->val + l2->val + carry) / 10;
                l1 = l1->next;
                l2 = l2->next;
                ptr->next = tmp;
                tmp->next = NULL;
                ptr = tmp;
        }
        ListNode *l;
        if (l1 == NULL) {
                l = l2;
        } else {
                l = l1;
        }

        while (l != NULL) {
                ListNode *tmp = (ListNode*)malloc(sizeof(ListNode));
                tmp->val = (l->val + carry) % 10;
                carry = (l->val + carry) / 10;
                l = l->next;
                ptr->next = tmp;
                tmp->next = NULL;
                ptr = tmp;
        }
        if (carry == 1) {
                ListNode *tmp = (ListNode*)malloc(sizeof(ListNode));
                tmp->val = 1;
                ptr->next = tmp;
                tmp->next = NULL;
                ptr = tmp;
        }

        return head->next;
}
