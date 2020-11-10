#pragma once
#ifndef _LIST_H
#define _LIST_H

using namespace std;

class LineListException{};

template <class T> class LineListElem
{
private:
 T data;
 LineListElem* next;
public:
 LineListElem(const T& adata, LineListElem* anext);
 const T& getData() const;
 LineListElem* getNext(int n=1);
 template <class T1> friend class LineList;
};

template <class T> class LineList {
private:
 LineListElem<T>* start;// Начало списка
 LineListElem<T>* finish;
 LineList(const LineList& list);
 LineList& operator =(const LineList& list);
public:
 LineList();
 ~LineList();
 LineListElem<T>* getStart();
 T operator [](int index);
 void deleteFirst();
 void deleteAfter(LineListElem<T>* ptr);
 void insertFirst(const T& data);
 void insertAfter(LineListElem<T>* ptr, const T& data);
 template <class T1> friend ostream& operator <<(ostream& out, LineList<T1>& list);
};

template <class T> T LineList<T>::operator [](int index)
{
    if (index < 0) throw LineListException();
    int counter = 0;
    for (LineListElem<int>* it=this->getStart();it; it=it->getNext()){
        if (counter==index) return it->getData();
        counter++;
    }
    throw LineListException();
}

template <class T> LineListElem<T>::LineListElem(const T& adata, LineListElem<T>* anext)
{
     data = adata;
     next = anext;
}

template <class T> LineListElem<T>* LineListElem<T>::getNext(int n)
{
    LineListElem* nextEl;

    if(n==0) {
            nextEl = this;
    } else if(n>0) {
            nextEl = next;
    } else throw LineListException();

    n--;
    while (n>0){
            nextEl = nextEl->getNext();
            n--;
    }
    return nextEl;
}

template <class T> const T& LineListElem<T>::getData() const
{
    return data;
}

template <class T> LineListElem<T>* LineList<T>::getStart()
{
    return start;
}

template <class T> void LineList<T>::deleteFirst()
{
 if (start)
 {
     LineListElem<T>* last;
     LineListElem<T>* temp = start->next;
     if(temp == start) {
        delete start;
        start = 0;
     } else{
     for (LineListElem<int>* it=start;it; it=it->getNext()){
            last=it;
            if (last->next==start){
                last->next = temp;
                break;
            }
        }
       start = temp;
       delete start;
     }
 } else throw LineListException();
}

template <class T> LineList<T>::LineList()
{
    start = 0;
}

template <class T> LineList<T>::~LineList()
{
    while (start) deleteFirst();
}

template <class T> void LineList<T>::insertFirst(const T& data)
{
     LineListElem<T>* last;
     LineListElem<T>* second = start;
     if(second){
        start = new LineListElem<T>(data, second);
     } else {
         start = new LineListElem<T>(data, start);
         start->next = start;
     }

     for (LineListElem<int>* it=second;it; it=it->getNext()){
            last=it;
            if (last->next==second){
                last->next = start;
                break;
            }
        }
}

template <class T> void LineList<T>::deleteAfter(LineListElem<T>* ptr) {
     if (ptr && ptr->next) {
         if (ptr->next == start){
            if (ptr == start){
                    delete start;
                    start = 0;
            } else start = ptr->next->next;
         }
         LineListElem<T>* temp = ptr->next;
         ptr->next = ptr->next->next;
         delete temp;
     } else throw LineListException();
    }

template <class T> void LineList<T>::insertAfter(LineListElem<T>* ptr, const T& data) {
     if(!ptr->next){
         LineListElem<T>* temp = this->getStart();
         ptr->next = new LineListElem<T>(data, temp);
     }
     else if (ptr) {
         LineListElem<T>* temp = ptr->next;
         ptr->next = new LineListElem<T>(data, temp);
     }
}

template <class T> ostream& operator << (ostream& out, LineList<T>& list)
{
     LineListElem<T>* ptr = list.start;
     if (!ptr) out<<"EMPTY ";
     else while (ptr)
     {
         out<<ptr->getData()<<' ';
         ptr = ptr->getNext();
         if (ptr == list.start) break;
     }
     return out;
}


#endif
