#include "Rotations.c"

//stores location of rubik's cube
int up[2][2];
int down[2][2];
int left[2][2];
int right[2][2];
int front[2][2];
int back[2][2];
// a temperary store place so that we do not re read location
int up_tmp[2][2];
int down_tmp[2][2];
int left_tmp[2][2];
int right_tmp[2][2];
int front_tmp[2][2];
int back_tmp[2][2];

// writes to a temperary place to prevent errors
void store() {
	up_tmp   = up;
	down_tmp  = down;
	left_tmp  = left;
	right_tmp = right;
	front_tmp = front;
	back_tmp  = back;
}
// variable used to indicate direction of rotation
//prime means a turn in ccw direction, or 3 turns in the cw direction
int prime = 3;


// results in a clockwise turn of the up face
void U() {
	store();
	up[0][0] = up_tmp[1][0];
	up[0][1] = up_tmp[0][0];
	up[1][0] = up_tmp[1][1];
	up[1][1] = up_tmp[0][0];

	front[0][0] = right_tmp[0][0];
	front[0][1] = right_tmp[0][1];

	left[0][0] =front_tmp[0][0];
	left[0][1] =front_tmp[0][1];

	back[0][0] =left_tmp[0][0];
	back[0][1] =left_tmp[0][1];

	right[0][0] =back_tmp[0][0];
	right[0][1] =back_tmp[0][1];
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
	store();
	right[0][0] = right_tmp[1][0];
	right[0][1] = right_tmp[0][0];
	right[1][0] = right_tmp[1][1];
	right[1][1] = right_tmp[0][0];

	front[0][1] = down_tmp[0][1];
	front[1][1] = down_tmp[1][1];

	down[0][1] =back_tmp[0][1];
	down[1][1] =back_tmp[1][1];

	back[0][1] =up_tmp[0][1];
	back[1][1] =up_tmp[1][1];

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
	store();
	front[0][0] = front_tmp[1][0];
	front[0][1] = front_tmp[0][0];
	front[1][0] = front_tmp[1][1];
	front[1][1] = front_tmp[0][0];

	up[0][1] = left_tmp[0][1];
	up[1][1] = left_tmp[1][1];

	down[0][1] =right_tmp[0][1];
	down[1][1] =right_tmp[1][1];

	left[0][1] =down_tmp[0][1];
	left[1][1] =down_tmp[1][1];

	right[0][1] =up_tmp[0][1];
	right[1][1] =up_tmp[1][1];
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
