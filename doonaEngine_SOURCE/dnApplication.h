#pragma once
#include "CommonInclude.h"
#include "GameObject.h"
#include "RedObject.h"


namespace dn
{
	class Application
	{

	public:
		Application();
		~Application();
		void Initialize(HWND hwnd);
		void Update();
		void LateUpdate();
		void Run();

		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		GameObject mPlayer;
		RedObject mRedPlayer;
	};
}
