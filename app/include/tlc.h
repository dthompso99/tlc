
#include "tlc_window.h"

namespace Centauri {
	class TLC {
	public:
		TLC();
		~TLC();
		int test();
		void init();
		void error(std::string);
		TLCWindow* createWindow();
	};
}