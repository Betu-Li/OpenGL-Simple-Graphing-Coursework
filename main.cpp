//********将头文件嵌入源文件中（2-6行）********
#include<GL/glut.h>      
#include<GL/freeglut.h>
#include<GL/gl.h>
#include<iostream>
#include <math.h>
using std::cout;
#define _USE_MATH_DEFINES //使用数学定义
//********定义窗口大小********
GLfloat w = 700;
GLfloat h = 700;
//********图形沿x和y轴旋转********
double rotate_x = 0.0;
double rotate_y = 0.0;
//****************对颜色的宏定义****************
# define  white  1.0 ,  1.0  ,  1.0
# define  green  0.0 ,  0.502,  0.0
# define  red    1.0 ,  0.0  ,  0.0
# define  gray   0.502, 0.502,0.502
# define  hgray  0.117, 0.180,0.227
# define  blue   0.0  , 0.0  ,  1.0
# define  gold   1.0,215.0/255.0,0.0
# define  hgreen 0.0,100.0/255.0,0.0
# define  brown  210.0/255.0, 105.0/255.0,  30.0/255.0
# define  men   244.0/255.0 ,164.0/255.0 , 96.0/255.0
# define  menba   139.0/255.0 ,69.0/255.0,19.0/255.0
# define  pi  3.14159265

double RectangularV[8][3];// 定义长方体的8个顶点，定义constract函数，当给定长方体的最里面的点时，计算其余的7个顶点 并赋值
//*************************利用长方体的8个顶点绘制长方体*************************
void constract(double x, double y, double z, double x1, double y1, double z1) {
    RectangularV[0][0] = x;
    RectangularV[0][1] = y;
    RectangularV[0][2] = z;        //  第0个点

    RectangularV[1][0] = x;
    RectangularV[1][1] = y;
    RectangularV[1][2] = z + z1;     //  第一个点

    RectangularV[2][0] = x + x1;
    RectangularV[2][1] = y;
    RectangularV[2][2] = z + z1;     //  第二个点

    RectangularV[3][0] = x + x1;
    RectangularV[3][1] = y;
    RectangularV[3][2] = z;        //  第三个点
    for (int i = 0; i < 4; i++) {  // for()循环来完成其余的四个点
        for (int j = 0; j < 3; j++) {
            if (j == 1)
                RectangularV[i + 4][j] = RectangularV[i][j] + y1;
            else
                RectangularV[i + 4][j] = RectangularV[i][j];
        }
    }
}
void build() {
    glBegin(GL_POLYGON);
    glNormal3f(0.0, -1.0, 0.0);
    glVertex3f(RectangularV[0][0], RectangularV[0][1], RectangularV[0][2]);
    glVertex3f(RectangularV[1][0], RectangularV[1][1], RectangularV[1][2]);
    glVertex3f(RectangularV[2][0], RectangularV[2][1], RectangularV[2][2]);
    glVertex3f(RectangularV[3][0], RectangularV[3][1], RectangularV[3][2]);
    glEnd();   //     下底

    glBegin(GL_POLYGON);
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3f(RectangularV[1][0], RectangularV[1][1], RectangularV[1][2]);
    glVertex3f(RectangularV[0][0], RectangularV[0][1], RectangularV[0][2]);
    glVertex3f(RectangularV[4][0], RectangularV[4][1], RectangularV[4][2]);
    glVertex3f(RectangularV[5][0], RectangularV[5][1], RectangularV[5][2]);
    glEnd();   //     左面

    glBegin(GL_POLYGON);
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3f(RectangularV[7][0], RectangularV[7][1], RectangularV[7][2]);
    glVertex3f(RectangularV[6][0], RectangularV[6][1], RectangularV[6][2]);
    glVertex3f(RectangularV[2][0], RectangularV[2][1], RectangularV[2][2]);
    glVertex3f(RectangularV[3][0], RectangularV[3][1], RectangularV[3][2]);
    glEnd();   //     右面

    glBegin(GL_POLYGON);
    glNormal3f(0.0, 0.0, 1.0);
    glVertex3f(RectangularV[5][0], RectangularV[5][1], RectangularV[5][2]);
    glVertex3f(RectangularV[6][0], RectangularV[6][1], RectangularV[6][2]);
    glVertex3f(RectangularV[2][0], RectangularV[2][1], RectangularV[2][2]);
    glVertex3f(RectangularV[1][0], RectangularV[1][1], RectangularV[1][2]);
    glEnd();   //     前面

    glBegin(GL_POLYGON);
    glNormal3f(0.0, 0.0, -1.0);
    glVertex3f(RectangularV[0][0], RectangularV[0][1], RectangularV[0][2]);
    glVertex3f(RectangularV[3][0], RectangularV[3][1], RectangularV[3][2]);
    glVertex3f(RectangularV[7][0], RectangularV[7][1], RectangularV[7][2]);
    glVertex3f(RectangularV[4][0], RectangularV[4][1], RectangularV[4][2]);
    glEnd();   //     后面

    glBegin(GL_POLYGON);
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(RectangularV[4][0], RectangularV[4][1], RectangularV[4][2]);
    glVertex3f(RectangularV[7][0], RectangularV[7][1], RectangularV[7][2]);
    glVertex3f(RectangularV[6][0], RectangularV[6][1], RectangularV[6][2]);
    glVertex3f(RectangularV[5][0], RectangularV[5][1], RectangularV[5][2]);
    glEnd();   //     上面
}

