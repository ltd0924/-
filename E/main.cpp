#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
int Find(int x)
{
    int s;
    for (s=x; parent[s]>=0; s = parent[s]);
    while (s != x)
    {
        int tmp = parent[x];
        parent[x] = s;
        x = tmp;
    }
    return s;
}
