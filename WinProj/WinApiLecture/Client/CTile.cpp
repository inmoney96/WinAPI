#include "pch.h"
#include "CTile.h"

#include "Ctexture.h"

CTile::CTile()
	: m_pTileTex(nullptr)
	, m_iImgIdx(0)
{
	SetScale(Vec2(TILE_SIZE, TILE_SIZE));
}

CTile::~CTile()
{
}

void CTile::update()
{
}

void CTile::render(HDC _dc)
{
	if (nullptr == m_pTileTex)
	{
		return;
	}

	UINT iWidth = m_pTileTex->Width();
	UINT iHeight = m_pTileTex->Height();

	UINT iMaxCol = iWidth / TILE_SIZE;
	UINT iMaxRow = iHeight / TILE_SIZE;

	UINT iCurRow =(UINT)m_iImgIdx / iMaxCol;
	UINT iCurCol =(UINT)m_iImgIdx % iMaxCol;

	if (iMaxRow <= iCurRow) {
		assert(nullptr);
	}


	Vec2 vRenderPos = CCamera::GetInst()->GetRenderPos(GetPos());
	Vec2 vScale = GetScale();

	BitBlt(_dc
		, vRenderPos.x
		, vRenderPos.y
		, vScale.x
		, vScale.y
		, m_pTileTex->GetDC()
		, iCurCol * TILE_SIZE
		, iCurRow * TILE_SIZE
		, SRCCOPY);
}