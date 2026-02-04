#include <iostream>
using namespace std;

template <typename T>
class Stack
{
    enum { EMPTY = -1, FULL = 9 };
    T arr[FULL + 1];
    int topIndex;

public:
    Stack() : topIndex(EMPTY) {}

    bool IsFull() const
    {
        return topIndex == FULL;
    }

    bool IsEmpty() const
    {
        return topIndex == EMPTY;
    }

    bool Push(const T& elem)
    {
        if (!IsFull())
        {
            arr[++topIndex] = elem;
            return true;
        }
        return false;
    }

    T Pop()
    {
        if (!IsEmpty())
        {
            return arr[topIndex--];
        }
        throw runtime_error("Stack is empty");
    }

    T Peek() const
    {
        if (!IsEmpty())
        {
            return arr[topIndex];
        }
        throw runtime_error("Stack is empty");
    }

    int GetCount() const
    {
        return topIndex + 1;
    }

    void Clear()
    {
        topIndex = EMPTY;
    }

    void Print() const
    {
        for (int i = 0; i <= topIndex; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main()
{
    Stack<int> st;
    st.Push(1);
    st.Push(2);
    st.Push(3);
    st.Push(4);
    st.Print();
    cout << "Last element : " << st.Peek() << endl;

    while (!st.IsEmpty())
    {
        cout << "Element : " << st.Pop() << endl;
    }
    cout << "Size : " << st.GetCount() << endl;

}
