#ifndef DAQUEUE_H
#define DAQUEUE_H

#include <iostream>

template <typename T>
class queue {
    private:
        T* line;
        int front;
        int back;
        int size;
    public:
        queue(int s);
        bool isEmpty();
        bool isFull();
        void enqueue(T v);
        void dequeue();
        void getFront();
        void display();
        void displayRec(int index = 0);
        int getSize();
        ~queue();
};

template <typename T>
queue<T>::queue(int s) {
    size = s;
    front = -1;
    back = -1;
    line = new T[size];
}

template <typename T>
bool queue<T>::isEmpty() {
    return front == -1;
}

template <typename T>
bool queue<T>::isFull() {
    return back == size-1;
}

template <typename T>
void queue<T>::enqueue(T v) {
    if(isEmpty()) {
        front++;
        back++;
        line[front] = v;
    } else if(isFull()) {
        std::cout << "Queue is full" << std::endl;
    } else {
        back++;
        line[back] = v;
    }
}

template <typename T>
void queue<T>::dequeue() {
    if(isEmpty()) {
        std::cout << "Empty Queue" << std::endl;
    } else {
        T temp = line[front];
        front+=1;
    }
}

template <typename T>
void queue<T>::getFront() {
    if(isEmpty() || front == size) {
        std::cout << "Empty Queue" << std::endl;
    } else {
        std::cout << "Front: " << line[front] << std::endl;
    }
}

template <typename T>
void queue<T>::display() {
    if(isEmpty() || front == size) {
        std::cout << "Empty Queue" << std::endl;
    } else {
        for(int i = front; i <= back; i++) {
            std::cout << line[i] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
void queue<T>::displayRec(int start) {
    start+=front;
    if(isEmpty()) {
        std::cout << "Empty List" << std::endl;
        return;
    } 
    if(start >= size) {
        std::cout << std::endl;
        return;
    }
    std::cout << line[start] << " ";
    start-= front;
    displayRec(start+1);
}

template <typename T>
int queue<T>::getSize() {
    return size;
}

template <typename T>
queue<T>::~queue() {
    std::cout << "Destructor Called" << std::endl;
    delete [] line;
}

#endif // !DAQUEUE_H