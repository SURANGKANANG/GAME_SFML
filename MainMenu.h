#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

#define Max_main_menu 5

class MainMenu
{
public:
	MainMenu(float width, float height);

	void draw(RenderWindow& window);
	void HoverMouse_start();
	void HoverMouse_score();
	void HoverMouse_dogdag();
	void HoverMouse_exit();
	void UnHoverMouse_start();
	void UnHoverMouse_score();
	void UnHoverMouse_dogdag();
	void UnHoverMouse_exit();

	int MainMenuPressed() {
		return MainMenuSelected;
	}
	~MainMenu();

private:
	int MainMenuSelected;
	Font font;
	Text mainMenu[Max_main_menu];

};

