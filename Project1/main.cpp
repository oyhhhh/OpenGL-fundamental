#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include "render.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    init0();
    Object object1;
    object1.type = "cylinder";
    object1.size = glm::vec3(5.0f, 5.0f, 5.0f);

    Material material1;
    material1.type = "light_sensitive";
    material1.color = 0xCCBBFF;

    Mesh mesh(object1, material1);
    mesh.rotateX(90);
    mesh.rotateY(90);
    mesh.rotateZ(90);
    

    std::vector<Mesh> meshs;
    meshs.push_back(mesh);

    DirectionLight light(0xffffff);

    Light lights;
    lights.dirLights.push_back(light);

    Camera camera0(45, (float)800 / (float)600, 0.1f, 100.0f);
    camera0.setPosition(glm::vec3(0.0f, 20.0f, 30.0f));
    camera0.setTarget(glm::vec3(0.0f, 0.0f, 0.0f));


    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();

        render(meshs, camera0, lights);
    }

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}