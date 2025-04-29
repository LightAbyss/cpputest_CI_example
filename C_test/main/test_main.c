#include "include/io.h"
#include "include/functions.h"
#include <CppUTest/TestHarness_c.h>
#include <CppUTestExt/MockSupport_c.h>

//previous funcs to be executed
TEST_GROUP_C_SETUP(MyGroupC){

}

TEST_GROUP_C_TEARDOWN(MyGroupC){
  mock_c()->checkExpectations();
  mock_c()->clear();
}

TEST_C(MyGroupC, TestMyFunction){
  // Arrange
  int a = 5;
  int b = 10;
  int expected_result = 15;

  // Act
  int result = my_fun(a, b);

  // Assert
  CHECK_EQUAL_C_INT(expected_result, result);
}

TEST_C(MyGroupC, SecondTest){
  // Arrange
  int a = 8;
  int b = 10;
  int expected_result = 10;

  // Act
  int result = my_fun(a, b);

  // Assert
  CHECK_C(result > expected_result);
}

/***** Second group *****/
TEST_GROUP_C_SETUP(MyMockGroup){

}

TEST_GROUP_C_TEARDOWN(MyMockGroup){
  mock_c()->checkExpectations();
  mock_c()->clear();
}

IOdata_t IOread(IOaddrs_t addr){
  mock_c()->actualCall("IOread")
          ->withParameterOfType("IOaddrs_t", "addr", (void*)&addr);
      
  return mock_c()->unsignedIntReturnValue();
}

void IOwrite(IOaddrs_t addr, IOdata_t data){
  mock_c()->actualCall("IOwrite")
          ->withUnsignedIntParameters("addr", addr)
          ->withUnsignedIntParameters("data", data);
}

TEST_C(MyMockGroup, TestIORead){
  // Arrange
  IOdata_t expected_data = 42;
  IOaddrs_t addr = 0x0001;
  //mock_c()->installComparator("IOaddrs_t", mock_c()->getUnsignedIntComparator(), sizeof(IOaddrs_t));
  mock_c()->expectOneCall("IOread")
          ->withParameterOfType("IOaddrs_t", "addr", (void*)&addr)
          ->andReturnUnsignedIntValue(expected_data);

  // Act
  IOdata_t result = IOread(0x0001);

  // Assert
  CHECK_EQUAL_C_UINT(expected_data, result);
}

TEST_C(MyMockGroup, TestIOWrite){
  IOdata_t data_to_write = 42;
  mock_c()->expectOneCall("IOwrite")
          ->withUnsignedIntParameters("addr", 0x0001)
          ->withUnsignedIntParameters("data", data_to_write);


  IOwrite(0x0001, data_to_write);

}