#include <iostream>
using namespace std;
#include "test.h"
#include "queue.h"

void test()
{
    if(test_1())
        cout<<"test_1: PASS"<<endl;
    else
        cout<<"test_1: FAIL"<<endl;

    if(test_2())
        cout<<"test_2: PASS"<<endl;
    else
        cout<<"test_2: FAIL"<<endl;

    if(test_3())
        cout<<"test_3: PASS"<<endl;
    else
        cout<<"test_3: FAIL"<<endl;

    if(test_4())
        cout<<"test_4: PASS"<<endl;
    else
        cout<<"test_4: FAIL"<<endl;

    if(test_5())
        cout<<"test_5: PASS"<<endl;
    else
        cout<<"test_5: FAIL"<<endl;

    if(test_6())
        cout<<"test_6: PASS"<<endl;
    else
        cout<<"test_6: FAIL"<<endl;

    cout<<endl<<"PRZYKLAD:"<<endl;
    example();
}

bool test_1()
{
    Queue A;  /* testowa kolejka */
    Queue Wynik; /* kolejka z poprawnym wynikiem */
    int element_1=3, element_2=4;
    int n=2; /* ilosc dodawanych elementow */

    Wynik.push1(element_1);
    Wynik.push1(element_2);

    A.push1(element_1);

    if(A.pop()!=element_1)
        return false;

    A.push1(element_1);
    A.push1(element_2);

    if(A.pop()!=element_1)
        return false;

    A.push1(element_1);

    if(A.pop()!=element_2)
        return false;

    A.push1(element_2);

    if(A.size()!=n)
        return false;

    if(A==Wynik)
        return true;
    else
        return false;
}

bool test_2()
{
    Queue A; /* testowa kolejka */
    int element_1=3, element_2=4;
    int n=2; /* ilosc dodawanych elementow */

    A.push2(element_1);

    if(A.pop()!=element_1)
        return false;

    A.push2(element_1);
    A.push2(element_2);

    if(A.pop()!=element_1)
        return false;

    A.push2(element_2);

    if(A.pop()==element_1)
        return false;

    A.push2(element_2);

    if(A.size()==n)
        return true;
    else
        return false;

}

bool test_3()
{

    Queue A,B,C; /* testowe kolejki */
    Queue Suma;	 /* kolejka bedaca poprawnym wynikiem */

    A.push1(2);
    A.push1(8);
    A.push1(4);

    B.push1(0);
    B.push1(3);
    B.push1(5);
    B.push1(1);

    Suma.push1(2);
    Suma.push1(8);
    Suma.push1(4);
    Suma.push1(0);
    Suma.push1(3);
    Suma.push1(5);
    Suma.push1(1);

    C=A+B;

    if(C!=Suma)
    	return false;

    A+=B;

    if(A==Suma)
        return true;
    else
        return false;
}

bool test_4()
{
    Queue A; /* testowa kolejka */

    if(!A.empty())
        return false;

    A.push1(1);

    if(A.empty())
        return false;

    for( int i=2; i<=10; i++)
        A.push1(i);

    if(A.full())
        return true;
    else
        return false;
}

bool test_5()
{
   Queue A, B, C, D; /* testowe kolejki */

   A.push2(5);
   A.push2(1);
   A.push2(8);

   B.push2(5);
   B.push2(1);
   B.push2(8);
   B.push2(8);

   C.push2(8);
   C.push2(1);
   C.push2(5);

   D.push2(5);
   D.push2(1);
   D.push2(8);

   if(A==B)
	return false;

   if(A==C)
	return false;

   if(A!=D)
	return false;
   else
	return true;

}

bool test_6()
{
   Queue A; /* testowa kolejka */
   int element_1=3, element_2=0, element_3=9, element_4=5, element_5=13, element_6=1;

   A.push1(element_1);
   A.push2(element_2);
   A.push1(element_3);
   A.push2(element_4);
   A.push1(element_5);
   A.push2(element_6);

   if(A.pop()!=element_1)
	return false;
   if(A.pop()!=element_2)
	return false;
   if(A.pop()!=element_3)
	return false;
   if(A.pop()!=element_4)
	return false;
   if(A.pop()!=element_5)
	return false;
   if(A.pop()!=element_6)
	return false;

   if(A.empty())
	return true;
   else
	return false;
}

void example()
{
        Queue A,B,C;  /* testowe kolejki */
        int a, b, x;  /* dlugosc kolejek A i B oraz pomocnicza zmienna do wczytania */

        cout<<"podaj dlugosc kolejki A"<<endl;
        cin>>a;
        cout<<"podaj elementy kolejki A"<<endl;

        for(int i=1; i<=a; i++)
        {
            cin>>x;
            A.push2(x);
        }

        cout<<"podaj dlugosc kolejki B"<<endl;
        cin>>b;
        cout<<"podaj elementy kolejki B"<<endl;

        for(int i=1; i<=b; i++)
        {
            cin>>x;
            B.push2(x);
        }

        cout<<endl<<"rozmiar A : "<<A.size()<<endl;
        cout<<A<<endl;
        cout<<endl<<"rozmiar B : "<<B.size()<<endl;
        cout<<B<<endl;

        C=A+B;
        cout<<endl<<"rozmiar A+B : "<<C.size()<<endl;
        cout<<A+B<<endl;

        if(!A.empty())
        cout<<endl<<"Zdjety z A: "<<A.pop()<<endl;
        if(!B.empty())
        cout<<"Zdjety z B: "<<B.pop()<<endl;

        if(A==B)
        {cout<<endl<<"KOLEJKI TAKIE SAME"<<endl;}
        else
        {cout<<endl<<"KOLEJKI INNE"<<endl;}
}

