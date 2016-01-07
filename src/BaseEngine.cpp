#include "BaseEngine.h"


unsigned int BaseEngine::vboHandle = 0;
unsigned int BaseEngine::elementsHandle = 0;
int BaseEngine::attribLocationColor = 0;
ofShader BaseEngine::shader;

void BaseEngine::onKeyPressed(ofKeyEventArgs& event)
{
	int key = event.keycode;
    io->KeysDown[key] = true;
}

void BaseEngine::onMousePressed(ofMouseEventArgs& event)
{
    if(event.button >= 0 && event.button < 5)
    {
        io->MouseDown[event.button] = true;
    }
}

void BaseEngine::onMouseReleased(ofMouseEventArgs& event)
{
    if(event.button >= 0 && event.button < 5)
    {
        io->MouseDown[event.button] = false;
    }
}

void BaseEngine::onMouseScrolled(ofMouseEventArgs& event)
{
    io->MouseWheel = event.scrollY;
}

void BaseEngine::onWindowResized(ofResizeEventArgs& window)
{
    io->DisplaySize = ImVec2((float)window.width, (float)window.height);
}


const char* BaseEngine::getClipboardString()
{
    return &ofGetWindowPtr()->getClipboardString()[0];
}

void BaseEngine::setClipboardString(const char * text)
{
    ofGetWindowPtr()->setClipboardString(text);
}


GLuint BaseEngine::loadTextureImage2D(unsigned char * pixels, int width, int height)
{
    GLint last_texture;
    glGetIntegerv(GL_TEXTURE_BINDING_2D, &last_texture);
    
    GLuint new_texture;
    glGenTextures(1, &new_texture);
    glBindTexture(GL_TEXTURE_2D, new_texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(
                 GL_TEXTURE_2D,
                 0,
                 GL_RGBA,
                 width, height,
                 0,
                 GL_RGBA,
                 GL_UNSIGNED_BYTE,
                 pixels
                 );
    
    glBindTexture(GL_TEXTURE_2D, last_texture);
    
    return new_texture;
};