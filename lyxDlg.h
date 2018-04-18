// lyxDlg.h : header file
//

#if !defined(AFX_LYXDLG_H__10230638_97AE_48C2_B698_DAA4FE2CEC1A__INCLUDED_)
#define AFX_LYXDLG_H__10230638_97AE_48C2_B698_DAA4FE2CEC1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLyxDlg dialog

class CLyxDlg : public CDialog
{
// Construction
public:
	CLyxDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLyxDlg)
	enum { IDD = IDD_LYX_DIALOG };
	CButton	m_b;
	CString	m_e1;
	CString	m_e2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLyxDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLyxDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LYXDLG_H__10230638_97AE_48C2_B698_DAA4FE2CEC1A__INCLUDED_)
