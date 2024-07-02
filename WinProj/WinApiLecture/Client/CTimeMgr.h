#pragma once
class CTimeMgr
{
	SINGLE(CTimeMgr);
private:
	LARGE_INTEGER	m_llCurCount;
	LARGE_INTEGER	m_llFrequency;
	LARGE_INTEGER	m_llPrevCount;

	double			m_dDT; //프레임 간 시간값
	double			m_dAcc;
	UINT			m_iCallCount;
	UINT			m_iFPS;

public:
	void init();
	void update();

	double GetDT() { return m_dDT; }
	float GetfDT() { return (float)m_dDT; }
};

