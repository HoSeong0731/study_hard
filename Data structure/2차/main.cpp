#include "Manager.h"

using namespace std;

int main() {
	Manager manager(2,3); //first value is threshold of fpgrowth, second value is order of bptree 
	manager.run("command.txt");
	return 0;
}

