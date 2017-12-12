#include <cstdio>
#include <cstdlib>
#include <clang-c/Index.h>
#include <boost/filesystem.hpp>
#include <iostream>
#include "mstch/mstch.hpp"

std::ostream& operator<<(std::ostream& stream, const CXString& str)
{
	stream << clang_getCString(str);
	clang_disposeString(str);
	return stream;
}

CXChildVisitResult visitChild(CXCursor c, CXCursor parent, CXClientData client_data){
	using namespace std;
	cout << "Cursor '" << clang_getCursorSpelling(c) << "' of kind '"
		<< clang_getCursorKindSpelling(clang_getCursorKind(c)) << "'\n";
	return CXChildVisit_Recurse;

}

int main(int argc, const char **argv) {

	/*
	std::string view{"{{#names}}Hi {{name}}!\n{{/names}}"};
	mstch::map context{
		{"names", mstch::array{
				  mstch::map{{"name", std::string{"Chris"}}},
				  mstch::map{{"name", std::string{"Mark"}}},
				  mstch::map{{"name", std::string{"Scott"}}},
				  }}
	};

	//std::cout << mstch::render(view, context) << std::endl;
	*/
	CXString version = clang_getClangVersion();
	printf("%s\n", clang_getCString(version));
	clang_disposeString(version);

	boost::filesystem::path path = boost::filesystem::canonical("../../terrian_prototype/build/compile_commands.json");
	printf("Full path: %S\nExists: %d\n", path.c_str(), 
			boost::filesystem::exists(path));
	//std::cout << path << std::endl;

	CXIndex index = clang_createIndex(1, 1);

	CXTranslationUnit unit = clang_parseTranslationUnit(
			index,
			"header.hpp", nullptr, 0,
			nullptr, 0,
			CXTranslationUnit_None);
	if(unit == nullptr){
		fprintf(stderr, "Unable to parse translation unit\n");
		exit(-1);
	}
	CXCursor cursor = clang_getTranslationUnitCursor(unit);
	clang_visitChildren(
			cursor,
			visitChild,
			nullptr);
	
	clang_disposeTranslationUnit(unit);
	clang_disposeIndex(index);
	    
	return 0;
}
