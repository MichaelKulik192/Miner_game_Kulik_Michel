/// \@author Кулик Михаил
#include "TXLib.h"

//----------------------------Классы:----------------------------------------

class MAP // класс карты
{
  private:
    HDC Map;
    int maze[15][15]; // массив с картой, только один уровень !

  public:
    int *count_level; // счетчик уровня

    void init(HDC Map,int &count_level)     // инициализация
    {
        this->Map = Map;
        this->count_level = &count_level;
        set_new_level();
    }

    void draw()     // рисование
    {
        for(int i = 0; i < 15; i++)
        {
            for(int j = 0; j < 15; j++)
            {
                if(maze[i][j] == 0)     // коренная порода
                {
                    Win32::TransparentBlt(txDC(), 50 * (j+ 1), 50 * (i + 1), 50, 50, Map, 0, 0, 50, 50, TX_WHITE);
                }
                else if(maze[i][j] == 1)    // камень
                {
                        Win32::TransparentBlt(txDC(), 50 * (j+ 1), 50 * (i + 1), 50, 50, Map, 0, 50, 50, 50, TX_WHITE);
                }
                else if(maze[i][j] == 2)    // дорожка
                {
                        Win32::TransparentBlt(txDC(), 50 * (j+ 1), 50 * (i + 1), 50, 50, Map, 0, 100, 50, 50, TX_WHITE);
                }
                else if(maze[i][j] == 3)    // уголь
                {
                    Win32::TransparentBlt(txDC(), 50 * (j+ 1), 50 * (i + 1), 50, 50, Map, 50, 200, 50, 50, TX_WHITE);
                }
                else if(maze[i][j] == 4)    // железо
                {
                    Win32::TransparentBlt(txDC(), 50 * (j+ 1), 50 * (i + 1), 50, 50, Map, 50, 150, 50, 50, TX_WHITE);
                }
                else if(maze[i][j] == 5)    // золото
                {
                    Win32::TransparentBlt(txDC(), 50 * (j+ 1), 50 * (i + 1), 50, 50, Map, 50, 100, 50, 50, TX_WHITE);
                }
                else if(maze[i][j] == 6)    // изумруды
                {
                    Win32::TransparentBlt(txDC(), 50 * (j+ 1), 50 * (i + 1), 50, 50, Map, 50, 50, 50, 50, TX_WHITE);
                }
                else if(maze[i][j] == 7)    // алмазы
                {
                    Win32::TransparentBlt(txDC(), 50 * (j+ 1), 50 * (i + 1), 50, 50, Map, 50, 0, 50, 50, TX_WHITE);
                }
                else if(maze[i][j] == -1)  // бомба
                {
                    Win32::TransparentBlt(txDC(), 50 * (j+ 1), 50 * (i + 1), 50, 50, Map, 0, 50, 50, 50, TX_WHITE);
                }
            }
        }
    }

    int get_block(int i, int j)     // взятия блока из массива с картой
    {
        return maze[i][j];
    }

    void set_block(int i, int j, int n) // замена блока из массива с картой на новый
    {
        maze[i][j] = n;
    }

