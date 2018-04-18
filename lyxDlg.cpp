// lyxDlg.cpp : implementation file
//

#include "stdafx.h"
#include "lyx.h"
#include "lyxDlg.h"
#include <atlconv.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
static CFont font;
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
	
	// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA
	
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	
	// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
//{{AFX_MSG_MAP(CAboutDlg)
// No message handlers
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLyxDlg dialog

CLyxDlg::CLyxDlg(CWnd* pParent /*=NULL*/)
: CDialog(CLyxDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLyxDlg)
	m_e1 = _T("");
	m_e2 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLyxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLyxDlg)
	DDX_Control(pDX, IDC_BUTTON1, m_b);
	DDX_Text(pDX, IDC_EDIT1, m_e1);
	DDX_Text(pDX, IDC_EDIT2, m_e2);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLyxDlg, CDialog)
//{{AFX_MSG_MAP(CLyxDlg)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLyxDlg message handlers

BOOL CLyxDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	// Add "About..." menu item to system menu.
	font.CreatePointFont(200,"黑体");
	GetDlgItem(IDC_STATIC1)->SetFont(&font);
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLyxDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLyxDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLyxDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CLyxDlg::OnButton1() 
{
	UpdateData();
	// TODO: Add your control notification handler code here
	int bmpHeight;  
    int bmpWidth;  
    unsigned char *pBmpBuf;  
    RGBQUAD *pColorTable;  
    int biBitCount;  
	
	CString key;
	GetDlgItemText(IDC_EDIT1,key);
	
	USES_CONVERSION;  
	
	char* keyChar = T2A(key.GetBuffer(0));
	key.ReleaseBuffer();
	FILE *fp=fopen(keyChar,"rb"); 
	system(keyChar);
	while (!fp) {
        MessageBox ("文件路径错误，兄dei！","错误提示",MB_OKCANCEL);
        system("pause");
		exit(0);   
    }
	
    fseek(fp,sizeof(BITMAPFILEHEADER),0);  
	
    BITMAPINFOHEADER head;  
    fread(&head,40,1,fp);  
    bmpHeight=head.biHeight;  
    bmpWidth=head.biWidth;  
    biBitCount=head.biBitCount;  
	
    if(biBitCount==8) {  
        pColorTable=new RGBQUAD[256];  
        fread(pColorTable,sizeof(RGBQUAD),256,fp);  
    }  
    int LineByte=(bmpWidth*biBitCount/8+3)/4*4; 
    pBmpBuf=new unsigned char[LineByte*bmpHeight];  
    fread(pBmpBuf,LineByte*bmpHeight,1,fp);  
    fclose(fp);  
	
	CString key2;
	GetDlgItemText(IDC_EDIT2,key2);
	char* keyChar2 = T2A(key2.GetBuffer(0));
	key2.ReleaseBuffer();
	CString strMsg;
	strMsg.Format("%s",keyChar2);
	MessageBox("输出路径"+strMsg+"正确！！！","转换成功老铁！",MB_OKCANCEL );
	
	FILE *fp1=fopen(keyChar2,"wb");  
	
    int LineByte1=(bmpWidth*8/8+3)/4*4;  
	
    BITMAPFILEHEADER bfhead;  
    bfhead.bfType=0x4D42;  
    bfhead.bfSize=14+40+256*sizeof(RGBQUAD)+LineByte1*bmpHeight;  
    bfhead.bfReserved1=0;  
    bfhead.bfReserved2=0;  
    bfhead.bfOffBits=14+40+256*sizeof(RGBQUAD); 
    fwrite(&bfhead,14,1,fp1);    
	
    BITMAPINFOHEADER head1;  
    head1.biBitCount=8;    
    head1.biClrImportant=0;  
    head1.biCompression=0;  
    head1.biClrUsed=0;  
    head1.biHeight=bmpHeight;  
    head1.biWidth=bmpWidth;  
    head1.biPlanes=1;  
    head1.biSize=40;  
    head1.biSizeImage=LineByte1*bmpHeight;
    head1.biXPelsPerMeter=0;  
    head1.biYPelsPerMeter=0;  
    fwrite(&head1,40,1,fp1);    
	
    if(biBitCount==24){  
        pColorTable=new RGBQUAD[256];  
        for (int  i = 0; i < 256; i++ ){
            pColorTable[i].rgbRed = pColorTable[i].rgbGreen = pColorTable[i].rgbBlue = i; 	
		}
    }  
    fwrite(pColorTable,sizeof(RGBQUAD),256,fp1);  
	
    unsigned char *pBmpBuf1;  
    pBmpBuf1= new unsigned char[LineByte1*bmpHeight];  
    for(int i=0;i<bmpHeight;i++)  {
        for(int j=0;j<bmpWidth;j++) {  
            unsigned char *pb1,*pb2;  
            pb1=pBmpBuf+i*LineByte+(j+28)*3;  
            int y=*(pb1)*0.299+*(pb1+1)*0.587+*(pb1+2)*0.114;   
            pb2=pBmpBuf1+i*LineByte1+j;  
            *pb2=y;  
		}
	}  
	if(biBitCount==8)  
		fwrite(pBmpBuf,LineByte*bmpHeight,1,fp1);  
	else  
		fwrite(pBmpBuf1,LineByte1*bmpHeight,1,fp1);  		
	fclose(fp1);  
}
