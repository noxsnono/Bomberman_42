#include <enemy.class.hpp>

Enemy::~Enemy( void ) {}

Enemy::Enemy( int id, int x, int y, int status ) : Entity( ENEMY, id, x, y, status ) {
	this->frame = 0;
	this->speed = 1;
	this->dir = DIR_BOTTOM;
}
