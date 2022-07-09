// Dlg_bmp.cpp : 実装ファイル
//

#include "pch.h"
#include "Scroll_bmp.h"
#include "Dlg_bmp.h"
#include "afxdialogex.h"


// Dlg_bmp ダイアログ

IMPLEMENT_DYNAMIC(Dlg_bmp, CDialogEx)

Dlg_bmp::Dlg_bmp(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BMPScroll, pParent)
{
    fBlt = TRUE;// FALSE;
    fScroll = FALSE;
    fSize = FALSE;

    // Initialize the horizontal scrolling variables. 
    xMinScroll = 0;
    xCurrentScroll = 0;
    xMaxScroll = 0;

    // Initialize the vertical scrolling variables. 
    yMinScroll = 0;
    yCurrentScroll = 0;
    yMaxScroll = 0;
    m_dlgon = 0;
    m_one = false;

    erase = false;

}

Dlg_bmp::~Dlg_bmp()
{
}

void Dlg_bmp::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Dlg_bmp, CDialogEx)
    ON_WM_HSCROLL()
    ON_WM_VSCROLL()
    ON_WM_SIZE()
    ON_WM_PAINT()
    ON_WM_RBUTTONDOWN()
    ON_WM_ERASEBKGND()
END_MESSAGE_MAP()
// Dlg_bmp メッセージ ハンドラー
BOOL Dlg_bmp::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // TODO: ここに初期化を追加してください
    EnableScrollBarCtrl(SB_BOTH, FALSE);//非表示
//	EnableScrollBarCtrl(SB_BOTH, TRUE);//表示
//	EnableScrollBarCtrl(SB_HORZ, TRUE);//
//	EnableScrollBarCtrl(SB_HORZ, FALSE);//
//	EnableScrollBarCtrl(SB_VERT, TRUE);//
//	EnableScrollBarCtrl(SB_VERT, FALSE);//
#if 1    
    CFileDialog dlg(TRUE, _T("G:\\"), NULL, 0, _T("*.bmp|*.*"));
    if (dlg.DoModal() == IDOK)
    {
        // 開くボタンを押下した場合
        m_fullPathName = dlg.GetPathName();
        //MessageBox(m_fullPathName);
    }
    else
    {
        // キャンセルボタンを押下した場合
        return TRUE;
    }
#endif    
    CRect r;
    GetClientRect(&r);
    r.right = 500;
    r.bottom = 400;
    MoveWindow(&r);
    this->CenterWindow();

    fSize = TRUE;
    m_dlgon = 1;
    return TRUE;  // return TRUE unless you set the focus to a control
                  // 例外 : OCX プロパティ ページは必ず FALSE を返します。
}


void Dlg_bmp::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    // TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。
#if 1
 //	MessageBox(_T("H"));
    CRect r;
    int xDelta;     // xDelta = new_pos - current_pos  
    int xNewPos;    // new position 
    int yDelta = 0;
    switch (nSBCode)//LOWORD(wParam))
    {
        // User clicked the scroll bar shaft left of the scroll box. 
    case SB_PAGEUP:
        xNewPos = xCurrentScroll - 50;
        break;

        // User clicked the scroll bar shaft right of the scroll box. 
    case SB_PAGEDOWN:
        xNewPos = xCurrentScroll + 50;
        break;

        // User clicked the left arrow. 
    case SB_LINEUP:
        xNewPos = xCurrentScroll - 5;
        break;

        // User clicked the right arrow. 
    case SB_LINEDOWN:
        xNewPos = xCurrentScroll + 5;
        break;

        // User dragged the scroll box. 
    case SB_THUMBPOSITION:
        xNewPos = nPos;// HIWORD(wParam);
        break;
        //追加
#if 1    
    case SB_THUMBTRACK:

        xNewPos = nPos;// HIWORD(wParam);
        break;
#endif

    default:
        xNewPos = xCurrentScroll;
    }
    // New position must be between 0 and the screen width. 
    xNewPos = max(0, xNewPos);
    xNewPos = min(xMaxScroll, xNewPos);

    // If the current position does not change, do not scroll.
    if (xNewPos == xCurrentScroll) {
        return;// break;
    }
    //    m_str = _T("OnHScroll"); SetWindowText(m_str);// MessageBox(_T("OnHScroll"));
        // Set the scroll flag to TRUE. 
    fScroll = TRUE;

    // Determine the amount scrolled (in pixels). 
    xDelta = xNewPos - xCurrentScroll;

    // Reset the current scroll position. 
    xCurrentScroll = xNewPos;

    ScrollWindowEx(-xDelta, -yDelta, (CONST RECT*) NULL,
        (CONST RECT*) NULL, NULL, (PRECT)NULL,
        SW_INVALIDATE);
    UpdateWindow();

    // Reset the scroll bar. 
    si.cbSize = sizeof(si);
    si.fMask = SIF_POS;
    si.nPos = xCurrentScroll;
    SetScrollInfo(SB_HORZ, &si, TRUE);
#endif
    erase = true;
    CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void Dlg_bmp::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    // TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。
