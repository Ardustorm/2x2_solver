#include "solver_v1.c"

//Now the  bottom is oriented as this:
//					X X
// 				  X ?
//defines functions before hand
void step1B();
void step1Ba();
void step1Bb();
void step1Bc();
void step1Bd();
void step1Be();
void step1Bf();
void step1Bg();
void step1Bh();

void step1A();
void step1Aa();
void step1Ab();
void step1Ac();
void step1Ad();
void step1Ae();
void step1Af();
void step1Ag();
void step1Ah();




void step1() {
	if(righty_cn[1][0] == down[0][0]) {
		//this is the second row on: http://www.amvhell.com/stuff/cubes/guimond/guimond.html
		step1B();	}
	else if(front_cn[1][1] == down[0][0]) {
		//and this the first row
		step1A();	}}

void step1B() {
	combineColors();
	int BottomColor = down_cn[0][1];
	//step1Ba
	if( up_cn[0][0] == up_cn[0][1] == lefty_cn[0][1] == front_cn[0][1] ==  BottomColor) { step1Ba(); }
	else if(back_cn[0][1] == up_cn[0][1] == lefty_cn[0][1] == up_cn[1][1] ==   BottomColor) { R(prime);step1Ba();}
	else if(back_cn[0][1] == righty_cn[0][1] == up_cn[1][0] == up_cn[1][1] ==   BottomColor) { R(2);step1Ba();}
	else if(up_cn[0][0] == righty_cn[0][1] == up_cn[1][0] == front_cn[0][1] ==    BottomColor) { R();step1Ba();}
	//step1Bb
	else if( up_cn[0][0] == righty_cn[0][1] == lefty_cn[0][1] == up_cn[1][1] ==  BottomColor) { step1Bb(); }
	else if(back_cn[0][1] == up_cn[0][1] == lefty_cn[0][1] == up_cn[1][1] ==   BottomColor) { R(prime);step1Ba();}
	else if(back_cn[0][1] == righty_cn[0][1] == up_cn[1][0] == up_cn[1][1] ==   BottomColor) { R(2);step1Ba();}
	else if(up_cn[0][0] == righty_cn[0][1] == up_cn[1][0] == front_cn[0][1] ==    BottomColor) { R();step1Ba();}
	//step1Bc
	else if( back_cn[0][1] == back_cn[0][0] == front_cn[0][0] == up_cn[1][1] ==  BottomColor) { step1Bc(); }
	else if(lefty_cn[0][0] == righty_cn[0][1] == righty_cn[0][0] == up_cn[1][0] ==   BottomColor) { R(prime);step1Bc();}
	else if(up_cn[0][0] == back_cn[0][0] == front_cn[0][0] == front_cn[0][1] ==    BottomColor) { R(2);step1Bc();}
	else if(lefty_cn[0][0] == up_cn[0][1] ==  lefty_cn[0][1] == righty_cn[0][0] ==    BottomColor) { R();step1Bc();}

}
//These algs. are from row 2 of the website.
void step1Ba() { R(); U(prime); R(prime);}
void step1Bb() { F(prime); U(prime); F(); }
void step1Bc() { F(prime); U(2); F(); }
void step1Bd() { R(2); U(); R(prime);}
void step1Be() { F(); R(); U(); R(prime);}
void step1Bf() { R(2); F(2); U(); R();}
void step1Bg() { R(); B(2); U(prime); R(prime);}
void step1Bh() { R(prime); U(2); F(); R(2); U(prime); R(prime);}



void step1A() {
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
