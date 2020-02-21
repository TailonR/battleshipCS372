#include "hangman.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <chrono>
std::string hangman::hiddenWord;

bool hangman::playhangman(Ship& sunkenShip, Board& board)
{
	bool didYouWin;
	std::vector<std::string> vectOfWordsForHangman{ "lua", "public", "haskell", "PC", "ram", "cpu", "turing" };
	std::cout << "Do you want to revive a ship?" << std::endl;
	int y = 0;
	std::cin >> y;
	std::cin.ignore();
	if (y == 1)
	{
		std::cout << "Hello! You want you ship back, then win this game" << std::endl;
		bool stillPlayingHangman = true;
		std::cout << "\n\n\n\n" << std::endl;
		hangman::drawHangmanBeginning();
		srand(time(NULL));
		std::string word = vectOfWordsForHangman[rand() % vectOfWordsForHangman.size()];
		std::cout << "The word is: " << word << std::endl;
		hangman::fillHiddenWordWithUnderscores(word.length());
		std::string userEntry = "";
		while (stillPlayingHangman)
		{
			std::cout << "Enter a letter\n\n\n\n" << std::endl;
			std::getline(std::cin, userEntry);
			int numberOfFailedChoices = hangman::drawMan(numberOfMisses(userEntry, word));
			hangman::revealCorrectLetters(userEntry, word);
			std::cout << "\n\n";
			hangman::printWordWithRevealedLetters();
			if (numberOfFailedChoices == 6)
			{
				hangman::drawHangmanEnd();
				stillPlayingHangman = false;
				didYouWin = false;
			}
			else
			{
				if (hangman::hiddenWord == word)
				{
					didYouWin = true;
					stillPlayingHangman = false;
				}
				hangman::drawHangmanBeginning();
			}

		}
		
	}
	return didYouWin;
}

void hangman::fillHiddenWordWithUnderscores(int wordLength)
{
	for (int ii = 0; ii < wordLength; ii++)
	{
		hangman::hiddenWord += "_";
	}
}

std::string hangman::revealCorrectLetters(std::string userGuess, std::string word)
{
	auto pos = word.find(userGuess, 0);
	while (pos != std::string::npos)
	{
		hangman::hiddenWord[pos] = word[pos];
		pos = word.find(userGuess, pos + 1);
	}
	return hangman::hiddenWord;
}

int hangman::numberOfMisses(std::string userGuess, std::string word)
{
	int numMatches = 0;
	auto pos = word.find(userGuess, 0);
	while (pos != std::string::npos)
	{
		numMatches++;
		pos = word.find(userGuess, pos + 1);
	}
	return numMatches;
}

void hangman::printWordWithRevealedLetters()
{
	for (int ii = 0; ii < hangman::hiddenWord.length(); ii++)
	{
		std::cout << hangman::hiddenWord[ii] << " ";
	}
	std::cout << std::endl;
}

int hangman::drawMan(int numMatches)
{
	static int numberOfChances = 0;
	if (numberOfChances == 0)
	{
		if (numMatches == 0)
			numberOfChances++;
	}
	if (numberOfChances == 1)
	{
		std::cout << "          O    " << std::endl;
	}
	else if (numberOfChances == 2)
	{
		if (numMatches == 0)
			numberOfChances++;
		std::cout << "          O    " << std::endl;
		std::cout << "         /";
	}
	else if (numberOfChances == 3)
	{
		if (numMatches == 0)
			numberOfChances++;
		std::cout << "          O    " << std::endl;
		std::cout << "         /";
		std::cout << "|";
	}
	else if (numberOfChances == 4)
	{
		if (numMatches == 0)
			numberOfChances++;
		std::cout << "          O    " << std::endl;
		std::cout << "         /";
		std::cout << "|";
		std::cout << "\\" << std::endl;
	}
	else if (numberOfChances == 5)
	{
		if (numMatches == 0)
			numberOfChances++;
		std::cout << "          O    " << std::endl;
		std::cout << "         /";
		std::cout << "|";
		std::cout << "\\" << std::endl;
		std::cout << "         /";
	}
	else if (numberOfChances == 6)
	{
		if (numMatches == 0)
			numberOfChances++;
		std::cout << "          |" << std::endl;
		std::cout << "          O    " << std::endl;
		std::cout << "         /";
		std::cout << "|";
		std::cout << "\\" << std::endl;
		std::cout << "         /";
		std::cout << "\\" << std::endl;
	}
	return numberOfChances;
}

void hangman::drawHangmanEnd()
{
	
	std::cout << "------              ------------------";
	std::cout << "      |             |" << std::endl;
}

void hangman::drawHangmanBeginning()
{
	std::cout << "\n\n" << std::endl;
	std::cout << "--------------------------------------" << std::endl;
}