#pragma systemFile

#include "/states/RD2FLUR.c"


// a temperary store place so that we do not re read location
int up_tmp[2][2];
int down_tmp[2][2];
int lefty_tmp[2][2];
int right_tmp[2][2];
int front_tmp[2][2];
int back_tmp[2][2];

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
	X(prime); Y(); X();
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
	F(); // turns the top layer
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
