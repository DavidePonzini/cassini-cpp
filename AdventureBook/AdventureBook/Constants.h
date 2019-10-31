#pragma once

#include <string>

using namespace std;


const string PAGES_DIR = "../../pages";
const string END_MESSAGE = "THE END";


enum class Error {
	ERR_INDEX_OUT_OF_BOUNDS,
	ERR_FILE_READ
};

