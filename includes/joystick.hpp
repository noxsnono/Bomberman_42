/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joystick.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 17:03:20 by rcargou           #+#    #+#             */
/*   Updated: 2016/02/05 12:50:12 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOYSTICK_HPP
# define JOYSTICK_HPP

# include <ft42.class.hpp>

# define CONFIG_FILE "config/config.txt"

class Joystick : public ft42 {
public:
	int				timer;
	int				test = 0;
	SDL_Joystick *	manette1;
	SDL_Joystick *	manette2;
	int 			config[5]; // 0: controller, 1: keyboard

	Joystick(void);
	// Joystick( Joystick const & src );
	// Joystick & operator=( Joystick const & rhs );
	virtual ~Joystick( void );
	void read_key(int mode);
	void change_dir_joystick(t_key *key, int dir);
	void load_config( void );
	void	save_config( void );
	void	save_default_config( void );

private:

};

#endif
