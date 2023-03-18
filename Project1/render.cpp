#include "render.h"

std::vector<ShaderProgram> shaders;
std::vector<unsigned int> buffers;

//��ʼ��ʱ������ͬ����ɫ����
void createShaderArr() {
    const char* vShader1 = "./shaderv1.vs";
    const char* fShader1 = "./shaderf1.vs";
    const char* vShader2 = "./shaderv2.vs";
    const char* fShader2 = "./shaderf2.vs";
    shaders.push_back(ShaderProgram(vShader1, fShader1));
    shaders.push_back(ShaderProgram(vShader2, fShader2));
}

//��ʼ��ʱ������ͬ��VAO
void createVaoArr() {

    buffers.push_back(getBox());
    buffers.push_back(getSphere(30, 50));
    buffers.push_back(getCylinder(30));

}


void init0() //��ʼ��
{
    createShaderArr();
    createVaoArr();
}

//��ȡ����Ķ�������
unsigned int getSphere(int ySegments, int xSegments) {
    std::vector<Vertex> vertices;
    for (int y = 0; y <= ySegments; y++) {
        for (int x = 0; x <= xSegments; x++) {
            float radA = (float)y / (float)ySegments * PI;
            float radB = (float)x / (float)xSegments * 2.0f * PI;

            float xPos = 0.5 * sin(radA) * cos(radB);
            float yPos = 0.5 * cos(radA);
            float zPos = 0.5 * sin(radA) * sin(radB);

            glm::vec3 position = glm::vec3(xPos, yPos, zPos);
            glm::vec3 normal = glm::vec3(2 * xPos, 2 * yPos, 2 * zPos);
            glm::vec2 texCoord = glm::vec2((float)x / (float)xSegments, (float)y / (float)ySegments);

            Vertex vertex(position, normal, texCoord);

            vertices.push_back(vertex);

        }
    }

    std::vector<unsigned int> indices;
    for (int i = 0; i < ySegments; i++) {
        for (int j = 0; j < xSegments; j++) {
            indices.push_back(i * (xSegments + 1) + j);
            indices.push_back((i + 1) * (xSegments + 1) + j);
            indices.push_back((i + 1) * (xSegments + 1) + j + 1);

            indices.push_back(i * (xSegments + 1) + j);
            indices.push_back((i + 1) * (xSegments + 1) + j + 1);
            indices.push_back(i * (xSegments + 1) + j + 1);
        }
    }

    GeometryBuffer buffer(vertices, indices);
    return buffer.VAO;
}

