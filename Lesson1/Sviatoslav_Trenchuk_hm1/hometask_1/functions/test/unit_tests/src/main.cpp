#include "vec_test.h"
#include "magicNumber_test.h"
#include "listReverse_test.h"

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

