// Array operations

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// main functions

bool searchEle(int a[], int x, int size);

bool insertEle(int a[], int y, int yi, int size);

bool deleteEle(int a[], int z, int size);

// helper functions

// recursive binary search
bool binarySearch(int a[], int x, int s, int e)
{
  if (s > e)
  {
    return -1;
  }
  else
  {

    int mid = (s + e) / 2;

    // find the mid ele
    if (a[mid] == x)
      return mid;
    // else return the other halves of the array
    else if (a[mid] > x)
      return binarySearch(a, x, s, mid - 1);
    else
      return binarySearch(a, x, mid + 1, e);
  }
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int a[10000];
    int size = (sizeof(a)) / (sizeof(int));
    memset(a, -1, sizeof(a));
    for (int i = 0; i < n; i++)
      cin >> a[i];
    int x, y, yi, z;
    cin >> x >> y >> yi >> z;
    bool b = searchEle(a, x, size);
    if (b == true)
      cout << "1 ";
    else
      cout << "0 ";
    b = insertEle(a, y, yi, size);
    if (b)
    {
      if (a[yi] == y)
        cout << "1 ";
      else
        cout << "0 ";
    }
    else
      cout << "0 ";
    b = deleteEle(a, z, size);
    if (b)
    {
      if (!searchEle(a, z, size))
        cout << "1 \n";
      else
        cout << "0 \n";
    }
    else
      cout << "0 \n";
  }
}

bool searchEle(int a[], int x, int size)
{
  // binary search the element in the array
  // sort the array
  sort(a, a + size);
  int pos = binarySearch(a, x, 0, size - 1);
  if (pos == -1)
    return 0;
  else
    return 1;
}

bool insertEle(int a[], int y, int yi, int size)
{
  // insert element at that position (replace)
  if (yi < 0 || yi > size - 1)
  {
    return 0;
  }
  int i = 0;
  while (i != yi)
    i++;
  a[yi] = y;
  return 1;
}

bool deleteEle(int a[], int z, int size)
{
  // sort the array
  sort(a, a + size);
  int pos = binarySearch(a, z, 0, size - 1);
  if (pos < 0)
  {
    return 0;
  }
  else
  {
    if (pos == size - 1)
    {
      a[pos] = -1;
    }
    else
    {
      int i = pos;
      for (; i <= size - 2; i++)
        a[i] = a[i + 1];
      a[i] = -1;
    }
    return 1;
  }
}