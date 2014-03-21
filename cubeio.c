#pragma systemFile

//#include "/states/RpUpLpFpD2Rp.c"
//#include "/states/solved.c"
#include "/states/R2UpFpUpF2RpURpUp.c"
// a temperary store place so that we do not re read location
int up_tmp[2][2];
int down_tmp[2][2];
int lefty_tmp[2][2];
int right_tmp[2][2];
int front_tmp[2][2];
int back_tmp[2][2];



TFileHandle   hFileHandle;              // will keep track of our file
  TFileIOResult nIOResult;                // will store our IO results
  string        sFileName = "Output.txt";   // the name of our file
  int           nFileSize = 500;          // will store our file size
  char CR = 0x13;   // define CR (carriage return)
  char LF = 0x10;   // define LF (line feed)

  string        sMessageToWrite = "ROBOTC IO test!			";    // we will write this to the file
  string        sMesageToWrite_2 = "A new line!";       // we will also write this to the file on the next line
  string        incomingString[5];                     // this will store the final, fully-read strings (with new strings getting put into new indexes



// writes to a temperary place to prevent errors
void store() {
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			up_tmp[i][j] = up[i][j];
	}}

	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			down_tmp[i][j] = down[i][j];
	}}
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			lefty_tmp[i][j] = lefty[i][j];
	}}
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			right_tmp[i][j] = righty[i][j];
	}}
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			front_tmp[i][j] = front[i][j];
	}}
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			back_tmp[i][j] = back[i][j];
	}}
}
// variable used to indicate direction of rotation
//prime means a turn in ccw direction, or 3 turns in the cw direction
int prime = 3;


void Y() {
	WriteText(hFileHandle, nIOResult, "Y ");
	store();
	righty[0][0] = right_tmp[1][0];
	righty[0][1] = right_tmp[0][0];
	righty[1][0] = right_tmp[1][1];
	righty[1][1] = right_tmp[0][1];

	lefty[0][0] = lefty_tmp[0][1];
	lefty[0][1] = lefty_tmp[1][1];
	lefty[1][0] = lefty_tmp[0][0];
	lefty[1][1] = lefty_tmp[1][0];

	back[0][0] = up_tmp[1][1];
	back[0][1] = up_tmp[1][0];
	back[1][0] = up_tmp[0][1];
	back[1][1] = up_tmp[0][0];

	down[0][0] = back_tmp[1][1];
	down[0][1] = back_tmp[1][0];
	down[1][0] = back_tmp[0][1];
	down[1][1] = back_tmp[0][0];

	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			front[i][j] = down_tmp[i][j];
	}}

	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			up[i][j] = front_tmp[i][j];
	}}


}
void Y(int rot) {
	if(rot == 2) {
		Y(); Y();
	}
	if(rot == prime) {
		Y(); Y(); Y();
	}
}

void X() {
	WriteText(hFileHandle, nIOResult, "X ");
	store();

	up[0][0] = up_tmp[0][1];
	up[0][1] = up_tmp[1][1];
	up[1][0] = up_tmp[0][0];
	up[1][1] = up_tmp[1][0];


	down[0][0] = down_tmp[1][0];
	down[0][1] = down_tmp[0][0];
	down[1][0] = down_tmp[1][1];
	down[1][1] = down_tmp[0][1];

	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			front[i][j] = lefty_tmp[i][j];
	}}
		for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			lefty[i][j] = back_tmp[i][j];
	}}
		for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			back[i][j] = right_tmp[i][j];
	}}
		for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			righty[i][j] = front_tmp[i][j];
	}}
	front = lefty_tmp;
	lefty  = back_tmp;
	back  = right_tmp;
	righty = front_tmp;

}

void X(int rot) {
	if(rot == 2) {
		X(); X();
	}
	if(rot == prime) {
		X(); X(); X();
	}
}


void Z() {
		WriteText(hFileHandle, nIOResult, "Z: ");
	X(); Y(); X(prime);
}

void Z(int rot) {
	if(rot == 2) {
		X(prime); Y(2); X();
	}
	if(rot == prime){
		X(); Y(); X(prime);
	}
}

////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////




// results in a clockwise turn of the up face
void U() {
		WriteText(hFileHandle, nIOResult, "U ");
	store();
	up[0][0] = up_tmp[1][0];
	up[0][1] = up_tmp[0][0];
	up[1][0] = up_tmp[1][1];
	up[1][1] = up_tmp[0][1];

	front[0][0] = right_tmp[0][0];
	front[0][1] = right_tmp[0][1];

	lefty[0][0] =front_tmp[0][0];
	lefty[0][1] =front_tmp[0][1];

	back[0][0] =lefty_tmp[0][0];
	back[0][1] =lefty_tmp[0][1];

	righty[0][0] =back_tmp[0][0];
	righty[0][1] =back_tmp[0][1];
}

