// Book Allocation Program
// https://www.youtube.com/watch?v=Ss9ta1zmiZo
// https://www.geeksforgeeks.org/allocate-minimum-number-pages/

#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;

// if possible function: determines if mid number of pages are the max nunmber read by each student
bool isPossible(int arr[], int books, int students, int mid) {
    int studentsUsed = 1;   // keeps track of students used
    int pagesRead = 0;  // keeps track o fpages read
        // for all books
        for (int i = 0; i < books; i++) {
        if(pagesRead + arr[i] > mid)
        {
            // if pages read exceed mid on this book, increment student, update value of pages read back to pages to currBook
            studentsUsed++;
            pagesRead = arr[i];
            // however if students used exceed actual students, return false
            if(studentsUsed > students)
                return false;
        }
        else
            // if it doesnt exceed mid, add pages of book to pages read
            pagesRead += arr[i];
    }
    return true;
}

// function to determine the ans
int bookAllocation(int books, int arr[], int students, int sum) {
    // corner case if books is less than students
    if (books < students)
        return -1;

    // setting the limits
    int l = arr[books - 1]; // lower limit will be eql to either 0 or largest number of books in the array
    int r = sum;    // larger limit is eql to teh sum of all books ie worst case where one students has to read all the books
    int ans = INT_MAX;  // variable that stores min value of max books that students have to read

    // binary tech -> monotonic search space
    while (l <= r) {
        int mid = l + (r - l) / 2;

        // check if all the books can be read by all the students with max pages being read by a student are mid
        if (isPossible(arr, books, students, mid)) {
            ans = min(ans, mid);    // update the ans
            r = mid - 1;    // try to find a more lesser value for ans by reducing min; by reducing right
        } else {
            l = mid + 1;    // if it isn't possible, then increase mid by shifting left
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