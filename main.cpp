#include <iostream>
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Player.h"
#include "Platform.h"
#include <vector>
#include<time.h>
#include <stdlib.h> 
#include<sstream>
#include<SFML/Audio.hpp>
#include "MainMenu.h"
#include <SFML/Window.hpp>
#include <string>
#include <iostream>





static const float VIEW_HEIGHT = 540.0f;
static const float VIEW_WIDTH = 960.0f;



void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_WIDTH);
}

void Showtexet(int x, int y, int num, int size, sf::Color color, sf::RenderWindow& window, sf::Font* font)
{
    sf::Text text;
    text.setFont(*font);
    text.setPosition(x, y);
    string str;
    stringstream ss;
    ss << num;
    ss >> str;
    text.setString(str);
    text.setCharacterSize(size);
    text.setFillColor(color);
    window.draw(text);
}

int main()
{



    // Create Sprite button //
    sf::RectangleShape DogdagButton(sf::Vector2f(165.0f, 60.0f));
    DogdagButton.setPosition({ 300.f, 80.f });
    DogdagButton.setFillColor(sf::Color::Transparent);
   
    sf::RectangleShape StartButton(sf::Vector2f(165.0f, 60.0f));
    StartButton.setPosition({ 370.f, 200.f });
    StartButton.setFillColor(sf::Color::Transparent);

    sf::RectangleShape ScoreButton(sf::Vector2f(165.0f, 60.0f));
    ScoreButton.setPosition({ 370.f, 300.f });
    ScoreButton.setFillColor(sf::Color::Transparent);

    sf::RectangleShape ExitButton(sf::Vector2f(145.0f, 60.0f));
    ExitButton.setPosition({ 360.f, 400.f });
    ExitButton.setFillColor(sf::Color::Transparent);


 

   
    sf::Clock clock_count;
    sf::Time timer;
    sf::Font font;
    font.loadFromFile("MEGLORIA.ttf");
    std::stringstream ss; sf::Text time_show("", font);
    int s = 0;
    int m = 0;
    float dt;
    sf::Clock dt_clock;

    sf::Text textbone;
    textbone.setFont(font);
    textbone.setCharacterSize(30);
    textbone.setFillColor(Color::Magenta);
    textbone.setString("Bone:");
    int counting = 0;

   
    float acceleration = 1.0f;
    float accelerationtime = 0.0f;


    // set BG
    sf::RectangleShape backgroundMainMenu(sf::Vector2f(960.f, 540.0f));
    Texture MainTexture;
    MainTexture.loadFromFile("snowymountains.png");
    backgroundMainMenu.setTexture(&MainTexture);

    // set BG score
    sf::RectangleShape backgroundScore(sf::Vector2f(960.f, 540.0f));
    Texture ScoreTexture;
    ScoreTexture.loadFromFile("bg beaty.jpg");
    backgroundScore.setTexture(&ScoreTexture);
    

    sf::RenderWindow window(sf::VideoMode(VIEW_WIDTH, VIEW_HEIGHT), "Game dogdag", sf::Style::Titlebar | sf::Style::Close);
    MainMenu mainMenu(window.getSize().x, window.getSize().y);

    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(960.0f, 540.0f));
    sf::Texture playerTexture;
    playerTexture.loadFromFile("dog4.png"); //ตัวละคร
  /*  int hp = 10;
    	RectangleShape hpBar;
    	hpBar.setFillColor(Color::Red);
    	hpBar.setSize(Vector2f((float)hp * 20.f, 20.f));
    	hpBar.setPosition(200.f, 10.f);*/
    
    sf::Texture BackgroundTexture;
    BackgroundTexture.loadFromFile("bg2.png");

  
    sf::Texture homeTexture;
    homeTexture.loadFromFile("home2.png");
    sf::Texture starTexture;
    starTexture.loadFromFile("star.png");
    sf::Texture boneTexture;
    boneTexture.loadFromFile("bone.png");
    sf::Texture puppyTexture;
    puppyTexture.loadFromFile("puppy.png");


    
    Player player(&playerTexture, sf::Vector2u(8, 3), 0.2f, 280.0f, 150.0f); //ความเร็วเเละการกระโดด
    
    sf::RectangleShape bg;
    bg.setSize(sf::Vector2f(16883.f, 780.f));
    bg.setPosition(sf::Vector2f(-500.0f, -280.0f));
    bg.setTexture(&BackgroundTexture);

    sf::RectangleShape home;
    home.setSize(sf::Vector2f(260.f, 256.f));
    home.setPosition(sf::Vector2f(15500.0f, 250.0f)); //15500
    home.setTexture(&homeTexture);

    /*sf::RectangleShape puppy;
    puppy.setSize(sf::Vector2f(200.f, 200.f));
    puppy.setPosition(sf::Vector2f(player.GetPosition().x + 350, player.GetPosition().y - 300));
    puppy.setTexture(&puppyTexture);*/

    
  
    //กระดูก
    srand(time(NULL));
    float bx = rand() % 480 + 0; float by = rand() % 300 + 200;
    Platform bone(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx, by));
    float bx1 = rand() % 480 + 480; float by1 = rand() % 300 + 200;
    Platform bone1(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx1, by1));
    float bx2 = rand() % 480 + 960; float by2 = rand() % 300 + 200;
    Platform bone2(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx2, by2));
    float bx3 = rand() % 480 + 1440; float by3 = rand() % 300 + 200;
    Platform bone3(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx3, by3));
    float bx4 = rand() % 480 + 1920; float by4 = rand() % 300 + 200;
    Platform bone4(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx4, by4));
    float bx5 = rand() % 480 + 2400; float by5 = rand() % 300 + 200;
    Platform bone5(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx5, by5));

    float bx6 = rand() % 480 + 2880; float by6 = rand() % 300 + 200;
    Platform bone6(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx6, by6));
    float bx7 = rand() % 480 + 3360; float by7 = rand() % 300 + 200;
    Platform bone7(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx7, by7));
    float bx8 = rand() % 480 + 3840; float by8 = rand() % 300 + 200;
    Platform bone8(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx8, by8));
    float bx9 = rand() % 480 + 4320; float by9 = rand() % 300 + 200;
    Platform bone9(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx9, by9));
    float bx10 = rand() % 480 + 4800; float by10 = rand() % 300 + 200;
    Platform bone10(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx10, by10));
    float bx11 = rand() % 480 + 5280; float by11 = rand() % 300 + 200;
    Platform bone11(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx11, by11));

    float bx12 = rand() % 480 + 5760; float by12 = rand() % 300 + 200;
    Platform bone12(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx12, by12));
    float bx13 = rand() % 480 + 6240; float by13 = rand() % 300 + 200;
    Platform bone13(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx13, by13));
    float bx14 = rand() % 480 + 6720; float by14 = rand() % 300 + 200;
    Platform bone14(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx14, by14));
    float bx15 = rand() % 480 + 7200; float by15 = rand() % 300 + 200;
    Platform bone15(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx15, by15));
    float bx16 = rand() % 480 + 7680; float by16 = rand() % 300 + 200;
    Platform bone16(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx16, by16));
    float bx17 = rand() % 480 + 8160; float by17 = rand() % 300 + 200;
    Platform bone17(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx17, by17));

    float bx18 = rand() % 480 + 8640; float by18 = rand() % 300 + 200;
    Platform bone18(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx18, by18));
    float bx19 = rand() % 480 + 9120; float by19 = rand() % 300 + 200;
    Platform bone19(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx19, by19));
    float bx20 = rand() % 480 + 9600; float by20 = rand() % 300 + 200;
    Platform bone20(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx20, by20));
    float bx21 = rand() % 480 + 10080; float by21 = rand() % 300 + 200;
    Platform bone21(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx21, by21));
    float bx22 = rand() % 480 + 10560; float by22 = rand() % 300 + 200;
    Platform bone22(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx22, by22));
    float bx23 = rand() % 480 + 11010; float by23 = rand() % 300 + 200;
    Platform bone23(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx23, by23));

    float bx24 = rand() % 480 + 11520; float by24 = rand() % 300 + 200;
    Platform bone24(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx24, by24));
    float bx25 = rand() % 480 + 12000; float by25 = rand() % 300 + 200;
    Platform bone25(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx25, by25));
    float bx26 = rand() % 480 + 12480; float by26 = rand() % 300 + 200;
    Platform bone26(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx26, by26));
    float bx27 = rand() % 480 + 12960; float by27 = rand() % 300 + 200;
    Platform bone27(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx27, by27));
    float bx28 = rand() % 480 + 13440; float by28 = rand() % 300 + 200;
    Platform bone28(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx28, by28));
    float bx29 = rand() % 480 + 13920; float by29 = rand() % 300 + 200;
    Platform bone29(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx29, by29));

    float bx30 = rand() % 480 + 14400; float by30 = rand() % 300 + 200;
    Platform bone30(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx30, by30));
    float bx31 = rand() % 480 + 14880; float by31 = rand() % 300 + 200;
    Platform bone31(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx31, by31));
    float bx32 = rand() % 480 + 15360; float by32 = rand() % 300 + 200;
    Platform bone32(&boneTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(bx32, by32));
   





    //ดาวตก

    float sx = rand() % 480 + 0;
    Platform star(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx, -100.0f));
    float sx1 = rand() % 480 + 480;
    Platform star1(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx1, -100.0f));
    float sx2 = rand() % 480 + 960;
    Platform star2(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx2, -100.0f));
    float sx3 = rand() % 480 + 1440;
    Platform star3(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx3, -100.0f));
    float sx4 = rand() % 480 + 1920;
    Platform star4(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx4, -100.0f));
    float sx5 = rand() % 480 + 2400;
    Platform star5(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx5, -100.0f));
    float sx6 = rand() % 480 + 2880;
    Platform star6(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx6, -100.0f));
    float sx7 = rand() % 480 + 3360;
    Platform star7(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx7, -100.0f));
    float sx8 = rand() % 480 + 3840;
    Platform star8(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx8, -100.0f));
    float sx9 = rand() % 480 + 4320;
    Platform star9(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx9, -100.0f));
    float sx10 = rand() % 480 + 4800;
    Platform star10(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx10, -100.0f));
    float sx11 = rand() % 480 + 5280;
    Platform star11(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx11, -100.0f));
    float sx12 = rand() % 480 + 5760;
    Platform star12(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx12, -100.0f));
    float sx13 = rand() % 480 + 6240;
    Platform star13(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx13, -100.0f));
    float sx14 = rand() % 480 + 6720;
    Platform star14(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx14, -100.0f));
    float sx15 = rand() % 480 + 7200;
    Platform star15(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx15, -100.0f));
    float sx16 = rand() % 480 + 7680;
    Platform star16(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx16, -100.0f));
    float sx17 = rand() % 480 + 8160;
    Platform star17(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx17, -100.0f));
    float sx18 = rand() % 480 + 8640;
    Platform star18(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx18, -100.0f));
    float sx19 = rand() % 480 + 9120;
    Platform star19(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx19, -100.0f));


    float sx20 = rand() % 240 + 9600;
    Platform star20(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx20, -100.0f));
    float sx21 = rand() % 240 + 9840;
    Platform star21(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx21, -100.0f));
    float sx22 = rand() % 240 + 10080;
    Platform star22(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx22, -100.0f));
    float sx23 = rand() % 240 + 10320;
    Platform star23(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx23, -100.0f));
    float sx24 = rand() % 240 + 10560;
    Platform star24(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx24, -100.0f));
    float sx25 = rand() % 240 + 10800;
    Platform star25(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx25, -100.0f));
    float sx26 = rand() % 240 + 11040;
    Platform star26(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx26, -100.0f));
    float sx27 = rand() % 240 + 11280;
    Platform star27(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx27, -100.0f));
    float sx28 = rand() % 240 + 11520;
    Platform star28(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx28, -100.0f));
    float sx29 = rand() % 240 + 11760;
    Platform star29(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx29, -100.0f));
    float sx30 = rand() % 240 + 12000;
    Platform star30(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx30, -100.0f));
    float sx31 = rand() % 240 + 12240;
    Platform star31(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx31, -100.0f));
    float sx32 = rand() % 240 + 12480;
    Platform star32(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx32, -100.0f));
    float sx33 = rand() % 240 + 12720;
    Platform star33(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx33, -100.0f));
    float sx34 = rand() % 240 + 12960;
    Platform star34(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx34, -100.0f));
    float sx35 = rand() % 240 + 13200;
    Platform star35(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx35, -100.0f));
    float sx36 = rand() % 240 + 13440;
    Platform star36(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx36, -100.0f));
    float sx37 = rand() % 240 + 13680;
    Platform star37(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx37, -100.0f));
    float sx38 = rand() % 240 + 13920;
    Platform star38(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx38, -100.0f));
    float sx39 = rand() % 240 + 14160;
    Platform star39(&starTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(sx39, -100.0f));
   
    

    std::vector<Platform> platforms;
    platforms.push_back(Platform(nullptr, sf::Vector2f(37000.0f, 200.0f), sf::Vector2f(480.0f, 600.0f))); //stage-7000
    platforms.push_back(Platform(nullptr, sf::Vector2f(1000.0f, 25.0f), sf::Vector2f(800.0f, 300.0f))); //1
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 150.0f), sf::Vector2f(300.0f, 500.0f))); //2
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 150.0f), sf::Vector2f(560.0f, 500.0f))); //3
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 150.0f), sf::Vector2f(820.0f, 500.0f))); //4
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 150.0f), sf::Vector2f(1080.0f, 500.0f))); //5
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 150.0f), sf::Vector2f(1500.0f, 500.0f))); //4
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 25.0f), sf::Vector2f(1900.0f, 380.0f)));  //5*
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 25.0f), sf::Vector2f(2200.0f, 370.0f)));  //6*
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 150.0f), sf::Vector2f(2600.0f, 500.0f))); //7
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 25.0f), sf::Vector2f(3000.0f, 380.0f)));  //8*
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 25.0f), sf::Vector2f(3400.0f, 350.0f)));  //9*
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 180.0f), sf::Vector2f(3800.0f, 450.0f))); //10
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 150.0f), sf::Vector2f(4200.0f, 500.0f))); //11
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 180.0f), sf::Vector2f(4600.0f, 500.0f))); //12
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 150.0f), sf::Vector2f(5000.0f, 500.0f))); //13
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 180.0f), sf::Vector2f(5400.0f, 500.0f))); //14
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 180.0f), sf::Vector2f(5800.0f, 450.0f))); //15
    platforms.push_back(Platform(nullptr, sf::Vector2f(300.0f, 25.0f), sf::Vector2f(6200.0f, 380.0f)));  //16*
    platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 200.0f), sf::Vector2f(6200.0f, 380.0f)));  //17*
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 25.0f), sf::Vector2f(6700.0f, 380.0f)));  //18*
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 25.0f), sf::Vector2f(7000.0f, 370.0f)));  //19*
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 150.0f), sf::Vector2f(7400.0f, 500.0f))); //20
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 180.0f), sf::Vector2f(7800.0f, 500.0f))); //21
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 180.0f), sf::Vector2f(8200.0f, 450.0f))); //22
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 25.0f), sf::Vector2f(8600.0f, 380.0f)));  //23*
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 25.0f), sf::Vector2f(9000.0f, 370.0f)));  //24*
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 150.0f), sf::Vector2f(9400.0f, 500.0f))); //25
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 25.0f), sf::Vector2f(9800.0f, 380.0f)));  //26*
    platforms.push_back(Platform(nullptr, sf::Vector2f(500.0f, 25.0f), sf::Vector2f(10200.0f, 380.0f)));  //27*
    platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 200.0f), sf::Vector2f(10600.0f, 380.0f)));  //28*
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 180.0f), sf::Vector2f(11000.0f, 450.0f)));  //29
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 150.0f), sf::Vector2f(11400.0f, 500.0f)));  //30
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 25.0f), sf::Vector2f(11800.0f, 450.0f)));  //31*
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 25.0f), sf::Vector2f(12200.0f, 400.0f)));  //32*
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 25.0f), sf::Vector2f(12600.0f, 350.0f)));  //33*
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 25.0f), sf::Vector2f(13000.0f, 300.0f)));  //34*
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 25.0f), sf::Vector2f(13400.0f, 380.0f)));  //35*
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 25.0f), sf::Vector2f(13800.0f, 300.0f)));  //36*
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 25.0f), sf::Vector2f(14200.0f, 400.0f)));  //37*
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 25.0f), sf::Vector2f(14600.0f, 380.0f)));  //38*
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 25.0f), sf::Vector2f(15000.0f, 300.0f)));  //39*
    
   

    float deltaTime = 0.0f;

    sf::Clock clock;
    
    goto menu;

