#include <iostream>
using namespace std;

// recursive method
int binnary_search(int arr[], int key, int upper, int lower)
{
    if (lower <= upper)
    {
        int mid = (upper + lower) / 2;
        if (arr[mid] == key)
            return 1;
        else if (key > arr[mid])
        {
            return binnary_search(arr, key, upper, mid + 1);
        }

        return binnary_search(arr, key, mid - 1, lower);
    }
    return 0;
}

int main()
{
    int arr[] = {3, 6, 8, 12, 14, 17, 25, 29, 31, 36, 42, 47, 53, 55, 62};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    cin >> key;
    int upper = n - 1;
    int lower = 0;
    if (binnary_search(arr, key, upper, lower))
        cout << "present";
    else
        cout << "not present";
    return 0;
}