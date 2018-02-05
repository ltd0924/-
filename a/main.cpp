#include <iostream>

using namespace std;
void UFset() // ��ʼ��
{
    for (int i = 0; i < n; i ++)
        parent[i] = -1;
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

void spare (int R1, int R2)
{
    // r1λR1�ĸ���㣬r2λR2�ĸ����
    int r1 = Find(R1), r2 = Find(R2);
    int tmp = parent[r1] + parent[r2];   // �������ϵĽ�����֮�ͣ�������
    // ���R2������������ > R1������������
    // ע��parent[r1]��parent[r2]���Ǹ���
    if(parent[r1] > parent[r2])    // �Ż����� -- ��Ȩ����
    {
        parent[r1] = r2;        // �������r1���ڵ�����Ϊr2���������ϲ���
        parent[r2] = tmp;       // ���¸����r2��parent[]ֵ
    }
    else
    {
        parent[r2] = r1;         // �������r2���ڵ�����Ϊr1���������ϲ���
        parent[r1] = tmp;        // ���¸����r1��parent[]ֵ
    }
}
