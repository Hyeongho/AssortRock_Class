#pragma once
#include "../Ref.h"
class CUIWidget :
    public CRef
{
public:
    CUIWidget();
    CUIWidget(const CUIWidget& widget);
    virtual ~CUIWidget();

protected:
    int m_ZOrder;
    bool m_Visibility;

public:
    void SetVisibility(bool Visibility)
    {
        m_Visibility = Visibility;
    }

    bool GetVisibility() const
    {
        return m_Visibility;
    }
};

