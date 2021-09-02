#pragma once

#include "../GameInfo.h"

class CCollisionManager
{
private:
	CCollisionManager();
	~CCollisionManager();

public:
	bool Init();

private:
	static CCollisionManager* m_Inst;

public:
	static CCollisionManager* GetInst()
	{
		if (!m_Inst)
			m_Inst = new CCollisionManager;

		return m_Inst;
	}

	static void DestroyInst()
	{
		SAFE_DELETE(m_Inst);
	}
};

