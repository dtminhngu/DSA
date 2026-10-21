#include <bits/stdc++.h>
using namespace std;

// Backtracking function to search for the word in 4 directions
bool Try(int r, int c, int k, vector <vector<char>> &board, string word) {
    // 1. Base case: Successfully matched all characters of the word
    if (k == word.size()) return true;
    // 2. Pruning: Out of bounds or cell already visited ('#')
    if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] == '#') return false;
    // 3. Pruning: Current cell character does not match word[k]
    if (board[r][c] != word[k]) return false;
    // 4. Choose: Temporarily mark current cell as visited
    char temp = board[r][c];
    board[r][c] = '#';
    // 5. Explore: Recursively check 4 directions and increment k by 1
    bool found = Try(r+1, c, k+1, board, word) || 
                 Try(r-1, c, k+1, board, word) || 
                 Try(r, c+1, k+1, board, word) || 
                 Try(r, c-1, k+1, board, word);
                 
    // 6. Un-choose (Backtrack): Restore the original cell character
    board[r][c] = temp;
    
    return found;
}

// Wrapper function to scan every cell on the board as a starting point
bool exist(vector <vector<char>> &board, string word) {
    int r = board.size();
    int c = board[0].size();
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            // Start backtracking if the starting cell matches word[0]
            if (Try(i, j, 0, board, word)) return true;   
        }
    }
    return false;
}

int main() {
    int m, n;
    string word;
    cin >> word;
    cin >> m >> n;
    // Initialize 2D vector with size m x n
    vector <vector<char>> board(m, vector<char>(n));
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cin >> board[i][j];
        }
    }
    if (exist(board, word)) cout << "TRUE";
    else cout << "FALSE";
    
    return 0;
}