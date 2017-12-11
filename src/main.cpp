#include <cstdio>
#include <cstdlib>
#include <clang-c/Index.h>
#include <iostream>
#include "mstch/mstch.hpp"

int main(int argc, const char **argv) {

	std::string view{"{{#names}}Hi {{name}}!\n{{/names}}"};
	mstch::map context{
		{"names", mstch::array{
				  mstch::map{{"name", std::string{"Chris"}}},
				  mstch::map{{"name", std::string{"Mark"}}},
				  mstch::map{{"name", std::string{"Scott"}}},
				  }}
	};

	//std::cout << mstch::render(view, context) << std::endl;
	CXString version = clang_getClangVersion();
	printf("%s\n", clang_getCString(version));
	clang_disposeString(version);

	CXIndex index = clang_createIndex(1, 1);
	
	clang_disposeIndex(index);
	    
  return 0;
}