    void set_new_level() // переход на новый уровень
    {
        int map_1[15][15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // первый уровень
                             0, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 4, 4, 4, 0,
                             0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 0,
                             0, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                             0, 1, 1, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 5, 0,
                             0, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 5, 5, 0,
                             0, 1, 1, 1, 1, 3, 1, 1, 1, 6, 6, 1, 5, 1, 0,
                             0, 4, 1, 1, 1, 1, 1, 5, 5, 1, 1, 1, 1, 1, 0,
                             0, 4, 4, 1, 1, 1, -1, 5, 5, 1, 1, 1, 1, 1, 0,
                             0, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                             0, 1, 1, 1, 1, 6, 1, 1, 1, 1, 1, 1, 3, 3, 0,
                             0, 1, 1, 1, 6, 6, 1, 1, 1, 1, 1, 3, 3, 3, 0,
                             0, 1, 1, 1, 1, 1, 4, 4, 1, 1, 1, 3, 7, 3, 0,
                             0, 1, 1, 1, 1, 4, 4, 4, 1, 1, 1, 7, 7, 3, 0,
                             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        int map_2[15][15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // второй уровень
                            0, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 3, 0,
                            0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 0,
                            0, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 3, 3, 3, 0,
                            0, 1, 4, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 5, 0,
                            0, 1, 4, 1, 3, 3, 1, 1, 1, 1, 1, 1, 5, 5, 0,
                            0, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                            0, 1, 1, 6, 1, 1, 1, 7, 5, 1, 1, 1, 1, 1, 0,
                            0, 1, 6, 6, 1, 1, -1, 7, 7, 1, 1, 1, 1, 1, 0,
                            0, 1, 1, 1, 1, 1, 7, 7, 1, 1, 1, 1, 1, 1, 0,
                            0, 1, 4, 1, -1, 6, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                            0, 4, 4, 1, 6, 6, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                            0, 1, 1, 1, 1, 1, 4, 4, 1, 1, 1, 1, 5, 1, 0,
                            0, 1, 1, 1, 1, 4, 4, 4, 1, 1, 1, 5, 5, 1, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        int map_3[15][15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // третий уровень
                            0, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 0,
                            0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                            0, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                            0, 1, 1, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                            0, 1, 1, 1, 3, 3, 1, 3, 1, 4, 1, 1, 1, 1, 0,
                            0, 1, 1, 1, -1, 3, 3, 3, 3, 4, 4, 1, 1, 1, 0,
                            0, 7, 1, 1, 1, 1, 3, 3, 3, 4, 4, 4, 1, 1, 0,
                            0, 7, 6, 1, 1, 1, 3, 3, 3, 1, 4, 4, 1, 1, 0,
                            0, 7, 1, 1, 1, 1, 1, 3, 1, -1, 1, 1, 1, 1, 0,
                            0, 1, 1, 1, 5, 5, 1, 3, 1, 1, 1, 1, 1, 1, 0,
                            0, 1, 1, 5, 5, 1, 1, 1, 1, 7, 7, 3, 1, 1, 0,
                            0, 1, 1, 5, 5, 1, 1, 1, -1, 7, 7, 1, 1, 1, 0,
                            0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


        if (*count_level == 1) // если 1 уровень
        {
            for(int i = 0; i < 15; i++)
            {
                for(int j = 0; j < 15; j++)
                {
                    this->maze[i][j] = map_1[i][j];
                }
            }
        }
        else if (*count_level == 2) // если 2 уровень
        {
            for(int i = 0; i < 15; i++)
            {
                for(int j = 0; j < 15; j++)
                {
                    this->maze[i][j] = map_2[i][j];
                }
            }
        }
        else if (*count_level == 3) // если 3 уровень
        {
            for(int i = 0; i < 15; i++)
            {
                for(int j = 0; j < 15; j++)
                {
                    this->maze[i][j] = map_3[i][j];
                }
            }
        }


    }
};

class character // класс персонажа
{
  private:
    int x, y;           // координаты персонажа
    double siz;         // увеличение
    int w, h;           // ширина и высота кадра с персонажом
    int xpic, ypic;     // левый верхний угол кадра
    COLORREF color;     // цвет, который станет прозрачным
    HDC Miner;
    int dx;             // шаг персонажа

    int count_1;        // счетчик очков

    MAP *a;

    int *Is_it_end;     // это конец?
    int *Is_it_win;     // это победа?

    int *count_level;   // счетчик уровней


  public:
    void init(int x, int y, double siz, int w, int h, int xpic, int ypic, COLORREF color, HDC Miner, int dx, MAP &map_1, int count_1, int Is_it_end, int &count_level, int Is_it_win) // инициализация
    {
        this->x = x;
        this->y = y;
        this->siz = siz;
        this->w = w;
        this->h = h;
        this->xpic = xpic;
        this->ypic = ypic;
        this->color = color;
        this->Miner = Miner;
        this->dx = dx;
        this->a = &map_1;
        this->count_1 = count_1;
        this->Is_it_end = &Is_it_end;
        this->count_level = &count_level;
        this->Is_it_win = &Is_it_win;

    }

    void draw()  // рисование
    {
        Win32::TransparentBlt(txDC(), x, y, int(siz * w), int(siz * h), Miner, xpic, ypic, w, h, color);
    }

    void check_keys(MAP &a, int &Is_it_end, int &Is_it_win)  // проверка нажатия клавиш
    {
        if (GetAsyncKeyState (VK_RIGHT)) // если нажата клавиша вправо
        {
            go_right(a, Is_it_end, Is_it_win);
        }

        if (GetAsyncKeyState (VK_LEFT)) // если нажата клавиша влево
        {
            go_left(a, Is_it_end, Is_it_win);
        }

        if (GetAsyncKeyState (VK_UP)) // если нажата клавиша вверх
        {
            go_up(a, Is_it_end, Is_it_win);
        }

        if (GetAsyncKeyState (VK_DOWN)) // если нажата клавиша вниз
        {
            go_down(a, Is_it_end, Is_it_win);
        }
    }

    void go_right(MAP &a, int &Is_it_end, int &Is_it_win)   // шаг направо
    {
        ypic = h;            // переход на нужную строку в спрайтшите

        if (a.get_block(int(y / 50) - 1, int(x / 50)) == 2)        // если это дорожка
        {
            x += dx;
            xpic += w;      // переход к следующему кадру
            if(xpic >= 5 * w)
                xpic = w;
            //cout << " + " << "\n";
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50)) == 1)   // если это камень
        {
            a.set_block(int(y / 50) - 1, int(x / 50), 2);
            //cout << " +- " << "\n";
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50)) == 0)   // если это кореннная порода
        {
            xpic += w;      // переход к следующему кадру
            if(xpic >= 5 * w)
                xpic = w;
            //cout << " - " << "\n";
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50)) == 3)   // если это уголь, то собираем его и получаем 5 очков
        {
            a.set_block(int(y / 50) - 1, int(x / 50), 2);
            int point = 5;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50)) == 4)   // если это железо, то собираем его и получаем 20 очков
        {
            a.set_block(int(y / 50) - 1, int(x / 50), 2);
            int point = 20;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50)) == 5)   // если это золото, то собираем его и получаем 50 очков
        {
            a.set_block(int(y / 50) - 1, int(x / 50), 2);
            int point = 50;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50)) == 6)   // если это железо, то собираем его и получаем 70 очков
        {
            a.set_block(int(y / 50) - 1, int(x / 50), 2);
            int point = 70;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50)) == 7)   // если это железо, то собираем его и получаем 100 очков
        {
            a.set_block(int(y / 50) - 1, int(x / 50), 2);
            int point = 100;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50)) == -1)  // если это бомба
        {
            a.set_block(int(y / 50) - 1, int(x / 50), 2);
            Is_it_end = 1;
            //cout << "взорвался" << " ";
        }
    }

    void go_left(MAP &a, int &Is_it_end, int &Is_it_win)    // шаг налево
    {
        ypic = 3 * h;     // переход на нужную строку

        if (a.get_block(int(y / 50) - 1, int(x / 50) - 2) == 2)        // если это дорожка
        {
            x -= dx;
            xpic += w;      // переход к следующему кадру
            if(xpic >= 5 * w)
                xpic = w;
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50)- 2) == 1)    // если это камень
        {
            a.set_block(int(y / 50) - 1, int(x / 50) - 2, 2);
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50) - 2) == 0)   // если это кореннная порода
        {
            xpic += w;      // переход к следующему кадру
            if(xpic >= 5 * w)
                xpic = w;
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50)- 2) == 3)    // если это уголь, то собираем его и получаем 5 очков
        {
            a.set_block(int(y / 50) - 1, int(x / 50) - 2, 2);
            int point = 5;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50)- 2) == 4)    // если это железо, то собираем его и получаем 20 очков
        {
            a.set_block(int(y / 50) - 1, int(x / 50) - 2, 2);
            int point = 20;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50)- 2) == 5)    // если это золото, то собираем его и получаем 50 очков
        {
            a.set_block(int(y / 50) - 1, int(x / 50) - 2, 2);
            int point = 50;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50)- 2) == 6)    // если это изумруд, то собираем его и получаем 70 очков
        {
            a.set_block(int(y / 50) - 1, int(x / 50) - 2, 2);
            int point = 70;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50)- 2) == 7)    // если это уголь, то собираем его и получаем 100 очков
        {
            a.set_block(int(y / 50) - 1, int(x / 50) - 2, 2);
            int point = 100;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50)- 2) == -1)   // если это бомба
        {
            a.set_block(int(y / 50) - 1, int(x / 50) - 2, 2);
            Is_it_end = 1;
        }
    }

    void go_up(MAP &a, int &Is_it_end, int &Is_it_win)  // шаг вверх
    {
        ypic = 2 * h;     // переход на нужную строку

        if (a.get_block(int(y / 50) - 2, int(x / 50) - 1) == 2)        // если это дорожка
        {
            y -= dx;
            xpic += w;      // переход к следующему кадру
            if(xpic >= 5 * w)
                xpic = w;
        }
        else if (a.get_block(int(y / 50) - 2, int(x / 50) - 1) == 1)   // если это камень
        {
            a.set_block(int(y / 50) - 2, int(x / 50) - 1, 2);
        }
        else if (a.get_block(int(y / 50) - 2, int(x / 50) - 1) == 0)   // если это кореннная порода
        {
            xpic += w;      // переход к следующему кадру
            if(xpic >= 5 * w)
                xpic = w;
        }
        else if (a.get_block(int(y / 50) - 2, int(x / 50) - 1) == 3)   // если это уголь, то собираем его и получаем 5 очков
        {
            a.set_block(int(y / 50) - 2, int(x / 50) - 1, 2);
            int point = 5;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50) - 2, int(x / 50) - 1) == 4)   // если это железо, то собираем его и получаем 20 очков
        {
            a.set_block(int(y / 50) - 2, int(x / 50) - 1, 2);
            int point = 20;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50) - 2, int(x / 50) - 1) == 5)   // если это золото, то собираем его и получаем 50 очков
        {
            a.set_block(int(y / 50) - 2, int(x / 50) - 1, 2);
            int point = 50;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50) - 2, int(x / 50) - 1) == 6)   // если это изумруд, то собираем его и получаем 70 очков
        {
            a.set_block(int(y / 50) - 2, int(x / 50) - 1, 2);
            int point = 70;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50) - 2, int(x / 50) - 1) == 7)   // если это алмаз, то собираем его и получаем 100 очков
        {
            a.set_block(int(y / 50) - 2, int(x / 50) - 1, 2);
            int point = 100;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50) - 2, int(x / 50) - 1) == -1)  // если это бомба
        {
            a.set_block(int(y / 50) - 2, int(x / 50) - 1, 2);
            Is_it_end = 1;
        }
    }

    void go_down(MAP &a, int &Is_it_end, int &Is_it_win)    // шаг вниз
    {
        ypic = 0;     // переход на нужную строку

        if (a.get_block(int(y / 50), int(x / 50) - 1) == 2)        // если это дорожка
        {
            y += dx;
            xpic += w;      // переход к следующему кадру
            if(xpic >= 5 * w)
                xpic = w;
        }
        else if (a.get_block(int(y / 50), int(x / 50) - 1) == 1)   // если это камень
        {
            a.set_block(int(y / 50), int(x / 50) - 1, 2);
        }
        else if (a.get_block(int(y / 50), int(x / 50) - 1) == 0)   // если это кореннная порода
        {
            xpic += w;      // переход к следующему кадру
            if(xpic >= 5 * w)
                xpic = w;
        }
        else if (a.get_block(int(y / 50), int(x / 50) - 1) == 3)   // если это уголь, то собираем его и получаем 5 очков
        {
            a.set_block(int(y / 50), int(x / 50) - 1, 2);
            int point = 5;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50), int(x / 50) - 1) == 4)   // если это железо, то собираем его и получаем 20 очков
        {
            a.set_block(int(y / 50), int(x / 50) - 1, 2);
            int point = 20;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50), int(x / 50) - 1) == 5)   // если это золото, то собираем его и получаем 50 очков
        {
            a.set_block(int(y / 50), int(x / 50) - 1, 2);
            int point = 50;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50), int(x / 50) - 1) == 6)   // если это изумруд, то собираем его и получаем 70 очков
        {
            a.set_block(int(y / 50), int(x / 50) - 1, 2);
            int point = 70;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50), int(x / 50) - 1) == 7)   // если это алмаз, то собираем его и получаем 100 очков
        {
            a.set_block(int(y / 50), int(x / 50) - 1, 2);
            int point = 100;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50), int(x / 50) - 1) ==-1)   // если это бомба
        {
            a.set_block(int(y / 50), int(x / 50) - 1, 2);
            Is_it_end = 1;
        }
    }

    void score(int &point, int &Is_it_win)  // подсчет очков
    {
        count_1 += point;
        next_level(Is_it_win);
    }

    void out_score() // вывод очков
    {
        char out[10] = "";

        sprintf(out, "%d", count_1);

        txSetColor (TX_BLACK);
        txSetFillColor (TX_WHITE); Win32::RoundRect (txDC(), 345, 0, 500, 50, 5, 5);
        txSelectFont ("Arial", 20, 0, FW_BOLD);

        txDrawText (345, 0, 405,50, "Score:");
        txDrawText (405, 0, 495,50, out);
    }

    void next_level(int &Is_it_win) // переход на новый уровень
    {
        if (count_1 >= 600 && *count_level == 1) // переход на 2 уровень
        {
            *count_level = 2;
            a->set_new_level();
            x = 100;
            y = 100;
        }
        else if (count_1 >= 1200 && *count_level == 2) // переход на 3 уровень
        {
            *count_level = 3;
            a->set_new_level();
            x = 100;
            y = 100;
        }
        else if (count_1 >= 1800) // победа!
        {
            txClear();
            HDC Win = txLoadImage("Win.bmp");
            Win32::TransparentBlt(txDC(), 0, 0, 800, 800, Win, 0, 0, 800, 800, TX_WHITE);
            txSleep(500);
            txDeleteDC (Win);
            Is_it_win = 1;
        }
    }
};

