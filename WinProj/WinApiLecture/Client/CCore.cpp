#include "pch.h"
#include "CCore.h"

#include "CKeyMgr.h"
#include "CTimeMgr.h"
#include "CObject.h"
#include "CSceneMgr.h"


CObject g_obj;

CCore::CCore()
	: m_hWnd(0)
	, m_ptResolution{}
	, m_hdc(0)
	, m_hBit(0)
	, m_memDC(0)
{
}

CCore::~CCore()
{
	ReleaseDC(m_hWnd, m_hdc);

	DeleteDC(m_memDC);
	DeleteObject(m_hBit);
}

int CCore::init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;

	RECT rt = {0,0,m_ptResolution.x, m_ptResolution.y};

	AdjustWindowRect(&rt, WS_OVERLAPPED, true);
	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right-rt.left,rt.bottom-rt.top,0);

	m_hdc = GetDC(m_hWnd);

	//이중 버퍼링 용도의 비트맵과 DC를 만든다
	m_hBit = CreateCompatibleBitmap(m_hdc, m_ptResolution.x, m_ptResolution.y);
	m_memDC = CreateCompatibleDC(m_hdc);

	HBITMAP hOldBit = (HBITMAP)SelectObject(m_memDC, m_hBit);
	DeleteObject(hOldBit);

	//Manager 초기화
	CTimeMgr::GetInst()->init();
	CKeyMgr::GetInst()->init();
	CSceneMgr::GetInst()->init();

	g_obj.SetPos(Vec2((float)( m_ptResolution.x/2),(float)(_ptResolution.y/2)));
	g_obj.SetScale(Vec2{100,100});



	return S_OK;
}


void CCore::progress()
{
	CTimeMgr::GetInst()->update();
	CKeyMgr::GetInst()->update();


	update();

	render();


}

void CCore::update()
{
	Vec2 vPos = g_obj.GetPos();

	if (CKeyMgr::GetInst()->GetKeyState(KEY::LEFT)==KEY_STATE::TAP) {

		vPos.x -= 100.f *CTimeMgr::GetInst()->GetfDT();
	}

	if (CKeyMgr::GetInst()->GetKeyState(KEY::RIGHT) == KEY_STATE::TAP) {

		vPos.x += 100.f * CTimeMgr::GetInst()->GetfDT();
	}
	g_obj.SetPos(vPos);
}

void CCore::render()
{
	//clear

	Rectangle(m_memDC, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);


	//그리기
	Vec2 vPos = g_obj.GetPos();
	Vec2 vScale = g_obj.GetScale();

	Rectangle(m_memDC	, vPos.x - vScale.x / 2.f
						, vPos.y - vScale.y / 2.f
						, vPos.x + vScale.x / 2.f
						, vPos.y + vScale.y / 2.f);

	BitBlt(m_hdc,0,0,m_ptResolution.x,m_ptResolution.y,m_memDC, 0,0,SRCCOPY);

}
