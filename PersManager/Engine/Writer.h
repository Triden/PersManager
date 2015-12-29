#ifndef ENGINE_WRITER
#define ENGINE_WRITER

#include "..\rapidxml\rapidxml.hpp"
#include "..\rapidxml\rapidxml_print.hpp"
#include <list>
#include "Math.h"

namespace Core {
	using namespace rapidxml;
	class Example {
	public:
		void Save();
		void Load();
	};

	class XmlNode {
		xml_node<>* _node;
		xml_document<>* _doc;
		std::string GetValue(char* param);
	public:
		XmlNode(xml_node<>* node, xml_document<>* doc);
		//Save
		void AddParameter(const char* param, const char* value);
		xml_node<>* GetNode();
		void Apply();
		void ApplyTo(XmlNode* node);
		//Load
		int GetIntValueOrDef(char* param, int def = 0);
		float GetFloatValueOrDef(char* param, float def = 0.f);
		std::string GetStringValueOrDef(char* param, const std::string& def = "");
	};

	class XmlFile {
	private:
		std::string _path;
		xml_document<> _doc;		// character type defaults to char
		std::list<XmlNode> _list;
		std::vector<char> _data;
	public:
		XmlFile(const std::string& path);
		//Save
		XmlNode* AddNode(const char* nodeName);
		XmlNode* AddDeclaration();
		void Save();
		//Load
		void Open();
		XmlNode* GetNode(const char* nodeName);
		XmlNode* GetNodeFrom(XmlNode* node, const char* nodeName);
		XmlNode* GetNextNodeFrom(XmlNode* node, const char* nodeName);
		XmlNode* GetDeclaration();
	};
	extern Example writer;
};
#endif