//	MessageBox(_T("V"));
#if 1

    CRect r;
    int xDelta = 0;
    int yDelta;     // yDelta = new_pos - current_pos 
    int yNewPos;    // new position 

    switch (nSBCode)//LOWORD(wParam))
    {
        // User clicked the scroll bar shaft above the scroll box. 
    case SB_PAGEUP:
        yNewPos = yCurrentScroll - 50;
        break;

        // User clicked the scroll bar shaft below the scroll box. 
    case SB_PAGEDOWN:
        yNewPos = yCurrentScroll + 50;
        break;

        // User clicked the top arrow. 
    case SB_LINEUP:
        yNewPos = yCurrentScroll - 5;
        break;

        // User clicked the bottom arrow. 
    case SB_LINEDOWN:
        yNewPos = yCurrentScroll + 5;
        break;

        // User dragged the scroll box. 
    case SB_THUMBPOSITION:
        yNewPos = nPos;// HIWORD(wParam);
        break;
        //追加
#if 1   
    case SB_THUMBTRACK:

        yNewPos = nPos;// HIWORD(wParam);
        break;
#endif
    default:
        yNewPos = yCurrentScroll;
    }
    // New position must be between 0 and the screen height. 
    yNewPos = max(0, yNewPos);
    yNewPos = min(yMaxScroll, yNewPos);

    // If the current position does not change, do not scroll.
    if (yNewPos == yCurrentScroll) {
        return;// break;
    }
    //    m_str = _T("OnVScroll"); SetWindowText(m_str);// MessageBox(_T("OnVScroll"));
        // Set the scroll flag to TRUE. 
    fScroll = TRUE;

    // Determine the amount scrolled (in pixels). スクロール量を決定する
    yDelta = yNewPos - yCurrentScroll;

    // Reset the current scroll position. 
    yCurrentScroll = yNewPos;

    ScrollWindowEx(-xDelta, -yDelta, (CONST RECT*) NULL,
        (CONST RECT*) NULL, NULL, NULL,// (HRGN)NULL, (PRECT)NULL,
        SW_INVALIDATE);
    UpdateWindow();

    // Reset the scroll bar. 
    si.cbSize = sizeof(si);
    si.fMask = SIF_POS;
    si.nPos = yCurrentScroll;
    SetScrollInfo(SB_VERT, &si, TRUE);
#endif
    erase = true;// set_scbar();
    CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