void U(int rot) {
	if(rot == 2) {
		U(); U();
	}
	if(rot == prime) {
		U(); U(); U();
	}
}

void R() {
		WriteText(hFileHandle, nIOResult, "R ");
	store();
	righty[0][0] = right_tmp[1][0];
	righty[0][1] = right_tmp[0][0];
	righty[1][0] = right_tmp[1][1];
	righty[1][1] = right_tmp[0][1];

	front[0][1] = down_tmp[0][1];
	front[1][1] = down_tmp[1][1];

	down[0][1] =back_tmp[1][0];
	down[1][1] =back_tmp[0][0];

	back[0][0] =up_tmp[1][1];
	back[1][0] =up_tmp[0][1];

	up[0][1] =front_tmp[0][1];
	up[1][1] =front_tmp[1][1];
}
void R(int rot) {
	if(rot == 2) {
		R(); R();
	}
	if(rot == prime) {
		R(); R(); R();
	}
}
void F() {
		WriteText(hFileHandle, nIOResult, "F ");
	store();
	front[0][0] = front_tmp[1][0];
	front[0][1] = front_tmp[0][0];
	front[1][0] = front_tmp[1][1];
	front[1][1] = front_tmp[0][1];

	up[1][0] = lefty_tmp[1][1];
	up[1][1] = lefty_tmp[0][1];

	down[0][1] =right_tmp[0][0];
	down[0][0] =right_tmp[1][0];

	lefty[0][1] =down_tmp[0][0];
	lefty[1][1] =down_tmp[0][1];

	righty[0][0] =up_tmp[1][0];
	righty[1][0] =up_tmp[1][1];
}

void F(int rot) {
	if(rot == 2) {
		F(); F();
	}
	if(rot == prime) {
		F(); F(); F();
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void D() {
		WriteText(hFileHandle, nIOResult, "D ");
	U(); // turns the top layer
	X(); // then rotates the cube so it is as if the down face was turned
}
void D(int rot) {
	if(rot == 2) {
		D(); D();
	}
	if(rot == prime) {
		D(); D(); D();
	}
}

void L() {
		WriteText(hFileHandle, nIOResult, "L ");
	R(); // turns the right layer
	Y(prime); // then rotates the cube so it is as if the lefty face was turned
}
void L(int rot) {
	if(rot == 2) {
		R(); R();
	}
	if(rot == prime) {
		R(); R(); R();
	}
}


void B() {
		WriteText(hFileHandle, nIOResult, "B ");
	F(); // turns the FRONT layer
	X(prime);
	Y(); //
	X();
}
void B(int rot) {
	if(rot == 2) {
		F(); F();
	}
	if(rot == prime) {
		F(); F(); F();
	}
}

int cube[2][12] = {					// order: Up, Front, righty, Back, lefty, Down
	{ up[0][0],up[0][1],	front[0][0],front[0][1],	righty[0][0],righty[0][1],	back[0][0],back[0][1],	lefty[0][0],lefty[0][1],	 down[1][0],down[0][0]},
	{ up[1][0],up[1][1],	front[1][0],front[1][1],	righty[1][0],righty[1][1],	back[1][0],back[1][1],	lefty[1][0],lefty[1][1],	 down[1][1],down[0][1]}} ;



void updateCube() {

int tmpcube[2][12] = {					// order: Up, Front, righty, Back, lefty, Down
	{ up[0][0],up[0][1],	front[0][0],front[0][1],	righty[0][0],righty[0][1],	back[0][0],back[0][1],	lefty[0][0],lefty[0][1],	 down[1][0],down[0][0]},
	{ up[1][0],up[1][1],	front[1][0],front[1][1],	righty[1][0],righty[1][1],	back[1][0],back[1][1],	lefty[1][0],lefty[1][1],	 down[1][1],down[0][1]}} ;
//int tmpcube[2][12] = {					// order: Up, Front, righty, Back, lefty, Down
//	{ 1,2,3,4,5,6,7,8,9,0,1,2},
//	{  1,2,3,4,5,6,7,8,9,0,1,2}} ;

	for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 12; j++) {
       cube[i][j] = tmpcube[i][j];
    }}
  }
