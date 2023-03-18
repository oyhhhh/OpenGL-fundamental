#include "camera.h"

Camera::Camera(float fovy, float aspect, float near, float far)
{
	projection = glm::perspective(glm::radians(fovy), aspect, near, far);
}

void Camera::setPosition(glm::vec3 pos)
{
	position = pos;
	setView();
}

void Camera::setTarget(glm::vec3 tar)
{
	target = tar;
	setView();
}

void Camera::setView()
{
	if(!(position.x == 0 && position.z == 0))
	view = glm::lookAt(position, target, glm::vec3(0.0f, 1.0f, 0.0f));
	else
	{
		if(position.y > 0)
		view = glm::lookAt(position, target, glm::vec3(0.0f, 0.0f, -1.0f));
		else
		view = glm::lookAt(position, target, glm::vec3(0.0f, 0.0f, 1.0f));
	}
}

glm::vec3 Camera::getPosition()
{
	return position;
}

glm::vec3 Camera::getTarget()
{
	return target;
}