//-----------------------------Функции:--------------------------------------

void check_picture(HDC Map, HDC miner); // проверка наличия картинок

void the_end(HDC Map, HDC miner); // удаление картинок

void check_die(int Is_it_end, int count_1); // проверка на смерть персонажа

void start(); // начало

//---------------------------------------------------------------------------

int main() // тело программы
{
    txCreateWindow(900, 900);
    txClear();

    int Is_it_end = 0;   // проверка на смерть
    int Is_it_win = 0;   // проверка на победу
    int count_level = 1; // счетчик уровня
    int count_1 = 0;     // счетчик очков

    //карта
    HDC Map = txLoadImage("Map_texture.bmp");  // загружаем текстуры
    MAP map_1;                                 // создаем класс карты
    map_1.init(Map, count_level);              // инициализируем класс карты

    // персонаж
    HDC miner  = txLoadImage ("miner.bmp");  // загружаем спрайтшит персонажа
    character Miner; // создаем класс персонажа
    Miner.init(100, 100, 0.5, 100, 94, 0, 0, TX_BLACK, miner, 50, map_1, count_1, 0, count_level, 0); // инициализируем класс персонажа

    check_picture(Map, miner); // проверяем наличие картинок

    start(); // начало

    while (!GetAsyncKeyState (VK_ESCAPE) && (Is_it_end == 0) && (Is_it_win == 0))
    {
        txClear();
        map_1.draw();               // рисование карты
        Miner.draw();               // рисование персонажа
        Miner.check_keys(map_1, Is_it_end, Is_it_win);    // проверяем нажатие кнопок
        check_die(Is_it_end, count_1);  // проверяем не подорвался ли наш персонаж на бомбе
        Miner.out_score();  // выводим очки
        txSleep(90);
    }
    the_end(Map, miner); // удаляем картинки
    return 0;
}

