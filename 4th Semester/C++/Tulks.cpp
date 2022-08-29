#include <fstream>
using namespace std;

struct word
{
	char A[21];
	char B[21];
};

int size(char input[])
{				//funkcija kas nosaka char virknes garumu
	int count = 0;
	for (int x = 0; x < 21; x++)
	{
		if (input[x] != '\0')
		{
			count++;
		}
		else
		{
			return count;
		}
	}
}

bool compare(char input[], char word[])
{				// funkcija kas salīdzina 2 char virknes
	int elements_in_input = size(input);
	int elements_in_word = size(word);
	if (elements_in_input == elements_in_word)
	{
		for (int x = 0; x < elements_in_word; x++)
		{
			if (input[x] != word[x])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

void copy(char input[], char word[])
{						//funkcija kas kopē visus elementus no vienas virknes uz otru
	int elements_in_input = size(input);
	for (int x = 0; x < elements_in_input; x++)
	{
		word[x] = input[x];
	}
	word[elements_in_input] = '\0';
}

int main()
{
	ifstream file("tulks.in");
	char input[21];
	char garbage[21];
	char right[]{ "-->" };
	char left[]{ "<--" };
	int count = 0;

	while (file.is_open())
	{													//šīs daļas iemesls ir dabūt skaitu ar vārdu pāriem, lai taupītu atmiņu vēlāk
		file >> garbage;
		if (compare(garbage, right) || compare(garbage, left))
		{
			break;
		}
		file >> garbage;
		count++;
	}
	file.close();

	word* words = new word[count + 1];						//šeit izmantojam count, dinamiski aizvietojam atmiņu. Saraksts ar vārdu pāriem
	*words[0].A = '\0';
	*words[0].B = '\0';

	count = 0;

	ofstream outfile("tulks.out");
	file.open("tulks.in");

	while (!file.eof())
	{
		while (file.is_open())
		{
			word x;
			file >> input;													//lasa visus vārdu pārus no faila, saglabā tos kamēr satiek bultiņu
			if (compare(input, right) || compare(input, left))
			{
				break;
			}
			copy(input, x.A);
			input[0] = '\0';
			file >> input;
			copy(input, x.B);
			input[0] = '\0';
			words[count] = x;
			count++;
		}
		if (compare(input, right))  		//ja tekstu tulko pa labi, sāk rakstīt jaunā failā
		{
			while (file.is_open())
			{
				bool found = false;
				input[0] = '\0';
				file >> input;
				for (int a = 0; a < count; a++)
				{
					if (compare(input, words[a].A))
					{							//ja vārds sakrīt ar kādu no pāriem
						outfile << words[a].B << " ";
						found = true;
						break;
					}
				}
				if (file.eof())
				{
					file.close();
					break;
				}
				if (found == false)
				{								// ja vārds nesakrīt ne ar vienu
					outfile << '?' << input << " ";
				}
			}
		}
		else
		{						//ja tekstu tulko pa kreisi
			while (file.is_open())
			{
				bool found = false;
				input[0] = '\0';
				file >> input;
				for (int a = 0; a < count; a++)
				{
					if (compare(input, words[a].B))
					{
						/*outfile.write(words[a].A, size(words[a].A));
						outfile << " ";*/
						outfile << words[a].A << " ";
						found = true;
						break;
					}
				}
				if (file.eof())
				{
					file.close();
					break;
				}

				if (found == false)
				{
					outfile << '?' << input << " ";
				}
			}
		}
		outfile.close();
	}
}