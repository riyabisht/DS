#include <bits/stdc++.h>
using namespace std;
vector<int> merge(vector<int> arr1, vector<int> arr2, int k)
{
      for (auto i : arr1)
        cout << i << " ";
    cout << endl;
      for (auto i : arr2)
        cout << i << " ";
    cout << endl;

    vector<int> res;
    int i = 0, j = 0;
    while (i < k && j < k)
    {
        if (arr1[i] < arr2[j])
        {
            res.push_back(arr1[i]);
            i++;
        }
        else
        {
            res.push_back(arr2[j]);
            j++;
        }
    }
    for (auto i : res)
        cout << i << " ";
    cout << endl;
    if (i == k)
    {
        while (j < k)
        {
            res.push_back(arr2[j]);
            j++;
        }
    }
    else if (j == k)
    {
        while (i < k)
        {
            res.push_back(arr1[i]);
            i++;
        }
    }
    // for(auto i:res)
    //     cout<<i<<" ";
    // cout<<endl;
    arr1.clear();
    arr2.clear();
    return res;
}

// Function to merge k sorted arrays.
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    // code here
    vector<int> arr1;
    vector<int> res;
    arr1 = arr[0];
    for (int i = 1; i < K; i++)
    {

        res = merge(arr1, arr[i], K);
        arr1.clear();

        // for (auto i : res)
        //     arr1.push_back(i);
        for (auto i : arr1)
            cout << i << " ";
        cout << endl;
        res.clear();
    }
    return arr1;
}

int main()
{
    vector<vector<int>> arr({{1, 2, 3},
                             {4, 5, 6},
                             {7, 8, 9}});
    int k = 3;
    vector<int> res;
    res = mergeKArrays(arr, k);
    for(auto i:res){
        cout<<i<<" ";
    }

    return 0;
}