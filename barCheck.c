#include "cube.c"


typedef struct{

	int a;	// color pair 1
	int b;	// color pair 2
	int c;	// coror pair 3
	//	int d;	// keeps track of diagonals
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
task main() {

	//wait1Msec(200);
side test;
test.a = 100;
test.b = 2;
test.c = 3;
combineColors();
	barTest();
	nxtDisplayCenteredTextLine(2,"%i", test );
	nxtDisplayCenteredTextLine(4,"this:  %i", back_bar.b );
	nxtDisplayCenteredTextLine(6,"this:  %i", back_bar.c );
	while(1){}
}
