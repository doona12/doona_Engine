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
		//�Ķ� �귯�� ����
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));

		//�Ķ��귯�� DC�� ����,��� �귯�� ��ȯ
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