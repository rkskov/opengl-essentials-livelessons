#pragma once

#if defined(WINDOWS)
#include <windows.h>
#endif

#include <map>

namespace Library
{
	class ServiceContainer
	{
	public:
		ServiceContainer();

		void AddService(UINT typeID, void* service);
		void RemoveService(UINT typeID);
		void* GetService(UINT typeID) const;

	private:
		ServiceContainer(const ServiceContainer& rhs);
		ServiceContainer& operator=(const ServiceContainer& rhs);

		std::map<UINT, void*> mServices;		
	};
}
