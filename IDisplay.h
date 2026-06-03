class IDisplay
{
public:
	//Status function
	virtual BOOL	IsWindowed() = 0;
	virtual WORD	GetDisplayWidth() = 0;
	virtual WORD	GetDisplayHeight() = 0;

	//Creation/destruction methods
	virtual HRESULT	CreateFullScreenDisplay(HWND hWnd, int nScreenType) = 0;
	virtual HRESULT CreateWindowedDisplay(HWND hWnd, int nScreenType) = 0;
	virtual HRESULT	UpdateBounds() = 0;
	virtual HRESULT	DestroyObjects() = 0;
	virtual HRESULT	RestoreAllSurfaces() = 0;

	//Display methods
	virtual HRESULT	ClearScreen(DWORD dwColor) = 0;
	virtual HRESULT	UpdateScreen() = 0;

	//Image utilities
public:
	virtual HIMG	SelectImage(TImage *pImage) = 0;
	virtual HIMG	GenImageHandle(int w, int h, int attrib) = 0;
	virtual void	UpdateImage(HIMG hImg, int left, int top, TImage *pImage) = 0;
//-	virtual void	DrawImage(int left, int top, HIMG hImg) = 0;
	virtual void	ReleaseImageHandle(HIMG hImg) = 0;
	
	//Jim, added [11/27/2003]
	//{{{
	virtual int		GetImageWidth(HIMG hImg) = 0;
	virtual int		GetImageHeight(HIMG hImg) = 0;
//-	virtual void	DrawImageColor(int left, int top, HIMG hImg, DWORD dwColor) = 0;
	//}}}

	//czy, added [12/16/2003]
	//image特效
	virtual void	DrawImage( int left, int top, HIMG hImg, DWORD effect=0, DWORD dwColor=0xffffffff) = 0;
	virtual void	SetImageCenter( float centerX, float centerY) = 0;
	virtual void	SetImageScale( float scaleX, float scaleY) = 0;
	virtual void	SetImageRotate( float degree) = 0;

	//czy, added [1/8/2004]
	//将屏幕的 Back 缓存上的一个矩形，生成一个新的贴图
	// SnapScreen 有一个暂时无法解决的bug: 上下颠倒了，要用fxGeoMirrorY画才行
	virtual HIMG	SnapScreen( int left, int top, int width, int height)=0;
	virtual TImage*	SnapScreen2( int left, int top, int width, int height)=0;
	
	//czy, added [3/8/2004]
	//设置: 创建纹理时，对纹理过滤方式，是否使用线性插值。返回值：设置前的状态
	virtual bool	EnableTexLinear( bool flag)=0;
	
	//czy, added [2/6/2004]
	//设置剪裁矩形.
	virtual void	SetClipRect( int left, int top, int width, int height)=0;
	virtual void	GetClipRect( int&left, int&top, int&width, int&height)=0;
	
	virtual void	EnableClipRect( bool flag)=0;	
	virtual bool	IsClipEnable()=0;
	
	//add+lincoln
	//[2005:1:18] [16:34]
	//增加裁减状态堆栈	
	//{{{	
	virtual void	PushClipState(){}//保存当前裁减状态
	virtual void	PopClipState(){}//恢复之前保存的裁减状态
	virtual void	PushClipRect(int left, int top, int width, int height){}//保存当前状态，开启裁减，设置裁减矩形为：当前裁减rect和指定rect的交集
	//}}}

	virtual void	SetMaxTex( int size)=0;		//512, 1024, 2048
public:
	virtual void	DrawPixel(int x, int y, DWORD dwColor) = 0;
	virtual void	DrawLine(int x1, int y1, int x2, int y2, DWORD dwColor) = 0;
	virtual void	DrawPolygon( int numPoints, const float* xy, DWORD dwColor) = 0;
	virtual void	DrawPolygon( int numPoints, const float* xy, DWORD* dwColor) = 0;
	
	virtual void	DrawBar(int left, int top, int width, int height, DWORD dwColor) = 0;
	virtual void	DrawBox(int left, int top, int width, int height, DWORD dwColor) = 0;
//	virtual void    DrawImageArc(int left,int top,int angle,int rot,HIMG hImg,DWORD effect = 0,DWORD dwColor=0xffffffff)=0;
public:	
	//单行文本
	virtual void	DrawText( int sx, int sy, const char* strText, DWORD dwColor, int size, UINT flags=0) = 0;
	//czy, added [12/16/2003]
	virtual void	DrawTextEx( int left, int top, int width, int height, 
							    const char* str, int size, int space=0, 
							    DWORD dwColor=0xffffffff, UINT flags=0) = 0;
	
	//显示控制字符串：控制字符为 " ~C0", "~C1", …"~C9"。
	virtual void	DrawCtrlText( int left, int top, int width, int height, 
								const char* str, int size, int space, UINT flags)=0;

	//设置控制字符颜色：	colorIdx取值为0到MAX_TEXT_COLOR。返回原来该索引对应的颜色值
	virtual DWORD	SetCtrlTextColor( int colorIdx, DWORD dwColor )=0;

	//设置当前使用的字体：	0-明流 1-粗圆。	返回原来使用的字体类型
	virtual int		SetFont( int fontType)=0;

	//将字符串中的控制字符去掉
	virtual void	ClearCtrl( const char* ctrlStr, char* result)=0;
	
	//返回字符串的显示高度（单位：象素）
	virtual int		EstimateLine( const char* str, int width, int size, int space=0) = 0;
	
	//根据多行字符串str,和字符尺寸size, 求出显示所占矩形的大小。
	//width、height值分别为字符串最大宽度、字符串高度（单位：象素）
	//space是行间距
	virtual void	EstimateLine( const char* str, int size, int space, int& width, int& height) = 0;

/*	//czy, deleted [3/15/2004]
	//设置行距，并返回设置前的行距。缺省行距为0。
	virtual int		SetRowSpace( int) = 0;
	//返回当前的行距。缺省行距为0。
	virtual int		GetRowSpace() = 0;
*/

	//delta add[9/6/2004]
	virtual DWORD   GetCtrlTextColor( int colorIdx ) = 0;
	virtual void    DrawPixels( int ox, int oy, TImage *pimage ) = 0;

    //qjb add[12/29/2004]
    virtual HIMG    GenRotateImageHandle(TImage *pImage, int nArf, int nCenterx=0, int nCentery=0) = 0;
    virtual HIMG    GenScaleImageHandle(TImage *pImage, float fscalex, float fscaley) = 0;
    virtual bool    SaveGsoFile(HIMG hImg, char* szFileName) = 0;
};
