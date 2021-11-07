#include "MainMenu.h"

MainMenu::MainMenu(float width, float height)
{
	if (!font.loadFromFile("MEGLORIA.ttf")) {
		std::cout << "No font is here" << std::endl;
	}

	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(sf::Color(76, 107, 179, 255));
	mainMenu[1].setOutlineColor(sf::Color::White);
	mainMenu[1].setOutlineThickness(2);
	mainMenu[1].setString("DOGDAG");
	mainMenu[1].setCharacterSize(70);
	mainMenu[1].setLetterSpacing(5);
	mainMenu[1].setPosition(300, 80);

	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(sf::Color(76, 107, 179, 255));
	mainMenu[2].setOutlineColor(sf::Color::White);
	mainMenu[2].setOutlineThickness(2);
	mainMenu[2].setString("START");
	mainMenu[2].setCharacterSize(50);
	mainMenu[2].setLetterSpacing(5);
	mainMenu[2].setPosition(370, 200);


	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(sf::Color(76, 107, 179, 255));
	mainMenu[3].setOutlineColor(sf::Color::White);
	mainMenu[3].setOutlineThickness(2);
	mainMenu[3].setString("SCORE");
	mainMenu[3].setCharacterSize(50);
	mainMenu[3].setLetterSpacing(5);
	mainMenu[3].setPosition(370, 300);

	mainMenu[4].setFont(font);
	mainMenu[4].setFillColor(sf::Color(76, 107, 179, 255));
	mainMenu[4].setOutlineColor(sf::Color::White);
	mainMenu[4].setOutlineThickness(2);
	mainMenu[4].setString("EXIT");
	mainMenu[4].setCharacterSize(50);
	mainMenu[4].setLetterSpacing(5);
	mainMenu[4].setPosition(390, 400);


	MainMenuSelected = 0;

}

MainMenu::~MainMenu()
{
}

void MainMenu::draw(sf::RenderWindow& window)
{
	for (int i = 1; i < Max_main_menu; i++) {
		window.draw(mainMenu[i]);
	}
}


void MainMenu::HoverMouse_dogdag() {

	mainMenu[1].setFillColor(Color::White);
	mainMenu[1].setOutlineColor(Color(76, 107, 179, 255));
	mainMenu[1].setOutlineThickness(2);

}

void MainMenu::HoverMouse_start() {

	mainMenu[2].setFillColor(Color::White);
	mainMenu[2].setOutlineColor(Color(76, 107, 179, 255));
	mainMenu[2].setOutlineThickness(2);

}

void MainMenu::HoverMouse_score() {

	mainMenu[3].setFillColor(Color::White);
	mainMenu[3].setOutlineColor(Color(76, 107, 179, 255));
	mainMenu[3].setOutlineThickness(2);

}

void MainMenu::HoverMouse_exit() {

	mainMenu[4].setFillColor(Color::White);
	mainMenu[4].setOutlineColor(Color(76, 107, 179, 255));
	mainMenu[4].setOutlineThickness(2);
}

void MainMenu::UnHoverMouse_dogdag() {

	mainMenu[1].setOutlineColor(Color::White);
	mainMenu[1].setOutlineThickness(2);
	mainMenu[1].setFillColor(Color(76, 107, 179, 255));
}

void MainMenu::UnHoverMouse_start()
{
	mainMenu[2].setOutlineColor(Color::White);
	mainMenu[2].setOutlineThickness(2);
	mainMenu[2].setFillColor(Color(76, 107, 179, 255));
}

void MainMenu::UnHoverMouse_score()
{
	mainMenu[3].setOutlineColor(Color::White);
	mainMenu[3].setOutlineThickness(2);
	mainMenu[3].setFillColor(Color(76, 107, 179, 255));
}

void MainMenu::UnHoverMouse_exit()
{
	mainMenu[4].setOutlineColor(Color::White);
	mainMenu[4].setOutlineThickness(2);
	mainMenu[4].setFillColor(Color(76, 107, 179, 255));
}
