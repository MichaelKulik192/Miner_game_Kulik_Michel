/// \@author ����� ������
#include "TXLib.h"

//----------------------------������:----------------------------------------

class MAP // ����� �����
{
  private:
    HDC Map;
    int maze[15][15]; // ������ � ������, ������ ���� ������� !

  public:
    int *count_level; // ������� ������

    void init(HDC Map,int &count_level)     // �������������
    {
        this->Map = Map;
        this->count_level = &count_level;
        set_new_level();
    }

    void draw()     // ���������
    {
        for(int i = 0; i < 15; i++)
        {
            for(int j = 0; j < 15; j++)
            {
                if(maze[i][j] == 0)     // �������� ������
                {
                    Win32::TransparentBlt(txDC(), 50 * (j+ 1), 50 * (i + 1), 50, 50, Map, 0, 0, 50, 50, TX_WHITE);
                }
                else if(maze[i][j] == 1)    // ������
                {
                        Win32::TransparentBlt(txDC(), 50 * (j+ 1), 50 * (i + 1), 50, 50, Map, 0, 50, 50, 50, TX_WHITE);
                }
                else if(maze[i][j] == 2)    // �������
                {
                        Win32::TransparentBlt(txDC(), 50 * (j+ 1), 50 * (i + 1), 50, 50, Map, 0, 100, 50, 50, TX_WHITE);
                }
                else if(maze[i][j] == 3)    // �����
                {
                    Win32::TransparentBlt(txDC(), 50 * (j+ 1), 50 * (i + 1), 50, 50, Map, 50, 200, 50, 50, TX_WHITE);
                }
                else if(maze[i][j] == 4)    // ������
                {
                    Win32::TransparentBlt(txDC(), 50 * (j+ 1), 50 * (i + 1), 50, 50, Map, 50, 150, 50, 50, TX_WHITE);
                }
                else if(maze[i][j] == 5)    // ������
                {
                    Win32::TransparentBlt(txDC(), 50 * (j+ 1), 50 * (i + 1), 50, 50, Map, 50, 100, 50, 50, TX_WHITE);
                }
                else if(maze[i][j] == 6)    // ��������
                {
                    Win32::TransparentBlt(txDC(), 50 * (j+ 1), 50 * (i + 1), 50, 50, Map, 50, 50, 50, 50, TX_WHITE);
                }
                else if(maze[i][j] == 7)    // ������
                {
                    Win32::TransparentBlt(txDC(), 50 * (j+ 1), 50 * (i + 1), 50, 50, Map, 50, 0, 50, 50, TX_WHITE);
                }
                else if(maze[i][j] == -1)  // �����
                {
                    Win32::TransparentBlt(txDC(), 50 * (j+ 1), 50 * (i + 1), 50, 50, Map, 0, 50, 50, 50, TX_WHITE);
                }
            }
        }
    }

    int get_block(int i, int j)     // ������ ����� �� ������� � ������
    {
        return maze[i][j];
    }

    void set_block(int i, int j, int n) // ������ ����� �� ������� � ������ �� �����
    {
        maze[i][j] = n;
    }

