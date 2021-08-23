#pragma once

#include "GameInfo.h"

class CRef
{
public:
	CRef();
	virtual ~CRef();

protected:
	std::string m_Name;
	bool m_Active;

public:
	void Destroy()
	{
		m_Active = false;
	}

public:
	bool IsActive()
	{
		return m_Active;
	}

	std::string GetName() const
	{
		return m_Name;
	}

	void SetName(const std::string& Name)
	{
		m_Name = Name;
	}
};