//��ȡԲ����Ķ�������
unsigned int getCylinder(int segments) {
    std::vector<glm::vec3> verticesT;
    std::vector<glm::vec3> verticesB;
    std::vector<Vertex> vertices;
    for (int x = 0; x <= segments; x++) {
        float rad = (float)x / (float)segments * 2.0f * PI;
        float xPos = 0.5 * cos(rad);
        float yPos = 0.5;
        float zPos = 0.5 * sin(rad);

        glm::vec3 vertice = glm::vec3(xPos, yPos, zPos);

        verticesT.push_back(vertice);

    }

    for (int x = 0; x <= segments; x++) {
        float rad = (float)x / (float)segments * 2.0f * PI;
        float xPos = 0.5 * cos(rad);
        float yPos = -0.5;
        float zPos = 0.5 * sin(rad);

        glm::vec3 vertice = glm::vec3(xPos, yPos, zPos);

        verticesB.push_back(vertice);

    }

    for (int i = 0; i < segments; i++) {

        glm::vec3 position0 = glm::vec3(0.0f, 0.5f, 0.0f);
        glm::vec3 normal0 = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::vec2 texCoord0 = glm::vec2((float)i / (float)segments, 1);

        glm::vec3 position1 = verticesT[i];
        glm::vec3 normal1 = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::vec2 texCoord1 = glm::vec2((float)i / (float)segments, 1);

        glm::vec3 position2 = verticesT[i + 1];
        glm::vec3 normal2 = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::vec2 texCoord2 = glm::vec2((float)(i + 1) / (float)segments, 1);

        Vertex vertex0(position0, normal0, texCoord0);
        Vertex vertex1(position1, normal1, texCoord1);
        Vertex vertex2(position2, normal2, texCoord2);

        vertices.push_back(vertex0);
        vertices.push_back(vertex1);
        vertices.push_back(vertex2);

    }

    for (int i = 0; i < segments; i++) {

        glm::vec3 position0 = glm::vec3(0.0f, -0.5f, 0.0f);
        glm::vec3 normal0 = glm::vec3(0.0f, -1.0f, 0.0f);
        glm::vec2 texCoord0 = glm::vec2((float)i / (float)segments, 0);

        glm::vec3 position1 = verticesB[i];
        glm::vec3 normal1 = glm::vec3(0.0f, -1.0f, 0.0f);
        glm::vec2 texCoord1 = glm::vec2((float)i / (float)segments, 0);

        glm::vec3 position2 = verticesB[i + 1];
        glm::vec3 normal2 = glm::vec3(0.0f, -1.0f, 0.0f);
        glm::vec2 texCoord2 = glm::vec2((float)(i + 1) / (float)segments, 0);

        Vertex vertex0(position0, normal0, texCoord0);
        Vertex vertex1(position1, normal1, texCoord1);
        Vertex vertex2(position2, normal2, texCoord2);

        vertices.push_back(vertex0);
        vertices.push_back(vertex1);
        vertices.push_back(vertex2);
    }

    for (int i = 0; i < segments; i++) {

        glm::vec3 position0 = verticesT[i];
        glm::vec3 normal0 = glm::vec3(verticesT[i].x, 0, verticesT[i].z);
        glm::vec2 texCoord0 = glm::vec2((float)i / (float)segments, 1);

        glm::vec3 position1 = verticesB[i];
        glm::vec3 normal1 = glm::vec3(verticesB[i].x, 0, verticesB[i].z);
        glm::vec2 texCoord1 = glm::vec2((float)i / (float)segments, 0);

        glm::vec3 position2 = verticesB[i + 1];
        glm::vec3 normal2 = glm::vec3(verticesB[i + 1].x, 0, verticesB[i + 1].z);
        glm::vec2 texCoord2 = glm::vec2((float)(i + 1) / (float)segments, 0);

        glm::vec3 position3 = verticesT[i];
        glm::vec3 normal3 = glm::vec3(verticesT[i].x, 0, verticesT[i].z);
        glm::vec2 texCoord3 = glm::vec2((float)i / (float)segments, 1);

        glm::vec3 position4 = verticesT[i + 1];
        glm::vec3 normal4 = glm::vec3(verticesT[i + 1].x, 0, verticesT[i + 1].z);
        glm::vec2 texCoord4 = glm::vec2((float)i / (float)segments, 1);

        glm::vec3 position5 = verticesB[i + 1];
        glm::vec3 normal5 = glm::vec3(verticesB[i + 1].x, 0, verticesB[i + 1].z);
        glm::vec2 texCoord5 = glm::vec2((float)(i + 1) / (float)segments, 0);

        Vertex vertex0(position0, normal0, texCoord0);
        Vertex vertex1(position1, normal1, texCoord1);
        Vertex vertex2(position2, normal2, texCoord2);
        Vertex vertex3(position3, normal3, texCoord3);
        Vertex vertex4(position4, normal4, texCoord4);
        Vertex vertex5(position5, normal5, texCoord5);

        vertices.push_back(vertex0);
        vertices.push_back(vertex1);
        vertices.push_back(vertex2);
        vertices.push_back(vertex3);
        vertices.push_back(vertex4);
        vertices.push_back(vertex5);

    }

    std::vector<unsigned int> indices;
    indices.push_back(0);

    GeometryBuffer buffer(vertices, indices);
    return buffer.VAO;

}

//��ȡ������Ķ�������
unsigned int getBox() {
    float vertice[] = {
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
    };

    std::vector<Vertex> vertices;
    for (int i = 0; i < 36; i++)
    {
        glm::vec3 position = glm::vec3(vertice[i * 8], vertice[i * 8 + 1], vertice[i * 8 + 2]);
        glm::vec3 normal = glm::vec3(vertice[i * 8 + 3], vertice[i * 8 + 4], vertice[i * 8 + 5]);
        glm::vec2 texCoord = glm::vec2(vertice[i * 8 + 6], vertice[i * 8 + 7]);

        Vertex vertex(position, normal, texCoord);

        vertices.push_back(vertex);
    }

    std::vector<unsigned int> indices;
    indices.push_back(0);

    GeometryBuffer buffer(vertices, indices);
    return buffer.VAO;

}

//��intת��Ϊrgb
glm::vec3 colorRgb(int color)
{
    float blue = (float)(color % (16 * 16)) / 255.0f;
    float green = (float)((color >> 8) % (16 * 16)) / 255.0f;
    float red = (float)((color >> 16) % (16 * 16)) / 255.0f;
    glm::vec3 rgb = glm::vec3(red, green, blue);
    return rgb;
}

//�ƹ�һϵ�еĲ���������ɫ����
void setLightColor(ShaderProgram shader, int color, std::string lightname) {

    glm::vec3 colorf = colorRgb(color);
    shader.setValue3(lightname + ".ambient", 0.4f * colorf);
    shader.setValue3(lightname + ".diffuse", colorf);
    shader.setValue3(lightname + ".specular", glm::vec3(1.0f, 1.0f, 1.0f));

}

void setLightPosition(ShaderProgram shader, glm::vec3 position, std::string lightname) {
    shader.setValue3(lightname + ".position", position);
}

void setLightDirection(ShaderProgram shader, glm::vec3 direction, std::string lightname) {
    shader.setValue3(lightname + ".direction", direction);
}

