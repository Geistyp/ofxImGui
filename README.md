# ofxImGui

=======
--------
Change sth to support IME input

EngineGLFW.cpp
```c++
namespace ofxImGui
{
	GLuint EngineGLFW::g_FontTexture = 0;

	void ImGui_ImplGlfwGL3_CharCallback(GLFWwindow*, unsigned int c)
	{
		ImGuiIO& io = ImGui::GetIO();
		if (c > 0 && c < 0x10000)
			io.AddInputCharacter((unsigned short)c);
	}
	...
```
---
```c++
void EngineGLFW::setup(bool autoDraw)
{
	...
	// 
	auto ptr = static_cast<ofAppGLFWWindow*>(ofGetWindowPtr());
	glfwSetCharCallback(ptr->getGLFWWindow(), ImGui_ImplGlfwGL3_CharCallback);

	isSetup = true;
}
```
---
```c++
void EngineGLFW::onKeyPressed(ofKeyEventArgs& event)
{
	...
	if (key < GLFW_KEY_ESCAPE || isNumericalKey)
	{
		//io.AddInputCharacter((unsigned short)event.codepoint);
	}
}
```

<<<<<<< HEAD
ofxAddon that allows you to use [ImGui](https://github.com/ocornut/imgui) in [openFrameworks](https://github.com/openframeworks/openFrameworks).

### Compatibility
Master branch may not be tested on all platforms. See [Releases](https://github.com/jvcleave/ofxImGui/releases/) for more extensively tested versions.
=======
--------
ofxAddon that allows you to use [ImGui](https://github.com/ocornut/imgui) in [openFrameworks](https://github.com/openframeworks/openFrameworks)
>>>>>>> origin/master

Release versions tested with OF 0.9.x on
 - Raspberry Pi 1 and 2
 - Mac OS 10.11, Xcode 7
 - iOS 9.2 and 8.1.2, Xcode 7
 - Linux Desktop
 - Windows 10, Visual Studio 2015



#### Upgrade Notes
Versions 1.50 and higher use the keyword `ofxImGui` as a namespace for all classes in the addon, while previous versions just had a class called `ofxImGui`. If you're upgrading from a previous version, make sure to replace all instances of class `ofxImGui` with `ofxImGui::Gui`.

### Examples

![Screenshot](images/Screenshot.png)

#### example-demo    
Works on Desktop, uses imgui demo windows.

#### example-helpers
Works on Desktop, uses ofxImGui helper functions for interfacing with `ofParameter`.

#### example-ios  
iOS specific with keyboard input helper.
