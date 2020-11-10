#include <iostream>
#include <cmath>
#include "List.h"

using namespace std;

int josephus(int n, int k)
{
    if (n == 1)
        return 1;
    else
        return (josephus(n - 1, k) + k-1) % n + 1;
}

int josephus3(int n){
    if (n<2) return 0;

    double n1 = double(n);

    int pos;
    double a = 0.81111111111111;
    double m,c,d;

    m = round(log(n1/a)/log(1.5));
    m = round(a*pow(1.5,m))>n1? m-1:m;

    c = round(a*pow(1.5,m));

    d = a*pow(1.5,m) - c >0? 0: 1;

    pos = int(3*(n1-c)+ d);

    return pos+1;
}

int main(void)
{
 setlocale(LC_ALL, "Russian");
 LineList<int> list;
 int n,k;
 cout<<list<<endl;
 list.insertFirst(33);
 list.insertAfter(list.getStart(),22);
 cout<<list<<endl;
 list.deleteFirst();
 cout<<list<<endl;
 list.deleteFirst();
 cout<<list<<endl;
 list.insertFirst(44);
  cout<<list<<endl;

 /*while(true){
     cout<<"Enter the number of people and k: ";
     cin>>n>>k;

     for (int i=n;i>0;i--) list.insertFirst(i);

     for (LineListElem<int>* it=list.getStart()->getNext(k-2);it->getNext() != it; it=it->getNext(k-1)) list.deleteAfter(it);

     cout<<"The last one standing is number: "<<list<<endl;
     cout<<"Check: "<<josephus(n,k)<<endl;
     cout<<"josephus3: "<<josephus3(n)<<endl;
     cout<<endl<<endl;
     list.deleteFirst();
 }*/
 return 0;
}
