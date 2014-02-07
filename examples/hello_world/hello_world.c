#include <stdio.h>
#include <stdlib.h>

#if defined __APPLE__
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
    #include <GLUT/glut.h>
#else
    #include <GL/gl.h>
    #include <GL/glu.h>
    #include <GL/glut.h>
#endif

#include <GLFW/glfw3.h>


static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

static void key_callback(
        GLFWwindow* window,
        int key,
        int scancode,
        int action,
        int mods
)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main()
{
    GLFWwindow* window;
    float ratio;
    int width;
    int height;

    /* init glfw */
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        return -1;
    }

    /* create window and its opengl context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    /* loop till user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* frame buffer */
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;

        /* view port */
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);

        /* set matrix mode */
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);

        glLoadIdentity();
        glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);

        /* triangle */
        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    exit(EXIT_SUCCESS);
}
