#include "Graphics.hpp"

/*
 * Declaration de la variable static
 * Permet la modification de l'_eventList dans la fonction
 * de callback et donc en dehors de l'instance de la Lib
 */
std::vector<eEvent> AGraphics::_eventList;

Graphics::Graphics() {
    this->_window = nullptr;
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

int Graphics::init() {
    this->_window = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");
    return 1;
}

int Graphics::loopUpdate() {
    this->getEvent();
    this->_window->clear();
    this->_window->display();
    return this->_window->isOpen();
}

void Graphics::updateScreen() {

}

void Graphics::putStrScreen(std::string str) {

}

void Graphics::loadTexture(std::string path) {

}

void Graphics::cleanUp() {
    if (this->_window)
        delete this->_window;
}

std::vector<eEvent>& Graphics::getEvent() {
    sf::Event event;
    while (this->_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            // TODO add the values in the vector
            this->_window->close();
    }
    return this->_eventList;
}

unsigned char Graphics::getChar() {
    return 0;
}

Graphics *createGraphics() {
    return new Graphics();
}

void deleteGraphics(Graphics *graphics) {
    delete graphics;
}
