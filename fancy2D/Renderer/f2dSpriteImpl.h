////////////////////////////////////////////////////////////////////////////////
/// @file  f2dSpriteImpl.h
/// @brief fancy2D 精灵实现
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <fcyRefObj.h>
#include "../f2dRenderer.h"

////////////////////////////////////////////////////////////////////////////////
/// @brief fancy2D 精灵实现
////////////////////////////////////////////////////////////////////////////////
class f2dSpriteImpl : 
	public fcyRefObjImpl<f2dSprite>
{
	friend class f2dRendererImpl;
protected:
	f2dTexture2D* m_pTex;
	F2DSPRITEFLIP m_FlipType;
	fcyRect m_Org;
	fcyVec2 m_HotSpot;
	fcyColor m_Color[4];
	float m_ZValue;

	fcyRect m_UV;
	fcyRect m_SpriteRect;
protected:
	void recalcu();
public: // 接口实现
	f2dTexture2D* GetTexture();
	fResult SetTexture(f2dTexture2D* pTex);
	fcyRect GetTexRect();
	fResult SetTexRect(fcyRect Rect);
	fcyVec2 GetHotSpot();
	fResult SetHotSpot(fcyVec2 Point);
	F2DSPRITEFLIP GetFlipType();
	fResult SetFlipType(F2DSPRITEFLIP Type);
	fFloat GetZ();
	fResult SetZ(fFloat Value);
	fcyColor GetColor(fuInt Index);
	fResult SetColor(fcyColor Color);
	fResult SetColor(fuInt Index, fcyColor Color);
	fResult Draw(f2dGraphics2D* pGraph, const fcyRect& Dest);
	fResult Draw(f2dGraphics2D* pGraph, const fcyRect& Dest, const fcyRect& SubTex);
	fResult Draw(f2dGraphics2D* pGraph, const fcyVec2& Center);
	fResult Draw(f2dGraphics2D* pGraph, const fcyVec2& Center, const fcyVec2& Scale);
	fResult Draw(f2dGraphics2D* pGraph, const fcyVec2& Center, const fcyVec2& Scale, const fcyRect& SubTex);
	fResult Draw(f2dGraphics2D* pGraph, const fcyVec2& Center, const fcyVec2& Scale, fFloat Rotation);
	fResult Draw(f2dGraphics2D* pGraph, const fcyVec2& Center, const fcyVec2& Scale, fFloat Rotation, const fcyRect& SubTex);
protected:
	f2dSpriteImpl(f2dTexture2D* pTex);
	f2dSpriteImpl(f2dTexture2D* pTex, fcyRect SrcRect);
	f2dSpriteImpl(f2dTexture2D* pTex, fcyRect SrcRect, fcyVec2 HotSpot);
	~f2dSpriteImpl();
};
