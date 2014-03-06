int b = 1;
int g = 2;
int y = 3;
int k = 4;
int p = 5;
int r = 6;
//stores location of rubik's cube
	int up[2][2] = {
	{ p,g},
	{k,r}};
int down[2][2] = {
	{k,b},
	{p,y}};
int left[2][2] = {
	{y,b},
	{y,r}};
int right[2][2] = {
	{b,k},
	{k,g}};
int front[2][2] = {
	{p,y},
	{g,r}};
int back[2][2] = {
	{p,b},
	{r,g}};



// a temperary store place so that we do not re read location
int up_tmp[2][2];
int down_tmp[2][2];
int left_tmp[2][2];
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
			left_tmp[i][j] = left[i][j];
	}}
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			right_tmp[i][j] = right[i][j];
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
	right[0][0] = right_tmp[1][0];
	right[0][1] = right_tmp[0][0];
	right[1][0] = right_tmp[1][1];
	right[1][1] = right_tmp[0][1];

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
			front[i][j] = left_tmp[i][j];
	}}
		for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			left[i][j] = back_tmp[i][j];
	}}
		for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			back[i][j] = right_tmp[i][j];
	}}
		for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			right[i][j] = front_tmp[i][j];
	}}
	front = left_tmp;
	left  = back_tmp;
	back  = right_tmp;
	right = front_tmp;

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
	right[1][1] = right_tmp[0][1];

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

	up[1][0] = left_tmp[1][1];
	up[1][1] = left_tmp[0][1];

	down[0][1] =right_tmp[0][0];
	down[0][0] =right_tmp[1][0];

	left[0][1] =down_tmp[0][0];
	left[1][1] =down_tmp[0][1];

	right[0][0] =up_tmp[1][0];
	right[1][0] =up_tmp[1][1];
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
	Y(prime); // then rotates the cube so it is as if the left face was turned
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
