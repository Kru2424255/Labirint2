/*
 * Map.h
 *
 *  Created on: 16 may 2022 �.
 *      Author: serge
 */

#ifndef MAP_H_
#define MAP_H_

#include <vector>
#include <string>

class Map final
{
private:
	int _width {}, _height {};
	double _start_x {}, _start_y {}, _start_dir {};
	std::vector<std::string> _data;

	void next_line(std::ifstream& file, std::string& line);

public:
	Map(const char * filename);

	int getWidth() const 		{return _width;}
	int getHeight() const 	 	{return _height;}
	double getStartX() const 	{return _start_x;}
	double getStartY() const	{return _start_y;}
	double getStartDir() const 	{return _start_dir;}

	bool is_wall (int x, int y) const;
	bool is_wall (double x, double y) const;
};

#endif /* MAP_H_ */
