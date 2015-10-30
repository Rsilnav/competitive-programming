#include <iostream>
#include <cstring>

using namespace std;

int stacks[25][25];

int findInTable(int x) {
	for (int i=0; i<25; i++) {
		for (int j=0; j<25; j++) {
			if (stacks[i][j] == -1)
				break;
			if (stacks[i][j] == x)
				return i;
		}
	}
	return -1;
}

int findInStack(int s, int x) {
	for (int j=0; j<25; j++) {
		if (stacks[s][j] == -1)
			break;
		if (stacks[s][j] == x)
			return j;
	}
	return -1;
}

int findEmptyInStack(int s) {
	for (int j=0; j<25; j++) {
		if (stacks[s][j] == -1)
			return j;
	}
	return -1;
}

void moveOnto(int a, int b) {
	int stack, pos;
	stack = findInTable(a);
	pos = findInStack(stack, a);
	for (int i=pos+1; i<25; i++) {
		if (stacks[stack][i] == -1)
			break;
		int block = stacks[stack][i];
		stacks[block][findEmptyInStack(block)] = block;
		stacks[stack][i] = -1;
	}
	stacks[stack][pos] = -1;
	stack = findInTable(b);
	pos = findInStack(stack, b);
	for (int i=pos+1; i<25; i++) {
		if (stacks[stack][i] == -1)
			break;
		int block = stacks[stack][i];
		stacks[block][findEmptyInStack(block)] = block;
		stacks[stack][i] = -1;
	}
	stacks[stack][findEmptyInStack(stack)] = a;
}

void moveOver(int a, int b) {
	int stack = findInTable(a);
	int pos = findInStack(stack, a);
	int stack2 = findInTable(b);
	int pos2 = findInStack(stack2, b);

	for (int i=pos+1; i<25; i++) {
		if (stacks[stack][i] == -1)
			break;
		int block = stacks[stack][i];
		stacks[block][findEmptyInStack(block)] = block;
		stacks[stack][i] = -1;
	}
	stacks[stack][pos] = -1;

	stacks[stack2][findEmptyInStack(stack2)] = a;
}

void pileOnto(int a, int b) {
	int stack, pos;
	stack = findInTable(b);
	pos = findInStack(stack, b);
	for (int i=pos+1; i<25; i++) {
		if (stacks[stack][i] == -1)
			break;
		int block = stacks[stack][i];
		stacks[block][findEmptyInStack(block)] = block;
		stacks[stack][i] = -1;
	}

	int stack2 = findInTable(a);
	int pos2 = findInStack(stack2, a);
	for (int i=pos2; i<25; i++) {
		if (stacks[stack2][i] == -1)
			break;
		stacks[stack][findEmptyInStack(stack)] = stacks[stack2][i];
		stacks[stack2][i] = -1;
	}

}

void pileOver(int a, int b) {
	int stack, pos;
	stack = findInTable(b);

	int stack2 = findInTable(a);
	int pos2 = findInStack(stack2, a);
	for (int i=pos2; i<25; i++) {
		if (stacks[stack2][i] == -1)
			break;
		stacks[stack][findEmptyInStack(stack)] = stacks[stack2][i];
		stacks[stack2][i] = -1;
	}
}

int main() {
	ios_base::sync_with_stdio (false);
	int blocks;
	cin >> blocks;
	cin.ignore();

	for (int x=0; x<25;x++) {
		for (int y=0; y<25;y++)
			stacks[x][y] = -1;
	}

	for (int i=0; i<blocks; i++) {
		stacks[i][0] = i;
	}

	string instruction, position;
	int a, b;
	while (cin >> instruction && instruction.compare("quit") != 0) {
		cin >> a >> position >> b;
		if (a == b || findInTable(a) == findInTable(b))
			continue;

		if (instruction.compare("move") == 0) {
			if (position.compare("onto") == 0) {
				moveOnto(a, b);
			}
			else if (position.compare("over") == 0) {
				moveOver(a, b);
			}
		}
		else if (instruction.compare("pile") == 0) {
			if (position.compare("onto") == 0) {
				pileOnto(a, b);
			}
			else if (position.compare("over") == 0) {
				pileOver(a, b);
			}
		}
	}

	for (int i=0; i<blocks; i++) {
		cout << i << ":";
		for (int j=0; j<blocks; j++) {
			if (stacks[i][j] == -1)
				break;
			cout << " " << stacks[i][j];
		}
		cout << endl;
	}

	return 0;
}
