#include <SFML/Graphics.hpp>
#include <Windows.h>
#include<iostream>
#include<fstream>

// we use this to make the code easy and concise
using namespace sf;


int game = 1, speed = 500, size = 2;
int dir;
int score = 0;
int* difficulty = new int (1);
int highscore = 0;
int randomx = 0;
int randomy = 0;
bool good = true;

class Snake
{
public:
	int x = 0;
	int y = 0;
};
Snake s[100];


//Menu class
class Menu
{
protected:
	int select = 0;
	sf::Font font;
	sf::Text text[3];

public:
	Menu()
	{
		font.loadFromFile("Fonts/Calibri.ttf");

		// For Play
		text[0].setFont(font);
		text[0].setFillColor(Color::White);
		text[0].setString("Play");
		text[0].setCharacterSize(70);
		text[0].setPosition(150, 150);

		// For Options
		text[1].setFont(font);
		text[1].setFillColor(Color::White);
		text[1].setString("Options");
		text[1].setCharacterSize(70);
		text[1].setPosition(150, 250);

		// For Exit
		text[2].setFont(font);
		text[2].setFillColor(Color::White);
		text[2].setString("Exit");
		text[2].setCharacterSize(70);
		text[2].setPosition(150, 350);

	}

		//This function takes reference to the window so we use &
	void draw(sf::RenderWindow& window)
	{
		for (int i = 0; i < 3; i++)
		{
			window.draw(text[i]);
		}
	}
		// This function Allows user to move up in the menu
	void up()
	{
		text[select].setFillColor(sf::Color::White);

		select--;
		if (select < 0)
		{
			select = 2;
		}
		text[select].setFillColor(Color::Blue);
	}

		// This function Allows user to move down in the menu
	void down()
	{
		text[select].setFillColor(sf::Color::White);

		select++;
		if (select >= 3)
		{
			select = 0;
		}
		text[select].setFillColor(Color::Blue);
	}
		
		// This Function returns the selected option number
	int press()
	{
		return select;
	}
};


//Options menu class
class OptionsMenu : public Menu			//Inheriting from menu class
{
public:
	OptionsMenu() : Menu()
	{
		// For Snake Color option
		text[0].setString("Snake Color");
		text[0].setPosition(150, 150);

		// For Fruit option
		text[1].setString("Fruit");
		text[1].setPosition(150, 250);

		// For Back option
		text[2].setString("Back");
		text[2].setPosition(150, 350);

	}
};


//Snake Color menu
class scmenu   
{
protected:
	int select = 0;
	sf::Font font;


private:

	sf::Text sctext[6];

public:
	scmenu()
	{
		font.loadFromFile("Fonts/Calibri.ttf");
		//For Blue color
		sctext[0].setFont(font);
		sctext[0].setFillColor(Color::White);
		sctext[0].setString("Blue");
		sctext[0].setCharacterSize(70);
		sctext[0].setPosition(200, 100);

		//For Yellow Color
		sctext[1].setFont(font);
		sctext[1].setFillColor(Color::White);
		sctext[1].setString("Yellow");
		sctext[1].setCharacterSize(70);
		sctext[1].setPosition(200, 200);

		//For Red Color
		sctext[2].setFont(font);
		sctext[2].setFillColor(Color::White);
		sctext[2].setString("Red");
		sctext[2].setCharacterSize(70);
		sctext[2].setPosition(200, 300);

		//For Pink Color
		sctext[3].setFont(font);
		sctext[3].setFillColor(Color::White);
		sctext[3].setString("Pink");
		sctext[3].setCharacterSize(70);
		sctext[3].setPosition(200, 400);

		//For White Color
		sctext[4].setFont(font);
		sctext[4].setFillColor(Color::White);
		sctext[4].setString("White");
		sctext[4].setCharacterSize(70);
		sctext[4].setPosition(200, 500);

		//To go back to the Main Menu
		sctext[5].setFont(font);
		sctext[5].setFillColor(Color::White);
		sctext[5].setString("Back");
		sctext[5].setCharacterSize(70);
		sctext[5].setPosition(200, 600);

	}


