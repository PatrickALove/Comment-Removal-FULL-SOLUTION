#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string readFile(string path)
{
	ifstream file;
	file.open(path);
	char str;
	string strTot;
	while (file.get(str))
		strTot += str;
	file.close();
	return strTot;
}

void removeComments(string &data)
{
	bool isQuote = false;
	bool isComment = false;
	int commentStart;
	int commentLength;

	for (int i = 0; i < data.length(); i++)
	{
		if (data[i] == '"' && !isComment)
		{
			isQuote = true;
			while (data[++i] != '"') {}
			isQuote = false;
		}

		if (data[i] == '!' && !isQuote)
		{
			isComment = true;

			if (data[i + 1] == '-')
			{
				commentStart = i;
				while (data[i] != '\n')
					i++;
				data.erase(commentStart, i - commentStart);
				i = i - commentStart;
			}

			if (data[i + 1] == '!')
			{
				commentStart = i;
				i += 2;
				while (data[i] != '!')
					i++;
				commentLength = i - commentStart + 2;
				data.erase(commentStart, commentLength);
				i -= commentLength;
			}

			isComment = false;
		}
	}
}

int main()
{
	string data = readFile("comment.txt");
	removeComments(data);
	cout << data << endl;
	system("pause");
	return 0;
}