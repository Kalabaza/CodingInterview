#include <gtest/gtest.h>

// Entry point of the application, will run all the tests of the project
int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}