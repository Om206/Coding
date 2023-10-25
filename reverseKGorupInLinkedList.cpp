#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void insertNode(struct ListNode *&head, int val)
{
    struct ListNode *newNode = new ListNode(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    struct ListNode *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return;
}

void displayList(struct ListNode *head)
{
    while (head->next != NULL)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << head->val << endl;
    return;
}

struct ListNode *reverseList(struct ListNode *&head)
{
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *next = NULL;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return prev;
}

int countLength(struct ListNode *head)
{
    int count = 0;
    while (head)
    {
        head = head->next;
        count++;
    }
    return count;
}

struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
    if (head == NULL || k == 1)
        return head;
    struct ListNode *dummy = new ListNode(0);
    dummy->next = head;
    struct ListNode *prev = dummy;
    struct ListNode *curr = dummy;
    struct ListNode *next = dummy;
    int length = countLength(head);
    int count = length;
    while (count >= k)
    {
        curr = prev->next;
        next = curr->next;
        for (int i = 1; i < k; i++)
        {
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }
        prev = curr;
        count -= k;
    }
    return dummy->next;
}

int main()
{
    struct ListNode *head = NULL;
    int k, n;
    cin >> k >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insertNode(head, x);
    }
    insertNode(head, 10);
    displayList(head);
    displayList(head);
    displayList(head);

    struct ListNode *revHead = reverseList(head);
    displayList(revHead);
    head = reverseList(revHead);
    cout << countLength(head) << endl;
    displayList(head);

    cout << "Reverse with k group\n";
    head = reverseKGroup(head, k);
    displayList(head);
    return 0;
}