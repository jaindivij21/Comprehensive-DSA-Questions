// Staircase Search (For 2D Array)
// Works if the 2D array is sorted both row and column wise

/*
 *      Ways to Sort a 2D Array
 *      1) Brute Force N^2
 *      2) Binary Search in every row NlogN
 *      3) Staircase Approach O(N)
 */

#include<iostream>
using namespace std;
int m = 0;
int n = 0;

int staircaseSearch(int arr[][100], int rows, int columns, int x) {
    int i = 0;
    int j = columns - 1;
    while (i <= rows || j >= 0) {
        if(x > arr[i][j])
            i++;
        else if(x < arr[i][j])
            j--;
        else
        {
            m = i;
            n = j;
            return 1;
        }
    }
    return -1;
}

int main() {
    cout<<"Enter the number of rows and columns"<<endl;
    int rows, columns;
    cin >> rows >> columns;

    int arr[100][100];

    cout<<"Input the array"<<endl;
    //input the array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            cin >> arr[i][j];
    }
    cout<<endl;

    //original array
    cout << "Original Array" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    cout << "Enter the element to be found" << endl;
    int element;
    cin >> element;
    cout << endl;
    int res = staircaseSearch(arr, rows, columns, element);
    if (res == -1)
        cout << "Element not found" << endl;
    else
        cout << "Element found at " << m << " " << n << endl;

    return 0;
}



/*

// SMALLER AND GOOD SOLN

#include<iostream>
using namespace std;
int main() {
  int n,m,x;
  int arr[30][30];
  cin>>n>>m;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    cin>>arr[i][j];
  }
  cin>>x;
  int a=0;int b=m-1;
  int flag=0;int comp=arr[a][b];
  while((a<n)&&(b>=0))
  {
    if(x>comp)
    comp=arr[++a][b];
    else if(x<comp)
    comp=arr[a][--b];
    else{
    flag=1;
    break;
    }
  }
  cout<<flag<<endl;
	return 0;
}
*/