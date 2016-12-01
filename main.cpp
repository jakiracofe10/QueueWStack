#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class Queue {
public:
    Queue<T>() : size(0) {}

    void enQueue(T object) {
        size++;
        if (stack2.empty()) {
            stack2.push(object);
        } else {
            while (!stack2.empty()) {
                stack1.push(stack2.top());
                stack2.pop();
            }
            stack2.push(object);
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
    }

    //throw exception?
    T deQueue() {
        if (size > 0) {
            size--;
            T object = stack2.top();
            stack2.pop();
            return object;
        }
    }

    int getSize() {
        return size;
    }

private:
    stack<T> stack1;
    stack<T> stack2;
    int size;
};

int main()
{
    /* Create a queue with items 1 2 3*/
    Queue<int> q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    q.deQueue();
    q.deQueue();

    q.enQueue(100);
    q.enQueue(300);


    while (q.getSize() != 0) {
        cout << q.deQueue() << " ";
    }
}