#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>

//相机类 存储相机的位置和视角
class Camera 
{
public:
	glm::mat4 projection;
	glm::mat4 view;

	Camera(float fovy, float aspect, float near, float far);
	void setPosition(glm::vec3 pos);
	void setTarget(glm::vec3 tar);
	glm::vec3 getPosition();
	glm::vec3 getTarget();

protected:
	void setView();
	glm::vec3 position;
	glm::vec3 target;
	

};





#endif // !CAMERA_H

