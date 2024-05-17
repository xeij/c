#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int findKthLargest(int arr[], int n, int k)
{
    int low = INT_MAX, high = INT_MIN;

    for (int i = 0; i < n; i++) {
        low = min(low, arr[i]);
        high = max(high, arr[i]);
    }

    while (low <= high) {nction to find the Kth largest element in the gh) {
        int mid = low + (high - low) / 2;
        int count = 0;

        int i = 0; i < n; i++) {
               (arr[i] > mid) {
                count++;
            }
        }

        if (count >= k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return high;
}

void printKLargest(int arr[], int n, int k)
{
    int kthLargest = findKthLargest(arr, n, k);

    for (int i = 0; i < n; i++) {
        if (arr[i] >= kthLargest) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int main()
{
    int arr[] = { 12, 5, 787, 1, 23 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    cout << "K largest elements: ";
    printKLargest(arr, n, k);

    return 0;
}
