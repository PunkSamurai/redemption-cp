#include <iostream>
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
    int n, s1=0, s2=0, i=0;
    cin >> n;
    int ar[n+1];
    for(i=1; i<=n; i++)
    {
        cin >> ar[i];
        s1+=ar[i];
    }
    heapSort(ar, n); 
    i=1;
    while(s2<s1)
    {
        s2+=ar[i];
        s1-=ar[i];
        i++;
    }
    cout << n-(i-1);
}
