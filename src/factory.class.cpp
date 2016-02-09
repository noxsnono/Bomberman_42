// ************************************************************************** //
//   24 Bomb                                                                  //
//   By: rcargou <rcargou@student.42.fr>                  :::      ::::::::   //
//   By: nmohamed <nmohamed@student.42.fr>              :+:      :+:    :+:   //
//   By: adjivas <adjivas@student.42.fr>              +:+ +:+         +:+     //
//   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        //
//   By: jmoiroux <jmoiroux@student.42.fr>        +#+#+#+#+#+   +#+           //
//   Created: 2015/10/16 17:03:20 by rcargou           #+#    #+#             //
//   Updated: 2015/10/27 14:00:02 by rcargou          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <factory.class.hpp>
#include <wall.class.hpp>
#include <bomb.class.hpp>
#include <bonus.class.hpp>
#include <fire.class.hpp>
#include <player.class.hpp>
#include <enemy.class.hpp>
#include <boss.class.hpp>

Factory::Factory() {}

Factory::~Factory() {}

Wall *		Factory::create_wall(int status, float x, float y, int model) {
	Wall * wall = new Wall(x, y, status, model);
	if (wall == NULL) {
		main_event->w_full("Factory::create_wall:: wall Malloc error");
		throw std::exception();
	}
	return wall;
}

Bonus *		Factory::create_bonus(int status, float x, float y, int model) {
	Bonus * bonus = new Bonus(x, y, status, model);
	if (bonus == NULL) {
		main_event->w_full("create_bonus:: bonus Malloc error");
		throw std::exception();
	}
	return bonus;
}

Bomb *		Factory::create_bomb(int status, float x, float y, int model, int id) {
	Bomb * bomb = new Bomb(x, y, status, model, id);
	if (bomb == NULL) {
		main_event->w_full("create_bomb:: bomb Malloc error");
		throw std::exception();
	}
	return bomb;
}

Fire *		Factory::create_fire(int status, float x, float y, int model) {
	Fire * fire = new Fire(x, y, status, model);
	if (fire == NULL) {
		main_event->w_error("create_fire:: fire Malloc error");
		throw std::exception();
	}
	return fire;
}

Player *	Factory::create_player(int status, float x, float y, int model) {
	Player * player = new Player(x, y, status, model);
	if (player == NULL) {
		main_event->w_error("create_player:: player Malloc error");
		throw std::exception();
	}
	return player;
}

Enemy *		Factory::create_enemy(int status, float x, float y, int model) {
	Enemy * enemy = new Enemy(x, y, status, model);
	if (enemy == NULL) {
		main_event->w_error("create_enemy:: enemy Malloc error");
		throw std::exception();
	}
	return enemy;
}

Boss *		Factory::create_boss(int status, float x, float y, int name, int model) {
	Boss * boss = new Boss(x, y, status, name, model);
	if (boss == NULL) {
		main_event->w_error("create_enemy:: enemy Malloc error");
		throw std::exception();
	}
	return boss;
}

Entity *	Factory::create_empty(int x, int y) {
	Entity * ent = new Entity(EMPTY, (float)x, (float)y, NO_STATUS);
	if (ent == NULL) {
		main_event->w_error("create_empty:: enemy Malloc error");
		throw std::exception();
	}
	ent->model = -1;
	return ent;
}