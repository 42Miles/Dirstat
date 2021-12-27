#include "../src/dirstat.hpp"
#include "gtest/gtest.h"

TEST(ApplicationTest, EmptyFiles)
{
    fs::create_directories("./SimpleTest/test");
    std::string user_input = fs::current_path().c_str();
    user_input += "/SimpleTest/test/";

    size_t count = 10;

    for(size_t i = 0; i < count; ++i){
        std::ofstream { user_input + "test_file" + std::to_string(i) + ".txt" };
    }

    Application simpleTest(user_input);
    simpleTest.getDir();
    simpleTest.checkDirectory();
    simpleTest.getDirFiles();

    EXPECT_EQ(simpleTest.files.size(), count);

    fs::remove_all("SimpleTest");
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}