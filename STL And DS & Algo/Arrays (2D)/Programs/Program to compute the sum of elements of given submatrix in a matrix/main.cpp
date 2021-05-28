// Submatrix sum query on a matrix
// https://www.geeksforgeeks.org/submatrix-sum-queries/

// Brute force solution - O(Query*N*M) time; since we loop through the entire submatrix to cal the sum

// Efficient soln: O(1) time once we have the prefix sum matrix

#include<iostream>
using namespace  std;

int main()
{
    // input the matrix
    int rows, columns;
    cout<<"Enter the rows and columns"<<endl;
    cin>>rows>>columns;
    int matrix[rows][columns];

    cout<<"Enter the matrix"<<endl;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
            cin>>matrix[i][j];
    }

    cout<<endl;

    // Calculate the prefix i.e. matrix that has cumulative sum of the main matrix
    int prefixSumMatrix[rows][columns];
    int sum = 0;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j< columns; j++) {
            if(i == 0 && j == 0)
                prefixSumMatrix[i][j] = matrix[0][0];
            else if (i == 0)
                prefixSumMatrix[i][j] = prefixSumMatrix[i][j-1] + matrix[i][j];
            else
            {
                for(int x = 0; x <= i; x++)
                {
                    for(int y = 0; y <= j; y++)
                    {
                        sum += matrix[x][y];
                    }
                }
                prefixSumMatrix[i][j] = sum;
                sum = 0;
            }
        }
    }

    // Print out the prefix sum matrix
    for(int i = 0; i< rows; i++) {
        for (int j = 0; j < columns; j++)
            cout << prefixSumMatrix[i][j] << " ";
        cout<<endl;
    }

    // Input the queries
    int n;
    cout<<endl;
    cout<<"Enter the number of queries"<<endl;
    cin>>n;

    while(n--)
    {
        sum = 0;
        int tli, tlj, bri, brj;
        cout<<"Enter the query:";
        cin>>tli>>tlj>>bri>>brj;

        // Output the inputted query for assurance
        cout<<"Current Query:: "<<"tli: "<<tli<<" tlj: "<<tlj<<" bri: "<<bri<<" brj: "<<brj<<endl;

        // calculate the sum in O(1) time
        sum = prefixSumMatrix[bri][brj];
        // Some conditions to avoid out of bounds error
        if (tli > 0)
            sum -= prefixSumMatrix[tli-1][brj];
        if (tlj > 0)
            sum -= prefixSumMatrix[bri][tlj-1];
        if (tli > 0 && tlj > 0)
            sum += prefixSumMatrix[tli-1][tlj-1];
        cout<<"Sum for Current Query:: "<<sum<<endl;
        cout<<endl;
    }


    return 0;
}