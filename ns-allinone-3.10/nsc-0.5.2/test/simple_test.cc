#include "simple_test.h"
#include <list>
#include <string>
#include <iostream>

// Generally better to avoid C++ objects at the top level, but we'll make an 
// exception this time...
std::list<ST_TestInfo> global_test_list;

void ST_RegisterTest(const char* name, void (*func)(ST_TestInfo*)) {
  ST_TestInfo info;
  info.name = name;
  info.func = func;
  global_test_list.push_back(info);
}

int ST_RunTests() {
  std::list<ST_TestInfo>::iterator i = global_test_list.begin();
  int passed = 0;
  int failed = 0;
  for (; i != global_test_list.end(); ++i) {
    std::cerr << "TEST: " << i->name << " ... ";
    i->func(&*i);
    if (i->failed != 0) {
      std::cerr << "FAIL" << std::endl;
      if (!i->fail_string.empty()) {
        // This will already have end lines in it.
        std::cerr << i->fail_string;
      }
      failed++;
    } else {
      std::cerr << "PASS" << std::endl;
      passed++;
    }
  }

  // 0 failed means we return 0, which is "success" as this should be returned
  // from the main function.
  return failed;
}
