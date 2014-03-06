#include "Combined.c"

int cube[2][12] = {					// order: Up, Front, Right, Back, Left, Down
	{ up[0][0],up[0][1],	front[0][0],front[0][1],	right[0][0],right[0][1],	back[0][0],back[0][1],	left[0][0],left[0][1],	 down[1][0],down[0][0]},
	{ up[1][0],up[1][1],	front[1][0],front[1][1],	right[1][0],right[1][1],	back[1][0],back[1][1],	left[1][0],left[1][1],	 down[1][1],down[0][1]}} ;



void updateCube() {

int tmpcube[2][12] = {					// order: Up, Front, Right, Back, Left, Down
	{ up[0][0],up[0][1],	front[0][0],front[0][1],	right[0][0],right[0][1],	back[0][0],back[0][1],	left[0][0],left[0][1],	 down[1][0],down[0][0]},
	{ up[1][0],up[1][1],	front[1][0],front[1][1],	right[1][0],right[1][1],	back[1][0],back[1][1],	left[1][0],left[1][1],	 down[1][1],down[0][1]}} ;
//int tmpcube[2][12] = {					// order: Up, Front, Right, Back, Left, Down
//	{ 1,2,3,4,5,6,7,8,9,0,1,2},
//	{  1,2,3,4,5,6,7,8,9,0,1,2}} ;

	for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 12; j++) {
       cube[i][j] = tmpcube[i][j];
    }}
  }
void print() {

for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 12; j++) {
    		if(      cube[i][j] == b) {
    		nxtDisplayStringAt((j *8) + 2, (i * -11) + 40, "b"); }
    		else if( cube[i][j] == g) {
    		nxtDisplayStringAt((j *8) + 2, (i * -11) + 40, "g"); }
    		else if( cube[i][j] == y) {
    		nxtDisplayStringAt((j *8) + 2, (i * -11) + 40, "Y"); }
    		else if( cube[i][j] == k) {
    		nxtDisplayStringAt((j *8) + 2, (i * -11) + 40, "K"); }
    		else if( cube[i][j] == p) {
    		nxtDisplayStringAt((j *8) + 2, (i * -11) + 40, "P"); }
    		else if( cube[i][j] == r) {
    		nxtDisplayStringAt((j *8) + 2, (i * -11) + 40, "r"); }
    		else { nxtDisplayStringAt((j *8) + 2, (i * -11) + 40, "?"); }
    }
}
}

task main()
{
//U(prime);
//X();
//updateCube();
//nxtDisplayString(1," %i %i, %i, %i", );
print();
wait1Msec(1750);
R();
D(2);
F();
L();
U();
R();
B(2); B(2);
X(); Y(); Z();
updateCube();
print();
wait1Msec(3000);

print();
while(1){}
}
