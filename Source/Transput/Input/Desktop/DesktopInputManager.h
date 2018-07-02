#pragma once

#include "Composition/Event/EventManager.h"
#include "Transput/Input/Key.h"
#include "Transput/Input/InputManager.h"

#include <GLFW/glfw3.h>

class DesktopInputManager : public InputManager {

public:

	DesktopInputManager(EventManager&);
	~DesktopInputManager() override = default;

	DesktopInputManager(DesktopInputManager const&) = delete;
	void operator=(DesktopInputManager const&) = delete;

	DesktopInputManager(DesktopInputManager&& o) = delete;
	DesktopInputManager& operator=(DesktopInputManager&& other) = delete;

	//void AttachWindow(DesktopWindow* window);
	void Poll() override;


private:

	void KeyCallback(GLFWwindow*, int, int, int, int);
	void CharacterCallback(GLFWwindow*, uint);
	void ModdedCharacterCallback(GLFWwindow*, uint, int);
	void ButtonCallback(GLFWwindow*, int, int, int);
	void CursorCallback(GLFWwindow*, double, double);
	void CursorEnterCallback(GLFWwindow*, int);
	void ScrollCallback(GLFWwindow*, double, double);

	std::unordered_map<int, Key> keyStates_;

	double mouseXPos_;
	double mouseYPos_;

	double mouseXOffset_;
	double mouseYOffset_;

	bool firstMouse_;

};
