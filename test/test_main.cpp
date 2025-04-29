#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

extern "C"
{
  #include "../src/include/functions.h"
  #include "../src/include/extra_fun.h"
  #include "../src/include/io.h"
  #include "stdlib.h"
}

TEST_GROUP(MyTestGroup)
{
    void setup()
    {
        // This function is called before each test
    }

    void teardown()
    {
        // This function is called after each test
        mock().checkExpectations();
        mock().clear();
    }
};

TEST(MyTestGroup, TestMyFunction)
{
    // Arrange
    int a = 5;
    int b = 10;
    int expected_result = 15;

    // Act
    int result = my_fun(a, b);

    // Assert
    CHECK_EQUAL(expected_result, result);
}

TEST(MyTestGroup, SecondTest)
{
    // Arrange
    int a = 8;
    int b = 10;
    int expected_result = 10;

    // Act
    int result = my_fun(a, b);

    // Assert
    CHECK_COMPARE(result, >, expected_result);
}

TEST(MyTestGroup, TestComplexFunction)
{
  mock().expectOneCall("other_fun")
        .withParameter("a", 5)
        .andReturnValue(6);        
  // Arrange
  int a = 5;
  int expected_result = 6;

  // Act
  int result = complex_fun(a);

  // Assert
  CHECK_EQUAL(expected_result, result);
};

TEST_GROUP(MyMockGroup)
{
    void setup()
    {
        // This function is called before each test
    }

    void teardown()
    {
        // This function is called after each test
        mock().checkExpectations();
        mock().clear();
    }
};

IOdata_t IOread(IOaddrs_t addr)
{
    mock().actualCall("IOread").withParameter("addr", addr);
    return mock().unsignedIntReturnValue();
}

void IOwrite(IOaddrs_t addr, IOdata_t data)
{
    mock().actualCall("IOwrite")
            .withParameter("addr", addr)
            .withParameter("data", data);
}


TEST(MyMockGroup, TestIORead)
{
    // Arrange
    IOdata_t expected_data = 42;
    
    mock().expectOneCall("IOread")
          .withParameter("addr", 0x0001)
          .andReturnValue(expected_data);

    // Act
    IOdata_t result = IOread(0x0001);

    // Assert
    UNSIGNED_LONGS_EQUAL(expected_data, result);
}

TEST(MyMockGroup, TestIOWrite)
{
    // Arrange
    IOdata_t data_to_write = 42;
    
    mock().expectOneCall("IOwrite")
          .withParameter("addr", 0x0001)
          .withParameter("data", data_to_write);

    // Act
    IOwrite(0x0001, data_to_write);
}