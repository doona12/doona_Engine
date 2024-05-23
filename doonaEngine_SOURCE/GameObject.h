#pragma once
#include "CommonInclude.h"

namespace dn
{
	//Actor
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y)
		{
			mx = x;
			my = y;
		}

		float GetPositionX(){return mx;}
		float GetPositionY(){return my;}
		
	private:
		//게임오브젝트 좌표
		float mx;
		float my;
	};
}
