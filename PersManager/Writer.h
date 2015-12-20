#pragma once

#include "rapidxml\rapidxml.hpp"
#include "rapidxml\rapidxml_print.hpp"
#include <list>
#include <vector>

namespace Core {
	using namespace rapidxml;
	class Writer {
	public:
		void Save();
		void Load();
	};

	class XmlNode {
		xml_node<>* _node;
		xml_document<>* _doc;
	public:
		XmlNode(xml_node<>* node, xml_document<>* doc);
		//Save
		void AddParameter(char* param, char* value);
		xml_node<>* GetNode();
		void Apply();
		void ApplyTo(XmlNode* node);
		//Load
		std::string GetValue(char* param);
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
		XmlNode* GetDeclaration();
	};
	extern Writer writer;
};