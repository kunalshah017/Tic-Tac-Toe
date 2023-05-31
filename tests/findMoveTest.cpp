#include <iostream>
#include "../findMove.cpp"

int main() {
    char board1[10] = {'0', 'O', 'X', 'O', 'X', 'X', 'O', '7', '8', '9'};
    cout << findBestMove(board1) << endl;   // should be 9
    char board2[10] = {'0', 'X', 'O', 'X', 'O', 'O', 'X', 'X', 'O', '9'};
    cout << findBestMove(board2) << endl;   // should be 9
    // add more tests here...

    return 0;
}