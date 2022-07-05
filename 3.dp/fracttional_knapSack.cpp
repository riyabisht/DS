#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<pair<pair<int, int>, int>> datatype;

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    return a.first.first * (1.0 / a.first.second) > b.first.first * (1.0 / b.first.second);
}

datatype input_data()
{
    int n;
    std::cin >> n;
    vector<int> profit(n, 0);
    vector<int> weight(n, 0);

    for (int i = 0; i < n; i++)
        cin >> profit[i];

    for (int i = 0; i < n; i++)
        cin >> weight[i];

    datatype data;

    for (int i = 0; i < n; i++)
    {
        data.push_back(make_pair(make_pair(profit[i], weight[i]), i + 1));
    }

    return data;
}

void logic(datatype data)
{

    int k;
    /* Capacity */
    cin >> k;
    float max_profit = 0;
    sort(data.begin(), data.end(), compare);

    vector<pair<float, int>> selection;
    datatype ::iterator i;
    int j;
    for (i = data.begin(), j = 1; i < data.end(); i++, j++)
    {
        if ((*i).first.second <= k)
        {
            max_profit += (*i).first.first;
            k -= (*i).first.second;
            selection.push_back(make_pair((*i).first.first, (*i).first.second));
        }
        else
        {
            max_profit = max_profit + k * ((*i).first.first * (1.0 / (*i).first.second));
            selection.push_back(make_pair(k * ((*i).first.first * (1.0 / (*i).first.second)), k));
            break;
        }
    }
    /*  cout<<"Selected\nProfit\t\t"<<"Selected weight\t\t\n";
        for_each(selection.begin(),selection.end(),[](pair<float,int> n){cout<<n.first<<"\t\t"; cout<<n.second; cout<< endl;}); */

    cout << " max profit ::" << max_profit;
}

int main()
{
    datatype data;
    data = input_data();
    logic(data);

    return 0;
}