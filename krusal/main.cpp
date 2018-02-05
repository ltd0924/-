#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
void Pern(int list[], int k, int n) {   //  k表示前k个数不动仅移动后面n-k位数
    if (k == n - 1) {
        for (int i = 0; i < n; i++) {
            printf("%d", list[i]);
        }
        printf("\n");
    }else {
        for (int i = k; i < n; i++) {   //  输出的是满足移动条件所有全排列
            swap(list[k], list[i]);
            Pern(list, k + 1, n);
            swap(list[k], list[i]);
        }
    }
}
