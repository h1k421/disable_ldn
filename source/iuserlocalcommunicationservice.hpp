#pragma once

#include <switch.h>
#include <stratosphere.hpp>

class IUserLocalCommunicationService : public IServiceObject {
private:
    enum class CommandId {
        InitializeOld = 400,
        Initialize = 402,
    };
public:
    IUserLocalCommunicationService() {
        /* ... */
    };
        
    ~IUserLocalCommunicationService() {
        /* ... */
    };
    
protected:
    Result InitializeOld(u64 unk, PidDescriptor pid);
    Result Initialize(u64 unk, PidDescriptor pid);
public:
    DEFINE_SERVICE_DISPATCH_TABLE {
        MAKE_SERVICE_COMMAND_META(IUserLocalCommunicationService, InitializeOld),
        MAKE_SERVICE_COMMAND_META(IUserLocalCommunicationService, Initialize),
    };
};
