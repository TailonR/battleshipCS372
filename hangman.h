#ifndef HANGMAN_HPP
#define HANGMAN_HPP

#include "Ship.hpp"
#include "Board.hpp"
#include <vector>
class hangman
{
public:
	static bool playhangman(Ship&, Board&);
	static std::string hiddenWord;
private:
	static void drawHangmanBeginning();
	static void drawHangmanEnd();
	static int drawMan(int);
	static std::string revealCorrectLetters(std::string,std::string);
	static void printWordWithRevealedLetters();
	static void fillHiddenWordWithUnderscores(int);
	static int numberOfMisses(std::string, std::string);
};

#endif // !HANGMAN_HPP
