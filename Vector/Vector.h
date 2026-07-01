#ifndef VECTOR_
#define VECTOR_

#include <assert.h>
#include <iostream>
#include <utility>

template <typename T>
class Vector
{
public:
    Vector(int size)
    {
        if (size < 0)
        {
            size = 1;
        }
        capacity = size + 10;
        arr = new T[capacity]{}; 
        this->size = size;      
    }

    Vector(const Vector &obj)
    {
        this->size = obj.size;
        this->capacity = obj.capacity;
        this->arr = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            this->arr[i] = obj.arr[i];
        }
    }

    Vector()
    {
        capacity = 10;
        size = 0;
        arr = new T[capacity]{};
    }
    T &operator[](int index)
    {
        assert(0 <= index && index < size);
        return arr[index];
    }

    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    int Find(T value)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == value)
            {
                return i;
            }
        }
        return -1;
    }

    T Front()
    {
        assert(size > 0);
        return arr[0];
    }

    T Back()
    {
        assert(size > 0);
        return arr[size - 1];
    }

    void Push_Back(T value)
    {
        if (size == capacity)
        {
            expand_capacity();
        }

        arr[size++] = value;
    }

    void pop_back()
    {
        assert(size > 0);
        size--;
    }

    void Insert(int idx, T value)
    {
        assert(idx >= 0 && idx <= size);
        if (size == capacity)
        {
            expand_capacity();
        }
        for (int i = size; i > idx; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[idx] = value;
        size++;
    }

    int Get_Size()
    {
        return size;
    }

    T Get(int idx)
    {
        return arr[idx];
    }

    void left_rotate()
    {
        if (size <= 1)
            return;
        T temp = arr[0];
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[size - 1] = temp;
    }

    void right_rotate()
    {
        if (size <= 1)
            return;
        T temp = arr[size - 1];
        for (int i = size - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = temp;
    }

    void erase(int idx)
    {
        assert(idx >= 0 && idx < size);
        for (int i = idx; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    int find_transposition(T value)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == value)
            {
                if (i == 0)
                    return i;
                std::swap(arr[i], arr[i - 1]);
                return i - 1;
            }
        }
        return -1;
    }

    ~Vector()
    {
        delete[] arr;
    }

private:
    T *arr = nullptr;
    int size = {};
    int capacity{};
    void expand_capacity()
    {
        capacity *= 2;
        T *arr2 = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            arr2[i] = arr[i];
        }
        std::swap(arr, arr2);
        delete[] arr2;
    }
};

#endif