#pragma once

#include <exception>
#if defined(WINDOWS)
#include <windows.h>
#endif
#include <string>

namespace Library
{
	class GameException : public std::exception
	{
	public:
		GameException(const char* const& message, HRESULT hr = S_OK);

		HRESULT HR() const;
		std::wstring whatw() const;

	private:
		HRESULT mHR;
	};
}
