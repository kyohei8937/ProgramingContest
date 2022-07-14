#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;
const int MOD = 1000000007;

// マクロ
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()

#define DEBUG
#ifdef DEBUG
# define _PRINTF(fmt, ...)  printf(fmt, __VA_ARGS__);                   
#else
# define _PRINTF(fmt, ...)
#endif

// 便利関数
// ...最小値・最大値交換
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
// ...中央値
template <typename T> T median(std::vector<T>& c){size_t n = c.size() / 2;std::nth_element(c.begin(), c.begin() + n, c.end());return c[n];}
// ...べき乗のmodで割った余り
int modpow(int a, int n, int mod) {int res = 1;while (n > 0) {if (n & 1) res = res * a % mod;a = a * a % mod;n >>= 1;}return res;}

//============================================================================
//ここまでテンプレ
//============================================================================

using Grid = vector<string>;
 
Grid configureGrid(string stacks[], int numberOfStacks)
{
 
    Grid grid;
    for (int i = 0; i < numberOfStacks; i++)
        grid.push_back(stacks[i]);
 
    return grid;
}
 
// Function to find the max
int getStackHeight(Grid grid)
{
    int max = 0;
    for (auto stack : grid)
        if (max < stack.size())
            max = stack.size();
    return max;
}
 
// Convert vector of strings to
// canonicalRepresentation of strings
string canonicalStringConversion(Grid grid)
{
    string finalString;
    sort(grid.begin(), grid.end());
    for (auto stack : grid) {
        finalString += (stack + ";");
    }
    return finalString;
}
 
// Function to check if it is solved
// or not
bool isSolved(Grid grid, int stackHeight)
{
 
    for (auto stack : grid) {
        if (!stack.size())
            continue;
        else if (stack.size() < stackHeight)
            return false;
        else if (std::count(stack.begin(),
                            stack.end(),
                            stack[0])
                 != stackHeight)
            return false;
    }
    return true;
}
 
// Check if the move is valid
bool isValidMove(string sourceStack,
                 string destinationStack,
                 int height)
{
 
    // Can't move from an empty stack
    // or to a FULL STACK
    if (sourceStack.size() == 0
        || destinationStack.size() == height)
        return false;
 
    int colorFreqs
        = std::count(sourceStack.begin(),
                     sourceStack.end(),
                     sourceStack[0]);
 
    // If the source stack is same colored,
    // don't touch it
    if (colorFreqs == height)
        return false;
 
    if (destinationStack.size() == 0) {
 
        // If source stack has only
        // same colored balls,
        // don't touch it
        if (colorFreqs == sourceStack.size())
            return false;
        return true;
    }
    return (
        sourceStack[sourceStack.size() - 1]
        == destinationStack[destinationStack.size() - 1]);
}
 
// Function to solve the puzzle
bool solvePuzzle(Grid grid, int stackHeight,
                 unordered_set<string>& visited,
                 vector<vector<int> >& answerMod)
{
    if (stackHeight == -1) {
        stackHeight = getStackHeight(grid);
    }
    visited.insert(
        canonicalStringConversion(grid));
 
    for (int i = 0; i < grid.size(); i++) {
 
        // Iterate over all the stacks
        string sourceStack = grid[i];
        for (int j = 0; j < grid.size(); j++) {
            if (i == j)
                continue;
            string destinationStack = grid[j];
            if (isValidMove(sourceStack,
                            destinationStack,
                            stackHeight)) {
 
                // Creating a new Grid
                // with the valid move
                Grid newGrid(grid);
 
                // Adding the ball
                newGrid[j].push_back(newGrid[i].back());
 
                // Adding the ball
                newGrid[i].pop_back();
                if (isSolved(newGrid, stackHeight)) {
                    answerMod.push_back(
                        vector<int>{ i, j, 1 });
                    return true;
                }
                if (visited.find(
                        canonicalStringConversion(newGrid))
                    == visited.end()) {
                    bool solveForTheRest
                        = solvePuzzle(newGrid, stackHeight,
                                      visited, answerMod);
                    if (solveForTheRest) {
                        vector<int> lastMove
                            = answerMod[answerMod.size()
                                        - 1];
 
                        // Optimisation - Concatenating
                        // consecutive moves of the same
                        // ball
                        if (lastMove[0] == i
                            && lastMove[1] == j)
                            answerMod[answerMod.size() - 1]
                                     [2]++;
                        else
                            answerMod.push_back(
                                vector<int>{ i, j, 1 });
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
 
// Checks whether the grid is valid or not
bool checkGrid(Grid grid)
{
 
    int numberOfStacks = grid.size();
    int stackHeight = getStackHeight(grid);
    int numBallsExpected
        = ((numberOfStacks - 2) * stackHeight);
    // Cause 2 empty stacks
    int numBalls = 0;
 
    for (auto i : grid)
        numBalls += i.size();
    if (numBalls != numBallsExpected) {
        cout << "Grid has incorrect # of balls"
             << endl;
        return false;
    }
    map<char, int> ballColorFrequency;
    for (auto stack : grid)
        for (auto ball : stack)
            if (ballColorFrequency.find(ball)
                != ballColorFrequency.end())
                ballColorFrequency[ball] += 1;
            else
                ballColorFrequency[ball] = 1;
    for (auto ballColor : ballColorFrequency) {
        if (ballColor.second != getStackHeight(grid)) {
            cout << "Color " << ballColor.first
                 << " is not " << getStackHeight(grid)
                 << endl;
            return false;
        }
    }
    return true;
}
 
// Driver Code
signed main(void)
{
 
    // Including 2 empty stacks
    int numberOfStacks = 6;
    std::string stacks[]
        = { "gbbb", "ybry", "yggy", "rrrg", "", "" };
 
    Grid grid = configureGrid(
        stacks, numberOfStacks);
    if (!checkGrid(grid)) {
        cout << "Invalid Grid" << endl;
        return 1;
    }
    if (isSolved(grid, getStackHeight(grid))) {
        cout << "Problem is already solved"
             << endl;
        return 0;
    }
    unordered_set<string> visited;
    vector<vector<int> > answerMod;
 
    // Solve the puzzle instance
    solvePuzzle(grid, getStackHeight(grid),
                visited,
                answerMod);
 
    // Since the values of Answers are appended
    // When the problem was completely
    // solved and backwards from there
    reverse(answerMod.begin(), answerMod.end());
 
    for (auto v : answerMod) {
        cout << "Move " << v[0] + 1
             << " to " << v[1] + 1
             << " " << v[2] << " times"
             << endl;
    }
    return 0;
}