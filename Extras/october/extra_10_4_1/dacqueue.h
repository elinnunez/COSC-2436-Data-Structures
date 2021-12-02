#ifndef DACQUEUE_H
#define DACQUEUE_H

#include <iostream>
#include <fstream>
#include <string>

class DACQueue
{
private:
    int *line;
    int size;
    int front;
    int rear;
    int qSize;

public:
    DACQueue(int input);
    bool isEmpty();
    bool isFull();
    void enqueue(int input);
    void dequeue();
    void recPrintQueue(int index = 0);
    void printQueue();
    int getFront();
    int getSize();
    int getQSize();
    ~DACQueue();
};

DACQueue::DACQueue(int input)
{
    size = input;
    front = rear = -1;
    qSize = 0;
    line = new int[size];
}

int DACQueue::getFront()
{
    if (isEmpty())
    {
        std::cout << "No front to get" << std::endl;
        return -1;
    }
    else
    {
        // std::cout << "Cur Front at Index " << front << ": " << line[front] << std::endl;
        return line[front];
    }
}

bool DACQueue::isEmpty()
{
    return front == -1;
}

bool DACQueue::isFull()
{
    return (rear + 1) % size == front;
}

void DACQueue::enqueue(int input)
{
    if (isFull())
    {
        std::cout << "Full Queue" << std::endl;
        return;
    }
    else
    {
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        line[rear] = input;
        // std::cout << "REAR: " << rear << std::endl;
        // std::cout << "Index " << rear << ": " << line[rear] << std::endl;
        qSize++;
    }
}

void DACQueue::dequeue()
{
    if (isEmpty())
    {
        std::cout << "Can't dequeue empty list" << std::endl;
        return;
    }
    else
    {
        int temp = line[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
        // std::cout << "Dequeued: " << temp << std::endl;
        qSize--;
        return;
    }
}

void DACQueue::recPrintQueue(int index)
{
    index += front;
    if (isEmpty())
    {
        std::cout << "Can't print empty queue" << std::endl;
        return;
    }
    else if (index == rear)
    {
        std::cout << line[index] << std::endl;
        return;
    }
    else
    {
        std::cout << line[index] << std::endl;
        index -= front;
        recPrintQueue((index + 1) % size);
    }
}

void DACQueue::printQueue()
{
    if (isEmpty())
    {
        std::cout << "Empty Queue! Can't Print" << std::endl;
    }
    else
    {
        int index = front;

        do
        {
            std::cout << "Index " << index << ": " << line[index] << std::endl;
            index = (index + 1) % size;

        } while (index != (rear + 1) % size);
    }
}

int DACQueue::getSize()
{
    return size;
}

int DACQueue::getQSize()
{
    return qSize;
}

DACQueue::~DACQueue()
{
    delete[] line;
}
#endif // !DACQUEUE_H