void Dlg_bmp::OnSize(UINT nType, int cx, int cy)
{
    CDialogEx::OnSize(nType, cx, cy);
    //    return;
        // TODO: ここにメッセージ ハンドラー コードを追加します。
    //	MessageBox(_T("OnSize"));
    if (m_dlgon == 0)return;
    int xNewSize;
    int yNewSize;

    xNewSize = cx;// LOWORD(lParam);
    yNewSize = cy;// HIWORD(lParam);
    m_OnSizex = cx;// LOWORD(lParam);
    m_OnSizey = cy;// HIWORD(lParam); 
    if (fBlt)
        fSize = TRUE;
    //更新の為追加
    CRect r;
    GetClientRect(&r);
    InvalidateRect(&r);
    //追加end
        // The horizontal scrolling range is defined by 
        // (bitmap_width) - (client_width). The current horizontal 
        // scroll value remains within the horizontal scrolling range. 
    xMaxScroll = max(m_bmInfo.bmWidth - xNewSize, 0);
    xCurrentScroll = min(xCurrentScroll, xMaxScroll);
    si.cbSize = sizeof(si);
    si.fMask = SIF_RANGE | SIF_PAGE | SIF_POS;
    //    si.fMask = SIF_RANGE | SIF_PAGE | SIF_POS | SIF_DISABLENOSCROLL;
    si.nMin = xMinScroll;
    si.nMax = m_bmInfo.bmWidth;
    si.nPage = xNewSize;
    si.nPos = xCurrentScroll;
    SetScrollInfo(SB_HORZ, &si, TRUE);

    // The vertical scrolling range is defined by 
    // (bitmap_height) - (client_height). The current vertical 
    // scroll value remains within the vertical scrolling range. 
    yMaxScroll = max(m_bmInfo.bmHeight - yNewSize, 0);
    yCurrentScroll = min(yCurrentScroll, yMaxScroll);
    si.cbSize = sizeof(si);
    si.fMask = SIF_RANGE | SIF_PAGE | SIF_POS;
    si.nMin = yMinScroll;
    si.nMax = m_bmInfo.bmHeight;
    si.nPage = yNewSize;
    si.nPos = yCurrentScroll;
    SetScrollInfo(SB_VERT, &si, TRUE); 
}
void Dlg_bmp::OnPaint()
{
    CPaintDC dc(this); // device context for painting
                       // TODO: ここにメッセージ ハンドラー コードを追加します。
                       // 描画メッセージで CDialogEx::OnPaint() を呼び出さないでください。
//    return;
    CRect r;//dumy
//    PRECT prect;
//    hdc = BeginPaint(hwnd, &ps);
    //読み込む画像ファイルパス
    CImage img;
    HRESULT ret = img.Load(m_fullPathName);
    if (img.IsNull()) {
        MessageBox(_T("NG"));
        return;
    }
        //CDC* cdc;
        //cdc = m_st1.GetDC();//cstatic

    CDC bmpDC;
    CBitmap* cbmp;
    cbmp = CBitmap::FromHandle(img);
    bmpDC.CreateCompatibleDC(&dc); 
    //bmpDC.CreateCompatibleDC(cdc);
    CBitmap* oldbmp = bmpDC.SelectObject(cbmp);
    //伸縮すると画像が汚くなるので伸縮モードを指定
    //詳細はMSDN参照
    dc.SetStretchBltMode(STRETCH_HALFTONE);
    //cdc->SetStretchBltMode(STRETCH_HALFTONE);
    //ブラシのずれを防止するためSetBrushOrgExを呼び出す
    dc.SetBrushOrg(0, 0);
    //cdc->SetBrushOrg(0, 0);
    //画像を伸縮してピクチャーボックスに表示
    //拡大と縮小=StretchBlt
    //cdc->StretchBlt(0, 0, iWidth, iHeight, &bmpDC, 0, 0, img.GetWidth(), img.GetHeight(), SRCCOPY);
    cbmp->GetObject(sizeof(BITMAP), &m_bmInfo);//bitmap幅高さ等取得。
    m_xp = 0; m_yp =0;
   if (fSize)//OnSize
    {
        if (m_bmInfo.bmWidth == xCurrentScroll + m_OnSizex ||
            m_bmInfo.bmHeight == yCurrentScroll + m_OnSizey)
        {
            m_str.Format(_T("ov%d %d %d-%d %d %d"), m_bmInfo.bmWidth, xCurrentScroll, m_OnSizex, m_bmInfo.bmHeight, yCurrentScroll, m_OnSizey); SetWindowText(m_str);// MessageBox(_T("OnVScroll"));
            //引き出す様に表示
            dc.BitBlt(
            //cdc->BitBlt(
                    0, 0,
                //m_bmInfo.bmWidth, m_bmInfo.bmHeight,
                //xCurrentScroll + m_OnSizex, yCurrentScroll + m_OnSizey,
                m_OnSizex-m_xp, m_OnSizey- m_yp ,
                &bmpDC,//hdcScreenCompat,
                xCurrentScroll, yCurrentScroll,
                //m_bmInfo.bmWidth-xCurrentScroll, m_bmInfo.bmHeight-yCurrentScroll,
                SRCCOPY);
        }
        else {
            m_str.Format(_T("%d %d %d-%d %d %d"), m_bmInfo.bmWidth, xCurrentScroll, m_OnSizex, m_bmInfo.bmHeight, yCurrentScroll, m_OnSizey); SetWindowText(m_str);// MessageBox(_T("OnVScroll"));
            dc.BitBlt(
            //cdc->BitBlt(
                0, 0,
                m_bmInfo.bmWidth- m_xp , m_bmInfo.bmHeight- m_yp,
                &bmpDC,//hdcScreenCompat,
                xCurrentScroll, yCurrentScroll ,
                SRCCOPY);
        }
        fSize = FALSE;
    }
    // If scrolling has occurred, use the following call to 
    // BitBlt to paint the invalid rectangle. 
    // 
    // The coordinates of this rectangle are specified in the 
    // RECT structure to which prect points. 
    // 
    // Note that it is necessary to increment the seventh 
    // argument (prect->left) by xCurrentScroll and the 
    // eighth argument (prect->top) by yCurrentScroll in 
    // order to map the correct pixels from the source bitmap. 
#if 1

    if (fScroll)//スクロールされた
    {

        //       m_str = _T("OnPaint()fScroll"); SetWindowText(m_str);// MessageBox(_T("OnVScroll"));

        dc.BitBlt(
        //cdc->BitBlt(
            0, 0,
            m_OnSizex-m_xp, m_OnSizey-m_yp,
            &bmpDC,//hdcScreenCompat,
            xCurrentScroll, yCurrentScroll,
            SRCCOPY);
        fScroll = FALSE;
    }
#endif
    //    EndPaint(hwnd, &ps);
    bmpDC.SelectObject(oldbmp);
    //後片付け
    cbmp->DeleteObject();
    bmpDC.DeleteDC();
    ReleaseDC(&dc); 
    //ReleaseDC(cdc);
//    EnableScrollBarCtrl(SB_BOTH, TRUE);//表示
//    set_scbar();
    erase = false;
    if (m_one == FALSE) {//起動時スクロールバーが表示されないので追加
        EnableScrollBarCtrl(SB_BOTH, TRUE);
        m_one = TRUE;
    }
}
void Dlg_bmp::OnRButtonDown(UINT nFlags, CPoint point)
{
    //クライアント領域を右クリックすると、画面の内容がキャプチャされます。
    return;
    CDialogEx::OnRButtonDown(nFlags, point);
}
//最初ちらつく。
BOOL Dlg_bmp::OnEraseBkgnd(CDC* pDC)
{
    // TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。
    if (erase)
        return false;
    return CDialogEx::OnEraseBkgnd(pDC);
}