#include "Turns.c"
void Y() {
	store();
	right[0][0] = right_tmp[1][0];
	right[0][1] = right_tmp[0][0];
	right[1][0] = right_tmp[1][1];
	right[1][1] = right_tmp[0][0];

	left[0][0] = left_tmp[0][1];
	left[0][1] = left_tmp[1][1];
	left[1][0] = left_tmp[0][0];
	left[1][1] = left_tmp[1][0];

	back[0][0] = up_tmp[1][1];
	back[0][1] = up_tmp[1][0];
	back[1][0] = up_tmp[0][1];
	back[1][1] = up_tmp[0][0];

	down[0][0] = back_tmp[1][1];
	down[0][1] = back_tmp[1][0];
	down[1][0] = back_tmp[0][1];
	down[1][1] = back_tmp[0][0];


	front = down_tmp;

	up = front_tmp;



}

void X() {
	store();

	up[0][0] = up_tmp[0][1];
	up[0][1] = up_tmp[1][1];
	up[1][0] = up_tmp[0][0];
	up[1][1] = up_tmp[1][0];


	down[0][0] = down_tmp[1][0];
	down[0][1] = down_tmp[0][0];
	down[1][0] = down_tmp[1][1];
	down[1][1] = down_tmp[0][1];

	front = left_tmp;
	left  = back_tmp;
	back  = right_tmp;
	right = front_tmp;




}
