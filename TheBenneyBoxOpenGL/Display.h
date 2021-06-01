#pragma once
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>

class Display
{
public:
	Display(int Width, int Height, const std::string& Title);
	~Display();
	SDL_Window* m_Window;
	SDL_GLContext m_glContext;
	bool m_bIsClosed;

	void Clear(float R, float G, float B, float A);
	void Update();
	bool IsCloseed();
};