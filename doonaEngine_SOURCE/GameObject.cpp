#include "GameObject.h"


namespace dn
{
	GameObject::GameObject():mx(0.0f),my(0.0f)
	{
	}
	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mx -= 0.01f;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mx += 0.01f;
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			my -= 0.01f;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			my += 0.01f;
		}
	}

	void GameObject::LateUpdate()
	{

	}
	void GameObject::Render(HDC hdc)
	{
		//파란 브러쉬 생성
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));

		//파란브러쉬 DC에 선택,흰색 브러쉬 반환
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Rectangle(hdc, 100 + mx, 100 + my, 200 + mx, 200 + my);

		SelectObject(hdc, oldBrush);
		DeleteObject(brush);
		DeleteObject(redPen);
	}


}