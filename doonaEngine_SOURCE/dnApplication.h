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

		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;

		GameObject mPlayer;
		RedObject mRedPlayer;
	};
}
