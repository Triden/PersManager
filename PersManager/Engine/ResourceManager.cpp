#include "ResourceManager.h"
#include "Writer.h"
#include "Assertion.h"

namespace Core {
	ResourceManager::ResourceManager() {

	};

	void ResourceManager::Load(const std::string& fileName) {
		Clear();

		XmlFile xmlFile(fileName);
		xmlFile.Open();

		XmlNode *node = xmlFile.GetDeclaration();
		std::string encoding = node->GetStringValueOrDef("encoding");

		XmlNode *rootXml = xmlFile.GetNode("root");

		//Грузим объекты из полигонов
		XmlNode *polyXml = xmlFile.GetNodeFrom(rootXml, "poly");
		for (; polyXml != NULL; polyXml = xmlFile.GetNextNodeFrom(polyXml, "poly")) {
			std::string id = polyXml->GetStringValueOrDef("id", "unknow");
			float scale = polyXml->GetFloatValueOrDef("scale", 1.f);

			XmlNode *triangleXml = xmlFile.GetNodeFrom(polyXml, "triangle");

			PolyObject polyObject;
			Assert(_polygonObjects[id].Default());	//Объект с таким именем уже существует

			for (; triangleXml != NULL; triangleXml = xmlFile.GetNextNodeFrom(triangleXml, "triangle")) {
				FPolygon polygon;
				polygon.v1.x = triangleXml->GetFloatValueOrDef("x1", 0.f);
				polygon.v2.x = triangleXml->GetFloatValueOrDef("x2", 0.f);
				polygon.v3.x = triangleXml->GetFloatValueOrDef("x3", 0.f);
				polygon.v1.y = triangleXml->GetFloatValueOrDef("y1", 0.f);
				polygon.v2.y = triangleXml->GetFloatValueOrDef("y2", 0.f);
				polygon.v3.y = triangleXml->GetFloatValueOrDef("y3", 0.f);
				
				polyObject.AddPolygon(polygon, false);
			}

			polyObject.Scale(scale);
			_polygonObjects[id] = polyObject;
		}
	};

	PolyObject* ResourceManager::GetPoly(const std::string& name) {
		PolyObject *object = &_polygonObjects[name];
		Assert(object != NULL);
		return object;
	};

	void ResourceManager::Clear() {
		_polygonObjects.clear();
	};
};
