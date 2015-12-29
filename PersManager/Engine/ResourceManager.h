#ifndef ENGINE_RESOURCE_MANAGER
#define ENGINE_RESOURCE_MANAGER

#include "PolyObject.h"
#include "Types.h"
#include <unordered_map>

namespace Core {
	class ResourceManager {
	private:
		std::unordered_map<std::string, PolyObject> _polygonObjects;
	public:
		ResourceManager();
		void Load(const std::string& fileName);
		PolyObject* GetPoly(const std::string& name);
		void Clear();
	};
	extern ResourceManager resourceManager;
};
#endif