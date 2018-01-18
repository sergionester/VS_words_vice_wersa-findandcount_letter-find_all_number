#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int counter = 0; //счетчик для кол-ва вхождений буквы
	int Y = 0; // идентиф. есть ли цифра в строке, если есть, то 1
	int n = 0;
	int m = 0;
	char letter;
	string num[1024];
	string textin = " ";
	string buff[2048];
	ifstream in("example.txt");	
	if (!in.fail())
	{
		std::cout << "Введите искомую букву(англ.):";
		cin >> letter;
		while (!in.eof())
		{
			textin += in.get();
			if (in.eof()) break;

			for (unsigned int i = 0; i < textin.length(); i++)
			{
				if (textin[i] == letter)
				{
				counter++;
				}
					else if (('0' <= textin[i]) && (textin[i]<= '9'))
					{
						Y = 1;
						num[m] = textin[i];
						m++;
					}
			}
			if (textin != " ")
			{
				if ((textin == ".") || (textin == ",") || (textin == "?") || (textin == "!") || (textin == ":"))
				{
					n++;
					buff[n] = textin;
					textin = "";
				}
				else if (textin == "\n")
				{
					n++;
					buff[n] = " \n";
					textin = " ";
				}
				else
				{					
					buff[n] = buff[n] + textin;
					textin = "";
				}
			}
			else
			{
				n++;
				buff[n] = "";
			}
		}
		in.close();		
		std::cout << "Найдено " << counter << "'" << letter << "'" << endl;
		ofstream out("example_out.txt");
		for (int i = n+1; i>0 ; i--)
		{
			out << buff[i-1];
		}

		if (Y == 1)
		{
			out <<endl<< "Все цифры содержащиеся в тексте: " << endl;
			for (int i = 0; i<sizeof(textin); i++)
				out << num[i] << endl;
		}
		else
		{
			out << "В данном текст нет цифр" << endl;
		}

		out.close();
		return 0;
	}	
	else std::cout << "Error: file not found"<<endl;
}