	void draw(sf::RenderWindow& scwindow)
	{
		for (int i = 0; i < 6; i++)
		{
			scwindow.draw(sctext[i]);
		}
	}
	void up()
	{
		sctext[select].setFillColor(sf::Color::White);

		select--;
		if (select < 0)
		{
			select = 5;
		}
		sctext[select].setFillColor(Color::Blue);

	}
	void down()
	{
		sctext[select].setFillColor(sf::Color::White);

		select++;
		if (select >= 6)
		{
			select = 0;
		}
		sctext[select].setFillColor(Color::Blue);
	}

	int press()
	{
		return select;
	}

};

//Fruit Menu Class
class fruitmenu
{
protected:
	int select = 0;
	sf::Font font;


private:

	sf::Text fruit[6];

public:
	fruitmenu()
	{
		font.loadFromFile("Fonts/Calibri.ttf");

		//For Berry
		fruit[0].setFont(font);
		fruit[0].setFillColor(Color::White);
		fruit[0].setString("Berry");
		fruit[0].setCharacterSize(70);
		fruit[0].setPosition(200, 100);

		//For Orange
		fruit[1].setFont(font);
		fruit[1].setFillColor(Color::White);
		fruit[1].setString("Orange");
		fruit[1].setCharacterSize(70);
		fruit[1].setPosition(200, 200);

		//For Apple
		fruit[2].setFont(font);
		fruit[2].setFillColor(Color::White);
		fruit[2].setString("Apple");
		fruit[2].setCharacterSize(70);
		fruit[2].setPosition(200, 300);

		//For Lemon
		fruit[3].setFont(font);
		fruit[3].setFillColor(Color::White);
		fruit[3].setString("Lemon");
		fruit[3].setCharacterSize(70);
		fruit[3].setPosition(200, 400);

		//For Grape
		fruit[4].setFont(font);
		fruit[4].setFillColor(Color::White);
		fruit[4].setString("Grape");
		fruit[4].setCharacterSize(70);
		fruit[4].setPosition(200, 500);

		//To go back to the Main Menu
		fruit[5].setFont(font);
		fruit[5].setFillColor(Color::White);
		fruit[5].setString("Back");
		fruit[5].setCharacterSize(70);
		fruit[5].setPosition(200, 600);

	}

	void draw(sf::RenderWindow& fruitwindow)
	{
		for (int i = 0; i < 6; i++)
		{
			fruitwindow.draw(fruit[i]);
		}
	}
	void up()
	{
		fruit[select].setFillColor(sf::Color::White);

		select--;
		if (select < 0)
		{
			select = 5;
		}
		fruit[select].setFillColor(Color::Blue);

	}
	void down()
	{
		fruit[select].setFillColor(sf::Color::White);

		select++;
		if (select >= 6)
		{
			select = 0;
		}
		fruit[select].setFillColor(Color::Blue);
	}

	int press()
	{
		return select;
	}

};

