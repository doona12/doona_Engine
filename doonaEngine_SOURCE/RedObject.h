#pragma once
#include "CommonInclude.h"
namespace dn
{
	class RedObject
	{
	public:
		RedObject();
		~RedObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y)
		{
			mx = x;
			my = y;
		}

		float GetPositionX() { return mx; }
		float GetPositionY() { return my; }

	private:
		//레드오브젝트 좌표
		float mx;
		float my;
	};
}

