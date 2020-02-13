#include "pch.h"
#include "LS_Engine.h"

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
	WNDCLASSW wc = { 0 };

	wc.hInstance = hInst;
	wc.lpszClassName = L"WindowClass";
	wc.lpfnWndProc = WindowProcedure;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);

	if (!RegisterClassW(&wc))
		return -1;

	CreateWindowW(L"WindowClass", L"Leo Scott Engine", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 200, 200, 1200, 800, nullptr, nullptr, nullptr, nullptr);

	MSG msg = { 0 };

	while (GetMessage(&msg, nullptr, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	static LS_Engine sEngine;

	SetTimer(hWnd, 1, 25, NULL);

	COLORREF color = RGB(0, 0, 0);
	HPEN hPen = CreatePen(PS_SOLID, 7, color);
	PAINTSTRUCT ps;
	HDC hdc;

	hdc = BeginPaint(hWnd, &ps);

	switch (msg)
	{
		/*
		case WM_MOUSEMOVE:
			InvalidateRect(hWnd, NULL, true);
			UpdateWindow(hWnd);
			break;
		*/

	case WM_TIMER:
		InvalidateRect(hWnd, NULL, true);
		UpdateWindow(hWnd);
		break;

	case WM_PAINT:
	{
		sEngine.Update();
		sEngine.Input();

		for (int i = 0; i < sEngine.numberOfLines; i++)
		{
			sEngine.Draw(hWnd, hdc, ps, color, hPen, sEngine.lines[i]);
		}

		break;
	}

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProcW(hWnd, msg, wp, lp);
	}
}

void LS_Engine::Draw(HWND hWnd, HDC hdc, PAINTSTRUCT ps, COLORREF color, HPEN hPen, Line line)
{
	HPEN hPenOld = (HPEN)SelectObject(hdc, hPen);

	MoveToEx(hdc, line.startX, line.startY, NULL);
	LineTo(hdc, line.endX, line.endY);
	DeleteObject(SelectObject(hdc, hPenOld));
}

void LS_Engine::Input()
{
	if (GetAsyncKeyState(VK_UP))
	{
		LS_Engine::onUpPressed();
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		LS_Engine::onLeftPressed();
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		LS_Engine::onDownPressed();
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		LS_Engine::onRightPressed();
	}
}

LS_Engine::LS_Engine()
{
	Lines();
	WinMain(0, 0, 0, 0);
}