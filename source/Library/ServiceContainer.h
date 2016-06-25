#pragma once

#include <map>

namespace Library
{
	class ServiceContainer final
	{
	public:
		ServiceContainer() = default;
		ServiceContainer(const ServiceContainer& rhs) = delete;
		ServiceContainer& operator=(const ServiceContainer& rhs) = delete;
		ServiceContainer(ServiceContainer&& rhs) = delete;
		ServiceContainer& operator=(ServiceContainer&& rhs) = delete;
		~ServiceContainer() = default;

		void AddService(std::uint64_t typeID, void* service);
		void RemoveService(std::uint64_t typeID);
		void* GetService(std::uint64_t typeID) const;

		std::map<std::uint64_t, void*> mServices;
	};
}