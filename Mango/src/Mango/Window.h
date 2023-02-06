#pragma once
#include <GLFW/glfw3.h>
#include <string>

namespace Mango
{
	static bool WasGLFWInit = false;
	static uint32_t NumWindows = 0;

	struct WindowSpecification
	{
		std::string Title;
		uint32_t Width, Height;
		bool Maximized;

		WindowSpecification(const std::string& title, uint32_t width, uint32_t height, bool maximized)
			: Title(title), Width(width), Height(height), Maximized(maximized)
		{}
	};

	class Window
	{
	public:
		Window(const WindowSpecification& spec);
		~Window();

		void Update();
		void Display();
		bool ShouldClose() { return glfwWindowShouldClose(m_NativeWindow); }

	private:
		void SetupImGui();

		GLFWwindow* m_NativeWindow;
		WindowSpecification m_Spec;
	};
}