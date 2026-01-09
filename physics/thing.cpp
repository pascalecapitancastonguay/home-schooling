#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long num_moves = 0;
    vector <long long> v(n);
    cin >> v[0];
    for(int i=1; i<n; i++) {
        cin>>v[i];
        if(v[i] < v[i-1]){
            num_moves += v[i-1]- v[i];
            v[i] = v[i-1];
        }
    }
    cout << num_moves;
}







//   ^  ^
//  (. . )
//   👄

// 1. cin n and vector v
// 2. take second char of v
// 3. see if 1st char is = or lesser
// 4. else, add one to char 2, add one to num of moves
// 5. repeat 3 & 4 until 3= true
// 6. move onto the next char 
// 7. repeat number 5
// 8. repeat 3. to 6. n times
// 9. return num of moves

/* https://cses.fi/problemset/task/1094

You are given an array of n integers. You want to modify the array so that it is increasing, i.e., every element is at least as large as the previous element.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
On each move, you may increase the value of any element by one. What is the minimum number of moves required?
Input
The first input line contains an integer n: the size of the array.
Then, the second line contains n integers x_1,x_2,\ldots,x_n: the contents of the array.
Output
Print the minimum number of moves.
Constraints

Example
Input:
5
3 2 5 1 7

Output:
5
*/


/*
first we get array n
 then we take the first number x
  and if the next number is greater or equal to the first number
   then we don't change it
    if not we add just enough to the next number so that the next number is also x, 
 then we do this on repeat until all numbers are the sam e
  and then count how many times we added to a number, 
  this will be a. We return whatever a is .
  */
// Step one. We find out what the first number is. That will be x.
// Step two. We find out what the next number in the array is and if it is equal to or greater than the first number we don't change it 