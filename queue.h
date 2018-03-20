#ifndef queue_h
#define queue_h

using namespace std;

class Queue
{   enum {R= 10};
    int Q[R], s;
public:
    Queue() {s=0;} /* Konstruktor 2 wymiarowy*/
    Queue(int t[], int x);
    
    void push1(int e);  /* wersja z nadpisaniem wartosci */
    void push2(int c);  /* wersja z barakiem mozliwosci dopisania */
    int pop();
    int empty()const;
    int full() const;
    int size() const;

    Queue operator+(const Queue &q) const;
    Queue operator+=(const Queue &q);
    bool operator==(const Queue &q) const;
    bool operator!=(const Queue &q) const;

    friend
    std::ostream& operator<< (std::ostream &os,const Queue& q);

};

#endif