    void set_new_level() // ������� �� ����� �������
    {
        int map_1[15][15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // ������ �������
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

        int map_2[15][15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // ������ �������
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

        int map_3[15][15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // ������ �������
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


        if (*count_level == 1) // ���� 1 �������
        {
            for(int i = 0; i < 15; i++)
            {
                for(int j = 0; j < 15; j++)
                {
                    this->maze[i][j] = map_1[i][j];
                }
            }
        }
        else if (*count_level == 2) // ���� 2 �������
        {
            for(int i = 0; i < 15; i++)
            {
                for(int j = 0; j < 15; j++)
                {
                    this->maze[i][j] = map_2[i][j];
                }
            }
        }
        else if (*count_level == 3) // ���� 3 �������
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

class character // ����� ���������
{
  private:
    int x, y;           // ���������� ���������
    double siz;         // ����������
    int w, h;           // ������ � ������ ����� � ����������
    int xpic, ypic;     // ����� ������� ���� �����
    COLORREF color;     // ����, ������� ������ ����������
    HDC Miner;
    int dx;             // ��� ���������

    int count_1;        // ������� �����

    MAP *a;

    int *Is_it_end;     // ��� �����?
    int *Is_it_win;     // ��� ������?

    int *count_level;   // ������� �������


  public:
    void init(int x, int y, double siz, int w, int h, int xpic, int ypic, COLORREF color, HDC Miner, int dx, MAP &map_1, int count_1, int Is_it_end, int &count_level, int Is_it_win) // �������������
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

    void draw()  // ���������
    {
        Win32::TransparentBlt(txDC(), x, y, int(siz * w), int(siz * h), Miner, xpic, ypic, w, h, color);
    }

    void check_keys(MAP &a, int &Is_it_end, int &Is_it_win)  // �������� ������� ������
    {
        if (GetAsyncKeyState (VK_RIGHT)) // ���� ������ ������� ������
        {
            go_right(a, Is_it_end, Is_it_win);
        }

        if (GetAsyncKeyState (VK_LEFT)) // ���� ������ ������� �����
        {
            go_left(a, Is_it_end, Is_it_win);
        }

        if (GetAsyncKeyState (VK_UP)) // ���� ������ ������� �����
        {
            go_up(a, Is_it_end, Is_it_win);
        }

        if (GetAsyncKeyState (VK_DOWN)) // ���� ������ ������� ����
        {
            go_down(a, Is_it_end, Is_it_win);
        }
    }

    void go_right(MAP &a, int &Is_it_end, int &Is_it_win)   // ��� �������
    {
        ypic = h;            // ������� �� ������ ������ � ����������

        if (a.get_block(int(y / 50) - 1, int(x / 50)) == 2)        // ���� ��� �������
        {
            x += dx;
            xpic += w;      // ������� � ���������� �����
            if(xpic >= 5 * w)
                xpic = w;
            //cout << " + " << "\n";
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50)) == 1)   // ���� ��� ������
        {
            a.set_block(int(y / 50) - 1, int(x / 50), 2);
            //cout << " +- " << "\n";
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50)) == 0)   // ���� ��� ��������� ������
        {
            xpic += w;      // ������� � ���������� �����
            if(xpic >= 5 * w)
                xpic = w;
            //cout << " - " << "\n";
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50)) == 3)   // ���� ��� �����, �� �������� ��� � �������� 5 �����
        {
            a.set_block(int(y / 50) - 1, int(x / 50), 2);
            int point = 5;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50)) == 4)   // ���� ��� ������, �� �������� ��� � �������� 20 �����
        {
            a.set_block(int(y / 50) - 1, int(x / 50), 2);
            int point = 20;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50)) == 5)   // ���� ��� ������, �� �������� ��� � �������� 50 �����
        {
            a.set_block(int(y / 50) - 1, int(x / 50), 2);
            int point = 50;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50)) == 6)   // ���� ��� ������, �� �������� ��� � �������� 70 �����
        {
            a.set_block(int(y / 50) - 1, int(x / 50), 2);
            int point = 70;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50)) == 7)   // ���� ��� ������, �� �������� ��� � �������� 100 �����
        {
            a.set_block(int(y / 50) - 1, int(x / 50), 2);
            int point = 100;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50)) == -1)  // ���� ��� �����
        {
            a.set_block(int(y / 50) - 1, int(x / 50), 2);
            Is_it_end = 1;
            //cout << "���������" << " ";
        }
    }

    void go_left(MAP &a, int &Is_it_end, int &Is_it_win)    // ��� ������
    {
        ypic = 3 * h;     // ������� �� ������ ������

        if (a.get_block(int(y / 50) - 1, int(x / 50) - 2) == 2)        // ���� ��� �������
        {
            x -= dx;
            xpic += w;      // ������� � ���������� �����
            if(xpic >= 5 * w)
                xpic = w;
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50)- 2) == 1)    // ���� ��� ������
        {
            a.set_block(int(y / 50) - 1, int(x / 50) - 2, 2);
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50) - 2) == 0)   // ���� ��� ��������� ������
        {
            xpic += w;      // ������� � ���������� �����
            if(xpic >= 5 * w)
                xpic = w;
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50)- 2) == 3)    // ���� ��� �����, �� �������� ��� � �������� 5 �����
        {
            a.set_block(int(y / 50) - 1, int(x / 50) - 2, 2);
            int point = 5;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50)- 2) == 4)    // ���� ��� ������, �� �������� ��� � �������� 20 �����
        {
            a.set_block(int(y / 50) - 1, int(x / 50) - 2, 2);
            int point = 20;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50)- 2) == 5)    // ���� ��� ������, �� �������� ��� � �������� 50 �����
        {
            a.set_block(int(y / 50) - 1, int(x / 50) - 2, 2);
            int point = 50;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50)- 2) == 6)    // ���� ��� �������, �� �������� ��� � �������� 70 �����
        {
            a.set_block(int(y / 50) - 1, int(x / 50) - 2, 2);
            int point = 70;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50)- 2) == 7)    // ���� ��� �����, �� �������� ��� � �������� 100 �����
        {
            a.set_block(int(y / 50) - 1, int(x / 50) - 2, 2);
            int point = 100;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50) - 1, int(x / 50)- 2) == -1)   // ���� ��� �����
        {
            a.set_block(int(y / 50) - 1, int(x / 50) - 2, 2);
            Is_it_end = 1;
        }
    }

    void go_up(MAP &a, int &Is_it_end, int &Is_it_win)  // ��� �����
    {
        ypic = 2 * h;     // ������� �� ������ ������

        if (a.get_block(int(y / 50) - 2, int(x / 50) - 1) == 2)        // ���� ��� �������
        {
            y -= dx;
            xpic += w;      // ������� � ���������� �����
            if(xpic >= 5 * w)
                xpic = w;
        }
        else if (a.get_block(int(y / 50) - 2, int(x / 50) - 1) == 1)   // ���� ��� ������
        {
            a.set_block(int(y / 50) - 2, int(x / 50) - 1, 2);
        }
        else if (a.get_block(int(y / 50) - 2, int(x / 50) - 1) == 0)   // ���� ��� ��������� ������
        {
            xpic += w;      // ������� � ���������� �����
            if(xpic >= 5 * w)
                xpic = w;
        }
        else if (a.get_block(int(y / 50) - 2, int(x / 50) - 1) == 3)   // ���� ��� �����, �� �������� ��� � �������� 5 �����
        {
            a.set_block(int(y / 50) - 2, int(x / 50) - 1, 2);
            int point = 5;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50) - 2, int(x / 50) - 1) == 4)   // ���� ��� ������, �� �������� ��� � �������� 20 �����
        {
            a.set_block(int(y / 50) - 2, int(x / 50) - 1, 2);
            int point = 20;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50) - 2, int(x / 50) - 1) == 5)   // ���� ��� ������, �� �������� ��� � �������� 50 �����
        {
            a.set_block(int(y / 50) - 2, int(x / 50) - 1, 2);
            int point = 50;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50) - 2, int(x / 50) - 1) == 6)   // ���� ��� �������, �� �������� ��� � �������� 70 �����
        {
            a.set_block(int(y / 50) - 2, int(x / 50) - 1, 2);
            int point = 70;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50) - 2, int(x / 50) - 1) == 7)   // ���� ��� �����, �� �������� ��� � �������� 100 �����
        {
            a.set_block(int(y / 50) - 2, int(x / 50) - 1, 2);
            int point = 100;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50) - 2, int(x / 50) - 1) == -1)  // ���� ��� �����
        {
            a.set_block(int(y / 50) - 2, int(x / 50) - 1, 2);
            Is_it_end = 1;
        }
    }

    void go_down(MAP &a, int &Is_it_end, int &Is_it_win)    // ��� ����
    {
        ypic = 0;     // ������� �� ������ ������

        if (a.get_block(int(y / 50), int(x / 50) - 1) == 2)        // ���� ��� �������
        {
            y += dx;
            xpic += w;      // ������� � ���������� �����
            if(xpic >= 5 * w)
                xpic = w;
        }
        else if (a.get_block(int(y / 50), int(x / 50) - 1) == 1)   // ���� ��� ������
        {
            a.set_block(int(y / 50), int(x / 50) - 1, 2);
        }
        else if (a.get_block(int(y / 50), int(x / 50) - 1) == 0)   // ���� ��� ��������� ������
        {
            xpic += w;      // ������� � ���������� �����
            if(xpic >= 5 * w)
                xpic = w;
        }
        else if (a.get_block(int(y / 50), int(x / 50) - 1) == 3)   // ���� ��� �����, �� �������� ��� � �������� 5 �����
        {
            a.set_block(int(y / 50), int(x / 50) - 1, 2);
            int point = 5;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50), int(x / 50) - 1) == 4)   // ���� ��� ������, �� �������� ��� � �������� 20 �����
        {
            a.set_block(int(y / 50), int(x / 50) - 1, 2);
            int point = 20;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50), int(x / 50) - 1) == 5)   // ���� ��� ������, �� �������� ��� � �������� 50 �����
        {
            a.set_block(int(y / 50), int(x / 50) - 1, 2);
            int point = 50;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50), int(x / 50) - 1) == 6)   // ���� ��� �������, �� �������� ��� � �������� 70 �����
        {
            a.set_block(int(y / 50), int(x / 50) - 1, 2);
            int point = 70;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50), int(x / 50) - 1) == 7)   // ���� ��� �����, �� �������� ��� � �������� 100 �����
        {
            a.set_block(int(y / 50), int(x / 50) - 1, 2);
            int point = 100;
            score(point, Is_it_win);
        }
        else if (a.get_block(int(y / 50), int(x / 50) - 1) ==-1)   // ���� ��� �����
        {
            a.set_block(int(y / 50), int(x / 50) - 1, 2);
            Is_it_end = 1;
        }
    }

    void score(int &point, int &Is_it_win)  // ������� �����
    {
        count_1 += point;
        next_level(Is_it_win);
    }

    void out_score() // ����� �����
    {
        char out[10] = "";

        sprintf(out, "%d", count_1);

        txSetColor (TX_BLACK);
        txSetFillColor (TX_WHITE); Win32::RoundRect (txDC(), 345, 0, 500, 50, 5, 5);
        txSelectFont ("Arial", 20, 0, FW_BOLD);

        txDrawText (345, 0, 405,50, "Score:");
        txDrawText (405, 0, 495,50, out);
    }

    void next_level(int &Is_it_win) // ������� �� ����� �������
    {
        if (count_1 >= 600 && *count_level == 1) // ������� �� 2 �������
        {
            *count_level = 2;
            a->set_new_level();
            x = 100;
            y = 100;
        }
        else if (count_1 >= 1200 && *count_level == 2) // ������� �� 3 �������
        {
            *count_level = 3;
            a->set_new_level();
            x = 100;
            y = 100;
        }
        else if (count_1 >= 1800) // ������!
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

//-----------------------------�������:--------------------------------------

void check_picture(HDC Map, HDC miner); // �������� ������� ��������

void the_end(HDC Map, HDC miner); // �������� ��������

void check_die(int Is_it_end, int count_1); // �������� �� ������ ���������

void start(); // ������

//---------------------------------------------------------------------------

int main() // ���� ���������
{
    txCreateWindow(900, 900);
    txClear();

    int Is_it_end = 0;   // �������� �� ������
    int Is_it_win = 0;   // �������� �� ������
    int count_level = 1; // ������� ������
    int count_1 = 0;     // ������� �����

    //�����
    HDC Map = txLoadImage("Map_texture.bmp");  // ��������� ��������
    MAP map_1;                                 // ������� ����� �����
    map_1.init(Map, count_level);              // �������������� ����� �����

    // ��������
    HDC miner  = txLoadImage ("miner.bmp");  // ��������� ��������� ���������
    character Miner; // ������� ����� ���������
    Miner.init(100, 100, 0.5, 100, 94, 0, 0, TX_BLACK, miner, 50, map_1, count_1, 0, count_level, 0); // �������������� ����� ���������

    check_picture(Map, miner); // ��������� ������� ��������

    start(); // ������

    while (!GetAsyncKeyState (VK_ESCAPE) && (Is_it_end == 0) && (Is_it_win == 0))
    {
        txClear();
        map_1.draw();               // ��������� �����
        Miner.draw();               // ��������� ���������
        Miner.check_keys(map_1, Is_it_end, Is_it_win);    // ��������� ������� ������
        check_die(Is_it_end, count_1);  // ��������� �� ���������� �� ��� �������� �� �����
        Miner.out_score();  // ������� ����
        txSleep(90);
    }
    the_end(Map, miner); // ������� ��������
    return 0;
}

//---------------------------�������� �������:-------------------------------

void check_picture(HDC Map, HDC miner)  // �������� ������� ��������
{
    if (!Map)
        {
            txMessageBox("�� ���� ��������� �����");
        }
    if (!miner)
        {
            txMessageBox("�� ���� ��������� ���������");
        }
}

void the_end(HDC Map, HDC miner)    // �������� ��������
{
    txDeleteDC (Map);
    txDeleteDC (miner);
}

void check_die(int Is_it_end, int count_1) // �������� �� ������ ���������
{
    if (Is_it_end == 1)
        {
            //cout << "+" << " ";
            txClear();
            HDC End = txLoadImage("Die.bmp");
            Win32::TransparentBlt(txDC(), 0, 0, 900, 900, End, 0, 0, 900, 900, TX_WHITE);

            //==---------����� �����--------==

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
            //cout << "������ ";
            //exit(1);
        }
}

void start() // ������
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
