#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <string>
using namespace sf;
using namespace std;
int grid[100][100];
int sgrid[100][100];
int rows, columns, score, nmines, opened = 0;
string name, temp;
String str, str1;
ofstream fout;
ifstream fin;
void menu();
void how();
void getinput(int i);
void assign(int grid[][100], int sgrid[][100], int rows, int columns, int &mines, int nmines);
void Start(float w,int rows1,int columns1,int nmines);
void show(int x, int y, int rows, int columns);
void highscore(int score);
void readfile();
int main()
{
	menu();
}
void menu()
{
	main1:
	int spos = 250;
	RenderWindow menu(VideoMode(1000, 680), "MainMenu", Style::Close);
	Texture title, back, p, mmenu, hs, htp, q, c, sel, eas, med, exp, cus, d, sel1;

	sel1.loadFromFile("s1.png");

	d.loadFromFile("cd.png");

	eas.loadFromFile("easy.png");

	med.loadFromFile("medium.png");

	exp.loadFromFile("expert.png");

	cus.loadFromFile("custom.png");

	sel.loadFromFile("select.png");

	mmenu.loadFromFile("mainmenu.png");

	p.loadFromFile("play.png");

	title.loadFromFile("logo.png");

	back.loadFromFile("backmenu.jpg");

	c.loadFromFile("credit.png");

	htp.loadFromFile("how.png");

	hs.loadFromFile("highs.png");

	q.loadFromFile("quit.png");

	Sprite logo(title), bground(back), menulogo(mmenu), play(p), highs(hs), how1(htp), quit(q), credits(c), select(sel);
	Sprite easy(eas), medium(med), expert(exp), custom(cus), cd(d), select1(sel1);
	bground.setPosition(0, 0);
	bground.setTextureRect(IntRect(0, 0, 1000, 1000));
	
	select.setTextureRect(IntRect(0, 0, 230, 50));
	select.setPosition(393, 250);
	menu.setTitle("Difficulty Menu");

	while (menu.isOpen())
	{
		Vector2i pos = Mouse::getPosition(menu);
		int x = pos.x;
		int y = pos.y;
		Event e;
		menu.draw(bground);

		while (menu.pollEvent(e))
		{
			if (e.key.code == Keyboard::Up)
			{
				if (spos != 250)
					spos = spos - 25;
				else
					spos = 400;
				select.setPosition(393, spos);
			}
			if (e.key.code == Keyboard::Down)
			{
				if (spos != 400)
					spos = spos + 25;
				else
					spos = 250;
				select.setPosition(393, spos);
			}
			if (e.type == Event::Closed)
				menu.close();
			if (x > 399 && x < 615)
			{

				if (y>249 && y < 300)
				{
					select.setPosition(393, 250);
					
					Event e1;

						if (e.key.code == Mouse::Left||e.key.code==Keyboard::Return||e.key.code==Mouse::Right)
						{
							select1.setTextureRect(IntRect(0, 0, 460, 60));
							select1.setPosition(300, 250);
							menu.clear();
							bool selection = true;
							menu.setTitle("Difficulty Menu");
							while (selection)
							{
								Vector2i pos = Mouse::getPosition(menu);
								int x = pos.x;
								int y = pos.y;
								Event e1;
								while (menu.pollEvent(e1));
								{
								
									if (e1.type == Event::Closed)
										goto main;
									if (x > 299 && x < 760)
									{
										if (y>249 && y < 310)
										{
											select1.setPosition(295, 250);
											if (e1.key.code == Mouse::Left)
											{
												menu.close();
												system("CLS");
												Start(32, 9, 9, 10);
											}
										}

										if (y>310 && y < 370)
										{
											select1.setPosition(295, 310);
											if (e1.key.code == Mouse::Left)
											{
												menu.close();
												system("CLS");
												Start(32, 16, 16, 40);
											}
										}

										if (y>370 && y < 430)
										{
											select1.setPosition(295, 370);
											if (e1.key.code == Mouse::Left)
											{
												menu.close();
												system("CLS");
												Start(32, 16, 30, 99);
											}
										}

										if (y>430 && y < 490)
										{
											select1.setPosition(295, 430);
											if (e1.key.code == Mouse::Left)
											{
												system("CLS");
												menu.close();
												do{
													cout << "Enter No. of rows(Max Size 45): ";
													cin >> rows;
													if (rows>45 || rows<1)
														cout << "Size not valid!";
												} while (rows > 45||rows<1);

												do{
													cout << "Enter No. of columns(Max Size 70): ";
													cin >> columns;
													if (columns>70||columns<1)
														cout << "Size not valid!";
												} while (columns > 70||columns<1);
												do{
													cout << "Enter No. of mines: ";
													cin >> nmines;
													if (nmines >= rows*columns)
														cout << "Mines can't equal or exceed the no. of squares!" << endl;
												} while (nmines >= rows*columns);
												Start(32, rows, columns, nmines);

											}
										}
									}
									
								

								}

								menu.clear();
								menu.draw(bground);

								cd.setTextureRect(IntRect(0, 0, 517, 80));
								cd.setPosition(250, 150);
								menu.draw(cd);

								easy.setTextureRect(IntRect(0, 0, 242, 60));
								easy.setPosition(300, 250);
								menu.draw(easy);

								medium.setTextureRect(IntRect(0, 0, 455, 60));
								medium.setPosition(300, 310);
								menu.draw(medium);

								expert.setTextureRect(IntRect(0, 0, 348, 60));
								expert.setPosition(300, 370);
								menu.draw(expert);

								custom.setTextureRect(IntRect(0, 0, 240, 60));
								custom.setPosition(300, 430);
								menu.draw(custom);

								menu.draw(select1);

								menu.display();
							}
				main:			menu.setTitle("MainMenu");
							selection = 1;
						
					}
				}

				if (y>300 && y < 350)
				{

					select.setPosition(393, 300);
					if (e.type==Event::MouseButtonPressed)
					how();
				}

				if (y>350 && y < 400) 
				{

					select.setPosition(393, 350);
					if (e.type == Event::MouseButtonPressed)
					{
						menu.close();
						system("CLS");
						readfile();
						int g = 0;
						cout << endl << "Enter 1 to go back to menu" << endl;
						cin >> g;
						if (g == 1)
							goto main1;
					}
				}

				if (y>400 && y < 450)
				{

					select.setPosition(393, 400);
					if (e.type == Event::MouseButtonPressed)
						menu.close();
				}

			}
		}
		menu.draw(bground);

		logo.setTextureRect(IntRect(0, 0, 420, 420));
		logo.setPosition(1*280, -130);
		menu.draw(logo);

		menulogo.setTextureRect(IntRect(0, 0, 369, 50));
		menulogo.setPosition(300, 150);
		menu.draw(menulogo);

		play.setTextureRect(IntRect(0, 0, 186, 50));
		play.setPosition(400, 250);
		menu.draw(play);

		how1.setTextureRect(IntRect(0, 0, 218, 50));
		how1.setPosition(400, 300);
		menu.draw(how1);

		highs.setTextureRect(IntRect(0, 0, 215, 50));
		highs.setPosition(400, 350);
		menu.draw(highs);

		credits.setTextureRect(IntRect(0, 0, 407, 50));
		credits.setPosition(600, 600);
		menu.draw(credits);

		quit.setTextureRect(IntRect(0, 0, 73, 50));
		quit.setPosition(460, 400);
		menu.draw(quit);

		menu.draw(select);



		menu.display();
	}
}
void how()
{
	Texture how;
	how.loadFromFile("htpb.png");
	RenderWindow htp(VideoMode(1240, 700), "How To Play", Style::Close);
	Sprite h(how);
	h.setPosition(0, 0);
	h.setTextureRect(IntRect(0, 0, 1240, 700));
	while (htp.isOpen())
	{
		Event e;
		while (htp.pollEvent(e))
		{
			if (e.type == Event::Closed)
				htp.close();
			if (e.type == Event::MouseButtonPressed || e.type == Event::KeyPressed)
			{
				if (e.key.code == Mouse::Right||e.key.code==Keyboard::Escape)
				{
					htp.close();
				}
			}
		}
		htp.draw(h);
		htp.display();
	}
}
void Start(float w, int rows1, int columns1, int nmines)
{
	int mines = 0, flags = 0, flaggedmines = 0, nsquares = 0, nsquares_opened = 0, qmarks_placed = 0, score = 0, click1 = 0, rows = columns1, columns = rows1;
	clock_t start=0;
	int duration=0;
	
	if (columns > 60||rows>30) 
		w = 16;
	else if (columns > 35||rows>20)
		w = 20;
	system("Color 7F");
	srand(time(NULL));
	RenderWindow game(VideoMode::getDesktopMode(), "Minesweeper!", Style::Close);
	for (int i = 1; i < 100; i++)
		for (int j = 1; j < 100; j++)
		{
		grid[i][j] = 0;
		sgrid[i][j] = 10;
		}

		for (int i = 0, j = 0; j < 100; j++)
		{
		grid[i][j] = 14;
		sgrid[i][j] = 10;
		}

	for (int j = 0, i = 0; i < 100; i++)
		{
		
		grid[i][j] = 0;
		sgrid[i][j] = 10;
		}


	assign(grid, sgrid, rows, columns, mines, nmines);

	Texture tile, counter, background, flag, q, clock1, lose, won, m;
	
	if (w == 32)
		tile.loadFromFile("tiles.jpg");
	else if (w == 20)
		tile.loadFromFile("tiles1.jpg");
	else if (w == 16)
		tile.loadFromFile("tiles2.jpg");

	lose.loadFromFile("lost.png");

	m.loadFromFile("mine.png");

	won.loadFromFile("win.jpg");

	flag.loadFromFile("flag.png");

	q.loadFromFile("qmark.png");
	
	background.loadFromFile("background.jpg");
	
	clock1.loadFromFile("time.png");
	
	counter.loadFromFile("timer.png");

	Sprite count(counter), count1(counter), count2(counter), back(background), flag1(flag), qmark(q), time(clock1), lost(lose);

	Sprite s(tile), win(won), min(m);

	
	
	back.setTextureRect(IntRect(0, 0, 3000, 1500));

	back.setPosition(0, 0);

	game.draw(back);
	while (game.isOpen())
	{
		Vector2i pos = Mouse::getPosition(game);
		int x = pos.x / w;
		int y = pos.y / w;

		Event e;
		while (game.pollEvent(e))
		{

			if (e.type == Event::Closed)
				game.close();

			if (e.type == Event::MouseButtonPressed)
			{

				if (e.key.code == Mouse::Left)
				{
					if (x <= rows&&y <= columns)
					{
					check:		if (sgrid[x][y] == 10)
					{
						if (click1 == 0)
						{
							if ((rows*columns) - mines > 10)
							{
								if (grid[x][y] != 0)
								{
									mines = 0;
									assign(grid, sgrid, rows, columns, mines, nmines);
									click1 = 0;
									goto check;
								}
							}
							else if (((rows*columns)-mines) / 3 > nmines)
							{
								if (grid[x][y] != 0)
								{
									mines = 0;
									assign(grid, sgrid, rows, columns, mines, nmines);
									click1 = 0;
									goto check;
								}
							}
							else
							{
								if (grid[x][y] == 9)
								{
									mines = 0;
									assign(grid, sgrid, rows, columns, mines, nmines);
									click1 = 0;
									goto check;
								}
							}
						}
						if (grid[x][y] == 0)
						{

							show(x, y, rows, columns);
							
							if (click1==0)
								start = clock();

							click1 = 1;

						}
						else
						{
							sgrid[x][y] = grid[x][y];

							if (click1==0)
								start = clock();

							click1 = 1;
						}
					}
					}
				}
				else if (e.key.code == Mouse::Right)
				{
					if (sgrid[x][y] == 10)
					{
						if (grid[x][y] == 9)
						{
							flaggedmines++;
							grid[x][y] = 14;
						}
						if (sgrid[x][y] == 12)
						{
							qmarks_placed--;
						}
						sgrid[x][y] = 11;
						flags++;
					}
					else if (sgrid[x][y] == 11)
					{
						if (grid[x][y] == 14)
						{
							flaggedmines--;
							grid[x][y] = 9;
						}
						sgrid[x][y] = 12;
						qmarks_placed++;
						flags--;
					}
					else if (sgrid[x][y] == 12)
					{
						sgrid[x][y] = 10;
						qmarks_placed--;
					}
				}

			}
			system("CLS");
			cout << "mines: " << mines << endl;
			cout << "Flags: " << flags << endl;
			cout << "Flagged mine: " << flaggedmines << endl;
			cout << "Question Marks: " << qmarks_placed << endl;
			cout << "Time : " << duration << endl;
			cout << "Remaining mine: " << mines - flaggedmines << endl;
			cout << "Total Squares: " << rows*columns << endl;
			cout << "Opened Squares: " << opened << endl;

		}
		if (click1 == 1)
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;

		back.setTextureRect(IntRect(0 * 1944, 0, 4044, 1944));

		back.setPosition(0 * 1944, 0 * 1944);

		game.clear();

		game.draw(back);

		for (int i = 1; i <= rows; i++)
			for (int j = 1; j <= columns; j++)
			{
			if (click1 != 0)
				if (sgrid[x][y] == 9)
				{
				if (grid[i][j] == 9 || grid[i][j] == 14)
					sgrid[i][j] = grid[i][j];

				}
			s.setTextureRect(IntRect(sgrid[i][j] * w, 0, w, w));
			s.setPosition(i*w, j*w);
			game.draw(s);
			}

		count.setTextureRect(IntRect((flags % 10) * 26, 0, 26, 46));
		count.setPosition(50 * 26, 3 * 26);
		game.draw(count);
		count1.setTextureRect(IntRect(((flags / 10) % 10) * 26, 0, 26, 46));
		count1.setPosition(49 * 26, 3 * 26);
		game.draw(count1);
		count2.setTextureRect(IntRect((flags / 100) * 26, 0, 26, 46));
		count2.setPosition(48 * 26, 3 * 26);
		game.draw(count2);

		count.setTextureRect(IntRect((qmarks_placed % 10) * 26, 0, 26, 46));
		count.setPosition(50 * 26, 5 * 26);
		game.draw(count);
		count1.setTextureRect(IntRect(((qmarks_placed / 10) % 10) * 26, 0, 26, 46));
		count1.setPosition(49 * 26, 5 * 26);
		game.draw(count1);
		count2.setTextureRect(IntRect((qmarks_placed / 100) * 26, 0, 26, 46));
		count2.setPosition(48 * 26, 5 * 26);
		game.draw(count2);

		count.setTextureRect(IntRect((duration % 10) * 26, 0, 26, 46));
		count.setPosition(50 * 26, 7 * 26);
		game.draw(count);
		count1.setTextureRect(IntRect(((duration / 10) % 10) * 26, 0, 26, 46));
		count1.setPosition(49 * 26, 7 * 26);
		game.draw(count1);
		count2.setTextureRect(IntRect((duration / 100) * 26, 0, 26, 46));
		count2.setPosition(48 * 26, 7 * 26);
		game.draw(count2);

		count.setTextureRect(IntRect(((mines-flaggedmines) % 10) * 26, 0, 26, 46));
		count.setPosition(50 * 26, 9 * 26);
		game.draw(count);
		count1.setTextureRect(IntRect((((mines - flaggedmines) / 10) % 10) * 26, 0, 26, 46));
		count1.setPosition(49 * 26, 9 * 26);
		game.draw(count1);
		count2.setTextureRect(IntRect(((mines - flaggedmines) / 100) * 26, 0, 26, 46));
		count2.setPosition(48 * 26, 9 * 26);
		game.draw(count2);

		flag1.setTextureRect(IntRect(0, 0, 46, 51));
		flag1.setPosition(46 * 26, 3 * 26);
		game.draw(flag1);

		qmark.setTextureRect(IntRect(0, 0, 50, 50));
		qmark.setPosition(46 * 26, 5 * 26);
		game.draw(qmark);

		time.setTextureRect(IntRect(0, 0, 50, 50));
		time.setPosition(46 * 26, 7 * 26);
		game.draw(time);

		min.setTextureRect(IntRect(0, 0, 50, 50));
		min.setPosition(46 * 26, 9 * 26);
		game.draw(min);

		lost.setTextureRect(IntRect(0, 0, 350, 80));
		lost.setPosition(20 * 20, 15 * 20);

		win.setTextureRect(IntRect(0, 0, 500, 161));
		win.setPosition(10 * 20, 10 * 20);

		game.display();

		if (flaggedmines == mines&&flags == mines)
		{
			for (int i = 1; i <= rows; i++)
				for (int j = 1; j <= columns; j++)
				{
				sgrid[i][j] = grid[i][j];

				}
			game.clear(Color::White);
			game.draw(win);
			game.display();
			Sleep(3000);
			game.close();
			score = duration;
			highscore(score);

			break;
		}

		if (sgrid[x][y] == 9)
		{
			for (int i = 1; i <= rows; i++)
				for (int j = 1; j <= columns; j++)
				{
				if (click1 != 0)
					if (sgrid[x][y] == 9)
					{
					if (grid[i][j] == 9 || grid[i][j] == 14)
						sgrid[i][j] = grid[i][j];

					}
				s.setTextureRect(IntRect(sgrid[i][j] * w, 0, w, w));
				s.setPosition(i*w, j*w);
				game.draw(s);
				}

			game.draw(lost);
			Sleep(1000);
			game.display();
			Sleep(3000);
			game.close();
		}	
	}
	menu();
}
void show(int x, int y, int rows, int columns)
{
	
	if (grid[x][y] != 9 && sgrid[x][y] == 10 &&  x <= rows&& y <= columns&& y > 0 && x > 0)
	{
		sgrid[x][y] = grid[x][y];
		opened++;
		if (grid[x][y] == 0)
		{
			show(x + 1, y - 1,rows,columns);
			show(x + 1, y + 1, rows, columns);
			show(x, y - 1, rows, columns);
			show(x, y + 1, rows, columns);
			show(x - 1, y - 1, rows, columns);
			show(x - 1, y, rows, columns);
			show(x - 1, y + 1, rows, columns);
		}
	}
	
}
void assign(int grid[][100], int sgrid[][100], int rows, int columns, int &mines, int nmines)
{
	mines = 0;
	for (int i = 1; i <= rows; i++)
		for (int j = 1; j <= columns; j++)
		{
		grid[i][j] = 0;
		}
	mines = 0;
	while (mines != nmines)
	{
		int i = (rand() % rows)+1;
		int j = (rand() % columns)+1;

		if (grid[i][j] == 0)
		{
			grid[i][j] = 9;
			mines++;
		}

	}

	cout << "Mines: " << mines << endl;
	for (int i = 1; i <= rows; i++)
		for (int j = 1; j <= columns; j++)
		{
		int n = 0;
		if (grid[i][j] != 9)
		{
			if (grid[i + 1][j] == 9)
				n++;
			if (grid[i][j + 1] == 9)
				n++;
			if (grid[i - 1][j] == 9)
				n++;
			if (grid[i][j - 1] == 9)
				n++;
			if (grid[i + 1][j + 1] == 9)
				n++;
			if (grid[i - 1][j - 1] == 9)
				n++;
			if (grid[i - 1][j + 1] == 9)
				n++;
			if (grid[i + 1][j - 1] == 9)
				n++;
			grid[i][j] = n;
		}

		}
}
void highscore(int score)
{
	string name;
	
	fout.open("highscores.txt",ios::app);
	cout << "Score is  " << score << endl;
	cout << "What is Your Name: " << endl;
	cin >> name;

	fout << name << "\t" << score;
	fout << endl;
	fout.close();
}
void readfile()
{
	
	string nm;
	cout << "\nHighScores are:\n";

	fin.open("highscores.txt");
	if (fin.is_open())
		while (getline(fin, nm))
		{
		cout << nm << endl;
		}
	else
		cout << "Can't Open file!" << endl;
	fin.close();
}