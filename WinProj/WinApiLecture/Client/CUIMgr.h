#pragma once

class CUI;

class CUIMgr
{
	SINGLE(CUIMgr);
private:
	CUI* m_pFocusedUI;


public:
	void update();

private:
	CUI* GetFocusedUI();
	CUI* GetTargetedUI(CUI* _pParentUI);

};

