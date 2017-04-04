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
    }
	
    {   
        //make sure the local_filename is correct from a request
	srcml_request request2 = {"", "file", "data", ""};
    	assert(request_filename(request2) == "file");
    }

    {   
        //make sure the option_filename supersedes everything
        srcml_request request3 = {"file", "", "", ""};
    	assert(request_filename(request3) == "file");
    }
        
    {   
        //Make sure that the entry_filename works for filename
        srcml_request request4 = {"", "", "file", ""};
    	assert(request_filename(request4) == "file");
    }

    {
        //make sure that 
        srcml_request request4 = {"", "", "file.cpp", "C++"};
    	assert(request_filename(request4) == "file.cpp");
        assert(request_language(request4, "") == "C++");
    }

    return 0;
}
