#pragma once

class CCore {

	SINGLE(CCore);

private:
	HWND m_hWnd;
	POINT m_ptResolution;
	HDC m_hdc;

	HBITMAP m_hBit;
	HDC m_memDC;

public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();

private:
	void update();
	void render();

public:
	HWND GetMainHwnd() { return m_hWnd; }
	HDC GetMainDC() { return m_hdc; }
	POINT GetResolution() { return m_ptResolution; }
};
