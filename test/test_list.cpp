#include "../src/dirstat.hpp"
#include "gtest/gtest.h"

TEST(Test, EmptyFiles)
{
    fs::create_directories("./SimpleTest/EmptyFiles");
    std::string user_input = fs::current_path().c_str();
    user_input += "/SimpleTest/EmptyFiles/";

    size_t count = 10;

    for(size_t i = 0; i < count; ++i){
        std::ofstream { user_input + "test_file" + std::to_string(i) + ".txt" };
    }

    Application simpleTest(user_input);
    simpleTest.start();

    EXPECT_EQ(simpleTest.getFiles().size(), count);
    EXPECT_EQ(simpleTest.getAll_lines(), 0);
    EXPECT_EQ(simpleTest.getEmpty_lines(), 0);
    EXPECT_EQ(simpleTest.getWords(), 0);

    fs::remove_all("SimpleTests");
}

TEST(SimpleTest, EmptyDirectoy)
{
    fs::create_directories("./SimpleTest/EmptyDirectory");
    std::string user_input = fs::current_path().c_str();
    user_input += "/SimpleTest/EmptyDirectory/";

    Application simpleTest(user_input);
    simpleTest.start();

    EXPECT_EQ(simpleTest.getFiles().size(), 0);
    EXPECT_EQ(simpleTest.getAll_lines(), 0);
    EXPECT_EQ(simpleTest.getEmpty_lines(), 0);
    EXPECT_EQ(simpleTest.getWords(), 0);   

    fs::remove_all("SimpleTest");
}

TEST(SimpleTest, FewLines)
{
    fs::create_directories("./SimpleTest/FewLines");
    std::string user_input = fs::current_path().c_str();
    user_input += "/SimpleTest/FewLines/";

    size_t count = 10;
    int total = 0;
    int words = 0;

    for(size_t i = 0; i < count; ++i)
    {
        std::ofstream test_file { user_input + "test_file" + std::to_string(i) + ".txt" };
        test_file << "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n";
        test_file << "Quisque imperdiet posuere ligula, vel tincidunt neque venenatis vitae.\n";
        test_file << "Duis laoreet risus in nisl luctus efficitur. \n";
        test_file << "\n";
        test_file << "Sed luctus quam a dui dignissim mattis.\n";
        total += 5;
        words += 31;
    }

    Application simpleTest(user_input);
    simpleTest.start();

    EXPECT_EQ(simpleTest.getFiles().size(), count);
    EXPECT_EQ(simpleTest.getAll_lines(), total);
    EXPECT_EQ(simpleTest.getEmpty_lines(), total / 5);
    EXPECT_EQ(simpleTest.getWords(), words);

    fs::remove_all("SimpleTest");
}

TEST(SimpleTest, LargeNumberOfLines)
{
    fs::create_directories("./SimpleTest/LargeNumberOfLines");
    std::string user_input = fs::current_path().c_str();
    user_input += "/SimpleTest/LargeNumberOfLines/";

    size_t count = 10;
    int total = 0;
    int words = 0;

    for(size_t i = 0; i < count; ++i){
        std::ofstream test_file { user_input + "test_file" + std::to_string(i) + ".txt" };
        for(size_t j = 0; j < count * 2; ++j)
        {
        test_file << "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n";
        test_file << "Quisque imperdiet posuere ligula, vel tincidunt neque venenatis vitae.\n";
        test_file << "Duis laoreet risus in nisl luctus efficitur. \n";
        test_file << "\n";
        test_file << "Sed luctus quam a dui dignissim mattis.\n";
        total += 5;
        words += 31;
        }
    }

    Application simpleTest(user_input);
    simpleTest.start();

    EXPECT_EQ(simpleTest.getFiles().size(), count);
    EXPECT_EQ(simpleTest.getAll_lines(), total);
    EXPECT_EQ(simpleTest.getEmpty_lines(), total /5);
    EXPECT_EQ(simpleTest.getWords(), words);

    fs::remove_all("SimpleTest");
}

TEST(Test, Large)
{
    fs::create_directories("./SimpleTest/LargeNumberOfLines");
    std::string user_input = fs::current_path().c_str();
    user_input += "/SimpleTest/LargeNumberOfLines/";

    size_t count = 10;
    int total = 0;
    int words = 0;

    for(size_t i = 0; i < count; ++i){
        std::ofstream test_file { user_input + "test_file" + std::to_string(i) + ".txt" };
        for(size_t j = 0; j < count * 2; ++j)
        {
        test_file << "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n";
        test_file << "Quisque imperdiet posuere ligula, vel tincidunt neque venenatis vitae.\n";
        test_file << "Duis laoreet risus in nisl luctus efficitur. \n";
        test_file << "\n";
        test_file << "Sed luctus quam a dui dignissim mattis.\n";
        total += 5;
        words += 31;
        }
    }

    Application simpleTest(user_input);
    simpleTest.start();

    EXPECT_EQ(simpleTest.getFiles().size(), count);
    EXPECT_EQ(simpleTest.getAll_lines(), total);
    EXPECT_EQ(simpleTest.getEmpty_lines(), total / 5);
    EXPECT_EQ(simpleTest.getWords(), words);

    fs::remove_all("SimpleTest");
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}