//*****************绘制场景内各种组件*******************
void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //加载场景，如果将这行代码注释掉，将什么都看不到
    glMatrixMode(GL_MODELVIEW); //控制输出图形
    glLoadIdentity();          //增加M矩阵
    //*************控制x，y轴方向转动（222-223行）********************
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    glTranslatef(-270, 0, -270); //平移变换
    glScalef(1.5, 1.5, 1.5);     //图像缩放

    //****************************增加地面底板（颜色绿色228-231行）********
    glBegin(GL_POLYGON);
    constract(0, 0, 0, 500, 10, 500);//地板
    glColor3f(1.0, 1.0, 1.0);
    build();
    constract(0, 0, 0, 10, 500, 500);//左墙
    glColor3f(1.0, 1.0, 1.0);
    build();
    constract(0, 0, 0, 500, 500, 10);//后墙
    glColor3f(1.0, 1.0, 1.0);
    build();

    constract(10, 10, 10, 200, 50, 300);//床体
    glColor3f(0.5, 0.5, 0);
    build();
    constract(10, 60, 10, 200, 10, 300);//床垫
    glColor3f(1.0, 0.75, 0.44);
    build();
    constract(80, 63, 10, 70, 13, 50);//枕头
    glColor3f(white);
    build();
    constract(10, 63, 80, 200, 14, 220);//被子
    glColor3f(gray);
    build();

    constract(20, 10, 490, 180, 270, 10);//镜子
    glColor4f(white, 0.75);
    build();
    constract(210, 10, 400, 250, 260, 100);//衣柜
    glColor3f(brown);
    build();
    constract(240, 100, 10, 130, 10, 80);//桌面
    glColor3f(0.8, 0.34, 0.34);
    build();
    constract(270, 10, 110, 50, 60, 40);//椅子
    glColor3f(1.0, 0.76, 0.06);
    build();
    constract(250, 110, 40, 50, 3, 40);//电脑
    glColor3f(0.0, 0.0, 0.0);
    build();
    constract(250, 110, 40, 50, 40, 3);//电脑屏幕
    glColor3f(0.0, 0.0, 0.0);
    build();

    glColor3f(hgreen);
    glTranslatef(325, 138, 65);
    glutSolidSphere(16.0, 10, 10);  //盆栽球
    glTranslatef(-325, -140, -65);

    glTranslatef(330, 138, 130);
    constract(-5, 0, -65, 5, -30, 5);//树干
    glColor3f(brown);
    build();
    
    constract(169, -130, 200, 12, 250, 130);//门
    glColor3f(red);
    build();
    constract(159, 0, 200, 10, 10, 10);//门把手
    glColor3f(0.0, 0.0, 0.0);
    build();
    constract(179, 0, 200, 10, 10, 10);//门把手
    glColor3f(0.0, 0.0, 0.0);
    build();
    glTranslatef(-330, -140, -130);

    glColor3f(red);
    glTranslatef(30, 25, 420);
    glutSolidSphere(16.0, 10, 10);//哑铃球
    glTranslatef(-30, -25, -420);

    glColor3f(red);
    glTranslatef(30, 25, 380);
    glutSolidSphere(16.0, 10, 10);//哑铃球
    glTranslatef(-30, -25, -380);

    constract(30, 25, 380, 5, 5, 40);//哑铃棍
    glColor3f(0.0, 0.0, 0.0);
    build();

    glTranslatef(330, 140, 140);
    glutSolidTeapot(1);
    glFlush();
    glTranslatef(-330, -140, -140);

    constract(350, 300, 10, 10, 10, 5);//墙画1
    glColor3f(red);
    build();
    constract(330, 315, 10, 10, 10, 5);//墙画2
    glColor3f(red);
    build();
    constract(310, 300, 10, 10, 10, 5);//墙画3
    glColor3f(red);
    build();
    constract(315, 280, 10, 10, 10, 5);//墙画4
    glColor3f(red);
    build();
    constract(330, 260, 10, 10, 10, 5);//墙画5
    glColor3f(red);
    build();
    constract(350, 250, 10, 10, 10, 5);//墙画6
    glColor3f(red);
    build();
    constract(370, 315, 10, 10, 10, 5);//墙画8
    glColor3f(red);
    build();
    constract(390, 300, 10, 10, 10, 5);//墙画9
    glColor3f(red);
    build();
    constract(385, 280, 10, 10, 10, 5);//墙画10
    glColor3f(red);
    build();
    constract(370, 260, 10, 10, 10, 5);//墙画11
    glColor3f(red);
    build();


    constract(10, 300, 350, 2, 60, 80);//表
    glColor3f(1.0, 0.65, 0);
    build();
    constract(12, 330, 390, 1, 2, 20);//时针
    glColor3f(0, 0, 0);
    build();
    constract(12, 330, 390, 1, 26, 1);//分针
    glColor3f(0, 0, 0);
    build();

    constract(0, 500, 0, 500, 10, 500);//棚顶
    glColor4f(blue, 0.25);
    build();
    constract(500, 0, 0, 10, 500, 500);//右墙
    glColor4f(1.0, 1.0, 1.0, 0.3);
    build();
    constract(0, 0, 500, 500, 500, 10);//后墙
    glColor4f(blue, 0.25);
    build();



    glFlush();  // 刷新
    glutSwapBuffers();//双缓冲
}
//******************设置光照******************
void init(void)
{
    
    GLfloat sun_direction[] = { 250.0, 500.0, 250.0, 0.0 };//发光位置
    GLfloat sun_intensity[] = { 1.0, 1.0, 1.0, 1.0 };//强度
    GLfloat ambient_intensity[] = { 0.8, 0.5, 0.5, 1.0 };//颜色比例偏红

    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_intensity);

    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, sun_direction);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, sun_intensity);//漫射光
    glLightfv(GL_LIGHT0, GL_SPECULAR, sun_intensity);//镜面反光

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);//材质
    cout << "The OpenGL version is: " << glGetString(GL_VERSION) << "\n";
    cout << glGetString(GL_VENDOR) << "\n";
    glLineWidth(5);
    glClearColor(0.0, 0.0, 0.0, 0.0);      //定义背景颜色为黑色

    glEnable(GL_BLEND); // 打开混合
    glDisable(GL_DEPTH_TEST); // 关闭深度测试
    glBlendFunc(GL_SRC_ALPHA, GL_ONE); // 基于源象素alpha通道值的半透明混合函数

    glMatrixMode(GL_PROJECTION);
    glOrtho(-w, w, -h, h, -w, w);
}
//**********定义键盘上下左右控制**********
void specialkeys(int key, int x, int y) {
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 5;
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 5;
    else if (key == GLUT_KEY_UP)
        rotate_x += 5;
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 5;
    glutPostRedisplay();
}
void myKeyboard(unsigned char key, int x, int y)
{
    glMatrixMode(GL_MODELVIEW);
    glMatrixMode(GL_PROJECTION);
    switch (key)
    {
    case 'a': case 'A': glTranslated(-10, 0, 0); break;     //向左平移
    case 'd': case 'D': glTranslated(10, 0, 0); break;     //向右平移
    case 'w': case 'W': glTranslated(0, 10, 0); break;     //向上平移
    case 's': case 'S': glTranslated(0, -10, 0); break;     //向下平移
    case 'q': case 'Q': glTranslated(0, 0, 100); break;     //向外平移
    case 'e': case 'E': glTranslated(0, 0, -100); break;     //向里平移
    case 'j': case 'J': glRotated(10, 0, 1, 0); break;      //绕y轴旋转10度
    case 'l': case 'L': glRotated(10, 0, -1, 0); break;
    case 'i': case 'I': glRotated(10, 1, 0, 0); break;      //绕x轴旋转10度
    case 'k': case 'K': glRotated(10, -1, 0, 0); break;
    case 'u': case 'U': glRotated(10, 0, 0, 1); break;      //绕z轴旋转10度
    case 'o': case 'O': glRotated(10, 0, 0, -1); break;


    case 'z': case 'Z': glScalef(1.5, 1.5, 1.5); break;         //放大
    case 'x': case 'X': glScalef(0.5, 0.5, 0.5); break;         //缩小

    default: break;
    }

    glutPostRedisplay();      //重新绘制
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(w, h);  //定义窗口大小
    glutInitWindowPosition(100, 100); //窗口打开位置
    glutCreateWindow("微缩房间");
    
    init();

    glutKeyboardFunc(myKeyboard);
    glutSpecialFunc(specialkeys);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    
    glutMainLoop();
    return 0;
}