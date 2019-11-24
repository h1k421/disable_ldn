#pragma once

#include <switch.h>
#include <stratosphere.hpp>

#include "iuserlocalcommunicationservice.hpp"

class IUserServiceCreator : public IMitmServiceObject {
private:
    enum class CommandId {
        CreateUserLocalCommunicationService = 0,
    };
public:
    IUserServiceCreator(std::shared_ptr<Service> s, u64 pid, sts::ncm::TitleId tid) : IMitmServiceObject(s, pid, tid) {
        /* ... */
    }
    
    static bool ShouldMitm(u64 pid, sts::ncm::TitleId tid) {
        return true;
    }

    static void PostProcess(IMitmServiceObject *obj, IpcResponseContext *ctx) {};
protected:
    Result CreateUserLocalCommunicationService(Out<std::shared_ptr<IUserLocalCommunicationService>> out);
public:
    DEFINE_SERVICE_DISPATCH_TABLE {
        MAKE_SERVICE_COMMAND_META(IUserServiceCreator, CreateUserLocalCommunicationService),
    };
};
