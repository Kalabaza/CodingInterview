#include <gtest/gtest.h>

// 1.7 Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
// column are set to 0.

// The matrix used on the problem will be MxN.
#define M 5
#define N 4

void MarkMatrix(int matrix[M][N])
{
    bool rows[M]{};
    bool cols[N]{};

    // First find the zeros in the original matrix.
    for (auto i = 0; i < M; ++i)
    {
        for (auto j = 0; j < N; ++j)
        {
            // Mark the row and column positions.
            if (matrix[i][j] == 0)
            {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }

    // Now use the arrays to mark the original matrix.
    for (auto i = 0; i < M; ++i)
    {
        for (auto j = 0; j < N; ++j)
        {
            if (rows[i] || cols[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}

TEST(Question_1_7, MarkMatrix)
{
    int matrix[M][N]{ { 5, 8, 0, 1 }, { 2, 0, 9, 4 }, { 3, 2, 9, 4 }, { 0, 2, 8, 7 }, { 6, 2, 9, 1 } };
    MarkMatrix(matrix);
    int expected[M][N]{ { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 4 }, { 0, 0, 0, 0 }, { 0, 0, 0, 1 } };
    for (auto i = 0; i < M; ++i)
        for (auto j = 0; j < N; ++j)
            ASSERT_EQ(matrix[i][j], expected[i][j]);
}
