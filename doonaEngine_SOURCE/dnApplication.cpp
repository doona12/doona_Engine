#include "dnApplication.h"
#include "Input.h"
#include "Time.h"

namespace dn
{
	Application::Application():mHwnd(nullptr),mHdc(nullptr)
	{
	}
	Application::~Application()
	{
	}
	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		mPlayer.SetPosition(0, 0);

		Input::Initailize();
		Time::Initailize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();

		mPlayer.Update();
		
	}
	void Application::LateUpdate()
	{
	}
	
	void Application::Render()
	{
		mPlayer.Render(mHdc);
		Time::Render(mHdc);
		//mRedPlayer.Render(mHdc);
	}
}