#include <gtest/gtest.h>

// 1.6 Given an image represented by an NxN matrix, where each pixel in the image is 4
// bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

// The matrix used on the problem will be NxN (squared matrix).
#define N 4

// TODO: Understand a little bit more of this solution :(
void RotateMatrix(int matrix[N][N])
{
    for (auto layer = 0; layer < N / 2; ++layer)
    {
        auto first = layer;
        auto last = N - 1 - layer;
        for (auto i = first; i < last; ++i)
        {
            auto offset = i - first;

            // Save the top value of the matrix, this will be assigned at the end.
            auto top = matrix[first][i];

            // Move the left value to the top.
            matrix[first][i] = matrix[last - offset][first];

            // Move the bottom value to the left.
            matrix[last - offset][first] = matrix[last][last - offset];

            // Move the right value to the bottom.
            matrix[last][last - offset] = matrix[i][last];

            // Copy the top value saved before to the right.
            matrix[i][last] = top;
        }
    }
}

// Rotation of matrix
TEST(Question_1_6, RotateMatrix90Degrees)
{
    int matrix[N][N]{ {1, 2, 3, 4}, {5, 6, 7, 8}, { 9, 10, 11, 12 }, { 13, 14, 15, 16} };
    RotateMatrix(matrix);
    int expected[N][N]{ { 13, 9, 5, 1 },{ 14, 10, 6, 2 },{ 15, 11, 7, 3 },{ 16, 12, 8, 4 } };
    for (auto i = 0; i < N; ++i)
        for (auto j = 0; j < N; ++j)
            ASSERT_EQ(matrix[i][j], expected[i][j]);
}

// Rotation of matrix
TEST(Question_1_6, RotateMatrix360Degrees)
{
    int matrix[N][N]{ { 1, 2, 3, 4 },{ 5, 6, 7, 8 },{ 9, 10, 11, 12 },{ 13, 14, 15, 16 } };
    RotateMatrix(matrix);
    RotateMatrix(matrix);
    RotateMatrix(matrix);
    RotateMatrix(matrix);
    int expected[N][N]{ { 1, 2, 3, 4 },{ 5, 6, 7, 8 },{ 9, 10, 11, 12 },{ 13, 14, 15, 16 } };
    for (auto i = 0; i < N; ++i)
        for (auto j = 0; j < N; ++j)
            ASSERT_EQ(matrix[i][j], expected[i][j]);
}
