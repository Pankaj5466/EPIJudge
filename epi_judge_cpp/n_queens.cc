#include <algorithm>
#include <iterator>
#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

bool isValid(const vector<int> &col_placement) 
{
    int row_id = col_placement.size() - 1;

    for (int i = 0; i < row_id; i++)
    {
        int diff = abs(col_placement[i] - col_placement[row_id]);
        if (diff == 0 || diff == row_id - i)
            return false;
    }
    return true;
}

void NQueenDirect(int n, int row, vector<int>& col_placement, vector<vector<int>>& ans)
{
    if (row == n)
    {
        printf("One placement has been found\n");
        ans.push_back(col_placement);
    }

    for (int col = 0; col < n; col++)
    {
        col_placement.push_back(col);
        if (isValid(col_placement) == true)
        {
            NQueenDirect(n, row+1, col_placement, ans);
        }
        col_placement.pop_back();
    }
}

vector<vector<int>> NQueens(int n) {
  // TODO - you fill in here.
    vector<vector<int>> ans;

    NQueenDirect(n,0,vector<int>(),ans);

    return ans;
 
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "n_queens.cc", "n_queens.tsv", &NQueens,
                         UnorderedComparator{}, param_names);
}
