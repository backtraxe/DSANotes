#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x = 0, ListNode* next = nullptr) : val(x), next(next) {}
};

class MergeSort {
public:
    static ListNode* mergeSort(ListNode* head) noexcept {
        if (!head || !head->next) return head;

        // 快慢指针找到中间节点
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // 断开链接
        ListNode* mid = slow->next;
        slow->next = nullptr;

        // 2路归并
        ListNode* p1 = mergeSort(head);
        ListNode* p2 = mergeSort(mid);
        ListNode dummy;
        ListNode* p = &dummy;
        while (p1 && p2) {
            if (p1->val < p2->val) {
                p->next = p1;
                p1 = p1->next;
                p = p->next;
            } else {
                p->next = p2;
                p2 = p2->next;
                p = p->next;
            }
        }
        if (p1) p->next = p1;
        if (p2) p->next = p2;

        return dummy.next;
    }
};

ListNode* createList(vector<int>& nums) {
    ListNode dummy;
    ListNode* pre = &dummy;
    for (int& x : nums) {
        pre->next = new ListNode(x);
        pre = pre->next;
    }
    return dummy.next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

bool checkSorted(ListNode* head, bool ascend = true) {
    if (!head || !head->next) return true;
    ListNode* pre = head;
    ListNode* cur = pre->next;
    while (cur) {
        if (ascend && pre->val > cur->val) return false;
        if (!ascend && pre->val < cur->val) return false;
        pre = cur;
        cur = cur->next;
    }
    return true;
}

int main() {
    vector<int> nums = {3, 1, 2, 5, 6, 4};
    ListNode* head = createList(nums);
    printList(head);
    ListNode* newHead = MergeSort::mergeSort(head);
    printList(newHead);
    assert(checkSorted(newHead));
    return 0;
}