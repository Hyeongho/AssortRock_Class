
#include "SceneCollision.h"
#include "../Collision/Collider.h"
#include "../UI/UIWindow.h"
#include "../UI/UIWidget.h"
#include "../Input.h"
#include "Scene.h"
#include "Camera.h"

CSceneCollision::CSceneCollision()
{
	m_vecCollider.reserve(500);
	m_vecUIWindow.reserve(10);
	m_SelectWidget = nullptr;
	m_MouseHoveredWidget = nullptr;
}

CSceneCollision::~CSceneCollision()
{
}

void CSceneCollision::AddCollider(CCollider* Collider)
{
	m_vecCollider.push_back(Collider);
}

void CSceneCollision::AddUIWindow(CUIWindow* Window)
{
	m_vecUIWindow.push_back(Window);
}

void CSceneCollision::CollisionMouse(float DeltaTime)
{
	Vector2	MousePos = CInput::GetInst()->GetMousePos();
	Vector2	MouseWorldPos = MousePos + m_Scene->GetCamera()->GetPos();

	// ���� ���콺�� UI�� �浹ó���Ѵ�.
	int	WidgetCount = 0;

	// ��� �����찡 ������ �ִ� ��ü ������ ���� ���Ѵ�.
	size_t	WindowCount = m_vecUIWindow.size();
	for (size_t i = 0; i < WindowCount; ++i)
	{
		WidgetCount += m_vecUIWindow[i]->GetWidgetCount();
	}

	std::vector<CUIWidget*>	vecWidget;
	vecWidget.resize(WidgetCount);

	int	WidgetOffset = 0;

	if (m_SelectWidget)
	{
		vecWidget[WidgetOffset] = m_SelectWidget;
		++WidgetOffset;
	}
	
	for (size_t i = 0; i < WindowCount; ++i)
	{
		int	Count = m_vecUIWindow[i]->GetWidgetCount();

		for (int j = 0; j < Count; ++j)
		{
			CUIWidget* Widget = m_vecUIWindow[i]->GetWidget(j);

			if (Widget != m_SelectWidget)
			{
				vecWidget[WidgetOffset] = Widget;
				++WidgetOffset;
			}
		}
	}

	// ���콺�� UI�� �浹�� �����Ѵ�.
	// ���� �ϳ��� �浹�� �ȴٸ� ���̻� �浹�� �� �ʿ䰡 ����.
	bool	EnableCollision = false;

	for (int i = 0; i < WidgetCount; ++i)
	{
		if (vecWidget[i]->CollisionMouse(MousePos, DeltaTime))
		{
			if (m_MouseHoveredWidget && m_MouseHoveredWidget != vecWidget[i])
			{
				m_MouseHoveredWidget->CollisionMouseReleaseCallback(DeltaTime);
			}

			m_MouseHoveredWidget = vecWidget[i];

			EnableCollision = true;

			break;
		}
	}

	// ���콺�� ���忡 ��ġ�� ��ü���� �浹�� �����Ѵ�.
	// ��, ������ UI�� �浹�� �Ǿ��ٸ� �浹�� ���Ѵ�.
	if (!EnableCollision)
	{
		if (m_MouseHoveredWidget)
		{
			m_MouseHoveredWidget->CollisionMouseReleaseCallback(DeltaTime);
			m_MouseHoveredWidget = nullptr;
		}

		if (m_SelectWidget)
			m_SelectWidget = nullptr;

		// ������� �浹ü�� ���콺���� �浹ó���� �Ѵ�.
		// �浹ü���� ȭ�鿡 ������ �浹ü�鸸 �ɷ����� �浹ü�� �ٴ� ��������
		// ������ �����ش�.
	}
}

void CSceneCollision::Collision(float DeltaTime)
{
	size_t	Size = m_vecCollider.size();

	if (Size > 1)
	{
		for (size_t i = 0; i < Size - 1; ++i)
		{
			CCollider* Src = m_vecCollider[i];

			for (size_t j = i + 1; j < Size; ++j)
			{
				CCollider* Dest = m_vecCollider[j];

				// �� �浹ü�� ���� ������Ʈ�� �ҼӵǾ� �ִٸ� �浹�� ���Ѵ�.
				if (Src->GetOwner() == Dest->GetOwner())
					continue;

				CollisionProfile* SrcProfile = Src->GetProfile();
				CollisionProfile* DestProfile = Dest->GetProfile();

				// ���� ���濡 ���� CollisionState�� ���´�.
				ECollision_State	SrcState = SrcProfile->vecState[DestProfile->Channel];
				ECollision_State	DestState = DestProfile->vecState[SrcProfile->Channel];

				if (SrcState == ECollision_State::Ignore || // ��ȭ���� &&(��������)
					DestState == ECollision_State::Ignore)
					continue;

				if (Src->Collision(Dest))
				{
					// ������ �浹�ǰ� �־������� �Ǵ��Ѵ�.
					if (!Src->CheckCollisionList(Dest))
					{
						// ���� ������ �浹��Ͽ� �����Ѵ�.
						Src->AddCollisionList(Dest);
						Dest->AddCollisionList(Src);

						Src->CallCollisionBegin(Dest, DeltaTime);
						Dest->CallCollisionBegin(Src, DeltaTime);
					}
				}

				// �浹�� �ȵǾ��� ��� ������ �浹�ϴ� ��ü������ �Ǵ��Ѵ�.
				else if (Src->CheckCollisionList(Dest))
				{
					Src->DeleteCollisionList(Dest);
					Dest->DeleteCollisionList(Src);

					Src->CallCollisionEnd(Dest, DeltaTime);
					Dest->CallCollisionEnd(Src, DeltaTime);
				}
			}
		}
	}




	m_vecCollider.clear();
	m_vecUIWindow.clear();
}
