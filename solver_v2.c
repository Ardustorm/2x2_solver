#include "cubeio.c"
#include "write.c"
#include "Def.c"

typedef struct{
	int a;	// color pair 1
	int b;	// color pair 2
	int c;	// coror pair 3
	//	int d;	// keeps track of diagonals
	int dominant;
	int max;
}side;

side up_bar;
side down_bar;
side lefty_bar;
side righty_bar;
side front_bar;
side back_bar;
//cn stands for color neutral
int up_cn[2][2];
int down_cn[2][2];
int lefty_cn[2][2];
int righty_cn[2][2];
int front_cn[2][2];
int back_cn[2][2];

// combines opposite colors into 1, so that there are only 3 colors on the cube so to speak
//since robotc just chops off decimals, 3/2 = 1 etc.
void combineColors() {
	WriteText(hFileHandle, nIOResult, "_CombineColors_ ");
	for(int a = 0; a < 2; a++) {
		for(int b = 0; b < 2; b++) {
			up_cn[a][b]   = up[a][b]/2;
			down_cn[a][b] = down[a][b]/2;
			lefty_cn[a][b] = lefty[a][b]/2;
			righty_cn[a][b] = righty[a][b]/2;
			front_cn[a][b] = front[a][b]/2;
			back_cn[a][b] = back[a][b]/2;
	}}
}
void barTest() {
	WriteText(hFileHandle, nIOResult, "_barTest_");
	for(int a=0;a<2;a++) {
		//UP
		if(up_cn[a][0] == up_cn[a][1]) {	//checks for horizontal bars
			switch(up_cn[a][0]){
			case 0:	up_bar.a++;	break;
			case 1:	up_bar.b++;	break;
			case 2:	up_bar.c++;	break;
		}}
		if(up_cn[0][a] == up_cn[1][a]) {	//checks for vertical bars
			switch(up_cn[0][a]){
			case 0:	up_bar.a++;	break;
			case 1:	up_bar.b++;	break;
			case 2:	up_bar.c++;	break;
		}}
		//down
		if(down_cn[a][0] == down_cn[a][1]) {	//checks for horizontal bars
			switch(down_cn[a][0]){
			case 0:	down_bar.a++;	break;
			case 1:	down_bar.b++;	break;
			case 2:	down_bar.c++;	break;
		}}
		if(down_cn[0][a] == down_cn[1][a]) {	//checks for vertical bars
			switch(down_cn[0][a]){
			case 0:	down_bar.a++;	break;
			case 1:	down_bar.b++;	break;
			case 2:	down_bar.c++;	break;
		}}
		//lefty
		if(lefty_cn[a][0] == lefty_cn[a][1]) {	//checks for horizontal bars
			switch(lefty_cn[a][0]){
			case 0:	lefty_bar.a++;	break;
			case 1:	lefty_bar.b++;	break;
			case 2:	lefty_bar.c++;	break;
		}}
		if(lefty_cn[0][a] == lefty_cn[1][a]) {	//checks for vertical bars
			switch(lefty_cn[0][a]){
			case 0:	lefty_bar.a++;	break;
			case 1:	lefty_bar.b++;	break;
			case 2:	lefty_bar.c++;	break;
		}}
		//righty
		if(righty_cn[a][0] == righty_cn[a][1]) {	//checks for horizontal bars
			switch(righty_cn[a][0]){
			case 0:	righty_bar.a++;	break;
			case 1:	righty_bar.b++;	break;
			case 2:	righty_bar.c++;	break;
		}}
		if(righty_cn[0][a] == righty_cn[1][a]) {	//checks for vertical bars
			switch(righty_cn[0][a]){
			case 0:	righty_bar.a++;	break;
			case 1:	righty_bar.b++;	break;
			case 2:	righty_bar.c++;	break;
		}}
		//front
		if(front_cn[a][0] == front_cn[a][1]) {	//checks for horizontal bars
			switch(front_cn[a][0]){
			case 0:	front_bar.a++;	break;
			case 1:	front_bar.b++;	break;
			case 2:	front_bar.c++;	break;
		}}
		if(front_cn[0][a] == front_cn[1][a]) {	//checks for vertical bars
			switch(front_cn[0][a]){
			case 0:	front_bar.a++;	break;
			case 1:	front_bar.b++;	break;
			case 2:	front_bar.c++;	break;
		}}
		//back
		if(back_cn[a][0] == back_cn[a][1]) {	//checks for horizontal bars
			switch(back_cn[a][0]){
			case 0:	back_bar.a++;	break;
			case 1:	back_bar.b++;	break;
			case 2:	back_bar.c++;	break;
		}}
		if(back_cn[0][a] == back_cn[1][a]) {	//checks for vertical bars
			switch(back_cn[0][a]){
			case 0:	back_bar.a++;	break;
			case 1:	back_bar.b++;	break;
			case 2:	back_bar.c++;	break;
		}}
}}

