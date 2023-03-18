# OpenGL-fundamental
用OpenGL基础知识写了几个类

DirectionLight类
-------------------------------------------------
构造器：
DirectionLight()
DirectionLight(int color)
DirectionLight(int color, glm::vec3(direction))
color: int 默认值0xffffff
direction: glm::vec3 默认值glm::vec3(0.0f, -1.0f, 0.0f)

属性：
color:颜色
direction:方向


PointLight类
-------------------------------------------------
构造器：
PointLight()
PointLight(int color)
PointLight(int color, glm::vec3 position)
PointLight(int color, glm::vec3 position, float constant, float linear, float quadratic)
color: int 默认值0xffffff
position: glm::vec3 默认值glm::vec3(0.0f, 100.0f, 0.0f)
constant: float 默认值1.0
linear: float 默认值0.09
quadratic: float 默认值0.032

属性：
color:颜色
position:位置
constant, linear, quadratic:衰减参数


SpotLight类
-------------------------------------------------
构造器：
SpotLight()
SpotLight(int color)
SpotLight(int color, glm::vec3 direction)
SpotLight(int color, glm::vec3 direction, glm::vec3 position)
SpotLight(int color, glm::vec3 direction, glm::vec3 position, float constant, float linear, float quadratic)
SpotLight(int color, glm::vec3 direction, glm::vec3 position, float constant, float linear, float quadratic, float cutOff, float outerCutOff)
color: int 默认值0xffffff
position: glm::vec3 默认值glm::vec3(0.0f, 100.0f, 0.0f)
direction: glm::vec3 默认值glm::vec3(0.0f, -1.0f, 0.0f)
constant: float 默认值1.0
linear: float 默认值0.09
quadratic: float 默认值0.032
cutOff: float 默认值12.5(角度制)
outerCutOff: float 默认值17.5

属性：
color:颜色
direction:方向
position:位置
constant, linear, quadratic:衰减参数
cutOff, outerCutOff:切光角


Mesh类
-------------------------------------------------
构造器：
Mesh(Object object, Material material)
Mesh(const Mesh& mesh) //拷贝构造
Object:
position: glm::vec3 默认值glm::vec3(0.0f, 0.0f, 0.0f)
size: glm::vec3 默认值glm::vec3(1.0f, 1.0f, 1.0f)
type: string 无默认值 需填写"box"或"sphere"或"cylinder"
Material: //color和path需二选一
color: int 默认值NULL
path: vector<const char*> 默认值{}
type: string 无默认值 需填写"normal"或"light_sensitive"

属性：
color:颜色
type:形状
mType:材质种类
size:大小
model:模型变换矩阵

方法：
setPosition(float x, float y, float z)
setTexture(Material material)
rotateX(float rad)
rotateY(float rad)
rotateZ(float rad)
scale(float x, float y, float z)
getPosition()
getSize()
getTextureID()


Camera类（透视投影相机）
-------------------------------------------------
构造器：
Camera(float fovy, float aspect, float near, float far)

属性：
projection:投影矩阵
view:视角矩阵

方法：
setPosition(glm::vec3 pos)
setTarget(glm::vec3 tar)
getPosition()
getTarget()


init0函数：初始化设置，在构造各种类之前调用
-------------------------------------------------
调用方法：init0()

render函数：对物体进行渲染
-------------------------------------------------
调用方法：render(std::vector<Mesh> meshs, Camera camera, Light light)
Light:
dirLights: vector<DirectionLight>, 默认值{}
pointLights: vector<PointLight>, 默认值{}
spotLights: vector<SpotLight>, 默认值{}
