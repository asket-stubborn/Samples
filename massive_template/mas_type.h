//
// Created by Andrey on 11.11.2019.
//

#ifndef UNTITLED2_MAS_TYPE_H
#define UNTITLED2_MAS_TYPE_H
#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <utility>


template <typename T>
class Array
{
public:
    // конструкторы
    Array();
    Array(const std::initializer_list<T> &);
    Array(const size_t size);
    Array(const Array &);
    // оператор присваиваний
    Array& operator =(const Array &);
    // деструктор
    ~Array();

    // итераторы начала и конца контейнера
    T* begin() const;
    T* end() const;

    // опреаторы доступа
    T& operator [](const size_t);
    const T& operator [](const size_t) const;

    // прочие методы
    size_t size() const;

protected:
    void swap(Array &, Array &);
    T* m_data;
    size_t m_size;
};

template <typename T>
Array<T>::Array() :
    m_data(nullptr),
    m_size(0)
{}

template <typename T>
Array<T>::Array(const size_t size) :
    m_data(new T[size]),
    m_size(size)
{
    // вызываем конструкторы для каждого элемента
    std::fill(m_data, m_data + m_size, T());
}

template<typename T>
Array<T>::Array(const std::initializer_list<T> &il) :
    m_data(new T[il.size()]),
    m_size(il.size())
{
    std::copy(il.begin(), il.end(), m_data);
}

template <typename T>
Array<T>::Array(const Array &arr)
{
    m_size = arr.m_size;
    if (arr.m_data)
    {
        m_data = new T[m_size];
        // копируем элементы в новый контейнер
        std::copy(arr.m_data, arr.m_data + m_size, m_data);
    }
    else
        m_data = nullptr;
}

template <typename T>
Array<T>& Array<T>::operator =(const Array &arr)
{
    // исключаем работу при присваивании самому себе
    if (this != &arr)
        delete[] *this;

    Array(arrA.size);

 // Copy-and-swap idiom
    return *this;
};

template <typename T>
Array<T>::~Array()
{
    delete[] m_data;
}

template <typename T>
T* Array<T>::begin() const
{
    return m_data;
}

template <typename T>
T* Array<T>::end() const
{
    return m_data + m_size;
}

template <typename T>
T& Array<T>::operator [](const size_t index)
{
    return m_data[index];
}

template <typename T>
const T& Array<T>::operator [](const size_t index) const
{
    return m_data[index];
}

template <typename T>
size_t Array<T>::size() const
{
    return m_size;
}

template <typename T>
void Array<T>::swap(Array &first, Array &second)
{
    std::swap(first.m_data, second.m_data);
    std::swap(first.m_size, second.m_size);
}


#endif //UNTITLED2_MAS_TYPE_H
