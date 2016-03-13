#ifndef PQUEUE_H_INCLUDED
#define PQUEUE_H_INCLUDED
//���ȼ�����   �����鴢������
#include<assert.h>
#include<iostream>
#include<cstdlib>

using namespace std;

const int DefaultPQSize=50;

template<class T>
class PQueue
{
  public:
    PQueue(int sz=DefaultPQSize);       //���캯��
    ~PQueue(){delete[] pqelement;}      //��������
    bool Insert(const T &x);       //����Ԫ��x���뵽��β
    bool Remove(T &x); //����ͷԪ��ɾȥ
    bool getFront(T &x)const;  //��ȡ��ͷ��ֵ
    bool makeEmpty() {cout=0;return true;}  //�����ȼ�����Ϊ��
    bool IsEmpty()const {return (count==0)?true:false;}  //�ж϶��пշ�
    bool IsFull()const {return (count==maxSize)?true:false;}  //�ж϶����Ƿ�����
    int getSize()const {return count;}         //�����ȼ�������Ԫ�ظ���
  protected:
    T *pqelement;         //���ȼ���������
    int count;            // ��ǰԪ�ظ���
    int maxSize;          //������������Ԫ�ظ���
    void adjust();        //���е���
};


template<class T>
PQueue<T>::PQueue(int sz):maxSize(sz),count(0)
{   //���캯��:����һ��������maxSize��Ԫ�صĿ����ȼ����С�
    pqelement=new T[maxSize];  //�������пռ�
    assert(pqelement!=NULL);  //���ԣ���̬�洢����ɹ����
}


template<class T>
void PQueue<T>::adjust()
{   //����βԪ�ذ�������Ȩ��С�������ʵ�λ�ã���������Ԫ�ذ�����Ȩ��С��������
    T temp=pqelement[count-1];
    int j;
    for(j=count-2;j>=0;j--)
    {
        if(pqelement[j]<=temp) break;   //�����б�temp��С����ȵ�pqelement[j]�ӳ�ѭ��
        else
        {
            pqelement[j+1]=pqelement[j];     //��temp���Ԫ��pqelement[j]����
        }
    }
    pqelement[j+1]=temp;         //���뵽�ʵ�λ��
}


template<class T>
bool PQueue<T>::Insert(const T &x)
{    //�����ȼ����в�������Ԫ��x���뵽�ö��еĶ�β�����������
    if(count==maxSize) return false;      //��������������
    pqelement[count++]=x;   //����x����β
    adjust();       //������Ȩ���е���
    return true;
}

template<class T>
bool PQueue<T>::Remove(T &x)
{  //�����ȼ����в����������ض��о����������ȨԪ�ص�ֵ��ͬʱ����Ԫ��ɾ��
    if(count==0) return false;  //�����пգ���������false
    x=pqelement[0];
    for(int j=0;j<count-1;j++)
    {
        pqelement[j]=pqelement[j+1];  //Ԫ����ǰ��
    }
    count--;  //���ȼ�����Ԫ�ظ�����һ
    return true;
}

template<class T>
bool PQueue<T>::getFront(T &x)const
{    //�����ȼ����в����������ض��о���С����ȨԪ�ص�ֵ
    if(count==0) return false;  //�ȶ���Ϊ�գ���������
    x=pqelement[0];  //���ؾ���С����ȨԪ�ص�ֵ
    return true;
}

#endif // PQUEUE_H_INCLUDED
