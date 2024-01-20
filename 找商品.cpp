#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include <cstring>
#include <stdio.h>
#include<string>
#include<algorithm>
using namespace std;
typedef struct goods
{
    char name[11];
    double price;
    int k;
}goods;
int main()
{
    goods g[20];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> g[i].name >> g[i].price >> g[i].k;
    }
    goods max = g[0];
    goods g2[20];
    for (int i = 0; i < n; ++i)
    {
        if (g[i].k > max.k)
        {
            max = g[i];
        }
    }
    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        if (g[i].k == max.k)
        {
            g2[j] = g[i];
            j++;
        }
    }
    goods max2 = g2[0];
    for (int i = 0; i < n; ++i)
    {
        if (g2[i].price > max.price)
        {
            max2 = g2[i];
        }
    }
    printf("%s %.2lf %d\n", max2.name, max2.price, max2.k);
}
