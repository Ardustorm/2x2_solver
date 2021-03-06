#include "cube.c"
#include "write.c"


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
	combineColors();	//redefines cn so it knows where everything is at
	if(down_cn[1][0] == down_cn[1][1]) {}	// moves a bar on the bottom layer to down[1][0] and down[1][1]
	else if(down_cn[0][1] == down_cn[1][1]) {X();}
	else if(down_cn[0][0] == down_cn[0][1]) {X(2);}
	else if(down_cn[0][0] == down_cn[1][0]) {X();}
	combineColors();	//redefines cn so it knows where everything is at
	if(lefty_cn[0][0] == down_cn[1][0] || lefty_cn[1][0] == down_cn[1][0]) { B(); }
	if(righty_cn[0][1] == down_cn[1][0] || righty_cn[1][1] == down_cn[1][0]) { B(prime); }
	else{ PlaySoundFile("Sorry.rso");}		// it doesn't know what to do now. this will need to be fixed in the future
}

void find_start() {		//trys to find a side with at least 2 bars
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
		else{ PlaySoundFile("Sorry.rso");}		// it doesn't know what to do now. this will need to be fixed in the future
	}//Now there is 3 of a type on the bottom. It will now move the blank one to down[1][1]
	combineColors();
	if(down_cn[0][0] == down_cn[0][1] == down_cn[1][0]) { }
	else	if(down_cn[0][0] == down_cn[0][1] == down_cn[1][1]) { D(prime);}
	else	if(down_cn[0][0] == down_cn[1][0] == down_cn[1][1]) { D();}
	else	if(down_cn[1][0] == down_cn[0][1] == down_cn[1][1]) { D(2);}
//	//Now the  bottom is oriented as this:
//	//					X X
//	// 				  X ?

//}
//void step1Ba() {}
//void step1B() {
//	combineColors();
//	int BottomColor = down_cn[0][1];
//	//step1Ba
//	if( lefty_cn[0][1] == front_cn[0][1] == up_cn[0][0] == up_cn[0][1] == BottomColor) {
//	}
//}
//void step1() {
//	if(righty_cn[1][0] == down[0][0]) {
//		//this is the second row on: http://www.amvhell.com/stuff/cubes/guimond/guimond.html
//		step1B();


//	}
//	else if(front_cn[1][1] == down[0][0]) {
//		//and this the first row
//	}
}

task main()
{
	print();
	wait1Msec(3000);
	combineColors();
	barTest();
	find_start();


	while(1){}
}
