#include "SceneCollision.h"
#include "../Collision/Collider.h"

CSceneCollision::CSceneCollision()
{
	m_vecCollider.reserve(500);
}

CSceneCollision::~CSceneCollision()
{
}

void CSceneCollision::AddCollider(CCollider* Collider)
{
	m_vecCollider.push_back(Collider);
}

void CSceneCollision::Collision(float DeltaTime)
{
	size_t Size = m_vecCollider.size();

	if (Size <= 1)
	{
		m_vecCollider.clear();
		return;
	}

	for (size_t i = 0; i < Size - 1; i++)
	{
		CCollider* Src = m_vecCollider[i];

		for (size_t j = i + 1; j < Size; j++)
		{
			CCollider* Dest = m_vecCollider[j];

			// �� �浹ü�� ���� ������Ʈ�� �ҼӵǾ� �ִٸ� �浹�� ���Ѵ�.
			if (Src->GetOwner() == Dest->GetOwner())
			{
				continue;
			}

			CollisionProfile* SrcProfile = Src->GetProfile();
			CollisionProfile* DestProfile = Dest->GetProfile();

			// ���� ���濡 ���� CollisionState�� ���´�.
			ECollision_State SrcState = SrcProfile->vecState[DestProfile->Channel];
			ECollision_State DestState = DestProfile->vecState[SrcProfile->Channel];

			if (SrcState == ECollision_State::Ignore || DestState == ECollision_State::Ignore) // ��ȭ���� &&(��������)
			{
				continue;
			}

			if (Src->Collision(Dest))
			{
				//MessageBox(0, TEXT("�浹"), TEXT("�浹"), MB_OK);
			}

			else
			{

			}
		}
	}

	m_vecCollider.clear();
}
