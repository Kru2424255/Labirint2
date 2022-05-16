/*
 * texture.h
 *
 *  Created on: 17 мая 2022 г.
 *      Author: serge
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <GL/gl.h>
#include <GL/glu.h>

class texture final{
private:
	GLuint _tex {};
public:
	texture(const char * filename);
	~texture();

	void bind() {glBindTexture(GL_TEXTURE_2D, _tex);}

};

#endif /* TEXTURE_H_ */
