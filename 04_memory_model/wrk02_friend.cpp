#include <cassert>
#include <cstddef>
#include <string>
#include <utility>

template <typename Type>
class SingleLinkedList {
    // Узел списка
    struct Node {
        Node() = default;
        Node(const Type& val, Node* next)
            : value(val)
            , next_node(next) {
        }
        Type value;
        Node* next_node = nullptr;
    };

    template <typename ValueType>
    class BasicIterator {
    private:
        // Разрешаем SingleLinkedList обращаться к приватной области
        friend class SingleLinkedList;
        explicit BasicIterator(Node* node) {}
        Node* node_ = nullptr;
    };

public:
    using Iterator = BasicIterator<Type>;
    using ConstIterator = BasicIterator<const Type>;
    [[nodiscard]] Iterator begin() noexcept {
        // Благодаря дружбе SingleLinkedList имеет доступ к приватному конструктору своего итератора
        BasicIterator it;// = Iterator{head_.next_node};
    }

    SingleLinkedList() {
        size_=0;
    }
    
    ~SingleLinkedList(){
        Clear();
    }
    
    void PushFront(const Type& value){
        head_.next_node = new Node(value, head_.next_node);
        ++size_;
    }
    
    
    void Clear(){
        while(head_.next_node) {
            Node* next_node_new = head_.next_node->next_node;
            delete head_.next_node;
            head_.next_node = next_node_new;
            --size_;
        }
    }

    // Возвращает количество элементов в списке за время O(1)
    [[nodiscard]] size_t GetSize() const noexcept {
        // Заглушка. Реализуйте метод самостоятельно
        //assert(false);
        //return 42;
        return size_;
    }

    // Сообщает, пустой ли список за время O(1)
    [[nodiscard]] bool IsEmpty() const noexcept {
        // Заглушка. Реализуйте метод самостоятельно
        //assert(false);
        //return false;
        return size_==0;
    }

private:
    // Фиктивный узел, используется для вставки "перед первым элементом"
    Node head_;
    size_t size_;
};

void Test0() {
    using namespace std;
    {
        const SingleLinkedList<int> empty_int_list;
        assert(empty_int_list.GetSize() == 0u);
        assert(empty_int_list.IsEmpty());
    }

    {
        const SingleLinkedList<string> empty_string_list;
        assert(empty_string_list.GetSize() == 0u);
        assert(empty_string_list.IsEmpty());
    }
}

int main() {
    Test0();
}