#pragma once

//전방선언 (포인터타입만 사용 가능)
class CObject;


class CScene
{
private:
	vector<CObject*>	m_arrObj[(UINT)GROUP_TYPE::END];
	wstring				m_strName;

public:
	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

public:
	CScene();
	virtual ~CScene();
};

