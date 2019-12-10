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
	std::string s;

	//1
	//Lees alle characters van deze file in een vector.
	file >> std::noskipws;
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
	std::map<std::string, int> map;
	std::ifstream file2("pg10.txt");
	std::string fileString;
	while (file2) {
		file2 >> fileString;
		if (map.count(fileString) > 0) {
			map[fileString] ++;
		}
		else {
			map[fileString] = 1;
		}
	}

	std::string word;
	int current_max;
	for (unsigned int i = 0; i < 10; i++) {
		current_max = 0;
		for (auto i : map) {
			if (i.second > current_max) {
				current_max = i.second;
				word = i.first;
			}
		}
		std::cout << word << "\n";
		map.erase(word);
	}
	
	sf::sleep(sf::milliseconds(100000));

}
 