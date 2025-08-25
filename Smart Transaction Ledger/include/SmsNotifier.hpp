class SmsNotifier : public IObserver {
private:
    std::string phone_number;
public:
    // The constructor now takes the specific detail it needs.
    SmsNotifier(const std::string& number) : phone_number(number) {}

    void update(const Transaction& trx) override {
        // Now it can use its specific data.
        std::cout << "Sending SMS to " << phone_number << " about transaction." << std::endl;
        // ... logic to format and send the email ...
    }
};