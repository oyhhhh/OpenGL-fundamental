#ifndef TEXTURE_H
#define TEXTURE_H


#include <glad/glad.h>
#include <string>
#include <vector>
#include <iostream>


class Texture
{
public:
	unsigned int id;
	Texture(const char* path);

private:
	int width, height, nrChannels;
};



#endif //

