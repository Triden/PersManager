#include "ResourceManager.h"
#include "Assertion.h""
#include "Writer.h"

namespace Core {
	ResourceManager::ResourceManager() {

	};

	void ResourceManager::Load(const std::string& fileName) {
		XmlFile xmlFile(fileName);
		xmlFile.Open();

		XmlNode *node = xmlFile.GetDeclaration();
		std::string encoding = node->GetValue("encoding");

		XmlNode *rootXml = xmlFile.GetNode("root");

		//Грузим объекты из полигонов
		XmlNode *polyXml = xmlFile.GetNodeFrom(rootXml, "poly");
		for (; polyXml != NULL; polyXml = xmlFile.GetNextNodeFrom(polyXml, "poly")) {
			std::string id = polyXml->GetValue("id");
			float scale = String::ToFloat(polyXml->GetValue("scale"));

			XmlNode *triangleXml = xmlFile.GetNodeFrom(polyXml, "triangle");

			PolyObject polyObject;
			Assert(_polygonObjects[id].Default());	//Объект с таким именем уже существует

			for (; triangleXml != NULL; triangleXml = xmlFile.GetNextNodeFrom(triangleXml, "triangle")) {
				FPolygon polygon;
				polygon.v1.x = String::ToFloat(triangleXml->GetValue("x1"));
				polygon.v2.x = String::ToFloat(triangleXml->GetValue("x2"));
				polygon.v3.x = String::ToFloat(triangleXml->GetValue("x3"));
				polygon.v1.y = String::ToFloat(triangleXml->GetValue("y1"));
				polygon.v2.y = String::ToFloat(triangleXml->GetValue("y2"));
				polygon.v3.y = String::ToFloat(triangleXml->GetValue("y3"));
				
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
