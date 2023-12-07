#include <TC_Facade.h>

namespace techyB
{
    namespace designs {

        namespace facade {
            void runClient() {
                std::cout << "================== Running Facade design pattern demo ================" << std::endl;
                // -------------- older implementation with tight coupling when facade class is not used ----------
                //Database db;
                //PaymentGateway pg;
                //MessagingService msg;
                //db.storeReservation("my reservatino");
                //pg.processPayment("payment info");
                //msg.sendMessage("my message");

                //--------------- using facade class to hide complex details and simplify reservasion -----------
                HotelReservationFacadeClass hotelReserv;
                hotelReserv.makeReservation("Reservation info", "Payment info");
                std::cout << "==================== End of demo ====================" << std::endl;
            }
        }

    }

}