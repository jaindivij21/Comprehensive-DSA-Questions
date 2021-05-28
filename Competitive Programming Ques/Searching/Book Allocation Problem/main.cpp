// Book Allocation Program
// https://www.youtube.com/watch?v=Ss9ta1zmiZo
// https://www.geeksforgeeks.org/allocate-minimum-number-pages/

#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;

bool isPossible(int arr[], int books, int students, int mid) {
    int studentsUsed = 1;
    int pagesRead = 0;
    for (int i = 0; i < books; i++) {
        if(pagesRead + arr[i] > mid)
        {
            studentsUsed++;
            pagesRead = arr[i];
            if(studentsUsed > students)
                return false;
        }
        else
            pagesRead += arr[i];
    }
    return true;
}

int bookAllocation(int books, int arr[], int students, int sum) {
    if (books < students)
        return -1;

    // setting the limits
    int l = arr[books - 1];
    int r = sum;
    int ans = INT_MAX;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (isPossible(arr, books, students, mid)) {
            ans = min(ans, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int main() {
    // enter the information
    int books;
    cout << "Enter the number of books:";
    cin >> books;

    int students;
    cout << "Enter the number of students:";
    cin >> students;

    // input the array w the pages
    int arr[books];
    int sum = 0;
    for (int i = 0; i < books; i++) {
        cin >> arr[i];  // its sorted array
        sum += arr[i];
    }

    // main funciton
    cout << "The min value of the max pages each student has to read is " << bookAllocation(books, arr, students, sum)
         << endl;
    return 0;
}