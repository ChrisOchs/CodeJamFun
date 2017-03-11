#include <algorithm>
#include <cstring>
#include <iostream>
#include "StoreCredit.h"

// Qualification Round Africa 2010 Problem A
void storeCreditSolution(int* items, size_t n, int credit) {

    int* sortedItems = new int[n];

    memcpy(sortedItems, items, n * sizeof(int));

    std::sort(sortedItems, sortedItems + n);

    int i = 0;
    int j = n - 1;

    while(i != j) {

        int sum = sortedItems[i] + sortedItems[j];

        if(sum == credit) {

            int firstValue = sortedItems[i];
            int secondValue = sortedItems[j];

            int firstValueIndex = -1;
            int secondValueIndex = -1;

            for(int c = 0; c < n; c++) {
                if(firstValueIndex == -1 && items[c] == firstValue) {
                    firstValueIndex = c;
                }

                if(secondValueIndex == -1 && firstValueIndex != c && items[c] == secondValue) {
                    secondValueIndex = c;
                }
            }

            if(firstValueIndex < secondValueIndex) {
                std::cout<<firstValueIndex + 1<<" "<<secondValueIndex + 1<<std::endl;
            } else {
                std::cout<<secondValueIndex + 1<<" "<<firstValueIndex + 1<<std::endl;
            }

            return;
        }

        if(sum < credit) {
            i++;
        } else {
            j--;
        }
    }

    std::cout<<"Does not exist"<<std::endl;

    delete [] sortedItems;
}
