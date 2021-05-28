// Tiling Problem using recusion
// Place the tiles
// https://www.geeksforgeeks.org/tiling-problem/

// Ques: Given a wall of size 4xN, and tiles of size (1,4) and (4,1), in how many ways can the wall eb built?
// Use recursion

#include<iostream>
#include<cstring>

using namespace std;

int waysToBuildWall(int height, int length) {
    // main observation here is that each step can be 2 things:
    // A) place 1 vertical brick (4x1) B) place 4 horizontal bricks (1x4)

    // base case
    if (length < 4)
        return 1;
    if (length == 4)
        return 2;
    // recursion
    int x = waysToBuildWall(4, length - 1);   // if we place the (one) vertical brick
    int y = waysToBuildWall(4, length - 4);   // if we place (4) horizontal bricks
    return x + y;
}

int main() {
    // input len of wall
    int n;

    // input
    cout << "Enter the length of wall" << endl;
    cin >> n;

    //  main
    cout << "Ways in which the wall can be printed: " << waysToBuildWall(4, n) << endl;
    return 0;
}