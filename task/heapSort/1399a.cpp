#include <bits/stdc++.h>

using namespace std;

void heapify(int arr[], int N, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < N && arr[l] > arr[largest])
        largest = l;
    if (r < N && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    for (int i = N - 1; i > 0; i--) 
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(void)
{
    int t;
    cin >> t;
    for(int it=0; it<t; it++)
    {
        int n;
        cin >> n;
        int ar[n];
        for(int i=0; i<n; i++)
            cin >> ar[i];
        heapSort(ar, n);
        int c=1;
        for(int i=1; i<n; i++)
            if((ar[i]-ar[i-1]) > 1)
            {
                c = 0;
                break;
            }
        if(c)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}