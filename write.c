
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
