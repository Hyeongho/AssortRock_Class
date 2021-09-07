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
    bool    m_Visibility;

public:
    void SetVisibility(bool Visiblity)
    {
        m_Visibility = Visiblity;
    }

    bool GetVisibility()    const
    {
        return m_Visibility;
    }

    void SetZOrder(int ZOrder)
    {
        m_ZOrder = ZOrder;
    }

    int GetZOrder() const
    {
        return m_ZOrder;
    }
};

