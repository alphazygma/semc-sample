#include "DataProviderFactory.hpp"
#include "TestProvider.hpp"

using namespace Data::Providers;

DataProviderInterface * DataProviderFactory::getProvider(ProviderTypeEnum pte) {
    DataProviderInterface * provider;
    
    switch (pte) {
        case DataProviderFactory::ProviderTypeEnum::TEST :
        {
            TestConfig testConfig;
            
            provider = new TestProvider(testConfig);
            break;
        }
        default:
            throw "Undefined Provider";
            break;
    }
    
    return provider;
}