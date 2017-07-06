//
//  main.cpp
//  sorting-tarea-7
//
//  Created by Sebastian Coronado on 5/07/17.
//  Copyright © 2017 Sebastian Coronado. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>

template <typename T>
struct cmpLess { inline bool operator()(const T &t1, const T &t2) const { return (t1 < t2); } };

template <typename T>
struct cmpGreater { inline bool operator()(const T &t1, const T &t2) const { return (t2 < t1); } };


template <typename RandomAccessIterator>
inline void InsertSort(RandomAccessIterator start, RandomAccessIterator end) {
    cmpLess < typename RandomAccessIterator::value_type > lessThan;
    InsertSort(start, end, lessThan);
}

template <typename RandomAccessIterator>
inline void SelectSort(RandomAccessIterator start, RandomAccessIterator end) {
    cmpLess < typename RandomAccessIterator::value_type > lessThan;
    SelectSort(start, end, lessThan);
}

template <typename RandomAccessIterator>
inline void StableSelectSort(RandomAccessIterator start, RandomAccessIterator end) {
    cmpLess < typename RandomAccessIterator::value_type > lessThan;
    StableSelectSort(start, end, lessThan);
}

template <typename RandomAccessIterator>
inline void HeapSort(RandomAccessIterator start, RandomAccessIterator end) {
    cmpLess < typename RandomAccessIterator::value_type > lessThan;
    HeapSort(start, end, lessThan);
}

template <typename RandomAccessIterator>
inline void MergeSort(RandomAccessIterator start, RandomAccessIterator end) {
    cmpLess < typename RandomAccessIterator::value_type > lessThan;
    MergeSort(start, end, lessThan);
}

template <typename RandomAccessIterator>
inline void IterativeMergeSort(RandomAccessIterator start, RandomAccessIterator end) {
    cmpLess < typename RandomAccessIterator::value_type > lessThan;
    IterativeMergeSort(start, end, lessThan);
}

template <typename RandomAccessIterator>
inline void LomutoQuickSort(RandomAccessIterator start, RandomAccessIterator end) {
    cmpLess < typename RandomAccessIterator::value_type > lessThan;
    LomutoQuickSort(start, end, lessThan);
}

template <typename RandomAccessIterator>
inline void HoareQuickSort(RandomAccessIterator start, RandomAccessIterator end) {
    cmpLess < typename RandomAccessIterator::value_type > lessThan;
    HoareQuickSort(start, end, lessThan);
}

template <typename RandomAccessIterator>
inline void YaroslavskiyQuickSort(RandomAccessIterator start, RandomAccessIterator end) {
    cmpLess < typename RandomAccessIterator::value_type > lessThan;
    YaroslavskiyQuickSort(start, end, lessThan);
}


template <typename RandomAccessIterator, typename LessThan>
inline void InsertSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan)
{
    RandomAccessIterator __j = start+2;
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;
    for (RandomAccessIterator __i = __j+1; __i != end; ++__i)
    {
        if (LessThan()(*__i, *__j))
        {
            
            RandomAccessIterator __k = __j;
            value_type __t(std::move(*__i));
            __j = __i;
            do
            {
                *__j = std::move(*__k);
                __j = __k;
            } while (__j != start && LessThan()(__t, *--__k));
            *__j = std::move(__t);
        }
        __j = __i;
    }
    //std::sort(start, end, lessThan);
}

template <typename RandomAccessIterator, typename LessThan>
inline void SelectSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) 
{
    RandomAccessIterator __j = start;
    RandomAccessIterator __end = end - 1;
    RandomAccessIterator __min;
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;
    for (RandomAccessIterator __i = __j+1; __i != end; ++__i)
    {
        __min = __i;
        
        for (RandomAccessIterator __k = __i + 1; __k != end; ++__k)
        {
             if (LessThan()(*__k, *__min))
             {
                *__min = std::move(*__k);
                __min = __k;
             }
        }
        *__i = std::move(*__min);
        __i = __min;
    }
}

template <typename RandomAccessIterator, typename LessThan>
inline void StableSelectSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {
    RandomAccessIterator __j = start;
    RandomAccessIterator __end = end - 1;
    RandomAccessIterator __min;
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;
    for (RandomAccessIterator __i = __j+1; __i != end; ++__i)
    {
        __min = __i;
        
        for (RandomAccessIterator __k = __i + 1; __k != end; ++__k)
        {
             if (LessThan()(*__k, *__min))
             {
                *__min = std::move(*__k);
                __min = __k;
             }
        }
        *__i = std::move(*__min);
        __i = __min;
    }
}

template <typename RandomAccessIterator, typename LessThan>
inline void HeapSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {
    // // Adicione el código de Heap Sort, use std::make_heap y std::pop_heap.
    // std::make_heap(start, end);
    // std::pop_heap(start, end);
  
    // RandomAccessIterator __j = start;
    
    // typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;
    // std::vector < RandomAccessIterator > v;
    
    // for (RandomAccessIterator __i = __j; __i != end; ++__i)
    // {
    //     v.push_back(*__i); 
    // }

    // for (RandomAccessIterator __i = __j; __i != end; ++__i)
    // {
    //     __i =  v.back();
    //      v.pop_back();
    // }
}

