#include <iostream>
using namespace std;
#include "test.h"
#include "queue.h"

void wybierz_test(Queue &A, Queue &B, Queue &C)
{
	cout<<"Podaj numer testu (1-5) lub podaj walasny wybierajac liczbe wieksza od 5 : "<<endl;
    int te=0;
    cin>>te;
    
	switch ( te )
    {
		case 1:
			test_1(A,B);
			break;
		case 2:
			test_2(A,B);
			break;
		case 3:
			test_3(A,B);
			break;
		case 4:
			test_4(A,B);
			cout<<endl<<"rozmiar A : "<<A.size()<<endl;
			cout<<A<<endl;
			A+=B;
            		cout<<endl<<"rozmiar A+=B : "<<A.size()<<endl;
            		cout<<A<<endl;
			break;
		case 5:
			test_5(A,B);
			break;
		default:
			test_6(A,B);
			break;
	}
} 

void test_1(Queue &A, Queue &B)
{	A.push1(8);
        A.push1(2);
        A.push1(3);
        A.push1(1);

        B.push1(13);
        B.push1(5);
        B.push1(9);
}

void test_2(Queue &A, Queue &B)
{	A.push1(8);
        A.push1(2);
        A.push1(7);
        A.push1(1);
        A.push1(4);
        A.push1(2);
        A.push1(3);
        A.push1(1);

        B.push1(8);
        B.push1(2);
        B.push1(7);
        B.push1(1);
        B.push1(4);
        B.push1(2);
}
void test_3(Queue &A, Queue &B)
{	A.push1(8);
        A.push1(2);
        A.push1(7);
        A.push1(1);
        A.push1(4);
        A.push1(2);
        A.push1(3);
        A.push1(1);

        A.push2(43);
        A.push2(2);
        A.push2(71);
        A.push2(0);

        B.push1(6);
}
void test_4(Queue &A, Queue &B)
{	A.push1(5);
        A.push1(2);
        A.push1(23);
        A.push1(87);
        A.push1(77);
        A.push1(2);
        A.push1(0);

        B.push1(6);
        B.push1(1);
        B.push1(9);
}
void test_5(Queue &A, Queue &B)
{	A.push1(6);
        A.push1(1);
        A.push1(9);

        B.push1(6);
        B.push1(1);
        B.push1(9);
}
void test_6(Queue &A, Queue &B)
{		
	int a, b, x;
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
}

void wynik(Queue &A, Queue &B, Queue &C)
{		
	cout<<endl<<"rozmiar A : "<<A.size()<<endl;
        cout<<A<<endl;
        cout<<endl<<"rozmiar B : "<<B.size()<<endl;
        cout<<B<<endl;

        C=A+B;
        cout<<endl<<"rozmiar A+B : "<<C.size()<<endl;
        cout<<A+B<<endl;

        cout<<endl<<"Zdjety z A: "<<A.pop()<<endl;
        cout<<"Zdjety z B: "<<B.pop()<<endl;

        if(A==B)
        {cout<<endl<<"KOLEJKI TAKIE SAME"<<endl;}
        else
        {cout<<endl<<"KOLEJKI INNE"<<endl;}
}