menu:
    //Main Menu Open
    while (window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {

            while (window.pollEvent(event)) {
                if (event.type == Event::Closed) {
                    window.close();
                }
                if (event.type == Event::KeyPressed) {
                    if (event.key.code == Keyboard::Escape) {
                        window.close();
                    }
                }
            }

            // Check hover

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if (DogdagButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                {
                   // goto ;
                }
                
                if (StartButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                {
                   goto play;
                }
                if (ScoreButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                {
                    goto score;
                }
                if (DogdagButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                {
                    // goto ;
                }
                
                if (ExitButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                {
                    window.close();
                }
            }
            if (event.type == Event::Closed)
            {
                window.close();
            }

            break;
        }


        window.clear();
        window.draw(backgroundMainMenu);
        window.draw(StartButton);
        window.draw(DogdagButton);
        window.draw(ScoreButton);
        window.draw(ExitButton);
       
        mainMenu.draw(window);
        window.display();


    }

 play:
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        if (deltaTime > 1.0f / 20.0f)
            deltaTime = 1.0f / 20.0f;

        sf::Event ev;
        while (window.pollEvent(ev))
        {
            if (ev.type == sf::Event::Closed)
                window.close();
            else if (ev.type == sf::Event::Resized)
            {
                ResizeView(window, view);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
                view.reset(sf::FloatRect(0, 0, VIEW_WIDTH, VIEW_HEIGHT));
                // view.setCenter(sf::Vector2f(player.GetPosition().x, player.GetPosition().y - 100.0f));
                window.setView(view);
                goto menu;
            }
          

        }

        player.Update(deltaTime,acceleration);
          dt = dt_clock.restart().asSeconds();
            clock.restart();
            if (accelerationtime -deltaTime > 0)
                accelerationtime -= deltaTime;
            else
                acceleration = 1;
            ss.str("");

            timer = clock_count.getElapsedTime();
            s = timer.asSeconds();
            m = s / 60;
            s = s - (m * 60);

            if (m < 10)
            {
                ss << "0" << m;
            }
            if (s < 10)
            {
                ss << " : " << "0" << s;
            }
            else
            {
                ss << " : " << s;
            }

            if (m == 1 && s >= 50) {
                time_show.setFillColor(sf::Color::Red);
            }

            if (m == 2) {
                window.close();
            }


            time_show.setString(ss.str());

       

        if (star.body.getPosition().y >= 600.0f)
        {


            float sx = rand() % 480 + 0;
            star.body.setPosition(sf::Vector2f(sx, -100.0f));
            float sx1 = rand() % 480 + 480;
            star1.body.setPosition(sf::Vector2f(sx1, -100.0f));
            float sx2 = rand() % 480 + 960;
            star2.body.setPosition(sf::Vector2f(sx2, -100.0f));
            float sx3 = rand() % 480 + 1440;
            star3.body.setPosition(sf::Vector2f(sx3, -100.0f));
            float sx4 = rand() % 480 + 1920;
            star4.body.setPosition(sf::Vector2f(sx4, -100.0f));
            float sx5 = rand() % 480 + 2400;
            star5.body.setPosition(sf::Vector2f(sx5, -100.0f));
            float sx6 = rand() % 480 + 2880;
            star6.body.setPosition(sf::Vector2f(sx6, -100.0f));
            float sx7 = rand() % 480 + 3360;
            star7.body.setPosition(sf::Vector2f(sx7, -100.0f));
            float sx8 = rand() % 480 + 3360;
            star8.body.setPosition(sf::Vector2f(sx8, -100.0f));
            float sx9 = rand() % 480 + 4320;
            star9.body.setPosition(sf::Vector2f(sx9, -100.0f));
            float sx10 = rand() % 480 + 4800;
            star10.body.setPosition(sf::Vector2f(sx10, -100.0f));
            float sx11 = rand() % 480 + 5280;
            star11.body.setPosition(sf::Vector2f(sx11, -100.0f));
            float sx12 = rand() % 480 + 5760;
            star12.body.setPosition(sf::Vector2f(sx12, -100.0f));
            float sx13 = rand() % 480 + 6240;
            star13.body.setPosition(sf::Vector2f(sx13, -100.0f));
            float sx14 = rand() % 480 + 6720;
            star14.body.setPosition(sf::Vector2f(sx14, -100.0f));
            float sx15 = rand() % 480 + 7200;
            star15.body.setPosition(sf::Vector2f(sx15, -100.0f));
            float sx16 = rand() % 480 + 7680;
            star16.body.setPosition(sf::Vector2f(sx16, -100.0f));
            float sx17 = rand() % 480 + 8160;
            star17.body.setPosition(sf::Vector2f(sx17, -100.0f));
            float sx18 = rand() % 480 + 8640;
            star18.body.setPosition(sf::Vector2f(sx18, -100.0f));
            float sx19 = rand() % 480 + 9120;
            star19.body.setPosition(sf::Vector2f(sx19, -100.0f));


            float sx20 = rand() % 240 + 9600;
            star20.body.setPosition(sf::Vector2f(sx20, -100.0f));
            float sx21 = rand() % 240 + 9840;
            star21.body.setPosition(sf::Vector2f(sx21, -100.0f));
            float sx22 = rand() % 240 + 10080;
            star22.body.setPosition(sf::Vector2f(sx22, -100.0f));
            float sx23 = rand() % 240 + 10320;
            star23.body.setPosition(sf::Vector2f(sx23, -100.0f));
            float sx24 = rand() % 240 + 10560;
            star24.body.setPosition(sf::Vector2f(sx24, -100.0f));
            float sx25 = rand() % 240 + 10800;
            star25.body.setPosition(sf::Vector2f(sx25, -100.0f));
            float sx26 = rand() % 240 + 11040;
            star26.body.setPosition(sf::Vector2f(sx26, -100.0f));
            float sx27 = rand() % 240 + 11280;
            star27.body.setPosition(sf::Vector2f(sx27, -100.0f));
            float sx28 = rand() % 240 + 11520;
            star28.body.setPosition(sf::Vector2f(sx28, -100.0f));
            float sx29 = rand() % 240 + 11760;
            star29.body.setPosition(sf::Vector2f(sx29, -100.0f));
            float sx30 = rand() % 240 + 12000;
            star30.body.setPosition(sf::Vector2f(sx30, -100.0f));
            float sx31 = rand() % 240 + 12240;
            star31.body.setPosition(sf::Vector2f(sx31, -100.0f));
            float sx32 = rand() % 240 + 12480;
            star32.body.setPosition(sf::Vector2f(sx32, -100.0f));
            float sx33 = rand() % 240 + 12720;
            star33.body.setPosition(sf::Vector2f(sx33, -100.0f));
            float sx34 = rand() % 240 + 12960;
            star34.body.setPosition(sf::Vector2f(sx34, -100.0f));
            float sx35 = rand() % 240 + 13200;
            star35.body.setPosition(sf::Vector2f(sx35, -100.0f));
            float sx36 = rand() % 240 + 13440;
            star36.body.setPosition(sf::Vector2f(sx36, -100.0f));
            float sx37 = rand() % 240 + 13680;
            star37.body.setPosition(sf::Vector2f(sx37, -100.0f));
            float sx38 = rand() % 240 + 13920;
            star38.body.setPosition(sf::Vector2f(sx38, -100.0f));
            float sx39 = rand() % 240 + 14160;
            star39.body.setPosition(sf::Vector2f(sx39, -100.0f));




        }
        else

            star.body.move(sf::Vector2f(0.0f, 100.0f) * 2.0f * deltaTime);
            
        star1.body.move(sf::Vector2f(0.0f, 100.0f) * 2.50f * deltaTime);
        star2.body.move(sf::Vector2f(0.0f, 100.0f) * 2.80f * deltaTime);
        star3.body.move(sf::Vector2f(0.0f, 100.0f) * 3.0f * deltaTime);
        star4.body.move(sf::Vector2f(0.0f, 100.0f) * 2.5f * deltaTime);
        star5.body.move(sf::Vector2f(0.0f, 100.0f) * 3.50f * deltaTime);
        star6.body.move(sf::Vector2f(0.0f, 100.0f) * 3.0f * deltaTime);
        star7.body.move(sf::Vector2f(0.0f, 100.0f) * 3.80f * deltaTime);
        star8.body.move(sf::Vector2f(0.0f, 100.0f) * 3.0f * deltaTime);
        star9.body.move(sf::Vector2f(0.0f, 100.0f) * 2.80f * deltaTime);
        star10.body.move(sf::Vector2f(0.0f, 100.0f) * 2.30f * deltaTime);
        star11.body.move(sf::Vector2f(0.0f, 100.0f) * 2.0f * deltaTime);
        star12.body.move(sf::Vector2f(0.0f, 100.0f) * 2.50f * deltaTime);
        star13.body.move(sf::Vector2f(0.0f, 100.0f) * 2.80f * deltaTime);
        star14.body.move(sf::Vector2f(0.0f, 100.0f) * 3.0f * deltaTime);
        star15.body.move(sf::Vector2f(0.0f, 100.0f) * 3.50f * deltaTime);
        star16.body.move(sf::Vector2f(0.0f, 100.0f) * 3.90f * deltaTime);
        star17.body.move(sf::Vector2f(0.0f, 100.0f) * 3.20f * deltaTime);
        star18.body.move(sf::Vector2f(0.0f, 100.0f) * 2.50f * deltaTime);
        star19.body.move(sf::Vector2f(0.0f, 100.0f) * 3.0f * deltaTime);

        star20.body.move(sf::Vector2f(0.0f, 100.0f) * 3.50f * deltaTime);
        star21.body.move(sf::Vector2f(0.0f, 100.0f) * 4.0f * deltaTime);
        star22.body.move(sf::Vector2f(0.0f, 100.0f) * 4.50f * deltaTime);
        star23.body.move(sf::Vector2f(0.0f, 100.0f) * 4.90f * deltaTime);
        star24.body.move(sf::Vector2f(0.0f, 100.0f) * 5.50f * deltaTime);
        star25.body.move(sf::Vector2f(0.0f, 100.0f) * 5.0f * deltaTime);
        star26.body.move(sf::Vector2f(0.0f, 100.0f) * 5.50f * deltaTime);
        star27.body.move(sf::Vector2f(0.0f, 100.0f) * 4.80f * deltaTime);
        star28.body.move(sf::Vector2f(0.0f, 100.0f) * 5.30f * deltaTime);
        star29.body.move(sf::Vector2f(0.0f, 100.0f) * 5.90f * deltaTime);
        star30.body.move(sf::Vector2f(0.0f, 100.0f) * 6.50f * deltaTime);
        star31.body.move(sf::Vector2f(0.0f, 100.0f) * 6.0f * deltaTime);
        star32.body.move(sf::Vector2f(0.0f, 100.0f) * 6.50f * deltaTime);
        star33.body.move(sf::Vector2f(0.0f, 100.0f) * 6.90f * deltaTime);
        star34.body.move(sf::Vector2f(0.0f, 100.0f) * 6.40f * deltaTime);
        star35.body.move(sf::Vector2f(0.0f, 100.0f) * 7.0f * deltaTime);
        star36.body.move(sf::Vector2f(0.0f, 100.0f) * 7.50f * deltaTime);
        star37.body.move(sf::Vector2f(0.0f, 100.0f) * 8.50f * deltaTime);
        star38.body.move(sf::Vector2f(0.0f, 100.0f) * 8.50f * deltaTime);
        star39.body.move(sf::Vector2f(0.0f, 100.0f) * 8.50f * deltaTime);


         
        Collider playerCollision = player.GetCollider();
        sf::Vector2f velocity;  velocity.x = 0.0f; 
        

        sf::Vector2f direction;
        for (Platform& platform : platforms)
            if (platform.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
                player.OnCollosion(direction);
            }

        view.setCenter(sf::Vector2f(player.GetPosition().x, player.GetPosition().y - 100.0f));
        if (velocity.x >= 0) {
           time_show.setPosition(player.GetPosition().x +360, player.GetPosition().y - 350);
           textbone.setPosition(player.GetPosition().x + 350, player.GetPosition().y - 300);
          
       }
      
       
        
        player.OnCollosion(direction);
        
    
        
        for (Platform&boneTexture : platforms)
            if (bone.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
                bone.body.setPosition(-600.0f, bone.body.getPosition().y); 
                counting++;
            }
      
        if (bone1.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone1.body.setPosition(-600.0f, bone1.body.getPosition().y);
            counting++;
            
        }
        if (bone2.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone2.body.setPosition(-600.0f, bone2.body.getPosition().y);
            counting++;
        }
        if (bone3.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone3.body.setPosition(-600.0f, bone3.body.getPosition().y);
            counting++;
        }
        if (bone4.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone4.body.setPosition(-600.0f, bone4.body.getPosition().y);
            counting++;
        }
        if (bone5.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone5.body.setPosition(-600.0f, bone5.body.getPosition().y);
            counting++;
        }
        if (bone6.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone6.body.setPosition(-600.0f, bone6.body.getPosition().y);
            counting++;
        }
        if (bone7.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone7.body.setPosition(-600.0f, bone7.body.getPosition().y);
            counting++;
        }
        if (bone8.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone8.body.setPosition(-600.0f, bone8.body.getPosition().y);
            counting++;
        }
        if (bone9.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone9.body.setPosition(-600.0f, bone9.body.getPosition().y);
            counting++;
        }
        if (bone10.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone10.body.setPosition(-600.0f, bone10.body.getPosition().y);
            counting++;
        }
        if (bone11.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone11.body.setPosition(-600.0f, bone11.body.getPosition().y);
            counting++;
        }
        if (bone12.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone12.body.setPosition(-600.0f, bone12.body.getPosition().y);
            counting++;
        }
        if (bone13.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone13.body.setPosition(-600.0f, bone13.body.getPosition().y);
            counting++;
        }
        if (bone14.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone14.body.setPosition(-600.0f, bone14.body.getPosition().y);
            counting++;
        }
        if (bone15.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone15.body.setPosition(-600.0f, bone15.body.getPosition().y);
            counting++;
        }
        if (bone16.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone16.body.setPosition(-600.0f, bone16.body.getPosition().y);
            counting++;
        }
        if (bone17.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone17.body.setPosition(-600.0f, bone17.body.getPosition().y);
            counting++;
        }
        if (bone18.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone18.body.setPosition(-600.0f, bone18.body.getPosition().y);
            counting++;
        }
        if (bone19.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone19.body.setPosition(-600.0f, bone19.body.getPosition().y);
            counting++;
        }
        if (bone20.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone20.body.setPosition(-600.0f, bone20.body.getPosition().y);
            counting++;
        }
        if (bone21.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone21.body.setPosition(-600.0f, bone21.body.getPosition().y);
            counting++;
        }
        if (bone22.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone22.body.setPosition(-600.0f, bone22.body.getPosition().y);
            counting++;
        }
        if (bone23.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone23.body.setPosition(-600.0f, bone23.body.getPosition().y);
            counting++;
        }
        if (bone24.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone24.body.setPosition(-600.0f, bone24.body.getPosition().y);
            counting++;
        }
        if (bone25.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone25.body.setPosition(-600.0f, bone25.body.getPosition().y);
            counting++;
        }
        if (bone26.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone26.body.setPosition(-600.0f, bone26.body.getPosition().y);
            counting++;
        }
        if (bone27.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone27.body.setPosition(-600.0f, bone27.body.getPosition().y);
            counting++;
        }
        if (bone28.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone28.body.setPosition(-600.0f, bone28.body.getPosition().y);
            counting++;
        }
        if (bone29.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone29.body.setPosition(-600.0f, bone29.body.getPosition().y);
            counting++;
        }
        if (bone30.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone30.body.setPosition(-600.0f, bone30.body.getPosition().y);
            counting++;
        }
        if (bone31.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone31.body.setPosition(-600.0f, bone31.body.getPosition().y);
            counting++;
        }
        if (bone32.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            bone32.body.setPosition(-600.0f, bone32.body.getPosition().y);
            counting++;
        }

        printf("%f\n", accelerationtime);
        for (Platform& starTexture : platforms)
            if (star.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
                star.body.setPosition(star.body.getPosition().x, 1000);
                acceleration = 0.9f;
                accelerationtime +=5.0f;
             
            }
        if (star1.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star1.body.setPosition(star1.body.getPosition().x, 1000);
            acceleration = 0.9f;
            accelerationtime += 5.0f;
        }
        if (star2.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star2.body.setPosition(star2.body.getPosition().x, 1000);
            acceleration = 0.9f;
            accelerationtime += 5.0f;
        }
        if (star3.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star3.body.setPosition(star3.body.getPosition().x, 1000);
            acceleration = 0.9f;
            accelerationtime += 5.0f;
        }
        if (star4.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star4.body.setPosition(star4.body.getPosition().x, 1000);
            acceleration = 0.9f;
            accelerationtime += 5.0f;
        }
        if (star5.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star5.body.setPosition(star5.body.getPosition().x, 1000);
            acceleration = 0.9f;
            accelerationtime += 5.0f;
        }
        if (star6.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star6.body.setPosition(star6.body.getPosition().x, 1000);
            acceleration = 0.9f;
            accelerationtime += 5.0f;
        }
        if (star7.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star7.body.setPosition(star7.body.getPosition().x, 1000);
            acceleration = 0.9f;
            accelerationtime += 5.0f;
        }
        if (star8.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star8.body.setPosition(star8.body.getPosition().x, 1000);
            acceleration = 0.9f;
            accelerationtime += 5.0f;
        }
        if (star9.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star9.body.setPosition(star9.body.getPosition().x, 1000);
            acceleration = 0.9f;
            accelerationtime += 5.0f;
        }
        if (star10.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star10.body.setPosition(star10.body.getPosition().x, 1000);
            acceleration = 0.7f;
            accelerationtime += 5.0f;
        }
        if (star11.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star11.body.setPosition(star11.body.getPosition().x, 1000);
            acceleration = 0.7f;
            accelerationtime += 5.0f;
        }
        if (star12.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star12.body.setPosition(star12.body.getPosition().x, 1000);
            acceleration = 0.7f;
            accelerationtime += 5.0f;
        }
        if (star13.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star13.body.setPosition(star13.body.getPosition().x, 1000);
            acceleration = 0.7f;
            accelerationtime += 5.0f;
        }
        if (star14.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star14.body.setPosition(star14.body.getPosition().x, 1000);
            acceleration = 0.7f;
            accelerationtime += 5.0f;
        }
        if (star15.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star15.body.setPosition(star15.body.getPosition().x, 1000);
            acceleration = 0.7f;
            accelerationtime += 5.0f;
        }
        if (star16.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star16.body.setPosition(star16.body.getPosition().x, 1000);
            acceleration = 0.7f;
            accelerationtime += 5.0f;
        }
        if (star17.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star17.body.setPosition(star17.body.getPosition().x, 1000);
            acceleration = 0.7f;
            accelerationtime += 5.0f;
        }
        if (star18.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star18.body.setPosition(star18.body.getPosition().x, 1000);
            acceleration = 0.7f;
            accelerationtime += 5.0f;
        }
        if (star19.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star19.body.setPosition(star19.body.getPosition().x, 1000);
            acceleration = 0.7f;
            accelerationtime += 5.0f;
        }
        if (star20.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star20.body.setPosition(star20.body.getPosition().x, 1000);
            acceleration = 0.7f;
            accelerationtime += 5.0f;
        }
        if (star21.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star21.body.setPosition(star21.body.getPosition().x, 1000);
            acceleration = 0.7f;
            accelerationtime += 5.0f;
        }
        if (star22.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star22.body.setPosition(star22.body.getPosition().x, 1000);
            acceleration = 0.6f;
            accelerationtime += 5.0f;
        }
        if (star23.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star23.body.setPosition(star23.body.getPosition().x, 1000);
            acceleration = 0.6f;
            accelerationtime += 5.0f;
        }
        if (star24.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star24.body.setPosition(star24.body.getPosition().x, 1000);
            acceleration = 0.6f;
            accelerationtime += 5.0f;
        }
        if (star24.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star24.body.setPosition(star24.body.getPosition().x, 1000);
            acceleration = 0.6f;
            accelerationtime += 5.0f;
        }
        if (star25.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star25.body.setPosition(star25.body.getPosition().x, 1000);
            acceleration = 0.6f;
            accelerationtime += 5.0f;
        }
        if (star26.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star26.body.setPosition(star26.body.getPosition().x, 1000);
            acceleration = 0.6f;
            accelerationtime += 5.0f;
        }
        if (star27.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star27.body.setPosition(star27.body.getPosition().x, 1000);
            acceleration = 0.6f;
            accelerationtime += 5.0f;
        }
        if (star28.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star28.body.setPosition(star28.body.getPosition().x, 1000);
            acceleration = 0.6f;
            accelerationtime += 5.0f;
        }
        if (star29.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star29.body.setPosition(star29.body.getPosition().x, 1000);
            acceleration = 0.6f;
            accelerationtime += 5.0f;
        }
        if (star30.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star30.body.setPosition(star30.body.getPosition().x, 1000);
            acceleration = 0.6f;
            accelerationtime += 5.0f;
        }
        if (star31.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star31.body.setPosition(star31.body.getPosition().x, 1000);
            acceleration = 0.6f;
            accelerationtime += 5.0f;
        }
        if (star32.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star32.body.setPosition(star32.body.getPosition().x, 1000);
            acceleration = 0.6f;
            accelerationtime += 5.0f;
        }
        if (star33.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star33.body.setPosition(star33.body.getPosition().x, 1000);
            acceleration = 0.5f;
            accelerationtime += 3.0f;
        }
        if (star34.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star34.body.setPosition(star34.body.getPosition().x, 1000);
            acceleration = 0.5f;
            accelerationtime += 3.0f;
        }
        if (star35.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star35.body.setPosition(star35.body.getPosition().x, 1000);
            acceleration = 0.5f;
            accelerationtime += 3.0f;
        }
        if (star36.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star36.body.setPosition(star36.body.getPosition().x, 1000);
            acceleration = 0.5f;
            accelerationtime += 3.0f;
        }
        if (star37.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star37.body.setPosition(star37.body.getPosition().x, 1000);
            acceleration = 0.5f;
            accelerationtime += 3.0f;
        }
        if (star38.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star38.body.setPosition(star38.body.getPosition().x, 1000);
            acceleration = 0.5f;
            accelerationtime += 3.0f;
        }
        if (star39.GetCollider().CheckCollider(playerCollision, direction, 1.0f)) {
            star39.body.setPosition(star39.body.getPosition().x, 1000);
            acceleration = 0.5f;
            accelerationtime += 3.0f;
        }

        window.clear(sf::Color(150, 150, 150));
        window.setView(view);
        window.draw(bg);
        window.draw(time_show);
        window.draw(home);
       /* window.draw(puppy);*/
        star.Draw(window);
        star1.Draw(window);
        star2.Draw(window);
        star3.Draw(window);
        star4.Draw(window);
        star5.Draw(window);
        star6.Draw(window);
        star7.Draw(window);
        star8.Draw(window);
        star9.Draw(window);
        star9.Draw(window);
        star10.Draw(window);
        star11.Draw(window);
        star12.Draw(window);
        star13.Draw(window);
        star14.Draw(window);
        star15.Draw(window);
        star16.Draw(window);
        star17.Draw(window);
        star18.Draw(window);
        star19.Draw(window);
        star20.Draw(window);

        star21.Draw(window);
        star22.Draw(window);
        star23.Draw(window);
        star24.Draw(window);
        star25.Draw(window);
        star26.Draw(window);
        star27.Draw(window);
        star28.Draw(window);
        star29.Draw(window);
        star30.Draw(window);
        star31.Draw(window);
        star32.Draw(window);
        star33.Draw(window);
        star34.Draw(window);
        star35.Draw(window);
        star36.Draw(window);
        star37.Draw(window);
        star38.Draw(window);
        star39.Draw(window);

        bone.Draw(window);
        bone1.Draw(window);
        bone2.Draw(window);
        bone3.Draw(window);
        bone4.Draw(window);
        bone5.Draw(window);

        bone6.Draw(window);
        bone7.Draw(window);
        bone8.Draw(window);
        bone9.Draw(window);
        bone10.Draw(window);
        bone11.Draw(window);

        bone12.Draw(window);
        bone13.Draw(window);
        bone14.Draw(window);
        bone15.Draw(window);
        bone16.Draw(window);
        bone17.Draw(window);

        bone18.Draw(window);
        bone19.Draw(window);
        bone20.Draw(window);
        bone21.Draw(window);
        bone22.Draw(window);
        bone23.Draw(window);

        bone24.Draw(window);
        bone25.Draw(window);
        bone26.Draw(window);
        bone27.Draw(window);
        bone28.Draw(window);
        bone29.Draw(window);

        bone30.Draw(window);
        bone31.Draw(window);
        bone32.Draw(window);
        player.Draw(window);
        window.draw(textbone);
       
        for (Platform& platform : platforms)
            platform.Draw(window);
        //TEXT
        Showtexet(player.GetPosition().x + 430, player.GetPosition().y - 300, counting, 30, sf::Color::Magenta, window, &font);
        window.display();

    }

score:
    while (window.isOpen()) {

        Event aevent;
        while (window.pollEvent(aevent)) {
            if (aevent.type == Event::Closed) {
                window.close();
            }
            if (aevent.type == Event::KeyPressed) {
                if (aevent.key.code == Keyboard::Escape) {
                    goto menu;
                }
            }
        }

        window.clear();
        window.draw(backgroundScore);
        window.display();

    }


    return 0;
}

