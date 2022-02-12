// iterative method
#include <iostream>
using namespace std;
int main()
{
    int arr[] = {3, 6, 8, 12, 14, 17, 25, 29, 31, 36, 42, 47, 53, 55, 62};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key=62;
    bool flag = false;
    int lower = 0, upper = n - 1;
    while (lower <= upper)
    {
        int mid = (lower + upper) / 2;
        if (arr[mid] == key)
        {
            flag = true;
            break;
        }
        else if (key > arr[mid])
        {
            lower = mid + 1;
        }
        else
        {
            upper = mid - 1;
        }
    }
    if (flag)
        cout << " present";
    else
        cout << " not present ";
    return 0;
}