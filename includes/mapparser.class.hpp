/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 13:27:34 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/11/07 16:09:55 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPPARSER_CLASS_HPP
# define MAPPARSER_CLASS_HPP

# include <ft42.class.hpp>

static std::map<std::string, int> const mapcase = {

  {"   ", EMPTY},
  {"1##", WALL_INDESTRUCTIBLE},
  {"1#1", WALL_HP_1},
  {"1#2", WALL_HP_2},
  {"1#3", WALL_HP_3},
  {"1#4", WALL_HP_4},
  {"2#1", ENEMY1},
  {"2#2", ENEMY2},
  {"2#3", ENEMY3},
  {"2#4", ENEMY4},
  {"3#a", BOSS_A},
  {"3#b", BOSS_B},
  {"3#c", BOSS_C}

};

class Entity;

class Mapparser : public ft42 {
public:
  static std::string *  error;

  Mapparser();
  virtual ~Mapparser();

  void        get_error() const ;
  static int  valid_map( char const *map_path ) ;

  Entity ***  map_from_file( char *map_path );
  Entity ***  map_alloc();

};

#endif