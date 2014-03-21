#include "cubeio.c"
void prepareWrite();

task main() {
	prepareWrite();
	R();
	Z();
	D();
 Close(hFileHandle, nIOResult);                              // close the file (DON'T FORGET THIS STEP!)
}


void prepareWrite() {


  Delete("Output.txt",nIOResult);
   OpenWrite(hFileHandle, nIOResult, sFileName, nFileSize);    // open the file for writing (creates the file if it does not exist)

}
