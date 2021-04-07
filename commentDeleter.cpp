#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string line;
	string path_in = "for_homework.txt";
	string path_out = "output_task.txt";
	fstream file(path_in);
	ofstream out(path_out);
	if (file.is_open() and out.is_open())
	{
		int counter = 0; //to count '/'
		/*
		counter == 0: continue to read the line
		counter == 1: watch for '/' and '*' symbols
		counter == 2: enouctered "//" (break func used instead)
		counter == 3: encountered "/*". Now watch for '*','/' symbols
		counter == 4: encountered "/**". Now watch for '/' to start read the line
		*/
		while (getline(file, line))
		{
			for (auto it = line.begin(); it != line.end(); it++)
			{
				if (counter == 0)
				{
					if (*it == '/')
						counter += 1;
					else
						out << *it;
				}
				else if (counter == 1)
				{
					if (*it == '/') // "//" case. In this case we stop reading the line.
					{
						counter = 0;
						break;
					}
					else if (*it == '*') // "/**/" case. In this case we don't put anything in output until we see "*/".
						counter = 3;
					else
					{
						counter = 0;
						out << '/';
						out << *it;
					}
				}
				else if (counter == 3) // "/*" case. Watch for '*'
				{
					if (*it == '*')
						counter += 1;
				}
				else if (counter == 4)// "/**" case. Watch for '/'
				{
					if (*it == '/')
						counter = 0;
					else
						counter = 3;
				}
			}
			out << '\n'; //new line
		}
		if (counter >= 3 && file.eof())
		{
			cout << endl << endl << endl << "ERROR: INCORRECT USE OF COMMENTS." << endl;
			return 1;
		}
		file.close();
		out.close();
	}
	else
		cout << "ERROR: NO SUCH FILE OR DIRECTORY.\nCHECK BOTH." << endl;
	return 0;
}
