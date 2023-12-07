#pragma once
#include <iostream>
namespace techyB
{
namespace designs {

	namespace adaptor {

		class Target {
		public:
			virtual ~Target() = default;
			virtual std::string request() const {
				return "Target: The default targets behavior!";
			}
		};

		class Adaptee {
		public:
			std::string SpecificRequest() const {
				return ".eetpadA eht fo roivaheb laicepS";
			}
		};

		// ----------- aproach 1 ---- using object adaptor ---------
		class Adapter : public Target {
		private:
			Adaptee* adaptee_;
		public:
			Adapter(Adaptee* adaptee) : adaptee_(adaptee) {};
			std::string request() const override {
				std::string msg = adaptee_->SpecificRequest();
				std::reverse(msg.begin(), msg.end());
				return "Translated: " + msg;
			}
		};

		// ------------ aprach 2 ---- using class adaptor ----------

		class ClassAdaptor : public Target, private Adaptee {
		public:
			std::string request() const override {
				std::string msg = SpecificRequest();
				std::reverse(msg.begin(), msg.end());
				return "Translated: " + msg;
			}
		};

		//---------------------------------------------------------------
		void invokeRequest(Target* target);
		void runClient();

	}
}

}