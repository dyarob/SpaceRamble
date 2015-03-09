#ifndef SKIN_HPP
# define SKIN_HPP

# include <vector>
# include <ncurses.h>
# include <fstream>

# include "CONST.h"

# ifndef MAXBG
#  define MAXBG 4
#  define MAXLUM 2
#  define MAXFOG 1
#  define IFG MAXBG*MAXLUM*MAXFOG
# endif

class Skin {

	private :
		// not declared in .cpp
		//Skin( void );
		//Skin( Skin const& );
		//Skin&	operator=( Skin const& );

		short	fg;
		short	bg;
		short	lum;
		short	fog;


	public :
		~Skin( void );
		Skin( char, short, short, short, short );

		short	cpId;
		char	c;

		std::ofstream	&printTo( std::ofstream &o ) const;
		std::ostream	&printTo( std::ostream &o ) const;
		void	redefine_fg( short fg );
		void	redefine_bg( short bg );

/*
		static short	cfg, cbg;
		static Skin		*curr_sk;
		static char		color_mode;

		static void		init_reserved_cp();
		static void		color_pick( short c );
		static void		print_cc();
*/
};

std::ofstream	&operator<<( std::ofstream &o, Skin const &sk );
std::ostream	&operator<<( std::ostream &o, Skin const &sk );

#endif
