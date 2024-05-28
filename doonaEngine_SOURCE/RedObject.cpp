#include "RedObject.h"


namespace dn
{
	RedObject::RedObject()
	{
	}
	RedObject::~RedObject()
	{
	}
	void RedObject::Update()
	{
		if (GetAsyncKeyState('A') & 0x8000)
		{
			mx -= 0.01f;
		}
		if (GetAsyncKeyState('D') & 0x8000)
		{
			mx += 0.01f;
		}
		if (GetAsyncKeyState('W') & 0x8000)
		{
			my -= 0.01f;
		}
		if (GetAsyncKeyState('S') & 0x8000)
		{
			my += 0.01f;
		}
	}
	void RedObject::LateUpdate()
	{
	}
	void RedObject::Render(HDC hdc)
	{
		//���� �귯�� ����
		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));

		//�����귯�� DC�� ����,��� �귯�� ��ȯ
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		Ellipse(hdc, 100 + mx, 100 + my, 200 + mx, 200 + my);

		SelectObject(hdc, oldBrush);
		DeleteObject(brush);
	}
}