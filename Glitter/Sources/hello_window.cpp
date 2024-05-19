// Local Headers
#include "glitter.hpp"

// System Headers
#include <GLFW/glfw3.h>
#include <glad/glad.h>

// Standard Headers

#include <cstdlib>
#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {

  // Load GLFW and Create a Window
  glfwInit();
  // 指定创建的上下文必须与之兼容的客户端API版本。这些提示的确切行为取决于请求的客户端API。
  // 主版本号
  // 次版本号  3.3
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
  //   glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  auto mWindow =
      // 宽高，窗口名称
      glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", nullptr, nullptr);

  // Check for Valid Context
  if (mWindow == nullptr) {
    std::cout << "Failed to Create OpenGL Context" << std::endl;
    // fprintf(stderr, "Failed to Create OpenGL Context");
    return EXIT_FAILURE;
  }

  // Create Context and Load OpenGL Functions
  glfwMakeContextCurrent(mWindow);
  // 告诉GLFW我们希望每当窗口调整大小的时候调用这个函数：
  glfwSetFramebufferSizeCallback(mWindow, framebuffer_size_callback);

  // glad: load all OpenGL function pointers
  // ---------------------------------------
  // 加载系统相关的OpenGL函数指针地址的函数
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  // render loop
  // -----------
  // 渲染循环
  while (!glfwWindowShouldClose(mWindow)) {
    // input
    // -----
    processInput(mWindow);

    // render
    // ------
    // 清除颜色缓冲之后，整个颜色缓冲都会被填充为glClearColor里所设置的颜色
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved
    // etc.)
    // -------------------------------------------------------------------------------
    // 交换颜色缓冲（它是一个储存着GLFW窗口每一个像素颜色值的大缓冲），它在这一迭代中
    // 被用来绘制，并且将会作为输出显示在屏幕上。
    glfwSwapBuffers(mWindow);
    // 检查有没有触发什么事件（比如键盘输入、鼠标移动等）、更新窗口状态，并调用对应的
    // 回调函数（可以通过回调方法手动设置）。
    glfwPollEvents();
  }

  // glfw: terminate, clearing all previously allocated GLFW resources.
  // ------------------------------------------------------------------
  // 渲染循环结束后我们需要正确释放/删除之前的分配的所有资源
  glfwTerminate();
  return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this
// frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window) {
  // 是否按下了返回键(Esc)
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback
// function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  // make sure the viewport matches the new window dimensions; note that width
  // and height will be significantly larger than specified on retina displays.
  // 告诉OpenGL渲染窗口的尺寸大小，即视口(Viewport)，这样OpenGL才只能知道怎样根据窗口大小显示数据和坐标。
  // 前两个参数控制窗口左下角的位置。第三个和第四个参数控制渲染窗口的宽度和高度（像素）。
  glViewport(0, 0, width, height);
}