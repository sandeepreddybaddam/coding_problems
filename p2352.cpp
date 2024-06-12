// EQUAL ROW AND COLUMN PAIRS

#include <iostream>
#include <vector>

using namespace std;

void PrintGrid(vector<vector<int>>& grid) {
    for (auto& row : grid) {
        for (auto& element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

vector<vector<int>> GetTranspose(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> grid_transpose;

    for(int j=0; j < cols; j++) {
        vector<int> col_elements;
        for (int i=0; i<rows; i++) {
            col_elements.push_back(grid[i][j]);
        }
        grid_transpose.push_back(col_elements);
    }
    return grid_transpose;
}

int equalPairs(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<int>> grid_transpose = GetTranspose(grid);
    int result = 0;

    for (int i = 0; i < rows; i++) {
        const auto& row_elements = grid[i];
        for (int j = 0; j < cols; j++) {
            const auto& col_elements = grid_transpose[j];
            
            if(row_elements == col_elements) result++;
        }
    }
    return result;
}

int main() {
    vector<vector<int>> grid{{3,2,1},{1,7,6},{2,7,7}};
    std::cout << equalPairs(grid) << std::endl;
}