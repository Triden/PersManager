#include "Writer.h"

#include "rapidxml\rapidxml.hpp"
#include "rapidxml\rapidxml_print.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace Core {
	void Writer::Save() {
		using namespace rapidxml;
		xml_document<> doc;    // character type defaults to char
		doc.parse<0>("");    // 0 means default parse flags

							 //declaration
		xml_node<>* decl = doc.allocate_node(node_declaration);
		decl->append_attribute(doc.allocate_attribute("version", "1.0"));
		decl->append_attribute(doc.allocate_attribute("encoding", "utf-8"));
		doc.append_node(decl);

		//root
		xml_node<>* root = doc.allocate_node(node_element, "root");
		root->append_attribute(doc.allocate_attribute("type", "example"));
		doc.append_node(root);

		// child node
		xml_node<>* child = doc.allocate_node(node_element, "child");
		child->append_attribute(doc.allocate_attribute("test", "2"));
		root->append_node(child);

		std::ofstream file;
		file.open("example.xml");
		file << doc;
	};

	void Writer::Load() {
		using namespace rapidxml;
		std::string input = "";
		std::string line = "";
		std::ifstream file("example.xml");
		while (std::getline(file, line)) {
			input += line;
		}

		std::vector<char> xml_copy(input.begin(), input.end());
		xml_copy.push_back('\0');

		// only use xml_copy from here on!
		xml_document<> doc;
		// we are choosing to parse the XML declaration
		// parse_no_data_nodes prevents RapidXML from using the somewhat surprising
		// behavior of having both values and data nodes, and having data nodes take
		// precedence over values when printing
		// >>> note that this will skip parsing of CDATA nodes <<<
		doc.parse<parse_declaration_node | parse_no_data_nodes>(&xml_copy[0]);

		std::string encoding = doc.first_node()->first_attribute("encoding")->value();
		// encoding == "utf-8"

		// we didn't keep track of our previous traversal, so let's start again
		// we can match nodes by name, skipping the xml declaration entirely
		xml_node<>* cur_node = doc.first_node("root");
		std::string root = cur_node->first_attribute("type")->value();
		//example

		cur_node = cur_node->first_node("child");
		std::string test = cur_node->first_attribute("test")->value();


	};
};