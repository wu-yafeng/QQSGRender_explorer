#include <Windows.h>
class ISwapChain
{
public:
    virtual void Free( bool) = 0;
    virtual int SetRenderTarget() = 0;
    virtual int Present() = 0;
    // todo
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

    // un-analysis
    virtual int TextureFunc1(int a1) = 0;
    virtual int TextureFunc2(int a1) = 0;
    virtual int TextureFunc3(int a1) = 0;
    virtual int TextureFunc4(int width, int height, int formatType) = 0;
    virtual int TextureFunc5(int a1, int a2, int a3, int a4) = 0;

    // todo more than 200 functions
};
