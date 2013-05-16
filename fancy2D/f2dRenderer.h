////////////////////////////////////////////////////////////////////////////////
/// @file   f2dRenderer.h
/// @brief  fancy2D引擎渲染器接口定义
/// @note   定义了f2D的渲染器接口
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include "f2dInterface.h"

#include "f2dRenderDevice.h"

/// @addtogroup f2d渲染系统
/// @brief fancy2d引擎中的渲染系统，提供对2D图形的渲染支持。
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @brief fancy2D 精灵翻转选项
////////////////////////////////////////////////////////////////////////////////
enum F2DSPRITEFLIP
{
	F2DSPRITEFLIP_NONE,  ///< @brief 无翻转
	F2DSPRITEFLIP_H,     ///< @brief 水平翻转
	F2DSPRITEFLIP_V,     ///< @brief 垂直翻转
	F2DSPRITEFLIP_HV     ///< @brief 水平垂直翻转
};

////////////////////////////////////////////////////////////////////////////////
/// @brief fancy2D 精灵
////////////////////////////////////////////////////////////////////////////////
struct f2dSprite : 
	public f2dInterface
{
	/// @brief 获得精灵绑定的纹理
	virtual f2dTexture2D* GetTexture()=0;

	/// @brief     设置一个新的纹理
	/// @param[in] pTex 纹理
	virtual fResult SetTexture(f2dTexture2D* pTex)=0;

	/// @brief 返回对应纹理的矩形
	virtual fcyRect GetTexRect()=0;

	/// @brief 设置对应纹理的矩形
	virtual fResult SetTexRect(fcyRect Rect)=0;

	/// @brief 返回热点
	virtual fcyVec2 GetHotSpot()=0;

	/// @brief     设置热点
	/// @param[in] Point 热点
	virtual fResult SetHotSpot(fcyVec2 Point)=0;

	/// @brief 返回翻转方式
	virtual F2DSPRITEFLIP GetFlipType()=0;
	
	/// @brief     设置翻转方式
	/// @param[in] Type 翻转方式
	virtual fResult SetFlipType(F2DSPRITEFLIP Type)=0;

	/// @brief 返回Z值
	virtual fFloat GetZ()=0;

	/// @brief     设置Z值
	/// @param[in] Value 新的Z值
	virtual fResult SetZ(fFloat Value)=0;

	/// @brief     返回顶点的颜色
	/// @param[in] Index 顶点索引[0~3]，按照顺时针方向定位
	virtual fcyColor GetColor(fuInt Index)=0;

	/// @brief     设置所有顶点的颜色
	/// @param[in] Color 混合颜色
	virtual fResult SetColor(fcyColor Color)=0;

	/// @brief 设置顶点颜色
	/// @param[in] Index 顶点索引[0~3]，按照顺时针方向定位
	/// @param[in] Color 混合颜色
	virtual fResult SetColor(fuInt Index, fcyColor Color)=0;

	/// @brief 绘制精灵
	/// @param[in] pGraph 绘图对象指针
	/// @param[in] Dest   目标矩形
	virtual fResult Draw(f2dGraphics2D* pGraph, const fcyRect& Dest)=0;

	/// @brief 绘制精灵
	/// @param[in] pGraph 绘图对象指针
	/// @param[in] Dest   目标矩形
	/// @param[in] SubTex 子纹理区域[0~1, 0~1]
	virtual fResult Draw(f2dGraphics2D* pGraph, const fcyRect& Dest, const fcyRect& SubTex)=0;

	/// @brief 绘制精灵
	/// @param[in] pGraph 绘图对象指针
	/// @param[in] Center 精灵显示中心
	virtual fResult Draw(f2dGraphics2D* pGraph, const fcyVec2& Center)=0;

	/// @brief 绘制精灵
	/// @param[in] pGraph 绘图对象指针
	/// @param[in] Center 精灵显示中心
	/// @param[in] Scale  缩放
	virtual fResult Draw(f2dGraphics2D* pGraph, const fcyVec2& Center, const fcyVec2& Scale)=0;

	/// @brief 绘制精灵
	/// @param[in] pGraph 绘图对象指针
	/// @param[in] Center 精灵显示中心
	/// @param[in] Scale  缩放
	/// @param[in] SubTex 子纹理区域[0~1, 0~1]
	virtual fResult Draw(f2dGraphics2D* pGraph, const fcyVec2& Center, const fcyVec2& Scale, const fcyRect& SubTex)=0;

	/// @brief 绘制精灵
	/// @param[in] pGraph   绘图对象指针
	/// @param[in] Center   精灵显示中心
	/// @param[in] Scale    缩放
	/// @param[in] Rotation 顺时针旋转角度，弧度制。
	virtual fResult Draw(f2dGraphics2D* pGraph, const fcyVec2& Center, const fcyVec2& Scale, fFloat Rotation)=0;
	
	/// @brief 绘制精灵
	/// @param[in] pGraph   绘图对象指针
	/// @param[in] Center   精灵显示中心
	/// @param[in] Scale    缩放
	/// @param[in] Rotation 顺时针旋转角度，弧度制。
	/// @param[in] SubTex   子纹理区域[0~1, 0~1]
	virtual fResult Draw(f2dGraphics2D* pGraph, const fcyVec2& Center, const fcyVec2& Scale, fFloat Rotation, const fcyRect& SubTex)=0;
};

