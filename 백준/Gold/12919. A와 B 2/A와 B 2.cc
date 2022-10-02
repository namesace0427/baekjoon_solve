#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int back(string s, string t)
{
    if (s == t)
    {
        return 1;
    }
    if (s.size() >= t.size())
        return 0;
    string temp;
    if (t[t.size() - 1] == 'A')
    {
        temp = t;
        temp.erase(temp.size() - 1);
        if (back(s, temp))
            return 1;
    }
    if (t[0] == 'B')
    {
        temp = t;
        temp.erase(temp.begin());
        reverse(temp.begin(), temp.end());
        if (back(s, temp))
            return 1;
    }
    return 0;
}

int main()
{
    char in[55];
    scanf(" %s", in + 1);
    string s = in + 1;
    scanf(" %s", in + 1);
    string t = in + 1;
    printf("%d", back(s, t));
    return 0;
}