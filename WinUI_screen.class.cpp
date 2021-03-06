#include    "WinUI_screen.class.hpp"

void	WinUI_screen::update ( std::list<AGameObject*> &l )
{
	//werase ( win );
	//box( win, 0, 0 );
	bg->draw(win, 1, 1);
	draw_all ( l );
	wrefresh ( win );
}

void	WinUI_screen::draw_all ( std::list<AGameObject*> const &l ) const
{
	std::list<AGameObject*>::const_iterator	it(l.begin());
	std::list<AGameObject*>::const_iterator	end(l.end());
	for (; it!=end; ++it) {
		draw( *it );
	}
}

void	WinUI_screen::draw ( AGameObject* const &u ) const
{
	vector2 v = u->pos;
	if (u->sk) {
		u->sk->init_cp();
		wattron(win, COLOR_PAIR(u->sk->_id));
		int	w = u->w;
		if ( w == 1 ) {
			char c = u->sk->_c;
			mvwaddch( win, v.y, v.x, c);
		}
		wattroff(win, COLOR_PAIR(u->sk->_id));
	}
}

//--------------------

WinUI_screen::WinUI_screen(void) 
: WinUI()
{
}

WinUI_screen::WinUI_screen(unsigned int width, unsigned int height, unsigned int x, unsigned y)
: WinUI(width, height, x, y)
{
	bg = new Asciimg(_height, _width);
	bg->load("bg");
}

WinUI_screen::~WinUI_screen(void)
{
}

/*
WinUI_screen::WinUI_screen(WinUI_screen const & src)
: WinUI(src)
{
}
WinUI_screen &	WinUI_screen::operator=(WinUI_screen const & src) {
	this->_height = src.h;
	this->_width = src.h;
	this->_heightMap = src.h * 3;
	this->_startX = src.getStartX();
	this->_startY = src.getStartY();
    return *this;
}
*/
