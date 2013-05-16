////////////////////////////////////////////////////////////////////////////////
/// @file  f2dRenderDeviceImpl.h
/// @brief fancy2D渲染设备接口实现
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include "f2dRenderDeviceAPI.h"

#include "../Engine/f2dWindowImpl.h"

class f2dEngineImpl;

////////////////////////////////////////////////////////////////////////////////
/// @brief fancy2D渲染设备实现
////////////////////////////////////////////////////////////////////////////////
class f2dRenderDeviceImpl :
	public fcyRefObjImpl<f2dRenderDevice>
{
private:
	struct ListenerNode
	{
		f2dRenderDeviceEventListener* pListener;
		ListenerNode* pNext;
	};
private:
	f2dEngineImpl* m_pEngine;

	// API入口
	f2dRenderDeviceAPI m_API;

	// DirectX组件
	IDirect3D9* m_pD3D9;
	IDirect3DDevice9* m_pDev;
	D3DPRESENT_PARAMETERS m_D3Dpp;
	D3DVIEWPORT9 m_ViewPort;
	std::string m_DevName;
	
	// 监听器链表
	ListenerNode* m_ListenerList;

	// 设备状态
	bool m_bDevLost;                              // 设备丢失标志
	IDirect3DSurface9* m_pBackBuffer;             // 后备渲染目标
	IDirect3DSurface9* m_pBackDepthBuffer;        // 后备深度模板缓冲
	RECT m_ScissorRect;                           // 裁剪矩形
	
	f2dTexture2D* m_pCurBackBuffer;               // 记录当前的后备缓冲区
	f2dDepthStencilSurface* m_pCurBackDepthBuffer;// 记录当前的后备深度缓冲区

	f2dGraphics* m_pCurGraphics;   // 当前的绘图对象，只记录指针
	fcyMatrix4 m_CurWorldMat;      // 当前世界矩阵
	fcyMatrix4 m_CurLookatMat;     // 当前观察矩阵
	fcyMatrix4 m_CurProjMat;       // 当前投影矩阵
	f2dBlendState m_CurBlendState; // 当前混合状态

	// Window
	HWND m_hWnd;
	f2dWindowDC m_DC;
	IDirect3DSurface9* m_pWinSurface;
private:
	void initState();         // 初始化状态
	int sendDevLostMsg();     // 发送设备丢失事件, 返回对象数目
	int sendDevResetMsg();    // 发送设备重置事件
public: // 内部函数
	f2dRenderDeviceAPI& GetAPI() { return m_API; }   // 返回API对象
	f2dEngineImpl* GetEngine() { return m_pEngine; } // 返回引擎对象
	fResult SyncDevice();                           // 协作测试，完成设备丢失处理
	fResult Present();                              // 呈现

	// 立即递交状态
	f2dGraphics* QueryCurGraphics() { return m_pCurGraphics; }
	fResult SubmitCurGraphics(f2dGraphics* pGraph, bool bDirty);  // 同步Graphics状态到设备
	fResult SubmitWorldMat(const fcyMatrix4& Mat);                // 立即提交世界变换矩阵
	fResult SubmitLookatMat(const fcyMatrix4& Mat);               // 立即提交观察矩阵
	fResult SubmitProjMat(const fcyMatrix4& Mat);                 // 立即提交投影矩阵
	fResult SubmitBlendState(const f2dBlendState& State);         // 立即提交混合状态
public: // 接口实现
	void* GetHandle() { return m_pDev; }
	fcStr GetDeviceName() { return m_DevName.c_str(); }
	fuInt GetBufferWidth() { return m_D3Dpp.BackBufferWidth; }
	fuInt GetBufferHeight() { return m_D3Dpp.BackBufferHeight; }
	fBool IsWindowed() { return m_D3Dpp.Windowed == TRUE ? 1 : 0; }
	F2DAALEVEL GetAALevel();
	fBool CheckMultiSample(F2DAALEVEL AALevel, fBool Windowed);
	fuInt GetSupportResolutionCount();
	fcyVec2 EnumSupportResolution(fuInt Index);
	fResult SetBufferSize(fuInt Width, fuInt Height, fBool Windowed, fBool VSync, F2DAALEVEL AALevel);

	fResult AttachListener(f2dRenderDeviceEventListener* Listener);
	fResult RemoveListener(f2dRenderDeviceEventListener* Listener);

	fResult CreateTextureFromStream(f2dStream* pStream, fuInt Width, fuInt Height, fBool IsDynamic, fBool HasMipmap, f2dTexture2D** pOut);
	fResult CreateDynamicTexture(fuInt Width, fuInt Height, f2dTexture2D** pOut);
	fResult CreateRenderTarget(fuInt Width, fuInt Height, fBool AutoResize , f2dTexture2D** pOut);
	fResult CreateDepthStencilSurface(fuInt Width, fuInt Height, fBool Discard, fBool AutoResize, f2dDepthStencilSurface** pOut);
	fResult CreateGraphics2D(fuInt VertexBufferSize, fuInt IndexBufferSize, f2dGraphics2D** pOut);
	fResult CreateGraphics3D(f2dEffect* pDefaultEffect, f2dGraphics3D** pOut);
	fResult CreateEffect(f2dStream* pStream, f2dEffect** pOut, f2dStream** pErrOut = NULL);

	fResult Clear(const fcyColor& BackBufferColor = 0, fFloat ZValue = 1.0f);
	fResult Clear(const fcyColor& BackBufferColor = 0, fFloat ZValue = 1.0f, fuInt StencilValue = 0);
	fResult ClearColor(const fcyColor& BackBufferColor = 0);
	fResult ClearZBuffer(fFloat Value=1.0f);
	fResult ClearStencilBuffer(fuInt StencilValue=0);
	f2dTexture2D* GetRenderTarget();
	fResult SetRenderTarget(f2dTexture2D* pTex);
	f2dDepthStencilSurface* GetDepthStencilSurface();
	fResult SetDepthStencilSurface(f2dDepthStencilSurface* pSurface);
	fcyRect GetScissorRect();
	fResult SetScissorRect(const fcyRect& pRect);

	fResult SaveScreen(f2dStream* pStream);
	fResult SaveTexture(f2dStream* pStream, f2dTexture2D* pTex);
	fResult UpdateScreenToWindow(fcyColor KeyColor, fByte Alpha);
public:
	f2dRenderDeviceImpl(f2dEngineImpl* pEngine, fuInt BackBufferWidth, fuInt BackBufferHeight, fBool Windowed, fBool VSync, F2DAALEVEL AALevel);
	~f2dRenderDeviceImpl();
};
