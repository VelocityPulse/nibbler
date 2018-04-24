#include "Graphics.hpp"


Graphics::Graphics() {

}

Graphics::Graphics(Graphics const &copy) {
    *this = copy;
}

Graphics::~Graphics() {

}

Graphics &Graphics::operator=(Graphics const &copy) {
    if (this != &copy) {
        // copy
    }
    return *this;
}

void	Graphics::helloWorld(void) {
	std::cout << "Hello Vulkan" << std::endl;

	//Init
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);



	uint32_t extensionCount = 0;
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

	std::cout << extensionCount << " extensions supported" << std::endl;

	glm::mat4 matrix;
	glm::vec4 vec;
	auto test = matrix * vec;

	//Mainloop
	while(!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}

	//Cleanup
	glfwDestroyWindow(window);
	glfwTerminate();

}