void barBottom() {
		WriteText(hFileHandle, nIOResult, "_barBottom_");
	combineColors();	//redefines cn so it knows where everything is at
	if(down_cn[1][0] == down_cn[1][1]) {}	// moves a bar on the bottom layer to down[1][0] and down[1][1]
	else if(down_cn[0][1] == down_cn[1][1]) {X();}
	else if(down_cn[0][0] == down_cn[0][1]) {X(2);}
	else if(down_cn[0][0] == down_cn[1][0]) {X();}
	combineColors();	//redefines cn so it knows where everything is at
	if(lefty_cn[0][0] == down_cn[1][0] || lefty_cn[1][0] == down_cn[1][0]) { B(); }
	if(righty_cn[0][1] == down_cn[1][0] || righty_cn[1][1] == down_cn[1][0]) { B(prime); }
	else{ PlaySoundFile("Woops.rso");}		// it doesn't know what to do now. this will need to be fixed in the future
}
//#####################################################################################################################################################
//
// 																FIRST STEP
//
//#####################################################################################################################################################
void find_start() {		//trys to find a side with at least 2 bars
		WriteText(hFileHandle, nIOResult, "_find_start_");
	//If there is 2 or more bars on a side, it will move it towards the bottom
	if(down_bar.a > 1 || down_bar.b > 1 || down_bar.c > 1) {}
	else if(up_bar.a > 1 || up_bar.b > 1 || up_bar.c > 1) 						{ Y(2);}
	else if(lefty_bar.a > 1 || lefty_bar.b > 1 || lefty_bar.c > 1) 		{ Z(prime);}
	else if(righty_bar.a > 1 || righty_bar.b > 1 || righty_bar.c > 1) { Z();}
	else if(back_bar.a > 1 || back_bar.b > 1 || back_bar.c > 1)				{ Y();}
	else if(front_bar.a > 1 || front_bar.b > 1 || front_bar.c > 1)		{ Y(prime);}
	//now check for 1 bar, move it towards down face then, to down[1][0] and down[1][1]
	else{
		if(down_bar.a > 0 || down_bar.b > 0 || down_bar.c > 0) {}
		else if(up_bar.a > 0 || up_bar.b > 0 || up_bar.c > 0) 						{ Y(2); barBottom();}
		else if(lefty_bar.a > 0 || lefty_bar.b > 0 || lefty_bar.c > 0) 		{ Z(prime); barBottom();}
		else if(righty_bar.a > 0 || righty_bar.b > 0 || righty_bar.c > 0) { Z(); barBottom();}
		else if(back_bar.a > 0 || back_bar.b > 0 || back_bar.c > 0)				{ Y(); barBottom();}
		else if(front_bar.a > 0 || front_bar.b > 0 || front_bar.c > 0)		{ Y(prime); barBottom();}
		else{ PlaySoundFile("Woops.rso");}		// it doesn't know what to do now. this will need to be fixed in the future
	}//Now there is 3 of a type on the bottom. It will now move the blank one to down[1][1]
	combineColors();
	if(down_cn[0][0] == down_cn[0][1] == down_cn[1][0]) { }
	else	if(down_cn[0][0] == down_cn[0][1] == down_cn[1][1]) { D(prime);}
	else	if(down_cn[0][0] == down_cn[1][0] == down_cn[1][1]) { D();}
	else	if(down_cn[1][0] == down_cn[0][1] == down_cn[1][1]) { D(2);}
}

