#pragma once

class CObject;

class CCamera
{
	SINGLE(CCamera);
private:
	Vec2		m_vLookAt;
	Vec2		m_vCurLookAt;
	Vec2		m_vPrevLookAt;
	CObject*	m_pTargetObj;

	Vec2		m_vDiff;

	float		m_fTime;
	float		m_fSpeed;
	float		m_fAccTime;

public:
	void SetLookAt(Vec2 _vLook) 
	{ 
		m_vLookAt = _vLook; 
		float fMoveDist = (m_vLookAt - m_vPrevLookAt).Length();
		m_fSpeed = fMoveDist / m_fTime;
		m_fAccTime = 0.f;
	}
	void SetTarget(CObject* _pTarget) { m_pTargetObj = _pTarget; }
	Vec2 GetLookAt() { return m_vCurLookAt; }
	Vec2 GetRenderPos(Vec2 _vObjPos) { return _vObjPos - m_vDiff; }
	Vec2 GetRealPos(Vec2 _vRenderPos) { return _vRenderPos + m_vDiff; }



	void update();


private:
	void CalDiff();
};

