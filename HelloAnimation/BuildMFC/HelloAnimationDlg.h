
// HelloAnimationDlg.h : header file
//

#pragma once
extern void startHelloAnimation(void* phy_fb, int width, int height, int color_bytes);
extern int sendTouch2HelloAnimation(void* buf, int len);
extern void* getUiOfHelloAnimation(int* width, int* height, bool force_update = false);

typedef struct
{
	unsigned int dwMsgId;
	unsigned int dwParam1;
	unsigned int dwParam2;
}OUTMSGINFO;

typedef struct tagMYBITMAPINFO {
	BITMAPINFOHEADER    bmiHeader;
	DWORD				biRedMask;
	DWORD				biGreenMask;
	DWORD				biBlueMask;
} MYBITMAPINFO;

// CHelloAnimationDlg dialog
class CHelloAnimationDlg : public CDialogEx
{
// Construction
public:
	CHelloAnimationDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HELLOSLIDE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()

private:
	void updateUI(CDC* pDC);
	CPoint pointMFC2GuiLite(CPoint point);
	static UINT ThreadHelloAnimation(LPVOID pParam);
	static UINT ThreadRefreshUI(LPVOID pParam);
	static CHelloAnimationDlg* m_the_dialog;
	CRect m_block_rect;
	int m_ui_width;
	int m_ui_height;
	int m_color_bytes;
	CBitmap		m_blockBmp;
	MYBITMAPINFO m_ui_bm_info;
	CDC			m_memDC;
	bool m_is_mouse_down;
};
