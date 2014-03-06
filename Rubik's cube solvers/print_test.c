int array[2][2] = {
	{1,4},
	{2,3}};

int new_array[2][2] = {
	{4,1},
	{3,2}};

void print() {
for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
        nxtDisplayStringAt((j *8) + 2, (i * -11) + 40, "%i", array[i][j]); }
    }}

task main()
{
print();
wait1Msec(2000);
array = new_array;
print();

while(1){}
}
