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

# include <particle.class.hpp>
# include <ctime>
# include <fire.class.hpp>

	std::list<Particle*>* Particle::list = new std::list<Particle*>;

	Particle::Particle( float x, float y, float z, int status, int _model ) : Entity(status, x, y, status, _model)
	{
        float r;
        float e;

		this->model = _model;
		cycle = 0;
		pos_z = z;
		r = rand();
		r /= RAND_MAX;
		r *= 6.28;
 		e = rand();
		e /= RAND_MAX;
		velx = cos(r) * e;
		e = rand();
		e /= RAND_MAX;
		velz = sin(r) * e;
		r = rand();
		r /= RAND_MAX;
		vely = (r * 6);
		lifetime = rand() / 10000000;
	}

	Particle::Particle( Particle const & src ) : Entity(src.type, src.pos_x, src.pos_y, src.status, src.model)
	{
		*this = src;
	}

	Particle & Particle::operator=( Particle const & rhs )
	{
		(Particle)rhs;
		return (*this);
	}

	Particle::~Particle( void )
	{

	}

	void Particle::update()
	{
		lifetime--;
		cycle++;
		vely -= 0.07 + vely / 100;
		velx -= velx / 100;
		velz -= velz / 100;

		if (pos_y < 0 || pos_y > 20 || pos_x < 0 || pos_x > 20 || pos_z < 0)
			;
		else
		{
			if (this->model == WALL_HP_1)
			{
				if (main_event->map[(int)pos_y][(int)pos_x]->type == EMPTY && vely + pos_z <= 0)
				{
					this->lifetime = 1;
					Particle::boom(50, (int)pos_x, (int)pos_y,  0);
				}
				else if (vely + pos_z <= 1)
				{
					this->lifetime = 1;
					Particle::boom(50, (int)pos_x, (int)pos_y, 0);
				}

			}
			if (main_event->map[(int)pos_y][(int)pos_x]->type != EMPTY)
			{
				if (pos_z + vely <= 1)
				{
					vely *= -0.7;
					velx /= 2;
					velz /= 2;
				}
			}
			else if (pos_z + vely <= 0)
			{
					vely *= -0.7;
					velx /= 2;
					vely /= 2;
			}
		}
		pos_y += velz / 10;
		pos_z += vely / 10;
		pos_x += velx / 10;

	}

	void Particle::boom(float n, float x, float y, float z)
	{
		n = n  * (float)rand() / (RAND_MAX);
		n /= 2000;
		n *= N_PARTICLES;
    	for (int i = 0; i < n; i++)
    	{
    		Particle *t = nullptr;

    			t = new Particle(x, y, z , PARTICLE, PARTICLEB);
    			Particle::list->push_back(t);
    			t = new Particle(x, y, z , PARTICLE, PARTICLE);
    			Particle::list->push_back(t);
    			t = new Particle(x, y, z , PARTICLEA, PARTICLEA);
    			Particle::list->push_back(t);
    			t = new Particle(x, y, z , PARTICLEA, PARTICLEA);
    			Particle::list->push_back(t);
    		//if (t != NULL)
        	//Particle::list->push_back(t);
    	}
	}

	void Particle::obstacle(float x, float y, float z, float velx, float vely, float velz, int model)
	{
    		Particle *t = nullptr;

    		t = new Particle(x, y, z , PARTICLE, model);
    		t->velx = velx;
    		t->vely = vely;
    		t->velz = velz;
    		t->lifetime = 100000000;
    		t->model = model;
    		Particle::list->push_back(t);
	}

	void Particle::update_all()
	{
    	std::list<Particle*>::iterator    itP;
    	std::list<Particle*>::iterator    itmp;
    	std::list<Particle*>::iterator    iteP;
		itP = Particle::list->begin();
		iteP = Particle::list->end();

		while (itP != iteP) {
			(*itP)->update();
			if (((*itP)->pos_z * (*itP)->pos_z + (*itP)->pos_y * (*itP)->pos_y + (*itP)->pos_x * (*itP)->pos_x) > 4000 || (*itP)->lifetime <= 0)
			{
				delete (*itP);
				itmp = itP;
				itP++;
				list->erase (itmp);
			}
			else
				itP++;
		}
		// std::cout << list->size() << std::endl;
	}
