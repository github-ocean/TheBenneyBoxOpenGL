#include "Display.h"
#include <iostream>

Display::Display(int Width, int Height, const std::string& Title)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	m_Window = SDL_CreateWindow(Title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width, Height, SDL_WINDOW_OPENGL);
	m_glContext = SDL_GL_CreateContext(m_Window);

	GLenum Status = glewInit();

	if (Status != GLEW_OK)
		std::cerr << "glew faild to initialize." << std::endl;

	m_bIsClosed = false;
}

Display::~Display()
{
	SDL_GL_DeleteContext(m_glContext);
	SDL_DestroyWindow(m_Window);
	SDL_Quit();
}

void Display::Clear(float R, float G, float B, float A)
{
	glClearColor(R, G, B, A);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Display::Update()
{
	SDL_GL_SwapWindow(m_Window);

	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
		{
			m_bIsClosed = true;
		}
	}
}

bool Display::IsCloseed()
{
	return m_bIsClosed;
}
