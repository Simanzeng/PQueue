#ifndef PQUEUE_H_INCLUDED
#define PQUEUE_H_INCLUDED
//优先级队列   用数组储存数据
#include<assert.h>
#include<iostream>
#include<cstdlib>

using namespace std;

const int DefaultPQSize=50;

template<class T>
class PQueue
{
  public:
    PQueue(int sz=DefaultPQSize);       //构造函数
    ~PQueue(){delete[] pqelement;}      //析构函数
    bool Insert(const T &x);       //将新元素x插入到队尾
    bool Remove(T &x); //将队头元素删去
    bool getFront(T &x)const;  //读取队头的值
    bool makeEmpty() {cout=0;return true;}  //置优先级队列为空
    bool IsEmpty()const {return (count==0)?true:false;}  //判断队列空否
    bool IsFull()const {return (count==maxSize)?true:false;}  //判断队列是否已满
    int getSize()const {return count;}         //求优先级队列中元素个数
  protected:
    T *pqelement;         //优先级队列数组
    int count;            // 当前元素个数
    int maxSize;          //队列最大可容纳元素个数
    void adjust();        //队列调整
};


template<class T>
PQueue<T>::PQueue(int sz):maxSize(sz),count(0)
{   //构造函数:建立一个最大具有maxSize个元素的空优先级队列。
    pqelement=new T[maxSize];  //创建队列空间
    assert(pqelement!=NULL);  //断言：动态存储分配成功与否
}


template<class T>
void PQueue<T>::adjust()
{   //将队尾元素按其优先权大小调整到适当位置，保持所有元素按优先权从小到大有序
    T temp=pqelement[count-1];
    int j;
    for(j=count-2;j>=0;j--)
    {
        if(pqelement[j]<=temp) break;   //发现有比temp更小或相等的pqelement[j]逃出循环
        else
        {
            pqelement[j+1]=pqelement[j];     //比temp大的元素pqelement[j]后移
        }
    }
    pqelement[j+1]=temp;         //插入到适当位置
}


template<class T>
bool PQueue<T>::Insert(const T &x)
{    //若优先级队列不满，则将元素x插入到该队列的队尾，否则出错处理
    if(count==maxSize) return false;      //队列满则函数返回
    pqelement[count++]=x;   //插入x到队尾
    adjust();       //按优先权进行调整
    return true;
}

template<class T>
bool PQueue<T>::Remove(T &x)
{  //若优先级队列不空则函数返回队列具有最大优先权元素的值，同时将该元素删除
    if(count==0) return false;  //若队列空，函数返回false
    x=pqelement[0];
    for(int j=0;j<count-1;j++)
    {
        pqelement[j]=pqelement[j+1];  //元素往前移
    }
    count--;  //优先级队列元素个数减一
    return true;
}

template<class T>
bool PQueue<T>::getFront(T &x)const
{    //若优先级队列不空则函数返回队列具最小优先权元素的值
    if(count==0) return false;  //热队列为空，函数返回
    x=pqelement[0];  //返回具最小优先权元素的值
    return true;
}

#endif // PQUEUE_H_INCLUDED