template <typename RandomAccessIterator, typename LessThan>
inline void MergeSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {
    // Adicione el código de Merge Sort.

}

template <typename RandomAccessIterator, typename LessThan>
inline void IterativeMergeSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {
    // Adicione el código de Merge Sort.
}

template <typename RandomAccessIterator, typename LessThan>
inline void LomutoQuickSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {
    // Adicione el código de Quick Sort de Lomuto.
}

template <typename RandomAccessIterator>
inline RandomAccessIterator HoarePartition(RandomAccessIterator start, RandomAccessIterator end)  
{
    RandomAccessIterator __i = start--;
    RandomAccessIterator __j = end;
    RandomAccessIterator __x = start;
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;
    while(true)
    {
        do __j--; while (*__j > *__x);
        do __i++; while (*__i < *__x);
        if (*__i < *__j)
        {
            *__i = std::move(*__j);
            __i = __j;
        } else 
        {
            return __j + 1;
        }
    }
}

template <typename RandomAccessIterator, typename LessThan>
inline void HoareQuickSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) 
{
    RandomAccessIterator q;
    if (distance(end, start) < 2) return;
    q = HoarePartition<RandomAccessIterator>(start,end);
    HoareQuickSort(start,q);
    HoareQuickSort(q,end);
}

template <typename RandomAccessIterator>
void swap(RandomAccessIterator start, RandomAccessIterator end)
{
    RandomAccessIterator __i = start;
    RandomAccessIterator __j = end;
    RandomAccessIterator __tmp;

    __tmp = __i
    *__i = std::move(*__j);
    __i = __j;
    *__j = std::move(*__tmp);
    __i = __tmp;
}

template <typename RandomAccessIterator, typename LessThan>
inline void YaroslavskiyQuickSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {
    // Adicione el código de Quick Sort con doble pivot y corte a insertion sort con pocos elementos.
    RandomAccessIterator __i = start;
    RandomAccessIterator __j = end;
    if (std::distance(__j,__i) < 0)
    {
        // Choose outermost elements as pivots
        if (*__j > *__i)
        {
            swap<RandomAccessIterator>(__i, __j);
        } 

        // Partition A according to invariant below
        RandomAccessIterator __l = __i + 1, __g = __j - 1, __k = __l;
        while (*__k <= __g) 
        {
            if (*__k < *__j) 
            {
                swap<RandomAccessIterator>(__k, __l);
                ++__l;
            } else if (*__k >= *__j) 
            {
                while (*__g > *__j && __k < __g) --__g;
                swap<RandomAccessIterator>(__k, __g);
                --__g;
                if (*__k < **__i)
                {
                    swap<RandomAccessIterator>(__k, __l);
                    ++__l;
                }
            }
            ++__k;
        }
        --__l; ++__g;

        // Swap pivots to final place
        swap<RandomAccessIterator>(__i, __l); swap<RandomAccessIterator>(__j, __g);

        // Recursively sort partitions
        YaroslavskiyQuickSort(__i, __l - 1);
        YaroslavskiyQuickSort(__l + 1, __g - 1);
        YaroslavskiyQuickSort(__g + 1, __j);
    }
}

int main(int argc, char** argv) {
    typedef void (*SORT_ALGORITHM)(std::vector<int>::iterator, std::vector<int>::iterator);
    for ( auto & i : {100,/*1000,10000,100000,1000000,10000000,100000000*/}){
        std::vector<int> w(i),v;
        std::iota(w.begin(), w.end(), 1);
        for(auto a = w.begin(), _a = w.begin()+i/100; a < w.end(); _a += i/100)
        {
            std::shuffle (a, _a, std::default_random_engine(std::time(0)));
            a = _a;
        }
        // retire el comentario para estudiar datos completamente desordenados:
        //std::shuffle (w.begin(), w.end(), std::default_random_engine(std::time(0)));
        std::vector<SORT_ALGORITHM> sort_algorithms = {InsertSort,  SelectSort, StableSelectSort, HeapSort, MergeSort, IterativeMergeSort, LomutoQuickSort, HoareQuickSort };
        if ( i > 100000 && i < 100000000)
        {
            sort_algorithms = {HeapSort, MergeSort, IterativeMergeSort, LomutoQuickSort, HoareQuickSort };
            std::cout << "-, -, -, ";
        }
        if (i == 100000000)
        {
            sort_algorithms = {IterativeMergeSort, LomutoQuickSort, HoareQuickSort };
            std::cout << "-, -, -, -, -, ";
        }
        for ( auto & sort_algorithm : sort_algorithms){
            v=w;
            std::clock_t inicio = std::clock();
            sort_algorithm(v.begin(),v.end());
            // for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++ ) {
            //     std::cout<<*it<<std::endl;
            // }
            std::cout << 1000.0 * (double)(std::clock()-inicio)/(double)CLOCKS_PER_SEC << ", " << std::flush;
        }
        std::cout << std::endl;
    }
    return 0;
}
