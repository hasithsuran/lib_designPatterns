#pragma once

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

		void invokeRequest(Target* target) {
			std::cout << "Request invoked!. Result : " << target->request() << std::endl;
			std::cout << "\n\n";
		}

		void runClient() {
			std::cout << "Works fine with just old Target objects! *****************" << std::endl;
			Target* tgt = new Target();
			invokeRequest(tgt);

			Adaptee* adptee = new Adaptee();
			std::cout << "Adaptee also works on its own! *****************" << std::endl;
			std::cout << adptee->SpecificRequest() << std::endl;
			std::cout << "\n\n";

			std::cout << "Lets see how it works through object adapter *****************" << std::endl;
			Adapter* adpter = new Adapter(adptee);
			invokeRequest(adpter);

			std::cout << "Lets see how it works through class adapter *****************" << std::endl;
			ClassAdaptor* clsAdpter = new ClassAdaptor();
			invokeRequest(clsAdpter);

			delete tgt;
			delete adptee;
			delete adpter;
			delete clsAdpter;
		}

	}
}