//Now the  bottom is oriented as this:
//					X X
// 				  X ?
void step1() {
		WriteText(hFileHandle, nIOResult, "_Step1_");
	if(righty_cn[1][0] == down[0][0]) {
		//this is the second row on: http://www.amvhell.com/stuff/cubes/guimond/guimond.html
		step1B();	}
	else if(front_cn[1][1] == down[0][0]) {
		//and this the first row
		step1A();	}}

void step1B() {
		WriteText(hFileHandle, nIOResult, "_Step1B_");
	combineColors();
	int BottomColor = down_cn[1][1];

	//step1Ba
	if( up_cn[0][0] == up_cn[0][1] == lefty_cn[0][1] == front_cn[0][1] ==  BottomColor) { step1Ba(); 	WriteText(hFileHandle, nIOResult, "_Step1Ba1_ ");}
	else if(back_cn[0][1] == up_cn[0][1] == lefty_cn[0][1] == up_cn[1][1] ==   BottomColor) { U(prime);step1Ba(); 	WriteText(hFileHandle, nIOResult, "_Step1Ba2_ ");}
	else if(back_cn[0][1] == righty_cn[0][1] == up_cn[1][0] == up_cn[1][1] ==   BottomColor) { U(2);step1Ba(); 	WriteText(hFileHandle, nIOResult, "_Step1Ba3_ ");}
	else if(up_cn[0][0] == righty_cn[0][1] == up_cn[1][0] == front_cn[0][1] ==    BottomColor) { U();step1Ba(); 	WriteText(hFileHandle, nIOResult, "_Step1Ba4_ ");}
	//step1Bb
	else if(up_cn[0][0] == righty_cn[0][1] == lefty_cn[0][1] == up_cn[1][1] ==  BottomColor) { step1Bb(); }
	else if(back_cn[0][1] == up_cn[0][1] == lefty_cn[0][1] == up_cn[1][1] ==   BottomColor) { U(prime);step1Bb();}
	else if(back_cn[0][1] == righty_cn[0][1] == up_cn[1][0] == up_cn[1][1] ==   BottomColor) { U(2);step1Bb();}
	else if(up_cn[0][0] == righty_cn[0][1] == up_cn[1][0] == front_cn[0][1] ==    BottomColor) { U();step1Bb();}
	//step1Bc
	else if(back_cn[0][1] == back_cn[0][0] == front_cn[0][0] == up_cn[1][1] ==  BottomColor) { step1Bc(); }
	else if(lefty_cn[0][0] == righty_cn[0][1]== up_cn[1][0] == righty_cn[0][0]  ==   BottomColor) { U(prime);step1Bc();}
	else if(up_cn[0][0] == back_cn[0][0] == front_cn[0][0] == front_cn[0][1] ==    BottomColor) { U(2);step1Bc();}
	else if(lefty_cn[0][0] == up_cn[0][1] ==  lefty_cn[0][1] == righty_cn[0][0] ==    BottomColor) { U();step1Bc();}
	//step1Bd
	else if(lefty_cn[0][0] ==  back_cn[0][0] == up_cn[1][0] == front_cn[0][1] ==  BottomColor) { step1Bd(); }
	else if(up_cn[0][0] == back_cn[0][0] == lefty_cn[0][1] == righty_cn[0][0] ==   BottomColor) { U(prime);step1Bd();}
	else if(back_cn[0][1] == up_cn[0][1] == front_cn[0][0] == righty_cn[0][0] ==    BottomColor) { U(2);step1Bd();}
	else if(lefty_cn[0][0] == righty_cn[0][1] ==  front_cn[0][0] == up_cn[1][1] ==    BottomColor) { U();step1Bd();}
	//step1Be
	else if(up_cn[0][0] == up_cn[0][1] == front_cn[0][0] == up_cn[1][1] ==  BottomColor) { step1Be(); }
	else if(lefty_cn[0][0] == up_cn[0][1] == up_cn[1][0] == up_cn[1][1] ==   BottomColor) { U(prime);step1Be();}
	else if(up_cn[0][0] == back_cn[0][0] == up_cn[1][0] == up_cn[1][1] ==   BottomColor) { U(2);step1Be();}
	else if(up_cn[0][0] == up_cn[0][1] == up_cn[1][0] == righty_cn[0][0] ==    BottomColor) { U();step1Be();}
	//step1Bf
	else if(lefty_cn[0][0] == up_cn[0][1] == front_cn[0][0] == front_cn[0][1] ==  BottomColor) { step1Bf(); }
	else if(lefty_cn[0][0] == back_cn[0][0] == lefty_cn[0][1] == up_cn[1][0] ==   BottomColor) { U(prime);step1Bf();}
	else if(back_cn[0][1] == back_cn[0][0] == up_cn[1][0] == righty_cn[0][0] ==    BottomColor) { U(2);step1Bf();}
	else if(up_cn[0][0] == righty_cn[0][1] ==  front_cn[0][0] == righty_cn[0][0] ==    BottomColor) { U();step1Bf();}
	//step1Bg
	else if(back_cn[0][1] == righty_cn[0][1] == lefty_cn[0][1] == righty_cn[0][0] ==  BottomColor) { step1Bg(); }
	else if(back_cn[0][1] == righty_cn[0][1] == front_cn[0][0] == front_cn[0][1] ==   BottomColor) { U(prime);step1Bg();}
	else if(lefty_cn[0][0] == righty_cn[0][1] == lefty_cn[0][1] == front_cn[0][1] ==    BottomColor) { U(2);step1Bg();}
	else if(back_cn[0][1] == back_cn[0][0] ==  lefty_cn[0][1] == front_cn[0][1] ==    BottomColor) { U();step1Bg();}
	//step1Bh
	else if( lefty_cn[0][0] == back_cn[0][0] == front_cn[0][0] == righty_cn[0][0] ==  BottomColor) { step1Bh(); }

	//error:
	else{
	 PlaySoundFile("Woops.rso");
	nxtDisplayCenteredTextLine(1,"It got stuck on Step1B" );
	}

}
//These algs. are from row 2 of the website.
void step1Ba() { }//R(); U(prime); R(prime); 	WriteText(hFileHandle, nIOResult, "_Step1Ba_ ");}
void step1Bb() { F(prime); U(prime); F(); 	WriteText(hFileHandle, nIOResult, "_Step1Bb_ "); }
void step1Bc() { F(prime); U(2); F();  	WriteText(hFileHandle, nIOResult, "_Step1Bc_ ");}
void step1Bd() { R(2); U(); R(prime); 	WriteText(hFileHandle, nIOResult, "_Step1Bd_ ");}
void step1Be() { F(); R(); U(); R(prime); 	WriteText(hFileHandle, nIOResult, "_Step1Be_ ");}
void step1Bf() { R(2); F(2); U(); R(); 	WriteText(hFileHandle, nIOResult, "_Step1Bf_ ");}
void step1Bg() { R(); B(2); U(prime); R(prime); 	WriteText(hFileHandle, nIOResult, "_Step1Bg_ ");}
void step1Bh() { R(prime); U(2); F(); R(2); U(prime); R(prime); 	WriteText(hFileHandle, nIOResult, "_Step1Bh_ ");}



