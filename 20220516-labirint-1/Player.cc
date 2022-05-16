/*
 * Player.cc
 *
 *  Created on: 17 мая 2022 г.
 *      Author: serge
 */

#include <cmath>
#include "Player.h"
static constexpr double Pi = acos(-1.0);

void Player::spawn(std::shared_ptr<Map> & m){
	_map = m;
	_x = m->getStartX();
	_y = m->getStartY();
	_dir = m->getStartDir();
}

void Player::walk_fwd(double dist) {
	double nx = _x + dist * cos(_dir);
	double ny = _y + dist * sin(_dir);
	if (not _map->is_wall(nx, ny)) {
		_x = nx;
		_y = ny;
	}
}

void Player::walk_back(double dist) {
	walk_fwd(-dist);
}

void Player::shift_left(double dist) {
	shift_right(-dist);
}

void Player::shift_right(double dist) {
	double nx = _x + dist * cos(_dir + Pi/2.0);
	double ny = _y + dist * sin(_dir + Pi/2.0);
		if (not _map->is_wall(nx, ny)) {
			_x = nx;
			_y = ny;
		}
}

void Player::turn_left(double angle) {
	_dir -= angle;
	if (_dir < 0.0)
		_dir += 2.0 * Pi;
}

void Player::turn_right(double angle) {
	_dir += angle;
	if (_dir >= 2.0 * Pi)
		_dir -= 2.0 * Pi;
}
