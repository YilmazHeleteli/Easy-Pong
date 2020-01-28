#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <SFML/Audio.hpp>


int main()
{

//Creation
    sf::RenderWindow window(sf::VideoMode(800, 600), "Easy Pong");
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);


    sf::Font font;

    //menu textures

    sf::Texture menu;
    sf::Texture help;
    sf::Texture selection;
    sf::Texture start;
    sf::Texture pausescreen;

    menu.loadFromFile("res/menu.png");
    help.loadFromFile("res/help.png");
    selection.loadFromFile("res/selection.png");
    start.loadFromFile("res/start.png");
    pausescreen.loadFromFile("res/pause.png");

    //game textures

    sf::Texture beachBall;
    sf::Texture moonBall;
    sf::Texture sombrero;
    sf::Texture classicball;

    sf::Texture classic;
    sf::Texture space;
    sf::Texture desert;
    sf::Texture island;

    font.loadFromFile("res/arial.ttf");
    beachBall.loadFromFile("res/beachball.png");
    moonBall.loadFromFile("res/moon.png");
    sombrero.loadFromFile("res/sombrero.png");
    classicball.loadFromFile("res/classicball.png");

    classic.loadFromFile("res/classic.png");
    desert.loadFromFile("res/desert.jpg");
    island.loadFromFile("res/beach.jpg");
    space.loadFromFile("res/space.jpg");

    //music

    sf::Music mexican;
    sf::Music astro;
    sf::Music party;

    mexican.openFromFile("mexican.wav");
    party.openFromFile("samba.wav");
    astro.openFromFile("space.wav");

    //shapes
    sf::Text score1, score2;

    int pad1score = 0;
    int pad2score = 0;

    //score1

    score1.setFont(font);
    score1.setColor(sf::Color::White);
    score1.setCharacterSize(60);
    score1.setPosition(280, 20);


    //score2

    score2.setFont(font);
    score2.setColor(sf::Color::White);
    score2.setCharacterSize(30);
    score2.setCharacterSize(60);
    score2.setPosition(520, 20);

    //background

    sf::RectangleShape background;
    background.setSize(sf::Vector2f(800, 600));
    background.setPosition(0,0);
    background.setTexture(&menu);

    //pause screen
    sf::RectangleShape pauseshow;
    pauseshow.setSize(sf::Vector2f(250, 250));
    pauseshow.setPosition(275, 50);

    //Sprite 1

    sf::RectangleShape pad1;
    pad1.setSize(sf::Vector2f(15, 150));
    pad1.setPosition(10, 200);
    pad1.setFillColor(sf::Color::White);
    pad1.setOutlineThickness(10);
    pad1.setOutlineColor(sf::Color::Black);

    //Sprite 2

    sf::RectangleShape pad2;
    pad2.setSize(sf::Vector2f(15, 150));
    pad2.setPosition(775, 200);
    pad2.setFillColor(sf::Color::White);
    pad2.setOutlineThickness(10);
    pad2.setOutlineColor(sf::Color::Black);

    //Ball

    sf::RectangleShape ball;
    ball.setSize(sf::Vector2f(50, 50));
    ball.setPosition(400, 300);

    //Movement

    int yVel1;
    int xVelBall = -6;
    int yVelBall = 6;
    int yVel2 = 0;

    bool up = false;
    bool down = false;


    //menu navigation

      int state = 0;
      int themeSelection;

         bool pause = true;
         bool play = false;
         int pausecode = 0;


    //Game Loop
    while (window.isOpen())
    {


        sf::Event event;


        while (window.pollEvent(event))
        {



            if (event.type == sf::Event::Closed)
                window.close();

                if(state == 0 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::P)
        {
        state = 2;
        }

        if(state == 0 && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::H)
        {
        state = 1;
        }

        if(state == 0 && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
        return -1;
        }
        if(state == 1 && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
        state = 0;
        }
        if(state == 2 && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
        state = 0;
        }

        //theme selection

        if(state == 2 && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::C)
        {
        state = 4;
        themeSelection = 1;
        }
        if(state == 2 && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::M)
        {
        state = 4;
        themeSelection = 2;
        }
        if(state == 2 && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S)
        {
        state = 4;
        themeSelection = 3;
        }
        if(state == 2 && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
        {

        state = 4;
        themeSelection = 4;

        }

        //set pause code

        if(state == 4 && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
        {
        switch(pausecode)
        {
        case 0:
        pausecode = 1;
        pause = false;
        break;
        case 1:
        pausecode = 2;
        pause = true;
        break;
        case 2:
        pausecode = 1;
        pause = false;
        break;
        }

        }

        if(pausecode == 2 && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
        return -1;
        }



        if(pausecode == 2 && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::M)
        {
        pause = true;
        play = false;
        pausecode = 0;
        pad1score = 0;
        pad2score = 0;
        pad1.setPosition(10, 200);
        pad2.setPosition(775, 200);
        ball.setPosition(400, 300);
        state = 0;
        party.stop();
        astro.stop();
        mexican.stop();
        themeSelection = 5;

        }


switch(themeSelection)

  {
  case 1:
  background.setTexture(&classic);
  ball.setTexture(&classicball);
  play = true;
  break;

  case 2:
  background.setTexture(&desert);
  ball.setTexture(&sombrero);
  play = true;
  themeSelection = 5;
  mexican.play();
  mexican.setLoop(true);

  break;

  case 3:
  background.setTexture(&space);
  ball.setTexture(&moonBall);
  play = true;
  themeSelection = 5;
  astro.play();
  astro.setLoop(true);
  break;

  case 4:
  background.setTexture(&island);
  ball.setTexture(&beachBall);
  play = true;
themeSelection = 5;
  party.play();
  party.setLoop(true);
  break;
  }
}


  //Set Menu Screen from State

  switch(state)

  {
  case 0:
  background.setTexture(&menu);
  break;
  case 1:
  background.setTexture(&help);
  break;
  case 2:
  background.setTexture(&selection);
  break;
  }


  //Set textures from Theme Selection







   if(play == true && pause == false)
        {


        //Key pressed
        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
        {
        up =  true;
        down = false;
        }

        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
        {
        up =  false;
        down = true;
        }
        //Key Released

        if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up)
        {
        up = false;
        }

        if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down)
        {
        down = false;
        }

        if(up == true && down == false)
        {
        yVel1 = -5;
        }

        if(up == false && down == true)
        {
        yVel1 = 5;
        }

        if((up == true && down == true) || (up == false && down == false))
        {
        yVel1 = 0;
        }

        //collision detection

        if(pad1.getPosition().y < 0)
        {
        pad1.setPosition(10, 0);
        }

        if(pad1.getPosition().y > 450)
        {
        pad1.setPosition(10, 450);
        }

        //pads

        pad1.move(0, yVel1);

        if(ball.getPosition().y < pad2.getPosition().y)
        {
        yVel2 = -2;
        }

        if(ball.getPosition().y > pad2.getPosition().y)
        {
        yVel2 = 2;
        }

        if(play == true && pause == false)
        {
        pad2.move(0, yVel2);
        }

        //ball

        if(pause == false)
        {
        ball.move(xVelBall, yVelBall);
        }


        if(ball.getPosition().y < 0)
        {
        yVelBall = -yVelBall;
        }

        if(ball.getPosition().y > 550)
        {
        yVelBall = -yVelBall;
        }

        if((ball.getGlobalBounds().intersects(pad1.getGlobalBounds()) == true) || (ball.getGlobalBounds().intersects(pad2.getGlobalBounds()) == true))
        {
        xVelBall = -xVelBall;
        }

        //score

        if(ball.getPosition().x > 1500)
        {
        pad1score++;
        ball.setPosition(400, 300);
        xVelBall = -xVelBall;

        }

        if(ball.getPosition().x < -700)
        {
        pad2score++;
        ball.setPosition(400, 300);
        xVelBall = -xVelBall;
        }
        }

        window.clear();

        window.draw(background);
        std::stringstream updateScore1;
        std::stringstream updateScore2;
        updateScore1 << pad1score;
        updateScore2 << pad2score;
        score1.setString(updateScore1.str());
        score2.setString(updateScore2.str());


if(play == true)
{
window.draw(score1);
        window.draw(score2);
        window.draw(pad1);
        window.draw(pad2);
        window.draw(ball);

        if(pause == true)
{

switch(pausecode)
{
case 0:
pauseshow.setTexture(&start);
break;

case 2:
pauseshow.setTexture(&pausescreen);
break;

}
window.draw(pauseshow);

}

        }


        window.display();
    }


    return 0;
}
