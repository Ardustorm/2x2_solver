#include "cube.c"
#include "write.c"


//word represents sides, the number represents color pairing
//sideC stores the dominate color of a side if there are 3 or more on that side
int upC = -1;
int up1;
int up2;
int up3;
int downC = -1;
int down1;
int down2;
int down3;

int leftC = -1;
int left1;
int left2;
int left3;
int rightC = -1;
int right1;
int right2;
int right3;

int frontC = -1;
int front1;
int front2;
int front3;
int backC = -1;
int back1;
int back2;
int back3;

//cn stands for color neutral
int up_cn[2][2];
int down_cn[2][2];
int lefty_cn[2][2];
int righty_cn[2][2];
int front_cn[2][2];
int back_cn[2][2];

// combines opposite colors into 1, so that there are only 3 colors on the cube so to speak
//since robotc just chops off decimals, 3/2 = 1 etc.
void combine_colors() {
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
void count_sides() {
	for(int a = 0; a < 2; a++) {
		for(int b = 0; b < 2; b++) {
			//checks up side to count # of each color
			switch(up_cn[a][b]) {		//up
			case 0:
				up1++;
				break;
			case 1:
				up2++;
				break;
			case 2:
				up3++;
				break;
			}

			switch(down_cn[a][b]) {		//down
			case 0:
				down1++;
				break;
			case 1:
				down2++;
				break;
			case 2:
				down3++;
				break;
			}
			switch(lefty_cn[a][b]) {		//left
			case 0:
				left1++;
				break;
			case 1:
				left2++;
				break;
			case 2:
				left3++;
				break;
			}
			switch(righty_cn[a][b]) {		//right
			case 0:
				right1++;
				break;
			case 1:
				right2++;
				break;
			case 2:
				right3++;
				break;
			}
			switch(front_cn[a][b]) {		//front
			case 0:
				front1++;
				break;
			case 1:
				front2++;
				break;
			case 2:
				front3++;
				break;
			}
			switch(back_cn[a][b]) {		//back
			case 0:
				back1++;
				break;
			case 1:
				back2++;
				break;
			case 2:
				back3++;
				break;
			}
	}} //end of cycling through arrays

	//Inputs which colors are dominant on each side
	if(up1 > 2) { upC = 1;}		if(up2 > 2) { upC = 2;}	if(up3 > 2) { upC = 3;}

	if(down1 > 2) { downC = 1;}	if(down2 > 2) { downC = 2;}	if(down3 > 2) { downC = 3;}

	if(left1 > 2) { leftC = 1;}	if(left2 > 2) { leftC = 2;}	if(left3 > 2) { leftC = 3;}

	if(right1 > 2) { rightC = 1;}	if(right2 > 2) { rightC = 2;}	if(right3 > 2) { rightC = 3;}

	if(front1 > 2) { frontC = 1;}	if(front2 > 2) { frontC = 2;}	if(front3 > 2) { frontC = 3;}

	if(back1 > 2) { backC = 1;}	if(back2 > 2) { backC = 2;}	if(back3 > 2) { backC = 3;}

}
void find_start() {		//trys to find a side with at least 3 on each side or at least 1 side
	//it then moves it towards the bottom/top
	if(upC == downC && upC > 0)				{}
	else if(frontC == backC && frontC > 0) { Y();}
	else if(leftC == rightC && leftC > 0)  { Z();}
	else if( upC > 0 || downC > 0 || leftC > 0 || rightC > 0 || frontC > 0 || backC > 0) {	//if no pairs exist, try to place at least one on the bottom
		if(upC > 0)     {Y(2); }
		else if(leftC > 0)   {Z(prime);}
		else if(rightC > 0)  {Z();}
		else if(frontC > 0 ) {Y(prime);}
		else if(backC > 0)   {Y();}
	}
	else { // uh oh, this may be a problem
		//todo: try and find a bar
	}
}
	task main()
	{
		print();
		wait1Msec(3000);
		combine_colors();
		count_sides();


		while(1){}
	}
