#pragma once

namespace Core {
	class Writer {
	public:
		void Save();
		void Load();
	};
	extern Writer writer;
};