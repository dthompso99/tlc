#include <vector>

class GLFWwindow;

namespace Centauri {
	class TLCWindow {
	public:
		TLCWindow();
		~TLCWindow();
		void loop();
		bool shouldClose;
	private:
		GLFWwindow* window;
		
	};
}