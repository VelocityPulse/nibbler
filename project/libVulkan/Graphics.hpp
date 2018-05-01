#ifndef NIBBLER_GRAPHICS_HPP
#define NIBBLER_GRAPHICS_HPP

#define GLFW_INCLUDE_VULKAN

#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <vulkan/vulkan.h>

#include <iostream>
#include "../incl/AGraphics.hpp"


class Graphics : public AGraphics {

public:
    Graphics(); // Canonical
    Graphics(Graphics const &copy); // Canonical
    ~Graphics(); // Canonical

    Graphics &operator=(Graphics const &copy); // Canonical

    int init(int windowWidth, int windowHeight);

    int loopUpdate();

    void updateScreen();

    void putStrScreen(std::string str);

    void loadTexture(std::string path, int key);

    void closeWindow();

    void cleanUp();

    std::vector<eEvent>& getEvent();

    unsigned char getChar();

    void putTexture(int key, int posX, int posY, int sizeX, int sizeY);

private:
    GLFWwindow *_window;
    bool _windowTerminated;

};

extern "C" {
    Graphics *createGraphics();
    void deleteGraphics(Graphics *graphics);
}


#endif //NIBBLER_GRAPHICS_HPP



















