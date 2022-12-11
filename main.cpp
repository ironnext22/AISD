#include <iostream>
#include "sort/sorty.h"
#include <algorithm>
#include <array>
#include <vector>
void sort012(int a[], int arr_size)
{
    int lo = 0;
    int hi = arr_size - 1;
    int mid = 0;

    // Iterate till all the elements
    // are sorted
    while (mid <= hi) {
        switch (a[mid]) {

            // If the element is 0
            case 0:
                swap(a[lo++], a[mid++]);
                break;

                // If the element is 1 .
            case 1:
                mid++;
                break;

                // If the element is 2
            case 2:
                swap(a[mid], a[hi--]);
                break;
        }
    }
}
struct dane{
    int kwota;
    string tytul;
    friend std::ostream& operator<<(std::ostream& st, const dane& x)
    {
        st<<x.kwota<<" "<<x.tytul<<endl;
        return st;
    }
        };
bool por(dane& a, dane& b)
{
    return a.kwota > b.kwota;
}
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


///Zadanie 1
    cout<<endl<<endl;
    vector<dane> x;
    x.push_back({10,"123"});
    x.push_back({34,"123"});
    x.push_back({54,"123"});
    x.push_back({43,"123"});
    x.push_back({23,"XD"});
    x.push_back({234,"123"});
    x.push_back({545,"123"});
    x.push_back({32,"123"});

    for(auto y : x)
    {
        std::cout<<y;
    }
    cout<<endl<<endl;

    sort(x.begin(),x.end(), por);

    for(auto y : x)
    {
        std::cout<<y;
    }
    cout<<endl<<endl;
    array<dane,5> top;
    for(int i=0;i<top.size();i++)
    {
        top[i] = x[i];
    }
    for(auto y : top)
    {
        std::cout<<y;
    }
///zadanie 2
    int arrx[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
    int nx = sizeof(arrx)/sizeof(arrx[0]);
    for(auto x : arrx)cout<<x<<" ";
    cout<<endl<<endl;
    sort012(arrx,nx);
    for(auto x : arrx)cout<<x<<" ";
    return 0;
}




