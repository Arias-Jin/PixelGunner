#include "stdafx.h"
#include "CFramework.h"

CFramework::CFramework()
{
}

CFramework::~CFramework()
{
}

HRESULT CFramework::InitD3D(HWND hWnd)
{
	m_hWnd = hWnd;

	if (NULL == (m_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		return E_FAIL;
	}

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;

	if (FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &m_pd3dDevice)))
	{
		return E_FAIL;
	}

	return S_OK;
}

void CFramework::Render()
{
	if (NULL == m_pd3dDevice)
	{
		return;
	}

	m_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

	if (SUCCEEDED(m_pd3dDevice->BeginScene()))
	{
		OnRender();

		m_pd3dDevice->EndScene();
	}

	m_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

void CFramework::Update()
{
	OnUpdate();
}

void CFramework::CleanUp()
{
	OnRelease();

	if (m_pd3dDevice != NULL)
	{
		m_pd3dDevice->Release();
	}
	if (m_pD3D != NULL)
	{
		m_pD3D->Release();
	}
}
