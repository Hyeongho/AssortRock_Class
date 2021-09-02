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

			// 두 충돌체가 같은 오브젝트에 소속되어 있다면 충돌을 안한다.
			if (Src->GetOwner() == Dest->GetOwner())
			{
				continue;
			}

			CollisionProfile* SrcProfile = Src->GetProfile();
			CollisionProfile* DestProfile = Dest->GetProfile();

			// 서로 상대방에 대한 CollisionState를 얻어온다.
			ECollision_State SrcState = SrcProfile->vecState[DestProfile->Channel];
			ECollision_State DestState = DestProfile->vecState[SrcProfile->Channel];

			if (SrcState == ECollision_State::Ignore || DestState == ECollision_State::Ignore) // 평화주의 &&(폭력주의)
			{
				continue;
			}

			if (Src->Collision(Dest))
			{
				//MessageBox(0, TEXT("충돌"), TEXT("충돌"), MB_OK);
			}

			else
			{

			}
		}
	}

	m_vecCollider.clear();
}