////////////////////////////////////////////////////////////////////////////////
/// @brief fancy2D简单几何体渲染器
////////////////////////////////////////////////////////////////////////////////
struct f2dGeometryRenderer : 
	public f2dInterface
{
	/// @brief 获得Z值
	virtual fFloat GetZ()=0;

	/// @brief     设置Z值
	/// @param[in] ZValue Z值
	virtual void SetZ(fFloat ZValue)=0;

	/// @brief     获得画笔的颜色
	/// @param[in] Index 索引[0~2]，0=外侧颜色，1=中间颜色，2=内侧颜色
	virtual fcyColor GetPenColor(fuInt Index)=0;

	/// @brief     设置画笔颜色
	/// @param[in] Index 索引[0~2]，0=外侧颜色，1=中间颜色，2=内侧颜色
	/// @param[in] Color 颜色值
	virtual void SetPenColor(fuInt Index, const fcyColor& Color)=0;

	/// @brief 获得画笔大小
	virtual fFloat GetPenSize()=0;

	/// @brief     设置画笔大小
	/// @param[in] Size 画笔大小
	virtual void SetPenSize(fFloat Size)=0;

	/// @brief     画线
	/// @param[in] pGraph 绘图指针
	/// @param[in] Begin  起点
	/// @param[in] End    终点
	virtual fResult DrawLine(f2dGraphics2D* pGraph, const fcyVec2& Begin, const fcyVec2& End)=0;

	/// @brief     绘制矩形
	/// @param[in] pGraph 绘图指针
	/// @param[in] Rect   矩形
	virtual fResult DrawRectangle(f2dGraphics2D* pGraph, const fcyRect& Rect)=0;

	/// @brief     绘制圆
	/// @param[in] pGraph 绘图指针
	/// @param[in] Center 中心
	/// @param[in] R      半径
	/// @param[in] Divide 细分
	virtual fResult DrawCircle(f2dGraphics2D* pGraph, const fcyVec2& Center, float R, fuInt Divide=50)=0;

	/// @brief     填充矩形
	/// @param[in] pGraph    绘图指针
	/// @param[in] Rect      填充区域
	/// @param[in] pColorArr 颜色数组[0~3]，顺时针四个角的颜色
	virtual fResult FillRectangle(f2dGraphics2D* pGraph, const fcyRect& Rect, const fcyColor* pColorArr)=0;

	/// @brief     填充圆
	/// @param[in] pGraph      绘图指针
	/// @param[in] Center      中心
	/// @param[in] R           半径
	/// @param[in] CenterColor 中心颜色
	/// @param[in] BoundColor  边界颜色
	/// @param[in] Divide      细分
	virtual fResult FillCircle(f2dGraphics2D* pGraph, const fcyVec2& Center, float R, const fcyColor& CenterColor, const fcyColor& BoundColor, fuInt Divide=50)=0;
};

