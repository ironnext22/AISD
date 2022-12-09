#include <iostream>
#include "sort/sorty.h"
#include <algorithm>
int main()
{
    int lista[] = {1,2,8,4,5};

    for(auto x : lista)
    {
        std::cout<<x<<" ";
    }
    std::cout<<std::endl;
    std::sort(lista,lista+5);
    for(auto x : lista)
    {
        std::cout<<x<<" ";
    }
    cout<<endl;

///Counter sort
    char arr[] = "geeksforgeeks";

    // Function call
    countSort(arr);

    cout << "Sorted character array is " <<arr<<endl;

///Radix sort
    int arr1[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr1) / sizeof(arr1[0]);

    // Function Call
    radixsort(arr1, n);
    print(arr1, n);
    cout<<endl;

///Bucket sort
    float arr2[]= { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
    int n1 = sizeof(arr2) / sizeof(arr2[0]);
    bucketSort(arr2, n1);

    cout << "\nSorted array is \n";
    for (int i = 0; i < n1; i++)
        cout << arr2[i] << " ";

    return 0;
}




