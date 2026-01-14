#include <iostream>
using namespace std;

/*
A number spiral is an infinite grid whose upper-left square has number 1. Here are the first five layers of the spiral:

Your task is to find out the number in row y and column x.
Input
The first input line contains an integer t: the number of tests.
After this, there are t lines, each containing integers y and x.
Output
For each test, print the number in row y and column x.
/Constraints

1 \le t \le 10^5
1 \le y,x \le 10^9

Example
Input:
9
2 3
1 1
4 2
1 101
101 1
5 7
7 5
11 11
1000 1000

Output
8
1
15
10201
10001
45
41
111
999001
*/

int spiral() {
    int t;
    cin >> t;

    while (t--) {
        long long y, x, k;
        cin >> y >> x;
        k = max(y,x);
        if (k == y) { // we are in 1st col
            if (k % 2 == 0) { // we are in an even row
                k = k*k;
                k = k - (x - 1);
            } else { // we are in an odd row
                k--;
                k = k*k;
                k = k + x;
            }
        } else { // we are in top row
            if (k % 2 == 0) { // we are in an even col
                k--;
                k = k*k + 1;
                k = k + (y - 1);
            } else { // we are in an odd col
                k = k*k;
                k = k - (y - 1);
            }   
        }
        cout << k << endl;
    }
    return 0;
}

int main() {
    spiral();
    return 0;
}