//---------------------------Описание функций:-------------------------------

void check_picture(HDC Map, HDC miner)  // проверка наличия картинок
{
    if (!Map)
        {
            txMessageBox("Не могу загрузить карту");
        }
    if (!miner)
        {
            txMessageBox("Не могу загрузить персонажа");
        }
}

void the_end(HDC Map, HDC miner)    // удаление картинок
{
    txDeleteDC (Map);
    txDeleteDC (miner);
}

void check_die(int Is_it_end, int count_1) // проверка на смерть персонажа
{
    if (Is_it_end == 1)
        {
            //cout << "+" << " ";
            txClear();
            HDC End = txLoadImage("Die.bmp");
            Win32::TransparentBlt(txDC(), 0, 0, 900, 900, End, 0, 0, 900, 900, TX_WHITE);

            //==---------Вывод счета--------==

            char out[10] = "";

            sprintf(out, "%d", count_1);

            txSetColor (TX_BLACK);
            txSetFillColor (TX_WHITE); Win32::RoundRect (txDC(), 345, 0, 500, 50, 5, 5);
            txSelectFont ("Arial", 20, 0, FW_BOLD);

            txDrawText (345, 850, 405, 900, "Score:");
            txDrawText (405, 850, 495, 900, out);

            //---------------------------------

            txSleep(500);
            txDeleteDC (End);
            //cout << "удалил ";
            //exit(1);
        }
}

void start() // начало
{
    HDC Start = txLoadImage("Start_1.bmp");
    HDC Rules = txLoadImage("Rules.bmp");

    txClear();
    Win32::TransparentBlt(txDC(), 0, 0, 900, 810, Start, 0, 0, 900, 810, TX_WHITE);
    txSleep(3000);
    txClear();
    Win32::TransparentBlt(txDC(), 0, 0, 900, 900, Rules, 0, 0, 900, 900, TX_WHITE);
    txSleep(10000);

    txDeleteDC (Start);
    txDeleteDC (Rules);
}
