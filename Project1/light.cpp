#include "light.h"

DirectionLight::DirectionLight() : color(0xFFFFFF), direction(glm::vec3(0.0f, -1.0f, 0.0f)) {}
DirectionLight::DirectionLight(int color) : color(color), direction(glm::vec3(0.0f, -1.0f, 0.0f)) {}
DirectionLight::DirectionLight(int color, glm::vec3(direction)) : color(color), direction(direction) {}

PointLight::PointLight() : color(0xFFFFFF), position(glm::vec3(0.0f, 100.0f, 0.0f)), constant(1.0), linear(0.09), quadratic(0.032) {}
PointLight::PointLight(int color) : color(color), position(glm::vec3(0.0f, 100.0f, 0.0f)), constant(1.0), linear(0.09), quadratic(0.032) {}
PointLight::PointLight(int color, glm::vec3 position) : color(color), position(position), constant(1.0), linear(0.09), quadratic(0.032) {}
PointLight::PointLight(int color, glm::vec3 position, float constant, float linear, float quadratic) : color(color), position(position), constant(constant), linear(linear), quadratic(quadratic) {}

SpotLight::SpotLight() : color(0xFFFFFF), direction(glm::vec3(0.0f, -1.0f, 0.0f)), position(glm::vec3(0.0f, 100.0f, 0.0f)), constant(1.0), linear(0.09), quadratic(0.032), cutOff(cos(12.5 * 3.1415926 / 180)), outerCutOff(cos(17.5 * 3.1415926 / 180)) {}
SpotLight::SpotLight(int color) : color(color), direction(glm::vec3(0.0f, -1.0f, 0.0f)), position(glm::vec3(0.0f, 100.0f, 0.0f)), constant(1.0), linear(0.09), quadratic(0.032), cutOff(cos(12.5 * 3.1415926 / 180)), outerCutOff(cos(17.5 * 3.1415926 / 180)) {}
SpotLight::SpotLight(int color, glm::vec3 direction) : color(0xFFFFFF), direction(direction), position(glm::vec3(0.0f, 100.0f, 0.0f)), constant(1.0), linear(0.09), quadratic(0.032), cutOff(cos(12.5 * 3.1415926 / 180)), outerCutOff(cos(17.5 * 3.1415926 / 180)) {}
SpotLight::SpotLight(int color, glm::vec3 direction, glm::vec3 position) : color(0xFFFFFF), direction(direction), position(position), constant(1.0), linear(0.09), quadratic(0.032), cutOff(cos(12.5 * 3.1415926 / 180)), outerCutOff(cos(17.5 * 3.1415926 / 180)) {}
SpotLight::SpotLight(int color, glm::vec3 direction, glm::vec3 position, float constant, float linear, float quadratic) : color(0xFFFFFF), direction(direction), position(position), constant(constant), linear(linear), quadratic(quadratic), cutOff(cos(12.5 * 3.1415926 / 180)), outerCutOff(cos(17.5 * 3.1415926 / 180)) {}
SpotLight::SpotLight(int color, glm::vec3 direction, glm::vec3 position, float constant, float linear, float quadratic, float cutOff, float outerCutOff) : color(0xFFFFFF), direction(direction), position(position), constant(constant), linear(linear), quadratic(quadratic), cutOff(cos(cutOff * 3.1415926 / 180)), outerCutOff(cos(outerCutOff * 3.1415926 / 180)) {}