////////////////////////////////////////////////////////////////////////////////
/// @brief fancy2D 字形数据
////////////////////////////////////////////////////////////////////////////////
struct f2dGlyphInfo
{
	f2dTexture2D* pTex;  ///< @brief 存放字形数据的纹理，弱引用
	fcyRect GlyphPos;    ///< @brief 字形在纹理上的uv坐标
	fcyVec2 BrushPos;    ///< @brief 笔触在纹理上的uv坐标
	fcyVec2 Advance;     ///< @brief 笔触的前进量(像素)
};

////////////////////////////////////////////////////////////////////////////////
/// @brief fancy2D 字体提供器
////////////////////////////////////////////////////////////////////////////////
struct f2dFontProvider
{
	/// @brief      请求一个字形
	/// @param[in]  pGraph    正在使用的渲染器，空表示只查询字形数据
	/// @param[in]  Character 请求的字符
	/// @param[out] InfoOut   返回的字形数据
	virtual fResult QueryGlyph(f2dGraphics* pGraph, fCharW Character, f2dGlyphInfo* InfoOut)=0;
};

////////////////////////////////////////////////////////////////////////////////
/// @brief fancy2D 字体选项
////////////////////////////////////////////////////////////////////////////////
enum F2DFONTFLAG
{
	F2DFONTFLAG_NONE,    ///< @brief 无选项
	F2DFONTFLAG_OUTLINE  ///< @brief 返回描边
};

////////////////////////////////////////////////////////////////////////////////
/// @brief fancy2D 字体绘制监听器
////////////////////////////////////////////////////////////////////////////////
struct f2dFontRendererListener
{
	/// @brief          正准备绘制字形
	/// @param[in]      Index     该字符在文本串中的索引
	/// @param[in]      Character 字符
	/// @param[in][out] DrawPos   起始绘制位置
	/// @param[in][out] Adv       前进量
	/// @return         字形是否被绘制，注意无论是否绘制，前进量仍起作用。
	virtual fBool OnGlyphBeginDraw(fuInt Index, fCharW Character, fcyVec2& DrawPos, fcyVec2& Adv) { return true; }

	/// @brief          绘制字形
	/// @param[in][out] pVerts 顶点数组，大小为4
	virtual void OnGlyphCalcuCoord(f2dGraphics2DVertex pVerts[]) { }
};

////////////////////////////////////////////////////////////////////////////////
/// @brief fancy2D 字体渲染器
////////////////////////////////////////////////////////////////////////////////
struct f2dFontRenderer
{
	/// @brief 返回监听器
	virtual f2dFontRendererListener* GetListener()=0;
	
	/// @brief 设置监听器
	virtual void SetListener(f2dFontRendererListener* pListener)=0;

	/// @brief 返回字形提供者
	virtual f2dFontProvider* GetFontProvider()=0;

	/// @brief     设置字形提供者
	/// @param[in] pProvider 字形提供者，非空
	virtual fResult SetFontProvider(f2dFontProvider* pProvider)=0;

	/// @brief 获得Z值
	virtual fFloat GetZ()=0;

	/// @brief     设置Z值
	/// @param[in] ZValue Z值
	virtual void SetZ(fFloat ZValue)=0;

	/// @brief     获得顶点颜色
	/// @param[in] Index 索引[0~3]
	virtual fcyColor GetColor(fuInt Index)=0;

	/// @brief     设置字体颜色
	/// @param[in] Color 字体颜色
	virtual void SetColor(const fcyColor& Color)=0;

	/// @brief     设置顶点颜色
	/// @param[in] Index 索引[0~3]
	/// @param[in] Color 颜色
	virtual void SetColor(fuInt Index, const fcyColor& Color)=0;

	/// @brief 获得翻转方式
	virtual F2DSPRITEFLIP GetFlipType()=0;

	/// @brief     设置翻转方式
	/// @param[in] Type 翻转方式
	virtual void SetFlipType(F2DSPRITEFLIP Type)=0;

