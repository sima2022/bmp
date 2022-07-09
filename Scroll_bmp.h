
// Scroll_bmp.h : Scroll_bmp アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル


// CScrollbmpApp:
// このクラスの実装については、Scroll_bmp.cpp を参照してください
//

class CScrollbmpApp : public CWinAppEx
{
public:
	CScrollbmpApp() noexcept;


// オーバーライド
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 実装
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CScrollbmpApp theApp;
