#ifndef DataProviderFactory_hpp
#define DataProviderFactory_hpp

#include <iostream>
#include "DataProviderInterface.hpp"

using namespace std;

namespace Data {
namespace Providers{
    
    class DataProviderFactory {
    public:
        enum ProviderTypeEnum { TEST, CSV, JSON, DB };
    
        /**
         * Obtain a specific provider instance givent the supplied type.
         * Note: Since a pointer is returned, the object is created on the heap so don't forget to
         * execute `delete` when the instance is no longer needed.
         * @return A Pointer to a DataProviderInterface derived class
         */
        DataProviderInterface * getProvider(ProviderTypeEnum pte);
    };
    
} // namespace Providers
} // namespace Data

#endif /* DataProviderFactory_hpp */
