#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness_c.h>

/* Required for each C test group*/
TEST_GROUP_C_WRAPPER(MyGroupC){
  TEST_GROUP_C_SETUP_WRAPPER(MyGroupC);
  TEST_GROUP_C_TEARDOWN_WRAPPER(MyGroupC);
};

TEST_C_WRAPPER(MyGroupC, TestMyFunction);
TEST_C_WRAPPER(MyGroupC, SecondTest);

TEST_GROUP_C_WRAPPER(MyMockGroup){
  TEST_GROUP_C_SETUP_WRAPPER(MyMockGroup);
  TEST_GROUP_C_TEARDOWN_WRAPPER(MyMockGroup);
};

TEST_C_WRAPPER(MyMockGroup, TestIORead);
TEST_C_WRAPPER(MyMockGroup, TestIOWrite);

int main(int ac, char** av)
{
    return RUN_ALL_TESTS(ac, av);
}