void setLightParameter(ShaderProgram shader, float constant, float linear, float quadratic, std::string lightname) {
    shader.setValue(lightname + ".constant", constant);
    shader.setValue(lightname + ".linear", linear);
    shader.setValue(lightname + ".quadratic", quadratic);
}

void setLightRad(ShaderProgram shader, float cutOff, float outerCutOff) {
    shader.setValue("spotlight.cutOff", cutOff);
    shader.setValue("spotlight.outerCutOff", outerCutOff);
}


void render(std::vector<Mesh> meshs, Camera camera, Light light)  //��Ⱦ���� //��Ⱦ��ͨ��shader��������л�����ɫ�����ÿ�������һ����ɫ����camera/lights�����ṩ��ɫ������
{
    glClearColor(colorRgb(0xFFFFCC)[0], colorRgb(0xFFFFCC)[1], colorRgb(0xFFFFCC)[2], 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);

    for (auto mesh : meshs)
    {
        //������ɫ��������Ⱦ��ͬ���ʵ�������ò�ͬ����ɫ������
        int index = 0;

        if (mesh.mType == "light_sensitive") {
            index = 1;
        }
        ShaderProgram shader(shaders[index]);

        shader.useProgram();

        //��������任
        shader.setMatrix4("projection", camera.projection);
        shader.setMatrix4("view", camera.view);
        shader.setMatrix4("model", mesh.model);

        if (mesh.mType == "normal") {
            if (mesh.color != NULL) {   //�ǹ��ղ���������ɫ���
                glm::vec3 color = colorRgb(mesh.color);
                shader.setValue("chooseColor", true);
                shader.setValue3("color", color);
            }
            else {   //�ǹ��ղ��������������
                shader.setValue("chooseColor", false);
                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D, mesh.getTextureID()[0]);
                shader.setValue("texture_normal", 0);
            }
        }
        else if (mesh.mType == "light_sensitive") {
            glm::mat4 normalMatrix = glm::transpose(glm::inverse(mesh.model));
            shader.setMatrix4("normalTransform", normalMatrix);

            if (mesh.color != NULL) {   //���ղ���������ɫ���
                glm::vec3 color = colorRgb(mesh.color);
                shader.setValue("choosematerial", true);
                shader.setValue3("material1.ambient", color);
                shader.setValue3("material1.diffuse", color);
                shader.setValue3("material1.specular", glm::vec3(0.5f, 0.5f, 0.5f));
                shader.setValue("material1.shininess", 32.0f);
            }
            else {    //���ղ��������������
                shader.setValue("choosematerial", false);
                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D, mesh.getTextureID()[0]);
                shader.setValue("material2.texture_diffuse", 0);

                glActiveTexture(GL_TEXTURE1);
                glBindTexture(GL_TEXTURE_2D, mesh.getTextureID()[1]);
                shader.setValue("material2.texture_specular", 1);

                shader.setValue("material2.shininess", 32.0f);

            }

            //���ù��ղ���
            shader.setValue("num1", false);
            shader.setValue("num2", false);
            shader.setValue("num3", false);



            for (auto dirLight : light.dirLights)
            {
                shader.setValue("num1", true);
                shader.setValue3("viewPos", camera.getPosition());
                setLightColor(shader, dirLight.color, "dirlight");
                setLightDirection(shader, dirLight.direction, "dirlight");


            }
            for (auto pointLight : light.pointLights)
            {
                shader.setValue("num2", true);
                shader.setValue3("viewPos", camera.getPosition());
                setLightColor(shader, pointLight.color, "pointlight");
                setLightPosition(shader, pointLight.position, "pointlight");
                setLightParameter(shader, pointLight.constant, pointLight.linear, pointLight.quadratic, "pointlight");

            }
            for (auto spotLight : light.spotLights)
            {
                shader.setValue("num3", true);
                shader.setValue3("viewPos", camera.getPosition());
                setLightColor(shader, spotLight.color, "spotlight");
                setLightDirection(shader, spotLight.direction, "spotlight");
                setLightPosition(shader, spotLight.position, "spotlight");
                setLightRad(shader, spotLight.cutOff, spotLight.outerCutOff);
                setLightParameter(shader, spotLight.constant, spotLight.linear, spotLight.quadratic, "spotlight");

            }
        }

        //���ݲ�ͬ��������״�󶨲�ͬ��VAO
        if (mesh.type == "box") {
            glBindVertexArray(buffers[0]);
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
        else if (mesh.type == "sphere") {
            glBindVertexArray(buffers[1]);
            glDrawElements(GL_TRIANGLES, 9000, GL_UNSIGNED_INT, 0);
        }
        else if (mesh.type == "cylinder") {
            glBindVertexArray(buffers[2]);
            glDrawArrays(GL_TRIANGLES, 0, 360);
        }
    }



}