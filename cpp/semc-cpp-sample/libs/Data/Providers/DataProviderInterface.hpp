#ifndef DataProviderInterface_hpp
#define DataProviderInterface_hpp

#include <iostream>
#include <vector>

using namespace std;

namespace Data {
namespace Providers{

/**
 * Base Struct to be used to be used as configuration object to initialize Data Providers.
 * It should be extended by the Derived classes of the DataProviderInterface to meet each provider
 * specific needs.
 * @author Alejandro B. Salazar (alphazygma@gmail.com)
 */
struct ProviderConfig {
};

/**
 * Interface used to provide base structure for the DataProvider derived classes.
 * @author Alejandro B. Salazar (alphazygma@gmail.com)
 */
class DataProviderInterface {
public:
    /**
     * Base Constructor needed to initialize the data source connection
     * @param providerConfig Configuration object with information on how to retrieve data
     */
    DataProviderInterface(const ProviderConfig & providerConfig) {};
    
    virtual ~DataProviderInterface() {}
    
    /**
     * Method to provide lazy initialization of a provider, with the intention to be use within
     * a framework and the object created when it is needed and initialized when used for the
     * first time
     */
    virtual void initialize()=0;
    
    /**
     * Simple method to retrieve data from the data source.
     * Think it of an overly simplified ORM system, where the returned data is standarized regardles
     * of how is it retrieved or accessed on different storages (MySql, MongoDb, Redis, etc)
     */
    virtual vector<vector<string>> getData()=0;
};

} // namespace Providers
} // namespace Data

#endif /* DataProviderInterface_hpp */
