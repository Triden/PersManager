#include "Writer.h"
#include <fstream>
#include <iostream>
#include "Types.h"
#include "Assertion.h"

namespace Core {

	XmlNode::XmlNode(xml_node<>* node, xml_document<>* doc) :
		_doc(doc),
		_node(node)
	{
	}

	void XmlNode::AddParameter(const char* param, const char* value) {
		_node->append_attribute(_doc->allocate_attribute(param, value));
	}

	xml_node<>* XmlNode::GetNode() {
		return _node;
	}

	void XmlNode::Apply() {
		_doc->append_node(_node);
	}

	void XmlNode::ApplyTo(XmlNode* node) {
		node->GetNode()->append_node(_node);
	}

	std::string XmlNode::GetValue(char* param) {
		if (_node->first_attribute(param) == NULL) {
			Assert(false);
			return "";
		}
		return _node->first_attribute(param)->value();
	}

	//========================XmlFile============================

	XmlFile::XmlFile(const std::string& path) :
		_path(path)
	{
		_doc.parse<0>("");    // 0 means default parse flags
	}

	XmlNode* XmlFile::AddNode(const char* nodeName) {
		xml_node<>* xmlNode = _doc.allocate_node(node_element, nodeName);
		if (xmlNode == NULL) {
			return NULL;
		}
		_list.push_back(XmlNode(xmlNode, &_doc));
		return &_list.back();
	}

	XmlNode* XmlFile::AddDeclaration() {
		xml_node<>* xmlNode = _doc.allocate_node(node_declaration);
		if (xmlNode == NULL) {
			return NULL;
		}
		_list.push_back(XmlNode(xmlNode, &_doc));
		return &_list.back();
	}

	void XmlFile::Save() {
		std::ofstream file;
		file.open(_path);
		file << _doc;
	}

	void XmlFile::Open() {
		std::string input = "";
		std::string line = "";
		std::ifstream file(_path);
		size_t MAX_SIZE = std::string().max_size();
		while (std::getline(file, line)) {
			if (line.length() > MAX_SIZE - input.length()) {
				Assert(false);
			}
			input += line;
		}

		// we are choosing to parse the XML declaration
		// parse_no_data_nodes prevents RapidXML from using the somewhat surprising
		// behavior of having both values and data nodes, and having data nodes take
		// precedence over values when printing
		// >>> note that this will skip parsing of CDATA nodes <<<

		_data.resize(input.size());
		memcpy(&_data[0], &input[0], input.size() * sizeof(char));
		_data.push_back('\0');

		_doc.parse<parse_declaration_node | parse_no_data_nodes>(&_data[0]);
	}

	XmlNode* XmlFile::GetNode(const char* nodeName) {
		xml_node<>* xmlNode = _doc.first_node(nodeName);
		if (xmlNode == NULL) {
			return NULL;
		}
		_list.push_back(XmlNode(xmlNode, &_doc));
		return &_list.back();
	}

	XmlNode* XmlFile::GetNodeFrom(XmlNode* node, const char* nodeName) {
		xml_node<>* xmlNode = node->GetNode()->first_node(nodeName);
		if (xmlNode == NULL) {
			return NULL;
		}
		_list.push_back(XmlNode(xmlNode, &_doc));
		return &_list.back();
	}

	XmlNode* XmlFile::GetNextNodeFrom(XmlNode* node, const char* nodeName) {
		xml_node<>* xmlNode = node->GetNode()->next_sibling(nodeName);
		if (xmlNode == NULL) {
			return NULL;
		}
		_list.push_back(XmlNode(xmlNode, &_doc));
		return &_list.back();
	}

	XmlNode* XmlFile::GetDeclaration() {
		xml_node<>* node = _doc.first_node();
		if (node == NULL) {
			return NULL;
		}
		_list.push_back(XmlNode(_doc.first_node(), &_doc));
		return &_list.back();
	}

	//========================Example============================

	void Example::Save() {
		XmlFile xmlFile("example.xml");

		//declaration
		XmlNode* node = xmlFile.AddDeclaration();
		node->AddParameter("version", "1.0");
		node->AddParameter("encoding", "utf-8");
		node->Apply();

		//root
		XmlNode* root = xmlFile.AddNode("root");
		root->AddParameter("type", "example");
		root->Apply();

		// child node
		std::vector<char *> test = {
			"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"
		};
		for (int i = 0; i < test.size(); ++i) {
			XmlNode* child = xmlFile.AddNode("child");
			child->AddParameter("test", test[i]);
			child->ApplyTo(root);
		}
		
		xmlFile.Save();
	};

	void Example::Load() {
		XmlFile xmlFile("example.xml");
		xmlFile.Open();

		XmlNode *node = xmlFile.GetDeclaration();
		std::string encoding = node->GetValue("encoding");

		XmlNode *rootXml = xmlFile.GetNode("root");
		std::string root = rootXml->GetValue("type");
		
		XmlNode *childXml = xmlFile.GetNodeFrom(rootXml, "child");
		int i = 0;
		for (; childXml != NULL; childXml = xmlFile.GetNextNodeFrom(childXml, "child")) {
			std::string test = childXml->GetValue("test");
			++i;
		}
	};
};