void step1A() {
		WriteText(hFileHandle, nIOResult, "_Step1A_");
	combineColors();
	int BottomColor = down_cn[0][1];
	//step1Ba
	if( lefty_cn[0][0] == back_cn[0][0] == up_cn[1][0] == up_cn[1][1] ==  BottomColor) { step1Aa(); }
	else if(1){
	}
}
//These algs. are from row 1 of the website.
void step1Aa() { F(prime); U(); F();}
void step1Ab() { R(); U(); R(prime);}
void step1Ac() { R(); U(2); R(prime);}
void step1Ad() { F(2); U(prime); R();}
void step1Ae() { B(); U(); B(prime); R(prime);}
void step1Af() { F(2); L(2); U(prime); L(prime);}
void step1Ag() { B(prime); U(2); R(); B();}
void step1Ah() { F(); U(prime); F(prime); L(); F(2);L(prime);}

//#####################################################################################################################################################
//
// 																SECOND STEP
//
//#####################################################################################################################################################
void step2() {

	if(down[0][1] == down[1][1]) { // step2a and step2d without a down turn
		//step2a
		if(up[0][0] == up[1][0] == down[0][1]){ step2a();}
		else if(up[1][0] == up[1][1] == down[0][1]) { U(prime); step2a();}
		else if(up[1][1] == up[0][1] == down[0][1]) { U(2); step2a();}
		else if(up[0][0] == up[0][1] == down[0][1]) { U(); step2a();}
		//step2d
		else if(up[0][0] == up[1][1] == down[0][0]){ step2d();}
		else if(up[1][0] == up[0][1] == down[0][0]) { U(); step2d();}
	}
	else if(down[0][0] == down[0][1]) { D(prime); // step2a and step2d with down turn
		// exactly the same as above, just without^ the down turn
		//step2a
		if(up[0][0] == up[1][0] == down[0][1]){ step2a();}
		else if(up[1][0] == up[1][1] == down[0][1]) { U(prime); step2a();}
		else if(up[1][1] == up[0][1] == down[0][1]) { U(2); step2a();}
		else if(up[0][0] == up[0][1] == down[0][1]) { U(); step2a();}
		//step2d
		else if(up[0][0] == up[1][1] == down[0][0]){ step2d();}
		else if(up[1][0] == up[0][1] == down[0][0]) { U(); step2d();}
	}

	else if(down[0][0] == down[1][1]) { // step2b and step2e
		//step2b
		if(up[0][0] == up[1][1] == down[0][0]) { step2b(); }
		else if(up[0][1] == up[1][0] == down[0][0]) { U(); step2b();}
		//step2e
		else if(up[0][0] == up[1][0] == down[0][0]){ step2e();}
		else if(up[1][0] == up[1][1] == down[0][0]) { U(); step2e();}
		else if(up[0][1] == up[1][1] == down[0][0]) { U(2); step2e();}
		else if(up[0][0] == up[0][1] == down[0][0]) { U(prime); step2e();}
	}


	else {
		// step2c
		//positions the down layer
		if(down[0][0] == down[1][0] == down[1][1]) { }
		else	if(down[0][0] == down[0][1] == down[1][1]) { D(2);}
		else	if(down[0][0] == down[1][0] == down[0][1]) { D(prime);}
		else	if(down[1][0] == down[0][1] == down[1][1]) { D();}
		//positions top layer
		if(up[0][1] == up[1][0] == up[1][1]) { }
		else	if(up[0][0] == up[0][1] == up[1][0]) { D(2);}
		else	if(up[0][0] == up[1][0] == up[1][1]) { D(prime);}
		else	if(up[0][0] == up[0][1] == up[1][1]) { D();}
		step2c();
	}
}


void step2a() {
	R(2);
}
void step2b() { R(2); U(2); F(2); }

void step2c() {R(2); U(); R(2);}
void step2d() { R(2); U(prime); R(2); U(prime); R(2); }
void step2e() { R(2); U(prime); R(2); U(prime); F(2); }

task main()
{
	 Delete("Output.txt",nIOResult);
   OpenWrite(hFileHandle, nIOResult, sFileName, nFileSize);    // open the file for writing (creates the file if it does not exist)


	print();
	wait1Msec(2000);
	combineColors();
	barTest();
	find_start();
	step1();
	//step2();

	eraseDisplay();
	wait1Msec(10);
	PlayTone(10,10);
	updateCube();
	print();

	 	WriteText(hFileHandle, nIOResult, "..end.. ");
Close(hFileHandle, nIOResult);                              // close the file (DON'T FORGET THIS STEP!)

	while(1){}
}
