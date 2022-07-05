#include <iostream>
#include <string>
#define out 0
#define IN 1

using namespace std;
int main()
{
    //char name[] = {"Welcome"};
    string name;
    getline(cin, name);
    int c = 0, state = out;
    for (int i = 0; name[i] != '\0'; i++)
    {
        if (name[i] == ' ')
            state = out;
        else if (state == out)
        {
            state = IN;
            ++c;
        }
    }

    cout << c;

    return 0;
}