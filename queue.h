#ifndef queue_h
#define queue_h

using namespace std;

const unsigned int Big=10; /* stala odpowiadajaca za maksymalna dlugosc kolejki */

class Queue
{   int Q[Big];     /* tablica w ktorej przechowywane sa elementy kolejki */
    int q_size;     /* zmienna przechowujaca aktualna dlugosc kolejki */
public:
    Queue() {q_size=0;} /* Konstruktor 2 wymiarowy*/
    Queue(int t[], int x);

    void push1(int e);  /* wersja z nadpisaniem wartosci */
    void push2(int c);  /* wersja z barakiem mozliwosci dopisania */
    int pop();
    bool empty()const;
    bool full() const;
    const int size() const; /* funkcja zwracajaca aktualna dlugosc kolejki */

    Queue operator+(const Queue &q) const;
    Queue operator+=(const Queue &q);
    bool operator==(const Queue &q) const;
    bool operator!=(const Queue &q) const;

    friend
    std::ostream& operator<< (std::ostream &os,const Queue& q);

};

#endif
