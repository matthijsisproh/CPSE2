#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cctype>
#include <map>
#include <sstream> 

int main()
{
	// Open file
	std::string filename = "pg10.txt";
	std::ifstream file(filename);

	//1
	//Lees alle characters van deze file in een vector.
	std::vector<char> Words{
		std::istream_iterator<char>{file},
		std::istream_iterator<char>{}
	}; 
	
	//2
	//Print hoeveel characters de file bevat (vraag het aan de vector).
	std::cout << "Amount of Chars: " << Words.size() << std::endl;

	//3
	//Print hoeveel regels de file bevat (gebruik de vector en een STL algorithme).
	std::cout << "Amount of newlines: " << std::count(Words.begin(), Words.end(), '\n') << std::endl;


	//4
	//Print hoeveel alfabetische characters de file bevat(vector + algorithme).
	std::string alfabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int count = 0;
	std::for_each(alfabet.begin(), alfabet.end(), [&](char & c) {count += std::count(Words.begin(), Words.end(), c); });
	std::cout << "Amount of abc's: " << count << std::endl;

	//5
	//Zet de letters in de vector om in kleine letters(max 3 regels code).
	std::for_each(Words.begin(), Words.end(), [&](char & c) {c = std::tolower(c); });

	//6
	//Tel in een lijst voor iedere letter(a..z) hoe vaak hij voorkomt in de vector(diverse manieren mogelijk).
	std::vector<int> countList;
	std::for_each(alfabet.begin(), alfabet.end(), [&](char & c) {countList.push_back(std::count(Words.begin(), Words.end(), c)); });

	//7
	//Druk deze lijst af 1) op lettervolgorde 2) op hoe vaak een letter voorkomt(gebruikt een algoritme).
	//7.1
	std::for_each(alfabet.begin(), alfabet.end(), [&](char & c) {std::cout << c << ": " << std::count(Words.begin(), Words.end(), c) << std::endl; });
	
	//7.2
	std::sort(countList.begin(), countList.end());
	std::for_each(countList.begin(), countList.end(), [](int & n) {std::cout << n << std::endl; });

	//8
	//Bepaal welke woorden er in de tekst voorkomen en druk de 10 meest voorkomende woorden af.
	//Een woord is aaneengesloten reeks letters. (gebruik een map)
	std::map< std::string, int > words;
	std::ifstream file2("pg10.txt");
	std::string fileString;

	while (file2) {
		file2 >> fileString;
		if (words.count(fileString) > 0) {
			words[fileString]++;
		}
		else {
			words[fileString] = 1;
		}
	}
	/*
	std::string tmp;
	std::vector<std::string> StringVec = {};
	std::vector<std::string> StringCountList = {};
	for (auto i : words) {
		int StringCount = 1;
		//std::cout << i.first << " " << i.second << std::endl;
		StringVec.push_back(i.first);
		for (auto j : StringVec) {
			if (StringVec[i] == StringVec[i][j]) {
				StringCount++;
				std::cout << StringCount << std::endl;
			}
		}
	}

	*/

	sf::sleep(sf::milliseconds(100000));

	
	

}
 