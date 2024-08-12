#pragma once

#include <iostream>

using namespace std;

char** words_to_sentence(int row, int col)
{
	string input;
	cout << "Enter Sentecne : ";
	getline(cin, input);

	int spaces = 0;
	int index = 0;
	while (input[index] != '\0')
	{
		if (input[index] == ' ')
		{
			spaces++;
		}
		index++;
	}

	row = spaces + 1;

	char **sentence = new char*[row];

	for (int i = 0; i < row; i++)
	{
		sentence[i] = new char[col];
	}

	char *word = new char[col];

	for (int i = 0; i < col; i++)
	{
		word[i] = ' ';
	}

	//int check = 0;
	//int word_check = 0;

	//cout << row;
	//for (int i = 0; i < row; i++)
	//{
	//	while (input[check] != ' ')
	//	{
	//		word[word_check] = input[check];
	//		check++;
	//		word_check++;
	//	}

	//	check++;
	//	word[word_check] = '\0';

	//	for (int j = 0; j < col; j++)
	//	{
	//		sentence[i][j] = word[j];
	//	}

	//	word_check = 0;
	//	/*cout << word;
	//	check++;*/
	//}

	int checker = 0;
	index = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if ((input[index] != ' ') && (input[index] != '\0'))
			{
				sentence[i][j] = input[index];
				index++;
			}
			else
			{
				sentence[i][j] = '\0';
				index++;
				break;
			}
		}
	}
	
	for (int i =0 ; i< row ; i++)
	{
		cout << "Row " << i+1 << ": ";
		cout << sentence[i] << endl;	
	}

	return sentence;
}
