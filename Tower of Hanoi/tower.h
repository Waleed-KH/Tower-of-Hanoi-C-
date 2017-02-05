class tower
{
public:
	tower(int, int, wchar_t);
	tower();
	System::String^ move(tower &);
	System::String^ display();
private:
	wchar_t name;
	int discsNo;
	stack<int> towerDiscs;
};

tower::tower(){
}

tower::tower(int no, int dNo, wchar_t n)
{
	discsNo =dNo;
	towerDiscs = stack<int>(discsNo);
	for (int x = no; x > 0; x--)
		towerDiscs.push(x);
	name = n;
}

System::String^ tower::move(tower &target)
{
	if (!towerDiscs.empty()) {
		int temp = towerDiscs.top();
		towerDiscs.pop();
		target.towerDiscs.push(temp);
		return "Move " + OrdinalNo(temp) + " Disc from Tower " + name + " to Tower " + target.name;
	}
}

System::String^ tower::display()
{
	System::String^ towerDisplay;
	int* discs;
	int size = towerDiscs.size() + 1;
	discs = new int[size];

	for (int x = 0; !towerDiscs.empty(); x++)
	{
		discs[x] = towerDiscs.top();
		towerDiscs.pop();
	}

	discs[size - 1] = discsNo + 1;

		for (int x = 0; x < (discsNo + 1) - (size); x++)
		{
			for (int s = 0; s < (discsNo * 2) + 2; s++)
				towerDisplay += " ";
			towerDisplay += "|\n";
		}

		for (int x = 0; x < size; x++)
		{
			for (int y = 0; y < ((discsNo * 2) + 2) - (discs[x] * 2 - 1); y++)
				towerDisplay += " ";

			for (int y = 0; y < discs[x] * 4 - 1; y++)
			{
				if ((x == 0 && y == (discs[x] * 4 - 1) / 2) || y == ((discs[x] * 4 - 1) - (discs[x - 1] * 4 - 1)) / 2 - 1 || y == ((discs[x] * 4 - 1) - (discs[x - 1] * 4 - 1)) / 2 + (discs[x - 1] * 4 - 1))
					towerDisplay += "|";
				else
					towerDisplay += "_";
			}

			towerDisplay += "\n";
		}

	for (int x = size - 2; x >= 0; x--)
	{
		towerDiscs.push(discs[x]);
	}

	return towerDisplay;
}