	/// @brief     测量一个字符串最终绘制的大小
	/// @param[in] String 字符串
	virtual fcyVec2 MeasureString(fcStrW String)=0;

	/// @brief     绘制文字
	/// @param[in] pGraph   渲染器
	/// @param[in] Text     文字
	/// @param[in] StartPos 绘制起始基准
	virtual fResult DrawTextW(f2dGraphics2D* pGraph, fcStrW Text, const fcyVec2& StartPos)=0;

	/// @brief     绘制文字
	/// @param[in]  pGraph   渲染器
	/// @param[in]  Text     文字
	/// @param[in]  Count    字数，设为-1则为全部文字
	/// @param[in]  StartPos 绘制起始基准
	/// @param[out] PosOut   绘制终止位置，可空
	virtual fResult DrawTextW(f2dGraphics2D* pGraph, fcStrW Text, fuInt Count, const fcyVec2& StartPos, fcyVec2* PosOut)=0;

	/// @brief      绘制文字
	/// @param[in]  pGraph   渲染器
	/// @param[in]  Text     文字
	/// @param[in]  Count    字数，设为-1则为全部文字
	/// @param[in]  Bias     倾斜角，0为不倾斜
	/// @param[in]  StartPos 绘制起始基准
	/// @param[out] PosOut   绘制终止位置，可空
	virtual fResult DrawTextW(f2dGraphics2D* pGraph, fcStrW Text, fuInt Count, fFloat Bias, const fcyVec2& StartPos, fcyVec2* PosOut)=0;
};

////////////////////////////////////////////////////////////////////////////////
/// @brief fancy2D渲染器
////////////////////////////////////////////////////////////////////////////////
struct f2dRenderer
{
	virtual f2dRenderDevice* GetDevice()=0;  ///< @brief 获得渲染设备指针

	// === 对象创建 ===
	/// @brief      创建Sprite2D
	/// @param[in]  pTex 绑定的纹理
	/// @param[out] pOut 创建的Sprite
	virtual fResult CreateSprite2D(f2dTexture2D* pTex, f2dSprite** pOut)=0;

	/// @brief      创建Sprite2D
	/// @param[in]  pTex 绑定的纹理
	/// @param[in]  Org  原始纹理矩形
	/// @param[out] pOut 创建的Sprite
	virtual fResult CreateSprite2D(f2dTexture2D* pTex, const fcyRect& Org, f2dSprite** pOut)=0;

	/// @brief      创建Sprite2D
	/// @param[in]  pTex    绑定的纹理
	/// @param[in]  Org     原始纹理矩形
	/// @param[in]  HotSopt 热点
	/// @param[out] pOut    创建的Sprite
	virtual fResult CreateSprite2D(f2dTexture2D* pTex, const fcyRect& Org, const fcyVec2& HotSopt, f2dSprite** pOut)=0;

	/// @brief      创建几何体渲染器
	/// @param[out] pOut 输出的渲染器对象
	virtual fResult CreateGeometryRenderer(f2dGeometryRenderer** pOut)=0;

	/// @brief      创建文字渲染器
	/// @param[in]  pProvider 字体源
	/// @param[out] pOut      输出的字体对象
	virtual fResult CreateFontRenderer(f2dFontProvider* pProvider, f2dFontRenderer** pOut)=0;

	/// @brief      从字体文件加载字体
	/// @param[in]  pStream   字体文件
	/// @param[in]  FaceIndex 若有多个Face，可以指定索引。0总是有效值。
	/// @param[in]  Flag      额外选项
	/// @param[out] pOut      返回的字体对象
	virtual fResult CreateFontFromFile(f2dStream* pStream, fuInt FaceIndex, F2DFONTFLAG Flag, f2dFontProvider** pOut)=0;

	/// @brief      从纹理加载字体
	/// @param[in]  pDefineFile 字体文件
	/// @param[in]  pTex        纹理
	/// @param[out] pOut        返回的字体对象
	virtual fResult CreateFontFromTex(f2dStream* pDefineFile, f2dTexture2D* pTex, f2dFontProvider** pOut)=0;
};

/// @}
