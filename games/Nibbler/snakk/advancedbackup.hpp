#ifndef ADVANCEDBACKUP_HPP
#define ADVANCEDBACKUP_HPP

#include <ncurses.h>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>


class Pos
{
    protected :
    int  _x, _y;
    //char _c;

    public :
        // Dtor
        ~Pos() = default;
        // Ctor
        Pos() : _x(0), _y(0) {}
        Pos(int x, int y/*, char c = 'x'*/) { setX(x), setY(y); /*setC(c);*/ }

        // Getter
        int  getX(void) const { return _x; }
        int  getY(void) const { return _y; }
        //char getC(void) const { return c; }
        // Setter
        void setX(int x)  { _x = x; }
        void setY(int y)  { _y = y; }
        void  setXY(int x, int y) { setX(x); setY(y); }
        //void setC(char c) { _c = c; }

        // Operator
        Pos &operator=(const Pos &vec)  { _x = vec.getX(); _y = vec.getY(); return *this; }
        Pos &operator+=(const Pos &vec) { _x += vec.getX(); _y += vec.getY(); return *this; }
        Pos &operator+(const Pos &vec)  { Pos _v(_x, _y); return (_v += vec); }
        Pos &operator-=(const Pos &vec) { _x -= vec.getX(); _y -= vec.getY(); return *this; }
        Pos &operator-(const Pos &vec)  { Pos _v(_x, _y); return (_v -= vec); }
        bool operator==(const Pos &vec) { return (_x == vec.getX() && _y == vec.getY()); }
        bool operator!=(const Pos &vec) { return !operator==(vec); }
};

class Item
{
    public :
    void getApple(int width, int height)
    {
        _xy.setX(rand() % width);
        _xy.setY(rand() % height);
    }
    //Pos getXY (void) const { return _xy; }
    int getX  (void) const { return _xy.getX(); }
    int getY  (void) const { return _xy.getY(); }
    //protected :
    Pos _xy;
};

class Snake
{
    protected :
    const int _height;
    const int _width;
    int _speed;
    int _tmpspeed;
    bool _exit;
    int _score;
    bool _write;
    std::vector<Pos> _body;
    Pos _direction;

    public :
        Item _apple;
        int _timer;
        int _boost;
    // Dtor
        ~Snake() {}
    // Ctor
        //        40 - 2      80 - 2
        Snake(int height, int width) : _height(height), _width(width), _speed(180), _tmpspeed(180), _exit(false), _score(0), _write(false)
        {
            _apple.getApple(width, height);
            _timer = 0;
            _boost = 1;
            _body.push_back(Pos(width/2, height/2));
            for (int i = 0; i != 3; i++)
                _body.push_back(_body.back());
            setDirection(0); // 0 = go en haut
            srand(time(NULL));
        }
    // Mem func
        void setDirection(int p)
        {
            if      (p == 0) _direction = Pos(0, -1);   // up
            else if (p == 1) _direction = Pos(1, 0);    // right
            else if (p == 2) _direction = Pos(0, 1);    // down
            else if (p == 3) _direction = Pos(-1, 0);   // left
        }
        void makeMove(void)
        {
            // Check if X is OOB
            if (_body[0].getX() < 0 || _body[0].getX() >= _width)
                _exit = true;
            else if (_body[0].getX() == 0 && _direction == Pos(-1, 0))
                _exit = true;
            else if (_body[0].getX() == (_width - 1) && _direction == Pos(1, 0))
                _exit = true;
            // Check if Y is OOB
            if (_body[0].getY() < 0 || _body[0].getY() >= _height)
                _exit = true;
            else if (_body[0].getY() == 0 && _direction == Pos(0, -1))
                _exit = true;
            else if (_body[0].getY() == (_height - 1) && _direction == Pos(0, 1))
                _exit = true;

            // add the direction to head of the snake
            if (!_exit) _body[0] += _direction;

            for (unsigned int i = 1; i < _body.size() - 1; ++i) // check self collision
                if (_body[i] == _body[0]) { _exit = true; break; }
        }
        void bodyMove(void)
        {
            for (unsigned int i = _body.size() - 1; i > 0; --i)
                snakeSwap(i);
        }
        void snakeSwap(uint i)
        {
            if (i >= _body.size())
                _body.push_back(_body.back());
            else
                _body[i] = _body[i - 1];
        }
    // Getter & Setter
        bool  getExit(void)      const   {  return _exit;     } // Is the game should exit?
        int   getSpeed(void)     const   {  return _speed;    } // Speed of the snake
        int   getTmpSpeed(void)  const   {  return _tmpspeed; } // To actually know if the snake got a boost
        int   getHeight(void)    const   {  return _height;   } // Height of the bounds
        int   getWidth(void)     const   {  return _width;    } // Width  of the bounds
        int   getScore(void)     const   {  return _score;    } // 1 apple = + 10
        bool  getWrite(void)     const   {  return _write;    } // Is the score already written
        void  setExit(bool exit)         {  _exit  = exit;    }
        void  setSpeed(int speed)        {  _speed = speed;   }
        void  setTSpeed(int tsd)         {  _tmpspeed = tsd;  }
        void  setWrite(bool write)       {  _write = write;   }
        Item  getApple(void)     const   {  return _apple;    }
        //Pos   getHead(void)      const   {  return _body[0];  }
        std::vector<Pos> getBody(void) const {  return _body; }

        int getDirection(void)
        {
            if (_direction.getX() == 1)
                return 1;
            else if (_direction.getX() == -1)
                return 3;
            else if (_direction.getY() == -1)
                return 0;
            else
                return 2;
        }

        void isPicked()
        {
            if (_body[0] == _apple._xy) {
                _apple.getApple(_width, _height);
                for (long unsigned int i = 0; i != _body.size(); i++) // if apple spawned in the snake body
                    if (_apple._xy == _body[i]) _apple.getApple(_width, _height);
                /*for (int k = 19; k != 29; k++)  // if apple spawned in the h barrier
                    if (_apple.getXY() == Pos(k, 2)) _apple.getApple(_width, _height);
                for (int j = 14; j != 30; j++)  // if apple spawned in the v barrier
                    if (_apple.getXY() == Pos(57, j)) _apple.getApple(_width, _height);*/
                snakeSwap(_body.size());
                _score += 10;
            }
        }
};

class Score
{

};

class Screen
{
    public :
    // Dtor
        ~Screen()
        {
            delwin(win);
            endwin();
        }
    // Ctor
        Screen(int x, int y, bool delay = false) : _x(x), _y(y)
        {
            initscr();
            noecho();
            cbreak();
            win = newwin(y - 3, x, 1, 0); // height, width, startY, startX
            box(win, 0, 0);
            delay == false ? nodelay(win, FALSE) : nodelay(win, TRUE);
            keypad(win, TRUE);
            curs_set(0);
        }
    // Mem func
        WINDOW *getwindow(void) const { return win; }
        void    setDelay(bool delay) { delay == false ? nodelay(win, FALSE) : nodelay(win, TRUE); }
    protected :
    int _x;
    int _y;
    WINDOW *win;
};

#endif