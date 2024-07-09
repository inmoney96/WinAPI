#include "pch.h"
#include "CMissile.h"
#include "CTimeMgr.h"


CMissile::CMissile()
	: m_fTheta(PI/4.f)
{
}

CMissile::~CMissile()
{
}

void CMissile::update()
{
	Vec2 vPos = GetPos();

	vPos.x += 600.f * fDT * cosf(m_fTheta);
	vPos.y -= 600.f * fDT * sinf(m_fTheta);

	SetPos(vPos);
}

void CMissile::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	Ellipse(_dc, vPos.x - vScale.x / 2.f, vPos.y - vScale.y / 2.f,
		vPos.x + vScale.x / 2.f, vPos.y + vScale.y / 2.f);

}
