/*
  @file request_srcml_t.cpp

  Test program for request_srcml()
*/

#include "request_srcml.hpp"
#include <cassert>

int main() {

	// all filenames and languages empty
    {
	//make sure empty request works
    	srcml_request request = { "", "", "", ""};
    	assert(request_filename(request) == "");
    	assert(request_language(request, "") == "");
	
	//make sure the filename is correct from a request
	srcml_request request2 = {"", "file", "", ""};
    	assert(request_filename(request2) == "file");
    }

    return 0;
}