int main()
{

	{
		std::ifstream file;		//Reading File
		file.open("highscore.txt");
		if (file.is_open())
		{
			file >> highscore;
			file.close();
		}

	}


	// To Load Textures into the Program
	Texture square, refresh, bg, food;
	square.loadFromFile("assets/body1.png");
	refresh.loadFromFile("assets/retry.png");
	bg.loadFromFile("assets/Untitled-1.png");
	food.loadFromFile("assets/fruit.png");

	// To Create a Sprite to add graphics in the game
	Sprite snake(square), red(food), Refresh(refresh), gamebg(bg);
	snake.setPosition(0, 0);
	snake.setColor(sf::Color(32,0,64));
	snake.setScale(0.819, 0.819);
	red.setPosition(1000, 0);
	red.setColor(sf::Color::Red);
	gamebg.setPosition(400, 50);
	gamebg.setScale(0.685, 0.55);
	red.setScale(0.08, 0.08);

	// Create the Main Menu window
	sf::RenderWindow window(sf::VideoMode(960, 720), "Snake Game", sf::Style::Fullscreen);

	// to set the Main Menu Background
	Texture mbg;
	mbg.loadFromFile("assets/mainbgr.png");

	Sprite mainbg(mbg);
	mainbg.setPosition(0, 0);

	//Creating Objects for Menu Class and OptionsMenu Class 
	Menu mainMenu;
	OptionsMenu optionsMenu;

	bool showOptionsMenu = false;

	// Opening the window 
	while (window.isOpen())
	{
		int e = 0;

		// Handling the events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (!showOptionsMenu && event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Up)
				{
					mainMenu.up();
					break;
				}
				else if (event.key.code == Keyboard::Down)
				{
					mainMenu.down();
					break;
				}
				else if (event.key.code == Keyboard::Return)
				{
					//assigning the value of select to x
					int x = mainMenu.press();
					if (x == 0)
					{
						//Game Loop
						RenderWindow Play(VideoMode(1366, 768), "Snake Game", sf::Style::Fullscreen);
						while (Play.isOpen())
						{
							game = 1;
							Play.requestFocus();
							Event aevent;

							//Creating a Boundary
							sf::RectangleShape playzone;
							playzone.setPosition(400, 50);
							playzone.setOutlineThickness(10);
							playzone.setFillColor(sf::Color::Transparent);
							playzone.setOutlineColor(sf::Color::Black);
							playzone.setSize(sf::Vector2f(750, 595));

							//to set snake start in the playzone
							s[0].x = 450;
							s[0].y = 100;

							Font font;
							font.loadFromFile("Fonts/Calibri.ttf");

							//For Creating the SCORE text
							Text Score;
							Score.setFont(font);
							Score.setCharacterSize(100);
							Score.setStyle(Text::Bold);
							Score.setString("SCORE : " + std::to_string(score));
							Score.setPosition(60, 200);
							Score.setScale(0.5, 0.5);

							//For Creating the HIGH SCORE text
							Text Highscore;
							Highscore.setFont(font);
							Highscore.setCharacterSize(100);
							Highscore.setStyle(Text::Bold);
							Highscore.setString("HIGH SCORE: " + std::to_string(highscore));
							Highscore.setPosition(60, 300);
							Highscore.setScale(0.5, 0.5);

							//For Creating the NEW HIGH SCORE text
							Text NewHighscore;  //New High score
							NewHighscore.setFont(font);
							NewHighscore.setCharacterSize(100);
							NewHighscore.setStyle(Text::Bold);
							NewHighscore.setString(" "); // string = empty so it can be updated when highscore is beaten
							NewHighscore.setFillColor(sf::Color::White);
							NewHighscore.setPosition(50, 700);
							NewHighscore.setScale(0.5, 0.5);


							//For Creating the DIFFICULTY text
							Text Difficulty;  // Difficulty
							Difficulty.setFont(font);
							Difficulty.setCharacterSize(100);
							Difficulty.setStyle(Text::Bold);
							Difficulty.setString("DIFFICULTY : " + std::to_string(*difficulty));
							Difficulty.setPosition(60, 400);
							Difficulty.setScale(0.5, 0.5);


							// generation random values of randomx and randomy for fruit
							srand(time(NULL));
							randomx = 450 + rand() % 551;
							randomy = 100 + rand() % 406;


							for (int i = 0; i < 12; i++)  //creating a 12x12 grid here to place fruit inside
							{
								//checking if the randomx and randomy falls within the grid
								if (randomx <= (i + 1) * 50 + 400 && randomx > i * 50 + 400)
								{
									randomx = (i + 1) * 50 + 400;
								}
								if (randomy <= (i + 1) * 50 && randomy > i * 50)
								{
									randomy = (i + 1) * 50;
								}
							}



							//Game
							while (Play.isOpen())
							{
								//to get position of mouse on screen and assign it to a variable
								Vector2i pos = Mouse::getPosition(Play);

								while (Play.pollEvent(aevent))
								{
									if (aevent.type == Event::Closed)
									{
										Play.close();
									}

									if (aevent.type == Event::MouseButtonReleased || aevent.type == Event::KeyReleased)
									{
										if (aevent.key.code == Mouse::Left || aevent.key.code == Keyboard::Return)
										{
											//Checks if user clicks on the retry button
											if (Refresh.getGlobalBounds().contains(pos.x, pos.y))
											{
												//game over
												if (game == 2)
												{

													score = 0;
													Highscore.setString("High Score: " + std::to_string(highscore));


													Score.setString("SCORE : " + std::to_string(score));

													NewHighscore.setString(" ");

													(*difficulty) = 1;
													Difficulty.setString("DIFFICULTY : " + std::to_string(*difficulty));
													
													Play.draw(NewHighscore);
													Play.draw(Difficulty);
													game = 1;
													Refresh.setPosition(1000, 0);
													size = 2;
													s[0].x = 450;
													s[0].y = 100;
													dir = 0;
													speed = 700;
													good = true;

													// this while loop checks that if fruit is spawned on the snake position then try again
													while (good)  
													{
														randomx = 450 + rand() % 551;
														randomy = 100 + rand() % 406;

														for (int i = 0; i < 12; i++)
														{
															if (randomx <= (i + 1) * 50 + 400 && randomx > i * 50 + 400)
															{
																randomx = (i + 1) * 50 + 400;
															}
															if (randomy <= (i + 1) * 50 && randomy > i * 50)
															{
																randomy = (i + 1) * 50;
															}
														}

														//checks if fruit is on the snake's body
														for (int i = 0; i < size; i++)
														{
															if (randomx != s[i].x || randomy != s[i].y)
															{
																good = false;
															}
														}
													}
												}
											}
										}
									}

									if (aevent.type == Event::KeyPressed)
									{
										//Game Playing state
										if (game == 1)
										{
											//For right Button To set the direction to right
											if (aevent.key.code == Keyboard::Right && dir != 1)
											{
												dir = 0;
											}

											//For Left Button To set the direction to left
											else if (aevent.key.code == Keyboard::Left && dir != 0)
											{
												dir = 1;
											}

											//For Down Button To set the direction to down
											else if (aevent.key.code == Keyboard::Down && dir != 3)
											{
												dir = 2;
											}

											//For Up Button To set the direction to up
											else if (aevent.key.code == Keyboard::Up && dir != 2)
											{
												dir = 3;
											}

											//Selects what to do if user press Escape key
											else if (aevent.key.code == Keyboard::Escape)
											{
												game = 2;
												score = 0;
												Highscore.setString("High Score: " + std::to_string(highscore));

												Score.setString("SCORE : " + std::to_string(score));

												(*difficulty) = 1;
												Difficulty.setString("DIFFICULTY : " + std::to_string(*difficulty));

												game = 1;
												Refresh.setPosition(1000, 0);
												size = 2;
												s[0].x = 450;
												s[0].y = 100;
												dir = 0;
												speed = 700;
												Play.close();
											}
										}
									}
								}
								Play.clear(Color(64, 64, 64));  //change background colour of the game

								//Playing The Game
								if (game == 1)
								{
									Refresh.setPosition(1000, 0);
									Play.draw(gamebg);

									//to check if the snake touches the boundary
									if (s[0].x >= playzone.getPosition().x + playzone.getSize().x || s[0].x < playzone.getPosition().x || s[0].y >= playzone.getPosition().y + playzone.getSize().y || s[0].y < playzone.getPosition().y)
									{
										score = 0;
										game = 2;
									}

									//Updating the snake's position during the game
									for (int i = size; i > 0; i--)
									{
										s[i].x = s[i - 1].x;
										s[i].y = s[i - 1].y;
									}

									//it adds 50 to snake's x position so it moves right in the grid
									if (dir == 0)
									{
										s[0].x += 50;
									}

									//it subtracts 50 from snake's x position so it moves left in the grid
									if (dir == 1)
									{
										s[0].x -= 50;
									}

									//it adds 50 to snake's y position so it moves down in the grid
									if (dir == 2)
									{
										s[0].y += 50;
									}

									//it subtracts 50 from snake's y position so it moves up in the grid
									if (dir == 3)
									{
										s[0].y -= 50;
									}

									// if the snake touches the boundary then game over
									if (s[0].x >= 1100 || s[0].x < 450 || s[0].y >= 600 || s[0].y < 100) 
									{
										score = 0;
										Score.setString("SCORE : " + std::to_string(score));
										game = 2;
									}

									// this loop checks if the snake touches itself then game over
									for (int i = 1; i < size; i++) 
									{
										if (s[0].x == s[i].x && s[0].y == s[i].y)
										{
											score = 0;
											Score.setString("SCORE : " + std::to_string(score));
											game = 2;
										}
									}

									//this checks if the snake eats the fruit and increase the size
									if (s[0].x == red.getPosition().x && s[0].y == red.getPosition().y) 
									{ 
										// sets the score and maintains the high score in the file
										score++;
										Score.setString("SCORE : " + std::to_string(score));
										if (score > highscore) {
											highscore = score;
											std::ofstream highscoreFile("highscore.txt");
											if (highscoreFile.is_open()) {
												highscoreFile << highscore;
												highscoreFile.close();
											}
											
												NewHighscore.setString("New High Score");
												
										}
										
										if (size % 5 == 0) // increases the dificulty
										{
											(*difficulty)++;
											Difficulty.setString("DIFFICULTY : " + std::to_string(*difficulty));
											Play.draw(Difficulty);
										}

										//this increments the size
										size += 1;

										// this decreases the delay and increases the speed
										if (speed > 100) 
										{
											speed -= 20;
										}
										good = true;

										//it checks if the fruit keeps on generating away from the snake's body
										while (good)
										{
											randomx = 450 + rand() % 551;
											randomy = 100 + rand() % 406;

											for (int i = 0; i < 12; i++)
											{
												if (randomx <= (i + 1) * 50 + 400 && randomx > i * 50 + 400)
												{
													randomx = (i + 1) * 50 + 400;
												}
												if (randomy <= (i + 1) * 50 && randomy > i * 50)
												{
													randomy = (i + 1) * 50;
												}
											}

											for (int i = 0; i < size; i++)
											{
												if (randomx == s[i].x && randomy == s[i].y)
												{
													break;
												}
												else if ((randomx != s[i].x ) && i == size - 1)
												{
													good = false;
												}
											}
										}
									}
									
									//this sets a random position for fruit to spawn and draws the fruit
									red.setPosition(randomx, randomy);
									Play.draw(red);

									//drawing the snake
									for (int i = 0; i < size; i++) 
									{
										snake.setPosition(s[i].x, s[i].y);
										Play.draw(snake);

									}

									//this draws the various items on the screen
									Play.draw(Score);
									Highscore.setPosition(60, 300);
									Play.draw(Highscore);									
									Play.draw(NewHighscore);
									Play.draw(Difficulty);
									Play.draw(playzone);
									Play.display();
									Sleep(speed);
								}

								//this checks if the game is over and sets scores to zero
								else if (game == 2)
								{
									Play.clear(Color(0, 128, 128));
									Refresh.setPosition(450, 300);
									Play.draw(Refresh);
									Play.display();
									if (aevent.type == Event::KeyReleased)
									{
										if (aevent.key.code == Keyboard::Escape)
										{
											Play.close();

											score = 0;
											Highscore.setString("High Score: " + std::to_string(highscore));


											Score.setString("SCORE : " + std::to_string(score));

											NewHighscore.setString(" ");

											(*difficulty) = 1;
											Difficulty.setString("DIFFICULTY : " + std::to_string(*difficulty));

											Play.draw(NewHighscore);
											Play.draw(Difficulty);
											game = 1;
											Refresh.setPosition(1000, 0);
											size = 2;
											s[0].x = 450;
											s[0].y = 100;
											dir = 0;
											speed = 700;

											break;
										}
									}
								}

							}
						
							Play.clear();
							Play.display();
						}
					}
					//Game code end

					//Show options menu
					else if (x == 1)
					{
						showOptionsMenu = true;
					}

					//close the window
					else if (x == 2)
					{
						window.close();
					}
				}
			}

			//this handles the Options Menu
			else if (showOptionsMenu && event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Up)
				{
					optionsMenu.up();
					break;
				}
				else if (event.key.code == Keyboard::Down)
				{
					optionsMenu.down();
					break;
				}
				else if (event.key.code == Keyboard::Return)
				{
					//it assigns the value of select to x
					int x = optionsMenu.press();
					if (x == 0)
					{
						//creates the window for snake color Options
						sf::RenderWindow scwindow(sf::VideoMode(1366, 768), "Color Menu", sf::Style::Fullscreen);

						//Set Background for snake color options menu
						RectangleShape bgsc;
						bgsc.setSize(Vector2f(1366, 768));

						Texture bgs;
						bgs.loadFromFile("assets/snakecolor.png");
						bgsc.setTexture(&bgs);

						//Object for scmenu Class
						scmenu sctext;

						while (scwindow.isOpen())
						{

							// Handle events
							sf::Event scevent;
							while (scwindow.pollEvent(scevent))
							{

								if (scevent.type == sf::Event::Closed)
									scwindow.close();

								if (scevent.type == Event::KeyReleased)
								{
									if (scevent.key.code == Keyboard::Escape)
									{
										scwindow.close();
										break;
									}
								}

								if (scevent.type == Event::KeyReleased)
								{
									if (scevent.key.code == Keyboard::Up)
									{
										sctext.up();
										break;
									}
								}
								if (scevent.type == Event::KeyReleased)
								{
									if (scevent.key.code == Keyboard::Down)
									{
										sctext.down();
										break;
									}
								}
								if (scevent.key.code == Keyboard::Return)
								{
									//assigns the value of select to x
									int x = sctext.press();
									if (x == 0)
									{
										snake.setColor(sf::Color::Cyan);
										e = 1;
									}

									if (x == 1)
									{
										snake.setColor(sf::Color::Yellow);
										e = 1;										
									}

									if (x == 2)
									{
										snake.setColor(sf::Color::Red);
										e = 1;										
									}

									if (x == 3)
									{
										snake.setColor(sf::Color::Magenta);
										e = 1;	
									}

									if (x == 4)
									{
										snake.setColor(sf::Color::White);
										e = 1;
									}

									if (x == 5)
									{
										e = 1;
										break;
									}

								}


							}
							// Clear the window
							scwindow.clear();

							// Draw the window							
							scwindow.draw(bgsc);
							sctext.draw(scwindow);

							//checks for the condition and closes the window if true
							if (e < 2 && e>0)
							{
								scwindow.close();
							}

							// Display the contents of the window
							scwindow.display();

						}

					}

					else if (x == 1)
					{
						//Creates the window for fruit menu
						sf::RenderWindow fruitwindow(sf::VideoMode(1366, 768), "Fruit Menu", sf::Style::Fullscreen);

						//back ground
						RectangleShape bgf;
						bgf.setSize(Vector2f(1366, 768));

						Texture fruitbg;
						fruitbg.loadFromFile("assets/selectfruit.png");
						bgf.setTexture(&fruitbg);

						//Creates an object for fruitmenu class
						fruitmenu fruit;

						while (fruitwindow.isOpen())
						{

							// Handle events
							sf::Event fevent;
							while (fruitwindow.pollEvent(fevent))
							{

								if (fevent.type == sf::Event::Closed)
									fruitwindow.close();

								if (fevent.type == Event::KeyReleased)
								{
									if (fevent.key.code == Keyboard::Escape)
									{
										fruitwindow.close();
										break;
									}
								}
								
								if (fevent.type == Event::KeyReleased)
								{
									if (fevent.key.code == Keyboard::Up)
									{
										fruit.up();
										break;
									}
								}
								if (fevent.type == Event::KeyReleased)
								{
									if (fevent.key.code == Keyboard::Down)
									{
										fruit.down();
										break;
									}
								}
								if (fevent.key.code == Keyboard::Return)
								{
									//assigns the value of select to x
									int x = fruit.press();
									if (x == 0)
									{
										red.setColor(sf::Color::Blue);
										e = 1;										
									}

									if (x == 1)
									{
										red.setColor(sf::Color(255, 128, 0));
										e = 1;
										

									}

									if (x == 2)
									{
										red.setColor(sf::Color::Red);
										e = 1;										
									}

									if (x == 3)
									{
										red.setColor(sf::Color::Yellow);
										e = 1;										
									}

									if (x == 4)
									{
										red.setColor(sf::Color::Green);
										e = 1;										
									}

									if (x == 5)
									{
										e = 1;										
										break;
									}

								}


							}
							// Clear the window
							fruitwindow.clear();

							// Draw the window							
							fruitwindow.draw(bgf);
							fruit.draw(fruitwindow);

							//checks for the condition, if its true then close the window
							if (e < 2 && e>0)
							{
								fruitwindow.close();
							}

							// Display the contents of the window
							fruitwindow.display();

						}
					}
					//stop displaying the options menu
					else if (x == 2)
					{
						showOptionsMenu = false;
					}
				}
			}
		}

		// Clear the window
		window.clear();

		// Draw the menu
		window.draw(mainbg);

		//checks if showoptionsmenu == true , if true then then display the menu and if false then close the menu
		if (showOptionsMenu)
		{
			optionsMenu.draw(window);
		}
		else
			//draws the main menu
		{
			mainMenu.draw(window);
		}

		// Display the contents of the window
		window.display();
	}
	delete difficulty;
	return 0;
}
