#ifndef FIRE_CLASS_HPP
# define FIRE_CLASS_HPP

# include <entity.class.hpp>

class Fire : public Entity {
public:
	
	Fire( int x, int y, int status );
	Fire( Fire const & src );
	Fire & operator=( Fire const & rhs );
	virtual ~Fire( void );

private:
	Fire( void );
};

#endif