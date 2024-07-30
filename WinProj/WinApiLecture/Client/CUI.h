#pragma once
#include "CObject.h"
class CUI :
    public CObject
{
private:
    vector<CUI*>    m_vecChildUI;
    CUI*            m_pParentUI;
    Vec2            m_vFinalPos;

    bool            m_bCamAffected; // ui ī�޶� ���� ����
    bool            m_bMouseOn;     // ���콺 UI ȣ��
    bool            m_bLbtnDown;    // ui ���ʹ�ư ������
public:
    Vec2 GetFinalPos() { return m_vFinalPos; }
    CUI* GetParent() { return m_pParentUI; }
    bool IsMouseOn() { return m_bMouseOn; }
    bool IsMouseDown() { return m_bLbtnDown; }

    void AddChild(CUI* _pUI) { m_vecChildUI.push_back(_pUI); _pUI->m_pParentUI = this; }
    const vector<CUI*> GetChildUI() { return m_vecChildUI; }

    virtual void update();
    virtual void finalupdate();
    virtual void render(HDC _dc);

    virtual CUI* Clone() = 0;


private:
    void update_child();
    void finalupdate_child();
    void render_child(HDC _dc);

    void MouseOnCheck();

public:
    virtual void MouseOn();

    virtual void MouseLbtnDown();
    virtual void MouseLbtnUp();
    virtual void MouseLbtnClicked();


public:
    CUI(bool _bCamAffected);
    CUI(const CUI& _origin);
    virtual ~CUI();

    friend class CUIMgr;

};


