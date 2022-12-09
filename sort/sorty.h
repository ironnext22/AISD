
// C++ Program for counting sort
#include <bits/stdc++.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define RANGE 255


//---------------------------------------------------------------//
//------------------------COUNTING SORT--------------------------//
// Stosować do stringów !!! Przedstawic je jako tablica charow
// the given string arr[] in
// alphabetical order
void countSort(char arr[])
{
    char output[strlen(arr)];

    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));

    for (i = 0; arr[i]; ++i)
        ++count[arr[i]];

    for (i = 1; i <= RANGE; ++i)
        count[i] += count[i - 1];

    for (i = 0; arr[i]; ++i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }
    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
}

//---------------------------------------------------------------//
//--------------------------RADIX SORT---------------------------//
// C++ implementation of Radix Sort


// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = { 0 };

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    // position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// A utility function to print an array
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}


//---------------------------------------------------------------//
//-------------------------BUCKET SORT---------------------------//
//Stosowac do rowno rozlokowanych liczb np co 0.1 lub o 1

// Function to sort arr[] of
// size n using bucket sort
void bucketSort(float arr[], int n)
{

    // 1) Create n empty buckets
    vector<float> b[n];

    // 2) Put array elements
    // in different buckets
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i]; // Index in bucket
        b[bi].push_back(arr[i]);
    }

    // 3) Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());

    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}





