#include <iostream>
using namespace std;

#define DEFAULT_SIZE 10

template <class Elem>
class SqStack
{
private:
    int count;
    int maxSize;
    Elem *elems;

public:
    SqStack(int size = DEFAULT_SIZE);                    //构造函数
    virtual ~SqStack();                                  //析构函数
    int Length() const;                                  //计算栈的长度
    bool Empty() const;                                  //判断栈是否为空
    void Clear();                                        //清空栈
    void Traverse() const;                               //遍历顺序栈
    bool Push(const Elem &e);                            //入栈
    bool Top(Elem &e) const;                             //取栈顶元素
    bool Pop(Elem &e);                                   //出栈
    SqStack(const SqStack<Elem> &copy);                  //复制构造函数
    SqStack<Elem> &operator=(const SqStack<Elem> &copy); //重载
};

template <class Elem>
SqStack<Elem>::SqStack(int size)
{
    maxSize = size;
    count = 0;
    elems = new Elem[maxSize];
}

template <class Elem>
SqStack<Elem>::~SqStack()
{
    delete[] elems;
}

template <class Elem>
int SqStack<Elem>::Length() const
{
    return count;
}

template <class Elem>
bool SqStack<Elem>::Empty() const
{
    return count == 0;
}

template <class Elem>
void SqStack<Elem>::Clear()
{
    count = 0;
}

template <class Elem>
void SqStack<Elem>::Traverse() const
{
    if (Empty())
    {
        cout << "No elems!" << endl;
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            cout << elems[i] << endl;
        }
    }
}
template <class Elem>
bool SqStack<Elem>::Push(const Elem &e)
{
    if (count == maxSize)
    {
        return false; //栈已满，无法继续插入
    }
    else //栈未满，可以继续插入元素
    {
        elems[count++] = e;
        return true;
    }
}

template <class Elem>
bool SqStack<Elem>::Top(Elem &e) const
{
    if (Empty())
    {
        return false; //栈处于空状态，无元素，无法取栈顶
    }
    else
    {
        e = elems[count - 1]; //取出在count计数之前的数据，就是栈顶
        return true;
    }
}

template <class Elem>
bool SqStack<Elem>::Pop(Elem &e)
{
    if (Empty()) //如果栈空，无元素可以出栈
    {
        return false;
    }
    else
    {
        e = elems[count - 1];
        count--;
        return true;
    }
}

template <class Elem>
SqStack<Elem>::SqStack(const SqStack<Elem> &copy) //复制构造函数
{
    //复制原栈的各种属性
    maxSize = copy.maxSize;
    count = copy.count;
    elems = new Elem[maxSize];
    for (int i = 0; i < count; i++) //从栈底到栈顶，复制元素
    {
        elems[i] = copy.elems[i];
    }
}

template <class Elem>
SqStack<Elem> &SqStack<Elem>::operator=(const SqStack<Elem> &copy) //重载 = 符号函数
{
    if (&copy != this)
    {
        maxSize = copy.maxSize;
        count = copy.count;
        delete[] elems;
        elems = new Elem[maxSize];
        for (int i = 0; i < count; i++)
        {
            elems[i] = copy.elems[i];
        }
    }
    return *this;
}

int main()
{
    //A test case.
    SqStack<int> S1;
    int a = 0;
    cout << "a = " << a << endl;
    S1.Push(1);
    S1.Traverse();
    S1.Pop(a);
    S1.Traverse();
    cout << "a = " << a << endl;
    return 0;
}
