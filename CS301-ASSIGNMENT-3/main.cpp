// Guan Ce Looa
// CS 301 Summer 2020
// Assignment 3: N-skip-M-grams

#include <iostream>
#include <fstream>
#include "Sentence.h"

int main()
{
	int skip;
	int gram;
	string line;
	string inputFileName = "quotes.txt";
	string outputFileName = "nskipmgram_quotes.txt";
	ifstream in(inputFileName);
	ofstream out(outputFileName);

	cout << "N-skip-M-gram generator initialized." << endl;
	cout << "Enter number of words to be skipped: ";
	cin >> skip;
	cout << "Enter number of words to be picked from a sentence: ";
	cin >> gram;
	cout << endl;
	cout << "Generated " << skip << "-skip-" << gram << "-gram." << endl;
	out << "Generated " << skip << "-skip-" << gram << "-gram." << endl;

	while (!in.eof())
	{
		getline(in, line);
		Sentence* sentence = new Sentence(line);
		for (int i = 0; i < sentence->getLength(); i++)
		{
			int tailLength = sentence->getLength() - i - 1;
			int skipgram = (skip + 1) * (gram - 1);
			if (tailLength >= skipgram)
			{
				if (i != 0)
				{
					cout << ", ";
					out << ", ";
				}
				else
				{
					cout << endl;
					out << endl;
				}
				int j = i;
				for (int k = 0; k < gram; k++)
				{
					cout << sentence->getWord(j);
					out << sentence->getWord(j);
					if (k != gram - 1)
					{
						cout << " ";
						out << " ";
					}
					j += skip;
					j++;
				}
			}
		}
		delete sentence;
	}

	in.close();
	out.close();

	cout << endl << endl;
	cout << "Output in nskipmgram_quotes.txt updated." << endl;
	cout << "Press any key to end program." << endl;
	cin.get();
	cin.get();
	return 0;
}