#include <iostream>
#include <initializer_list>
using namespace std;

template <typename T>
class Array
{
    T* arr;
    int size;

public:
    Array() : arr(nullptr), size(0) {}

    Array(int size)
    {
        this->size = size;
        arr = new T[size]{};
    }

    Array(const initializer_list<T>& list)
    {
        size = list.size();
        arr = new T[size];
        int i = 0;
        for (const T& element : list)
        {
            arr[i++] = element;
        }
    }

    void FillArray(const initializer_list<T>& list)
    {
        delete[] arr;
        size = list.size();
        arr = new T[size];

        int i = 0;
        for (const T& element : list)
        {
            arr[i++] = element;
        }
    }

    void Print() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    T* GetData() const { return arr; }
    int GetSize() const { return size; }

    ~Array()
    {
        delete[] arr;
    }
};

template <typename T>
T FindMax(T* arr, int size)
{
    T max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}


template <typename T>
T FindMin(T* arr, int size)
{
    T min = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] < min)
            min = arr[i];
    return min;
}


template <typename T>
void Sort(T* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}


template <typename T>
int Search(T* arr, int size, T key)
{
    int left = 0, right = size - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

template <typename T>
void RepVal(T* arr, int size, T oldValue, T newValue)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == oldValue)
            arr[i] = newValue;
    }
}

int main()
{
    Array<int> arr = { 5, 2, 9, 1, 7 };
    arr.Print();

    cout << "Max : " << FindMax(arr.GetData(), arr.GetSize()) << endl;
    cout << "Min : " << FindMin(arr.GetData(), arr.GetSize()) << endl;

    Sort(arr.GetData(), arr.GetSize());
    arr.Print();

    int index = Search(arr.GetData(), arr.GetSize(), 7);
    cout << "Index of 7 : " << index << endl;

    RepVal(arr.GetData(), arr.GetSize(), 7, 100);
    arr.Print();
}

