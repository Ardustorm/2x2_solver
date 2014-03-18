// Step 2
// This step separates the colors onto faces of the same color

void step2() {

if(down[0][1] == down[1][1]) { // step2a and step2d without a down turn
//step2a
	if(up[0][0] == up[1][0] == down[0][1]){ step2a();}
	else if(up[1][0] == up[1][1] == down[0][1]) { U(prime); step2a();}
	else if(up[1][1] == up[0][1] == down[0][1]) { U(2); step2a();}
	else if(up[0][0] == up[0][1] == down[0][1]) { U(); step2a();}
//step2d	
	else if(up[0][0] == up[1][1] == down[0][0]){ step2d();}
	else if(up[1][0] == up[0][1] == down[0][0]) { U(); step2d();}
}
else if(down[0][0] == down[0][1]) { D(prime); // step2a and step2d with down turn
// exactly the same as above, just without^ the down turn
//step2a
	if(up[0][0] == up[1][0] == down[0][1]){ step2a();}
	else if(up[1][0] == up[1][1] == down[0][1]) { U(prime); step2a();}
	else if(up[1][1] == up[0][1] == down[0][1]) { U(2); step2a();}
	else if(up[0][0] == up[0][1] == down[0][1]) { U(); step2a();}
//step2d	
	else if(up[0][0] == up[1][1] == down[0][0]){ step2d();}
	else if(up[1][0] == up[0][1] == down[0][0]) { U(); step2d();}
}

else if(down[0][0] == down[1][1]) { // step2b and step2e
//step2b
	if(up[0][0] == up[1][1] == down[0][0]) { step2b(); }
	else if(up[0][1] == up[1][0] == down[0][0]) { U(); step2b();}
//step2e
	else if(up[0][0] == up[1][0] == down[0][0]){ step2e();}
	else if(up[1][0] == up[1][1] == down[0][0]) { U(); step2e();}
	else if(up[0][1] == up[1][1] == down[0][0]) { U(2); step2e();}
	else if(up[0][0] == up[0][1] == down[0][0]) { U(prime); step2e();}
	}
	
}
else { 
// step2c
	//positions the down layer
	if(down[0][0] == down[1][0] == down[1][1]) { }	
	else	if(down[0][0] == down[0][1] == down[1][1]) { D(2);}
	else	if(down[0][0] == down[1][0] == down[0][1]) { D(prime);}
	else	if(down[1][0] == down[0][1] == down[1][1]) { D();}
	//positions top layer
	if(up[0][1] == up[1][0] == up[1][1]) { }	
	else	if(up[0][0] == up[0][1] == up[1][0]) { D(2);}
	else	if(up[0][0] == up[1][0] == up[1][1]) { D(prime);}
	else	if(up[0][0] == up[0][1] == up[1][1]) { D();}
	
	step2c();
}



void step2a() {
	R(2);
	}
void step2b() { R(2); U(2); F(2); }
	}
void step2c() {R(2); U(); R(2);}
void step2d() { R(2); U(prime); R(2); U(prime); R(2); }
void step2e() { R(2); U(prime); R(2); U(prime); F(2); }

}