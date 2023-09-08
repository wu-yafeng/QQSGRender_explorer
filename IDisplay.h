#include <Windows.h>
class ISwapChain
{
public:
    virtual void Free( bool) = 0;
    virtual int SetRenderTarget() = 0;
    virtual int Present() = 0;
    // todo
};

enum SURFACE_FORMAT
{
   A1R5G5B5 = 0,
   A4R4G4B4 = 1,
   A8R8G8B8 = 2,
   DXT1 = 3,
   DXT3 = 4,
   DXT5 = 5
}

struct TextureSurface
{
    int Width;
    int Height;
    int SrcPitch;
    // The surface format
    SURFACE_FORMAT Format;
    // The Surface Mem
    char SrcMem[256];
};

class IDisplay
{
public:
    virtual void Free(bool free) = 0;
    virtual bool IsWindowMode() = 0;
    virtual int GetBackBufferWidth() = 0;
    virtual int GetBackBufferHeight() = 0;
    virtual int GetDrawCall() = 0;
    virtual int CreateFullScreenDevice(HWND hWnd, int screenType) = 0;
    virtual int CreateWindowDevice(HWND hWnd, int screenType) = 0;
    virtual int InitSwapChain(HWND hWnd, int screenType) = 0;
    virtual int ResetDevice() = 0;
    virtual int ReleaseDevice() = 0;
    virtual int ClearDevice() = 0;
    virtual int BeginScene(int swapChainIdx) = 0;
    virtual int EndScene() = 0;
    virtual int Present() = 0;
    virtual int CreateAdditionalSwapChain(HWND hWnd) = 0;
    virtual int DeleteAdditionalSwapChain(ISwapChain *swapChain) = 0;

    // texture 引用计数器+1
    virtual int IncrTextureRef(int index) = 0;
    virtual int DecrTextureRef(int index) = 0;
    // 创建纹理
    virtual int CreateTextureFromMem(TextureSurface* parameter) = 0;
    virtual int CreateTexture(int width, int height, SURFACE_FORMAT format) = 0;
    virtual void ReleaseTextureSurface(int index, LONG left, LONG top,TextureSurface* parameter) = 0;

    virtual int GetXX();
    virtual int Todo(TextureSurface* surface1, TextureSurface* surface2);

    virtual int GetTextureViewWidth(int index);
    virtual int GetTextureViewHeight(int index);
    virtual int GetTextureViewVolume(int index);

    // todo more than 200 functions
};
