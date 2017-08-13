#include "TestProvider.hpp"

using namespace Data::Providers;

// --------------------------------------------------------------------------
// Implementing Public methods & constructor

TestProvider::TestProvider(const TestConfig & providerConfig) :
        DataProviderInterface(providerConfig),
        _providerConfig(providerConfig)
{}

vector<vector<string>> TestProvider::getData() {
    vector<vector<string>> dataSet = {
        {"id", "first_name", "last_name", "created_at"},
        {"1", "Alejandro", "Salazar", "1982-04-03"},
        {"2", "User", "Two", "2000-01-01"},
        {"3", "Another", "User", "2017-08-05"}
    };
    
    return dataSet;
}

void TestProvider::initialize() {
    // Nothing to do here, but if it were a DB, probably here is where we would initialize the
    // DB Connection
}

// --------------------------------------------------------------------------
// Implementing Private methods
