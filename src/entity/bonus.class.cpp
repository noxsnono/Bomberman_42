/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 17:03:20 by rcargou           #+#    #+#             */
/*   Updated: 2016/02/04 17:49:59 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bonus.class.hpp>
#include <entity.class.hpp>

Bonus::~Bonus( void ) {}

Bonus::Bonus( float x, float y, int status, int model ) : Entity( BONUS, x, y, status ) {
	this->model = model;
}

void Bonus::change_bomb(Entity *ent) {
	int rd = rand() % 4;

	if (rd == 0)
		ent->bomb_model = BOMB_DEFAULT;
	else if (rd == 1)
		ent->bomb_model = BOMB_WATER;
	else if (rd == 2)
		ent->bomb_model = BOMB_LIGHT;
	else
		ent->bomb_model = BOMB_WIND;
}

void	Bonus::affect(Entity *ent) {
	if (this->model == BONUS_POWER_UP)
		ent->blast_radius++;
	else if (this->model == BONUS_PLUS_ONE)
		ent->bomb_nbr++;
	else if (this->model == BONUS_KICK)
		ent->kick_bomb = true;
	else if (this->model == BONUS_CHANGE)
		change_bomb(ent);
}
