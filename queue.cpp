#include <iostream>
using namespace std;
#include "queue.h"

int Queue::empty()const { return s==0; }
int Queue::full() const { return s==R; }
int Queue::size() const { return s; }

Queue::Queue(int t[], int x)
    {
        for(int i=0; i<x; i++)
            this->Q[i]=t[i];
        this->s=x;
    }

void Queue::push1(int e)
{
    if(!full())
    {   Q[s]=e;
        s++;
    }
    else
    {   Q[s-1]=e; }
}

void Queue::push2(int c)
{
    if(!full())
    {   Q[s]=c;
        s++;
    }
    else
    {std::cout<<"Queue overflow"<<std::endl;}
}

int Queue::pop()
{
    if(!empty())
    {
        int w;
        w=Q[0];

        for(int i=1; i<=s; i++)
        {
            Q[i-1]=Q[i];
        }
        s--;

        return w;
    }
    else
    {std::cout<<"Queue underflow"<<std::endl;}
}

Queue Queue::operator+(const Queue &q) const
{
    int tab[q.R];
    int ro;

    for(int i=0; i<this->s; i++)
        tab[i]=this->Q[i];

    for(int i=0; i<q.s; i++)
        if((this->s+i)<q.R)
            tab[this->s+i]=q.Q[i];

        if((this->s+q.s)<=q.R)
            ro=this->s+q.s;
        else
            ro=q.R;

    return Queue(tab,ro);
}

Queue Queue::operator+=(const Queue &q)
{
    for(int i=0; i<q.s; i++)
        if((this->s+i)<q.R)
            this->Q[this->s+i]=q.Q[i];

    if((this->s+q.s)<=q.R)
            this->s+=q.s;
        else
            this->s=q.R;

    return * this;
}

bool Queue::operator==(const Queue &q)const
{
    if(this->s==q.s)
    {
        int pom=0, i=0;

        while(pom==0 && i<q.s)
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
    if(this->s==q.s)
    {
        int pom=0, i=0;

        while(pom==0 && i<q.s)
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
   for(int i=0; i<q.s; i++)
   {
       os<<q.Q[i]<<' ';
   }
   return os;
}
