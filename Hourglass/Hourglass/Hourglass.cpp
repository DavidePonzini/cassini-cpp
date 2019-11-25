#include <iostream>

using namespace std;

void DrawLine(int level, int height, int top, int bottom);


int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cerr << argv[0] << " <height> [sand top] [sand bottom]" << endl;
		return 1;
	}
	
	int height = atoi(argv[1]) + 1;
	int sandTop = argc > 2 ? atoi(argv[2]) + 1 : 0;
	int sandBottom = argc > 3 ? atoi(argv[3]) + 1 : 0;

	DrawLine(height, height, sandTop, sandBottom);
}

void DrawLine(int level, int height, int top, int bottom)
{
	if (height + level < 0)
		return;

	int lengthHourglass = abs(level) * 2 + 1;
	int lenghtTotal = height * 2 + 1;
	int padding = (lenghtTotal - lengthHourglass) / 2;

	for (int i = 0; i < padding; i++)
		cout << " ";
	for (int i = 0; i < lengthHourglass; i++)
	{
		if(abs(level) == height)						// top or bottom levels
			cout << "#";
		else if (i == 0 || i == lengthHourglass - 1)	// hourglass borders
			cout << "#";
		else if(level > 0 && level < top)				// sand top
			cout << ".";
		else if (level < 0 && height+level < bottom)	// sand bottom
			cout << ".";
		else
			cout << " ";	
	}
	cout << endl;

	DrawLine(level - 1, height, top, bottom);
}