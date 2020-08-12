#include <iostream>

using namespace std;

int main() {
	int two_d_array[2][3] = { 1,2,3,4,5,6 };	//Create Array
	int *a, *b, *c, *d;
	int *e[3], *f[3], *g[2][3];
	int ** h, ** i, ** j;

	a = &two_d_array[0][0];		//pointer connection
	b = &two_d_array[1][0];
	c = &two_d_array[0][1];
	d = &two_d_array[0][2];

	e[0] = &two_d_array[0][0];	//pointer connection
	e[1] = &two_d_array[0][1];
	e[2] = &two_d_array[0][2];
	f[0] = &two_d_array[1][0];
	f[1] = &two_d_array[1][1];
	f[2] = &two_d_array[1][2];

	h = &a;		//pointer connection
	i = &a;
	j = &c;

	for (int x = 0; x < 2; x++) {	//pointer connection
		for(int y = 0; y < 3; y++)
		g[x][y] = &two_d_array[x][y];
	}
	cout << "1)  a=" << *a << "  b=" << *b << "  c=" << *c << "  d=" << *d;	//address value output
	cout << "  h=" << **h << "  i=" << **i << "  j=" << **j << endl;
	cout << "2)  a=" << a << "  b=" << b << "  c=" << c << "  d=" << d;		//Location Output for Address
	cout << "  h=" << *h << "  i=" << *i << "  j=" << *j << endl;
	cout << "3)  e=" << *e[0] << "," << *e[1] << "," << *e[2] << endl;		//address value output
	cout << "    f=" << *f[0] << "," << *f[1] << "," << *f[2] << endl;
	cout << "    g=" << *g[0][0] << "," << *g[0][1] << "," << *g[0][2] << endl;
	cout << "      " << *g[1][0] << "," << *g[1][1] << "," << *g[1][2] << endl;

	return 0;	//Exit main function
}
