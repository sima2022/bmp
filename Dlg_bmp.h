#pragma once


// Dlg_bmp ダイアログ

class Dlg_bmp : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg_bmp)

public:
	Dlg_bmp(CWnd* pParent = nullptr);   // 標準コンストラクター
	virtual ~Dlg_bmp();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BMPScroll };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
    virtual BOOL OnInitDialog();
    afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
    afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg void OnPaint();

public:
    HDC hdc;
    PAINTSTRUCT ps;
    SCROLLINFO si;

#if 0    
    // These variables are required by BitBlt. 

    /*static*/ HDC hdcWin;           // window DC 
    /*static*/ HDC hdcScreen;        // DC for entire screen
    /*static*/ HDC hdcScreenCompat;  // memory DC for screen 
    /*static*/ HBITMAP hbmpCompat;   // bitmap handle to old DC 
    /*static*/ BITMAP bmp;           // bitmap data structure 
    /*static*/ BOOL fBlt;            // TRUE if BitBlt occurred 
    /*static*/ BOOL fScroll;         // TRUE if scrolling occurred 
    /*static*/ BOOL fSize;           // TRUE if fBlt & WM_SIZE 

    // These variables are required for horizontal scrolling. 
    /*static*/ int xMinScroll;       // minimum horizontal scroll value 
    /*static*/ int xCurrentScroll;   // current horizontal scroll value 
    /*static*/ int xMaxScroll;       // maximum horizontal scroll value 

    // These variables are required for vertical scrolling. 
    /*static*/ int yMinScroll;       // minimum vertical scroll value 
    /*static*/ int yCurrentScroll;   // current vertical scroll value 
    /*static*/ int yMaxScroll;       // maximum vertical scroll value 
#endif
     BOOL fBlt;            // TRUE if BitBlt occurred 
     BOOL fScroll;         // TRUE if scrolling occurred 
     BOOL fSize;           // TRUE if fBlt & WM_SIZE 

    // These variables are required for horizontal scrolling. 
     int xMinScroll;       // minimum horizontal scroll value 
     int xCurrentScroll;   // current horizontal scroll value 
     int xMaxScroll;       // maximum horizontal scroll value 

    // These variables are required for vertical scrolling. 
     int yMinScroll;       // minimum vertical scroll value 
     int yCurrentScroll;   // current vertical scroll value 
     int yMaxScroll;       // maximum vertical scroll value 

//追加
    CString m_fullPathName;
    BITMAP m_bmInfo;
    CString m_str;
    int m_OnSizex;
    int m_OnSizey;
    CRect m_r;
    int m_dlgon;
    BOOL erase;
    afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
public:
    int m_pattern;
    int m_resize_x;
    int m_resize_y;
    int m_xp;
    int m_yp;
    bool m_one;
};
