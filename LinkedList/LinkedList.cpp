#include <iostream>

template <typename T>
class LinkedList final {
private:
    struct ListNode {
        T data;
        ListNode* next;
        ListNode(T x = 0, ListNode* next = nullptr) : data(x), next(next) {}
    };

    const ListNode* m_dummy; // 哨兵节点
    ListNode* m_tail;        // 尾指针
    size_t m_size;           // 链表节点数量

public:
    explicit LinkedList() : m_dummy(new ListNode()) {
        m_tail = m_dummy;
    }

    virtual ~LinkedList() {
        if (!m_dummy) return;
        delete m_dummy;
        m_dummy = nullptr;
        m_tail = nullptr;
    }

    void push_back(int x) const noexcept {
        // 在末尾添加节点
        insert(m_tail, x);
        m_tail = m_tail->next;
    }

    void pop_back() const noexcept {
        // 删除末尾节点
        ListNode* p = m_dummy;
        while (p && p->next != m_tail) {
            p = p->next;
        }
    }

    void insert(ListNode* prev, int data) const noexcept {
        // 在 prev 节点之后插入
        if (!prev) return;
        ListNode* node = new ListNode(data);
        node->next = prev->next;
        prev->next = node;
    }

    void remove(ListNode* prev) const noexcept {
        // 删除 prev 节点之后的一个节点
        if (!prev || !prev->next) return;
        ListNode* node = prev->next;
        prev->next = prev->next->next;
        delete node;
    }

    T& back() {
        if (empty()) {
            throw "LinkedList is empty.";
        }
        return m_tail->data;
    }

    size_t size() const noexcept {
        return m_size;
    }

    bool empty() const noexcept {
        return m_size == 0;
    }

    static void PrintList(ListNode* head) noexcept {
        while (head) {
            std::cout << head->data << "->";
            head = head->next;
        }
        std::cout << std::endl;
    }
};
