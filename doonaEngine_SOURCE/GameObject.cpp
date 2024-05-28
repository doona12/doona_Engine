#include "GameObject.h"
#include "Input.h"
#include "Time.h"

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
		const int speed = 100.0f;

		if (Input::GetKey(eKeyCode::Left))
		{
			mx -= speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Right))
		{
			mx += speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Up))
		{
			my -= speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			my += speed * Time::DeltaTime();
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