#include <iostream>
#include "mas_type.h"
#include "mast_type_lipman_c.h"
template class elemType

void try_array( Array elemType &iA )

{

cout "try_array: начальные значения массива ";

cout iA endl;

elemType find_val = iA [ iA.size()-1 ];

iA[ iA.size()-1 ] = iA.min();

int mid = iA.size()/2;

iA[0] = iA.max();

iA[mid] = iA[0];

cout "try_array: после присваиваний ";

cout iA endl;

ArrayelemType iA2 = iA;

iA2[mid/2] = iA2[mid];

cout "try_array: почленная инициализация ";

cout iA endl;

iA = iA2;

cout "try_array: после почленного копирования ";

cout iA endl;

iA.grow();

cout "try_array: после вызова grow ";

cout iA endl;

int index = iA.find( find_val );

cout "искомое значение: " find_val;

cout " возвращенный индекс: " index endl;

elemType value = iA[index];

cout "значение элемента с этим индексом: ";

cout value endl;

}


nt main()
{
    Array<int> a(10), b, c(b), d = { 1, 2, 3, 4, 5 };
    std::cout << d.size() << ": ";
    for (const auto x : d)
        std::cout << x << ' ';



}