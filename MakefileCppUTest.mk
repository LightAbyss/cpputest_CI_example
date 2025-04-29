#Dir to cpp repo
CPPUTEST_HOME = ~/tools/cpputest

TEST_DIR = test/

TEST_TARGET = $(TEST_DIR)/test_sw

#CPPUTEST flags and variables
CPPUTEST_EXE_FLAGS= -c -v

CPPUTEST_USE_MEM_LEAK_DETECTION=Y

CPPUTEST_CXXFLAGS = -std=c++14

CPPUTEST_LDFLAGS = -lpthread

CPPUTEST_USE_EXTENSIONS = Y

SRC_DIRS = src \

MOCKS_SRC_DIRS = $(TEST_DIR)/mocks \

TEST_SRC_DIRS = $(TEST_DIR) \

INCLUDE_DIRS = \
	src/include \
$(CPPUTEST_HOME)/include

CPPUTEST_OBJS_DIR=$(TEST_DIR)/build/
CPPUTEST_LIB_DIR=$(TEST_DIR)/lib

include $(CPPUTEST_HOME)/build/MakefileWorker.mk