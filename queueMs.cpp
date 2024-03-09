 #include <iostream>
using namespace std;
#include <queue>
#include <stack>
class Deque {
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int size;

public:
    Deque(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        front = -1;
        rear = 0;
        size = 0;
    }

    void enqueue_rear(int value) {
        if ((front == 0 && rear == capacity - 1) || (rear + 1 == front)) {
            cout << "Deque is full" << endl;
            return;
        }

        if (front == -1)  
            front = 0;

        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    void enqueue_front(int value) {
        if ((front == 0 && rear == capacity - 1) || (rear + 1 == front)) {
            cout << "Deque is full" << endl;
            return;
        }

        if (front == -1)  
            front = rear = 0;
        else if (front == 0)
            front = capacity - 1;
        else
            front = (front - 1) % capacity;

        arr[front] = value;
        size++;
    }

    int dequeue_front() {
        if (front == -1) {
            cout << "Deque is empty" << endl;
            return INT_MIN; 
        }

        int value = arr[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % capacity;
        size--;
        return value;
    }

    int dequeue_rear() {
        if (front == -1) {
            cout << "Deque is empty" << endl;
            return INT_MIN; 
        }

        int value = arr[rear];
        if (front == rear)
            front = rear = -1;
        else if (rear == 0)
            rear = capacity - 1;
        else
            rear = (rear - 1) % capacity;
        size--;
        return value;
    }

    void display() {
        if (front == -1) {
            cout << "Deque is empty" << endl;
            return;
        }

        cout << "Elements in deque: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};
class Stack {
private:
    queue<int> q;

public:
    void push(int value) {
        q.push(value);
        int size = q.size();
         for (int i = 0; i < size - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (q.empty()) {
            cout << "Stack is empty" << endl;
            return INT_MIN;  
        }
        int top = q.front();
        q.pop();
        return top;
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty" << endl;
            return INT_MIN;  
        }
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};
class Queue {
private:
    stack<int> enqueueStack;
    stack<int> dequeueStack;

    void transferElements() {
        while (!enqueueStack.empty()) {
            dequeueStack.push(enqueueStack.top());
            enqueueStack.pop();
        }
    }

public:
    void enqueue(int value) {
        enqueueStack.push(value);
    }

    int dequeue() {
        if (dequeueStack.empty()) {
            if (enqueueStack.empty()) {
                cout << "Queue is empty" << endl;
                return INT_MIN;  
            }
            transferElements();
        }
        int front = dequeueStack.top();
        dequeueStack.pop();
        return front;
    }

    int front() {
        if (dequeueStack.empty()) {
            if (enqueueStack.empty()) {
                cout << "Queue is empty" << endl;
                return INT_MIN;  
            }
            transferElements();
        }
        return dequeueStack.top();
    }

    bool empty() {
        return enqueueStack.empty() && dequeueStack.empty();
    }
};


int main() {
    Deque dq(5);

    dq.enqueue_rear(1);
    dq.enqueue_rear(2);
    dq.enqueue_front(3);
    dq.enqueue_front(4);

    dq.display(); 

    cout << dq.dequeue_front() << endl;  
    cout << dq.dequeue_rear() << endl;  

    dq.display(); 

    return 0;
}
