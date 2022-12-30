#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

int main(){
    // start GL context and O/S window using the GLFW helper library
    if (!glfwInit()) // check GLFW_TRUE or GLFW_FALSE
    {
        fprintf(stderr, "ERROR: could not start GLFW3\n");
        return 1; 
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "Hello Triangle", NULL, NULL);
    if(!window)
    {
        fprintf(stderr, "ERROR: could not open window with GLFW3\n");
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(window);

    // start GLEW extension handler
    glewExperimental = GL_TRUE;
    glewInit();

    // get verison info
    const GLubyte* renderer = glGetString(GL_RENDERER);
    const GLubyte* version  = glGetString(GL_VERSION);
    printf("Renderer: %s\n", renderer);
    printf("OpenGL version supported %s\n", version);


    // tell GL to only draw onto a pixel if the shape is closer to the viewer
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    // close GL context and any other GLFW resources
    glfwTerminate();
    return 0;
}