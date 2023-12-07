#include <TC_Adapter.h>

namespace techyB
{
    namespace designs {

        namespace adaptor {

            void invokeRequest(Target* target) {
                std::cout << "Request invoked!. Result : " << target->request() << std::endl;
                std::cout << "\n\n";
            }

            void runClient() {
                std::cout << "================= Running Adaptor design pattern demonstration ========================" << std::endl;
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
                std::cout << "================= end of demo ==============" << std::endl;
                delete tgt;
                delete adptee;
                delete adpter;
                delete clsAdpter;
            }

        }

    }
}