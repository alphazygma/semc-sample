#ifndef TestProvider_hpp
#define TestProvider_hpp

#include "DataProviderInterface.hpp"

using namespace std;

namespace Data {
namespace Providers{
        
    struct TestConfig: ProviderConfig {};
        
    class TestProvider : public DataProviderInterface {
    public:
        TestProvider(const TestConfig & providerConfig);
        
        ~TestProvider() {}
        
        void initialize();
        
        vector<vector<string>> getData();
        
    protected:
        ProviderConfig _providerConfig;
        
    };
    
} // namespace Providers
} // namespace Data

#endif /* TestProvider_hpp */
