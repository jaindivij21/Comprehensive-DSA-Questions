// Sum of Sub-Array



// ************************************ ANS BY ME ***********************************


// #include<iostream>
// #include<vector>
// using namespace std;

// void firstSubArray(vector<int> arr, vector<int> arr2, int size, int sum)
// {

//     int newSum = 0;
//     int beginPos=0;
//     for(int i = 0; i<size; i++)
//     {
//         newSum += arr.at(i);
//         if(newSum > sum)
//         {
//             newSum = newSum - arr2.front();
//             arr2.erase(arr2.begin());
//             beginPos++;
//         }
//         if(newSum == sum) {
//             cout << beginPos + 1 << " " << i + 1;
//             return;
//         }
//     }
//     cout<<"-1";
// }


// int main()
// {
//     int testCases;
//     cin>>testCases;
//     int size;
//     long long sum;
//     int temp;

//     for(int j = 0; j<testCases; j++) {
//         cin>>size>>sum;
//         vector<int> arr;
//         vector<int> arr2;
//         for (int i = 0; i < size; i++) {
//             cin >> temp;
//             arr.push_back(temp);
//             arr2.push_back(temp);
//         }
//         firstSubArray(arr, arr2, size, sum);
//         cout<<endl;
//     }


//     return 0;
// }


// ************************************ CORRECT ANS ***********************************

#include <bits/stdc++.h>

using namespace std;

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long k;
        cin>>n>>k;
        int arr[n];
        
        int last=0;
        int start=0;
        unsigned long long  currsum=0;
        bool flag=false;
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        for(int i=0;i<n;i++)
        {
            currsum += arr[i];
            if(currsum>=k)
            {
                last=i;
                while(k<currsum && start<last)
                {
                    currsum -= arr[start];
                    ++start;
                }
                
                if(currsum==k)
                {
                    cout<<start+1<<" "<<last+1<<endl;
                    flag = true;
                    break;
                }
            }
        }
        if(flag==false)
        cout<<-1<<endl;
        
    }
	return 0;
}