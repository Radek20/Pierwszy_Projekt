#include <iostream>
using namespace std;
#include "queue.h"

bool Queue::empty()const { return q_size==0; }
bool Queue::full() const { return q_size==Big; }
const int Queue::size() const { return q_size; }  /* funkcja zwracajaca aktualna dlugosc kolejki */

Queue::Queue(int t[], int x) /* konstruktor */
    {
        for(int i=0; i<x; i++)
            this->Q[i]=t[i];
        this->q_size=x;
    }

void Queue::push1(int e)  /* wersja z nadpisaniem wartosci */
{
    if(!full())
    {   Q[q_size]=e;
        q_size++;
    }
    else
    {   Q[q_size-1]=e; }
}

void Queue::push2(int c)  /* wersja z barakiem mozliwosci dopisania */
{
    if(!full())
    {   Q[q_size]=c;
        q_size++;
    }
    else
    {std::cout<<"Queue overflow"<<std::endl;}
}

int Queue::pop()
{
    if(!empty())
    {
        int w; /* zmienna pomocnicza reprezentujaca zdjety element */
        w=Q[0];

        for(int i=1; i<=q_size; i++)
        {
            Q[i-1]=Q[i];
        }
        q_size--;

        return w;
    }
    else
    {std::cout<<"Queue underflow"<<std::endl;}
}

Queue Queue::operator+(const Queue &q) const
{
    int tab[Big];
    int roz; /* rozmiar powstalej kolejki */

    for(int i=0; i<this->q_size; i++)
        tab[i]=this->Q[i];

    for(int i=0; i<q.q_size; i++)
        if((this->q_size+i)<Big)
            tab[this->q_size+i]=q.Q[i];

        if((this->q_size+q.q_size)<=Big)
            roz=this->q_size+q.q_size;
        else
            roz=Big;

    return Queue(tab,roz);
}

Queue Queue::operator+=(const Queue &q)
{
    for(int i=0; i<q.q_size; i++)
        if((this->q_size+i)<Big)
            this->Q[this->q_size+i]=q.Q[i];

    if((this->q_size+q.q_size)<=Big)
            this->q_size+=q.q_size;
        else
            this->q_size=Big;

    return * this;
}

bool Queue::operator==(const Queue &q)const
{
    if(this->q_size==q.q_size)
    {
        int pom=0, i=0; /* zmienne pomocnicze, pom zlicza ilosc roznych elementow kolejek */ 

        while(pom==0 && i<q.q_size)
        {
            if(this->Q[i]!=q.Q[i])
                pom++;
                i++;
        }
        if(pom==0)
            return true;
        else
            return false;
    }
    else
           return false;
}

bool Queue::operator!=(const Queue &q)const
{
    if(this->q_size==q.q_size)
    {
        int pom=0, i=0; /* zmienne pomocnicze, pom zlicza ilosc roznych elementow kolejek */

        while(pom==0 && i<q.q_size)
        {
            if(this->Q[i]!=q.Q[i])
                pom++;
                i++;
        }
        if(pom==0)
            return false;
        else
            return true;
    }
    else
           return true;
}

std::ostream& operator<<(std::ostream &os,const Queue& q)
{
   for(int i=0; i<q.q_size; i++)
   {
       os<<q.Q[i]<<' ';
   }
   return os;
}
