#pragma once
#include <iostream>

namespace techyB
{
namespace designs {

	namespace facade {

        // ------------ individual complex services need to hide behind facade class --------------------
        class Database {
        public:
            void storeReservation(const std::string reservation_info) {
                std::cout << "Storing reservation info: " << reservation_info << std::endl;
            }
        };
    
        class PaymentGateway {
        public:
            void processPayment(const std::string payment_info) {
                std::cout << "Processing payment info: " << payment_info << std::endl;
            }
        };

        class MessagingService {
        public:
            void sendMessage(const std::string message) {
                std::cout << "Sending message: " << message << std::endl;
            }
        };

        //facade class to hide all complex details and simplify hotel reservation

        class HotelReservationFacadeClass {
        private:
            Database m_db;
            PaymentGateway m_pg;
            MessagingService m_msg;
        public:
            HotelReservationFacadeClass(): m_db(), m_pg(), m_msg() {}
            void makeReservation(const std::string reservation_info, const std::string payment_info) {
                m_db.storeReservation(reservation_info);
                m_pg.processPayment(payment_info);
                m_msg.sendMessage("Reservation confirmed");
            }
        };

        void runClient();

    }
}

}