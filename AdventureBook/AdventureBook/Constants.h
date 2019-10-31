#pragma once

#include <string>

using namespace std;


static string PAGES_DIR = "E:/Cassini/cpp-cassini/AdventureBook/pages";
const string END_MESSAGE = "THE END";


enum class Error {
	ERR_INDEX_OUT_OF_BOUNDS,
	ERR_FILE_READ
};

