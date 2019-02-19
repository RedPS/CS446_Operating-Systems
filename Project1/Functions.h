#include "Configuration.h"
#include "MetaData.h"


namespace Functions {
    void logoutput(Configuration config, std::ostream& output, int status, std::vector<MetaData> data);
    void logtofile(Configuration config, std::vector<MetaData> data) throw (std::runtime_error);
    void ProcTime(Configuration config, MetaData& data, int& status, int &progstatus) throw (std::runtime_error);
}
