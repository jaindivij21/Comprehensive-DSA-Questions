// Sum of all elements of all the submatrices of a matrix
// https://www.geeksforgeeks.org/sum-of-all-submatrices-of-a-given-matrix/
// Brute force solution O(N^6)

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of rows and columns"<<endl;
    cin>>n;

    int sum = 0;

    // input the matrix
    int matrix[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cin>>matrix[i][j];
    }

    // for every top corner
    for(int li = 0; li < n; li++)
    {
        for(int lj = 0; lj < n; lj++)
        {
            // to every bottom corner thus forming a rectangle
            for(int bi = li; bi < n; bi++)
            {
                for(int bj = lj; bj < n; bj++)
                {
                    // now we have all the coordinates of all the submatrices
                    // now we just ahve to compute the sum of all the elements of all the submatrices
                    for(int i = li; i <= bi; i++)
                    {
                        for(int j = lj; j <= bj; j++)
                        {
                            sum += matrix[i][j];
                        }
                    }
                }
            }

        }
    }

    cout<<"Sum:"<<sum<<endl;
    return 0;
}