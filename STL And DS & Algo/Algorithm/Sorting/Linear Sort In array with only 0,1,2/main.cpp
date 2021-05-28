// Sort in linear time arrays with only 3 items 0,1 2

#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int arr2[n];
    int j = n - 1;
    int k = 0;

    for (int i = 0; i < n; i++) {
            arr2[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            arr2[k] = 0;
            k++;
        }
        if (arr[i] == 2) {
            arr2[j] = arr[i];
            j--;
        }
    }


    for (int i = 0; i < n; i++) {
        cout<<arr2[i]<<endl;
    }
        return 0;
}

/*
 *  CAN ALSO USE
 * 
 *  mid = arr[0] = low
 *  high = arr[n-1]
 * 
 *  while(mid <= high)
 *  {
 *      if(arr[mid] == 0)
 *      {
 *          swap(low, mid)   
 *          mid++, low++
 *       }
 *      else if(mid = 1)
 *      {
 *          mid++    
 *      }  
 *      else
 *      {
 *          swap(mid, high)
 *          high--
 *      }
 *  }
 * 
*/
