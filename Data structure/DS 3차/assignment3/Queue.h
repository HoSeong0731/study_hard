#ifndef QUEUE_H
#define QUEUE_H

#ifndef NULL
#define NULL    0
#endif

template<class T> class Queue {
public:
    int front;
    int rear;
    int size; //Free to define (recommand 100 or 200)
    T *val;

    //Needs extra init
    Queue(int size)::val(new T[size]), size(size), front(0), rear(0);
    ~Queue() delete[] val;

    // input data
    void push(T value) {
        if (rear == size) return;
        val[rear] = value;
        rear++;
    }

    //Change Front
    void pop() {

    }

    //Check its empty or not
    bool empty() return !rear;
    bool isFull() return rear+1 == size;
};


#endif
